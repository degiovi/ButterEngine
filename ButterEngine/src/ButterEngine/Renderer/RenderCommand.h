#pragma once

#include "ButterEngine/Renderer/RendererAPI.h"

// A RenderCommand is executed dependent on the current rendering API
// A RenderCommand is more of a utility, single purpose
// The Renderer issues RenderCommands and determines how they are used

namespace Butter
{
	class RenderCommand
	{
	public:

		inline static void Init()
		{
			rendererAPI->Init();
		}

		inline static void SetViewport(uint32_t in_x, uint32_t in_y, uint32_t in_width, uint32_t in_height)
		{
			rendererAPI->SetViewport(in_x, in_y, in_width, in_height);
		}

		inline static void SetClearColor(const glm::vec4& color) 
		{ 
			rendererAPI->SetClearColor(color); 
		}

		inline static void Clear() 
		{ 
			rendererAPI->Clear();
		}

		inline static void DrawIndexed(const Ref<VertexArray> & in_vertexArray)
		{
			rendererAPI->DrawIndexed(in_vertexArray);
		}

		inline static void DrawTriangle()
		{
			rendererAPI->DrawTriangle();
		}

		inline static void MemBarrier()
		{
			rendererAPI->MemBarrier();
		}

	private:
		static Scope<RendererAPI> rendererAPI;
	};
}