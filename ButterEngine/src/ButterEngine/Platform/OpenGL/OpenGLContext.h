#pragma once

#include "ButterEngine/Renderer/RenderContext.h"

struct GLFWwindow;

namespace Butter
{
	class OpenGLContext : public RenderContext
	{
	public:

		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* windowHandle;

	};
}