#pragma once

#include "ButterEngine/Renderer/VertexArray.h"

namespace Butter
{
	class OpenGLVertexArray : public VertexArray
	{
	public:

		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void AddVertexBuffer(const Ref<VertexBuffer>& in_vertexBuffer) override;
		virtual void SetIndexBuffer(const Ref<IndexBuffer>& in_indexBuffer) override;

		virtual const std::vector<Ref<VertexBuffer>> & GetVertexBuffers() const { return vertexBuffers; }
		virtual const Ref<IndexBuffer> & GetIndexBuffer() const { return indexBuffer; }

	private:
		uint32_t rendererID;
		uint32_t vertexBufferIndex = 0;

		std::vector<Ref<VertexBuffer>> vertexBuffers;
		Ref<IndexBuffer> indexBuffer;
	};
}