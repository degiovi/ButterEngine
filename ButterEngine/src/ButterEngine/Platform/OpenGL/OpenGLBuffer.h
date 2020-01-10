#pragma once

#include "ButterEngine/Renderer/Buffer.h"

namespace Butter
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float * in_vertices, uint32_t in_size);
		virtual ~OpenGLVertexBuffer();
		
		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual const BufferLayout& GetLayout() const { return layout; }
		virtual void SetLayout(const BufferLayout& in_layout) override { layout = in_layout; }
	private:

		uint32_t rendererID;
		BufferLayout layout;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{

	public:
		OpenGLIndexBuffer(uint32_t * in_indices, uint32_t in_count);
		virtual ~OpenGLIndexBuffer();

		virtual void Bind() const;
		virtual void Unbind() const;

		virtual uint32_t GetCount() const { return count; }

	private:

		uint32_t rendererID;
		uint32_t count;

	};

}
