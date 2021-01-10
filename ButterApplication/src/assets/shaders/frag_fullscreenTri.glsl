#version 410 core

in vec2 UV;
layout (location = 0) out vec4 outColor;

uniform vec4 inColor;
uniform sampler2D tex;

void main()
{
	outColor = texture2D(tex, UV);
	//outColor = inColor;
}