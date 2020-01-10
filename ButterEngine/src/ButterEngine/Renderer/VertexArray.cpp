#include "btrpch.h"
#include "VertexArray.h"

#include "ButterEngine/Renderer/Renderer.h"
#include "ButterEngine/Platform/OpenGL/OpenGLVertexArray.h"


namespace Butter
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:	BTR_CORE_ASSERT(false, "Unknown Renderer API : None.");
			case RendererAPI::API::OpenGL:	return CreateRef<OpenGLVertexArray>();
		}

		BTR_CORE_ASSERT(false, "Unknown Renderer API. Cannot create Vertex Array.");
		return nullptr;
	}
}