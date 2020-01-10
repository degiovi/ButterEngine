#include "btrpch.h"
#include "ButterEngine/Renderer/Renderer.h"


namespace Butter
{
	void Renderer::Init()
	{
		RenderCommand::Init();
	}

	void Renderer::Shutdown()
	{
	}

	void Renderer::BeginScene()
	{
		// Takes in all scene parameters
		// Make sure that the shaders we're using get the right uniforms
		// Uniforms : textures, camera, params

	}

	void Renderer::Submit(const Ref<Shader> & in_shader, const Ref<VertexArray> & in_vertexArray)
	{
		//in_shader->Bind();
		//in_vertexArray->Bind();
		//RenderCommand::DrawIndexed(in_vertexArray);
		// Submit draw calls into a render command queue
		// Draw vertex array
	}

	void Renderer::EndScene()
	{
	}

}