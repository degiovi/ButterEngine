#include "btrpch.h"
#include "ButterEngine/Renderer/RenderCommand.h"

namespace Butter
{
	Scope<RendererAPI> RenderCommand::rendererAPI = RendererAPI::Create();
}