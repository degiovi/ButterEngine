#pragma once

#include "ButterEngine/Renderer/RendererAPI.h"

// OpenGL specific implementations of high level Renderer API concepts.

namespace Butter
{
	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void Init() override;
		virtual void SetViewport(uint32_t in_x, uint32_t in_y, uint32_t in_width, uint32_t in_height) override;

		virtual void SetClearColor(const glm::vec4& in_color) override;
		virtual void Clear() override;

		virtual void DrawIndexed(const Ref<VertexArray> & in_vertexArray) override;
		virtual void DrawTriangle() override;

		virtual void MemBarrier() override;
	};
}