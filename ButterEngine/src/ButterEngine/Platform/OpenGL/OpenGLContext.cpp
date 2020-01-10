#include "btrpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Butter
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: windowHandle(windowHandle)
	{
		BTR_CORE_ASSERT(windowHandle, "Window handle for OpenGLContext is null.");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(windowHandle);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		BTR_CORE_ASSERT(status, "Failed to initialize Glad!");


		BTR_CORE_INFO("OpenGL Info:");
		BTR_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		BTR_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		BTR_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(windowHandle);
	}
}