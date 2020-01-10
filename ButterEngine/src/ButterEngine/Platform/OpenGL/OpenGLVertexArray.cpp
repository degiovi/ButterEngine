#include "btrpch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace Butter
{
	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Float: return GL_FLOAT;
		case ShaderDataType::Float2: return GL_FLOAT;
		case ShaderDataType::Float3: return GL_FLOAT;
		case ShaderDataType::Float4: return GL_FLOAT;
		case ShaderDataType::Mat3: return GL_FLOAT;
		case ShaderDataType::Mat4: return GL_FLOAT;
		case ShaderDataType::Int: return GL_INT;
		case ShaderDataType::Int2: return GL_INT;
		case ShaderDataType::Int3: return GL_INT;
		case ShaderDataType::Int4: return GL_INT;
		case ShaderDataType::Bool: return GL_BOOL;
		}

		BTR_CORE_ASSERT(false, "Unknown ShaderDataType.");
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &rendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &rendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(rendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer> & in_vertexBuffer)
	{
		BTR_CORE_ASSERT(in_vertexBuffer->GetLayout().GetElements().size(), "Vertex buffer has no layout.");

		glBindVertexArray(rendererID);
		in_vertexBuffer->Bind();

		const auto& layout = in_vertexBuffer->GetLayout();

		for (const auto & element : layout)
		{
			glEnableVertexAttribArray(vertexBufferIndex);
			glVertexAttribPointer(vertexBufferIndex, 
				element.GetComponentCount(), 
				ShaderDataTypeToOpenGLBaseType(element.type),
				element.normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(), 
				(const void*)element.offset);

			vertexBufferIndex++;
		}

		vertexBuffers.push_back(in_vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer> & in_indexBuffer)
	{
		glBindVertexArray(rendererID);
		in_indexBuffer->Bind();

		indexBuffer = in_indexBuffer;
	}


}