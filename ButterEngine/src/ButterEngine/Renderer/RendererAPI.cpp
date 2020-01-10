#include "btrpch.h"
#include "ButterEngine/Renderer/RendererAPI.h"

#include "ButterEngine/Platform/OpenGL/OpenGLRendererAPI.h"

namespace Butter
{
	RendererAPI::API RendererAPI::api = RendererAPI::API::OpenGL;

	Scope<RendererAPI> RendererAPI::Create()
	{
		switch (api)
		{
		case RendererAPI::API::None:	BTR_CORE_ASSERT(false, "Invalid renderer API: None"); return nullptr;
		case RendererAPI::API::OpenGL:	return CreateScope<OpenGLRendererAPI>();
		}

		BTR_CORE_ASSERT(false, "Unknown RendererAPI.");
		return nullptr;
		
	}
}
