#version 440

layout (local_size_x = 1, local_size_y = 1) in;

layout(binding = 0, rgba32f) uniform image2D OutTexture;

uniform int Width = 512;
uniform int Height = 512;

uniform vec3 lightDir;

uniform vec3 CameraPosition;
uniform vec3 CameraUpVector;
uniform vec3 CameraRightVector;

uniform float ViewPlaneHalfWidth;
uniform float ViewPlaneHalfHeight;
uniform vec3 ViewPlaneOrigin;

uniform vec3 CameraLookAtVector;

struct Ray
{
	vec3 Origin;
	vec3 Direction;
};


struct Sphere 
{
	vec3 Origin;
	float Radius;
};

// This is a 0-1 pixel coordinate Vector2
ivec2 PixelCoord = ivec2(gl_GlobalInvocationID.xy);

Sphere sph = Sphere(vec3(0.0f,0.0f,0.0f), 1.0f);	
Ray ray;

Ray ComputeCameraRay()
{
	Ray ray;

	//vec2 NormalizedCoord = vec2((PixelCoord.x / Width) - 0.5f, (PixelCoord.y / Height) - 0.5f);
	//vec3 ImagePoint = NormalizedCoord.x * CameraRightVector + NormalizedCoord.y + CameraUpVector + CameraPosition + CameraLookAtVector;


	vec3 xIncrement = (CameraRightVector * 2 * ViewPlaneHalfWidth)/Width;
	vec3 yIncrement = (CameraUpVector * 2 * ViewPlaneHalfHeight)/Height;
	vec3 ImagePoint = ViewPlaneOrigin + (PixelCoord.x * xIncrement) + (PixelCoord.y * yIncrement);

	
	//vec3 ImagePoint =	NormalizedCoord.x * CameraRightVector	+
	//					NormalizedCoord.y * CameraUpVector		+
	//					CameraPosition + CameraLookAtVector;

	ray.Origin = CameraPosition;
	ray.Direction = normalize(ImagePoint - CameraPosition);
	
	return ray;
}

// Ray, initialize origin + direction

//vec3 rayToSphere = ray.origin - sph.origin;
//float b = dot(ray.dir, rayToSphere);
//float c = dot(rayToSphere, rayToSphere) - sph.radius * sph.radius;
//float bsqmc = b * b - c;

vec4 sphColor = vec4(1.0f, 0.4f, 1.0f, 1.0f);

vec4 PixelColor = vec4(0.0f,0.0f,0.0f,0.0f);

float t1, t2;

bool RayIntersectSphere(Ray r, Sphere s)
{

	vec3 ROtoSO = r.Origin - s.Origin;

	float ROtoSOdotRD = dot(ROtoSO, r.Direction);

	if(ROtoSOdotRD < 0)
		return false;
	else
	{
		float d = sqrt( dot(ROtoSO, ROtoSO) - (ROtoSOdotRD * ROtoSOdotRD) );

		if(d > s.Radius)
			return false;

		float t1c = sqrt( (s.Radius * s.Radius) - (d * d) );

		t1 = ROtoSOdotRD - t1c;
		t2 = ROtoSOdotRD + t1c;
	}

	
	//vec3 L = r.Origin - s.Origin;

	//float tc = dot(L, r.Direction);

	//if(tc < 0)
	//	return false;
	//else
	//{
	//	float d = sqrt(dot(L,L) - tc * tc);
	
	//	if(d > s.Radius)
	//		return false;

	//	float t1c = sqrt((s.Radius * s.Radius) - (d * d));

	//	t1 = tc - t1c;
	//	t2 = tc + t1c;
	//}
	

	return true;
	
};


bool RaySphereIntersection(Ray r, Sphere s)
{
	vec3 ROtoSO = r.Origin - s.Origin;
	float SphRSq = s.Radius * s.Radius;
	float ROtoSOdotRD = dot(ROtoSO, r.Direction);

	if(ROtoSOdotRD > 0 || dot(ROtoSO, ROtoSO) < SphRSq)
		return false;

	vec3 a = ROtoSO - ROtoSOdotRD * r.Direction;

	float aSq = dot(a, a);

	if(aSq > SphRSq)
		return false;

	float h = sqrt(SphRSq - aSq);
	vec3 i = a - h * ray.Direction;

	return true;
}

void main() 
{

	ray = ComputeCameraRay();


	if (RaySphereIntersection(ray, sph)) 
	{
		vec3 poi = ray.Origin + ray.Direction * t1;
		vec3 normal = normalize(poi - sph.Origin);
		float light = dot(lightDir, normal);
		light = clamp(light, 0.0f, 1.0f);

	  PixelColor = vec4(light, light, light, 1.0f);
	}

	imageStore(OutTexture, PixelCoord, PixelColor);

	/*
	int currIndex = (int(resolution.x) * storePos.y) + storePos.x;
	
	if(currIndex == index)
		imageStore(tex, storePos, vec4(1.0f,1.0f,1.0f,1.0f));
	else if(currIndex < index)
		imageStore(tex, storePos, vec4(1.0f, 0.0f, 0.0f, 1.0f));
	else
		imageStore(tex, storePos, vec4(storePos.x/resolution.x, storePos.y/resolution.y, 0, 1.0f));
	*/
}