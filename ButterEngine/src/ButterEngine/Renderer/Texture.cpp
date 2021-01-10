#include "btrpch.h"
#include "Texture.h"

#include "ButterEngine/Renderer/Renderer.h"
#include "ButterEngine/Platform/OpenGL/OpenGLTexture2D.h"

namespace Butter
{
	Ref<Texture2D> Texture2D::Create(uint32_t in_width, uint32_t in_height)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:	BTR_CORE_ASSERT(false, "Renderer API: 'None' is not currently supported.");
			case RendererAPI::API::OpenGL:	return CreateRef<OpenGLTexture2D>(in_width, in_height);
		}

		BTR_CORE_ASSERT(false, "Unknown RendererAPI.");
		return nullptr;
	}

	Ref<Texture2D> Texture2D::Create(std::string & in_filePath)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:	BTR_CORE_ASSERT(false, "Renderer API: 'None' is not currently supported.");
			case RendererAPI::API::OpenGL:	return CreateRef<OpenGLTexture2D>(in_filePath);
		}

		BTR_CORE_ASSERT(false, "Unknown RendererAPI.");
		return nullptr;
	}
}