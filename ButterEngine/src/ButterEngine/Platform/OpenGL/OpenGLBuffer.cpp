#pragma once
#include "btrpch.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace Butter
{

	// --------------------------------------------------------- //
	// VERTEX BUFFER
	// --------------------------------------------------------- //

	OpenGLVertexBuffer::OpenGLVertexBuffer(float * in_vertices, uint32_t in_size)
	{
		glCreateBuffers(1, &rendererID);
		glBindBuffer(GL_ARRAY_BUFFER, rendererID);
		glBufferData(GL_ARRAY_BUFFER, in_size, in_vertices, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &rendererID);
	}

	void OpenGLVertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, rendererID);
	}

	void OpenGLVertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	// -------------------------------------------------------- //
	// INDEX BUFFER
	// -------------------------------------------------------- //

	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t * in_indices, uint32_t in_count)
		: count(count)
	{
		glCreateBuffers(1, &rendererID);
		glBindBuffer(GL_ARRAY_BUFFER, rendererID);
		glBufferData(GL_ARRAY_BUFFER, in_count * sizeof(uint32_t), in_indices, GL_STATIC_DRAW);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &rendererID);
	}

	void OpenGLIndexBuffer::Bind() const 
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID);
	}

	void OpenGLIndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}



}