#pragma once
#include "ButterEngine/Renderer/RenderCommand.h"
#include "ButterEngine/Renderer/Shader.h"
#include "ButterEngine/Renderer/RendererAPI.h"


namespace Butter
{
	class Renderer
	{
	public:
		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

		static void Init();
		static void Shutdown();

		static void BeginScene();	// Take in scene parameters
		static void EndScene();

		static void Submit(const Ref<Shader> & in_shader, const Ref<VertexArray> & in_vertexArray);


	};
}