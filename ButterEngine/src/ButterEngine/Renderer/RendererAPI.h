#pragma once

#include <glm/glm.hpp>

#include "ButterEngine/Renderer/VertexArray.h"

namespace Butter
{
	class RendererAPI
	{

	public:

		enum class API
		{
			None = 0, OpenGL = 1
		};

	public:

		virtual void Init() = 0;
		virtual void SetViewport(uint32_t in_x, uint32_t in_y, uint32_t in_width, uint32_t in_height) = 0;
		virtual void SetClearColor(const glm::vec4& in_color) = 0;
		virtual void Clear() = 0;

		virtual void DrawIndexed(const Ref<VertexArray> & in_vertexArray) = 0;
		virtual void DrawTriangle() = 0;

		virtual void MemBarrier() = 0;

		inline static API GetAPI() { return api; }
		static Scope<RendererAPI> Create();

	private:
		
		static API api;

	};
}