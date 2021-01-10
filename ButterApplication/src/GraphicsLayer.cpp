#include "GraphicsLayer.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "stb_image/stb_image.h"


GraphicsLayer::GraphicsLayer()
	: Layer("GraphicsLayer")
{
}

void GraphicsLayer::OnAttach()
{

	//tex = Butter::Texture2D::Create(std::string("src/assets/textures/butter512.jpg"));

	tex = Butter::Texture2D::Create(resolution.x, resolution.y);
	tex->BindCompute();

	shader_compute = Butter::Shader::Create();
	shader_compute->AddShaderSource("src/assets/shaders/compute.glsl", Butter::ShaderType::Compute);

	shader_compute->Compile();
	shader_compute->Bind();
	shader_compute->SetInt("tex", 0);
	shader_compute->SetFloat2("resolution", resolution);
	


	shader_fullscreenTri = Butter::Shader::Create();
	shader_fullscreenTri->AddShaderSource("src/assets/shaders/vert_fullscreenTri.glsl", Butter::ShaderType::Vertex);
	shader_fullscreenTri->AddShaderSource("src/assets/shaders/frag_fullscreenTri.glsl", Butter::ShaderType::Fragment);

	shader_fullscreenTri->Compile();
	shader_fullscreenTri->Bind();

	camera = Butter::Camera();
}

void GraphicsLayer::OnDetach()
{
	shader_fullscreenTri->Unbind();
}

void GraphicsLayer::OnUpdate()
{

	// Render
	{
		//if (index >= 1.0f || index <= -1.0f)
		//	increment = -increment;

		//index += increment;

		//lightDir.x = index;
		//lightDir.z = -1.0f;

		shader_compute->Bind();

		shader_compute->SetFloat3("lightDir", lightDir);

		camera.Update();

		shader_compute->SetFloat3("CameraPosition", camera.Position);
		shader_compute->SetFloat3("ViewPlaneOrigin", camera.ViewPlaneOrigin);
		shader_compute->SetFloat3("CameraUpVector", camera.UpVector);
		shader_compute->SetFloat3("CameraRightVector", camera.RightVector);
		shader_compute->SetFloat("ViewPlaneHalfWidth", camera.ViewPlaneHalfWidth);
		shader_compute->SetFloat("ViewPlaneHalfHeight", camera.ViewPlaneHalfHeight);

		shader_compute->DispatchCompute(resolution.x, resolution.y, 1);

		//BTR_INFO("Light Direction: {0}, {1}, {2}", lightDir.x, lightDir.y, lightDir.z);

		Butter::RenderCommand::MemBarrier();

		Butter::RenderCommand::SetClearColor({ 0.0f, 0.0f, 1.0f, 1 });
		Butter::RenderCommand::Clear();

		tex->Bind();
		shader_fullscreenTri->Bind();
		Butter::RenderCommand::DrawTriangle();

	}

}

void GraphicsLayer::OnEvent(Butter::Event & e)
{
	Butter::EventDispatcher dispatcher(e);
	
	dispatcher.Dispatch<Butter::KeyPressedEvent>(BTR_BIND_EVENT_FN(GraphicsLayer::OnKeyPressed));
	dispatcher.Dispatch<Butter::MouseMovedEvent>(BTR_BIND_EVENT_FN(GraphicsLayer::OnMouseMoved));

}

bool GraphicsLayer::OnMouseMoved(Butter::MouseMovedEvent & e)
{
	//camera.LookAtVector.x += e.GetDeltaX() * 0.1f;
	//camera.LookAtVector.y += e.GetDeltaY() * 0.1f;

	//BTR_INFO("LookAtVector.X: {0}, LookAtVector.Y: {1}", camera.LookAtVector.x, camera.LookAtVector.y);
	return true;
}

bool GraphicsLayer::OnKeyPressed(Butter::KeyPressedEvent & e)
{


	if (e.GetKeyName()[0] == 'w')
	{
		camera.Position.z += 0.1f;
	}
	else if (e.GetKeyName()[0] == 's')
	{
		camera.Position.z += -0.1f;

	}
	else if (e.GetKeyName()[0] == 'a')
	{
		camera.Position.x += -0.1f;

	}
	else if (e.GetKeyName()[0] == 'd')
	{
		camera.Position.x += 0.1f;

	}


	return false;
}


