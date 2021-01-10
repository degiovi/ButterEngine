#include "btrpch.h"
#include "ButterEngine/Platform/OpenGL/OpenGLRendererAPI.h"

#include <glad/glad.h>


namespace Butter
{
	void OpenGLMessageCallback(
		unsigned source,
		unsigned type,
		unsigned id,
		unsigned severity,
		int length,
		const char* message,
		const void* userParam)
	{
		switch (severity)
		{
		case GL_DEBUG_SEVERITY_HIGH:         BTR_CORE_CRITICAL(message); return;
		case GL_DEBUG_SEVERITY_MEDIUM:       BTR_CORE_ERROR(message); return;
		case GL_DEBUG_SEVERITY_LOW:          BTR_CORE_WARN(message); return;
		case GL_DEBUG_SEVERITY_NOTIFICATION: BTR_CORE_TRACE(message); return;
		}

		BTR_CORE_ASSERT(false, "Unknown severity level!");
	}


	void OpenGLRendererAPI::Init()
	{

#ifdef BTR_DEBUG
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(OpenGLMessageCallback, nullptr);

		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
#endif

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_DEPTH_TEST);
	}

	void OpenGLRendererAPI::SetViewport(uint32_t in_x, uint32_t in_y, uint32_t in_width, uint32_t in_height)
	{
		glViewport(in_x, in_y, in_width, in_height);
	}

	void OpenGLRendererAPI::SetClearColor(const glm::vec4 & in_color)
	{
		glClearColor(in_color.r, in_color.g, in_color.b, in_color.a);
	}

	void OpenGLRendererAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRendererAPI::DrawIndexed(const Ref<VertexArray> & in_vertexArray)
	{
		glDrawElements(GL_TRIANGLES, in_vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void OpenGLRendererAPI::DrawTriangle()
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void OpenGLRendererAPI::MemBarrier()
	{
		glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
	}
}