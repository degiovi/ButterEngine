#include "btrpch.h"
#include "RenderContext.h"

#include "ButterEngine/Renderer/Renderer.h"
#include "ButterEngine/Platform/OpenGL/OpenGLContext.h"

namespace Butter
{
	Scope<RenderContext> RenderContext::Create(void* in_window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: BTR_CORE_ASSERT(false, "Invalid Renderer API: None.");
		case RendererAPI::API::OpenGL: return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(in_window));
		}

		BTR_CORE_ASSERT(false, "Unknown Renderer API.");
		return nullptr;
	}

}