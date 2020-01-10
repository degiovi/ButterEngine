#pragma once
#include "btrpch.h"
#include "ButterEngine/Renderer/Buffer.h"
#include "ButterEngine/Renderer/Renderer.h"
#include "ButterEngine/Platform/OpenGL/OpenGLBuffer.h"

namespace Butter
{
	Ref<VertexBuffer> VertexBuffer::Create(float * in_vertices, uint32_t in_size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: BTR_CORE_ASSERT(false, "Invalid Renderer API: None");
			case RendererAPI::API::OpenGL: return CreateRef<OpenGLVertexBuffer>(in_vertices, in_size);
		}

		BTR_CORE_ASSERT(false, "Unknown RendererAPI.");
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t * in_indices, uint32_t in_size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: BTR_CORE_ASSERT(false, "Invalid Renderer API: None");
			case RendererAPI::API::OpenGL: return CreateRef<OpenGLIndexBuffer>(in_indices, in_size);
		}

		BTR_CORE_ASSERT(false, "Unknown RendererAPI.");
		return nullptr;
	}
}