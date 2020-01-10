#pragma once

// The RenderContext is a class which abstracts renderer API specific commands involving our render context
// For example, each rendering API (i.e. OpenGL, DirectX, etc.) has a different implementation for things like swapping buffers
// But from our code, we want to make a generic call to swap the buffers all the same, regardless of what rendering API has been selected

namespace Butter
{
	class RenderContext
	{

	public:

		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;

		static Scope<RenderContext> Create(void * in_window);
	};
}