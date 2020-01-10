#pragma once

#include "ButterEngine/Window.h"
#include "ButterEngine/Renderer/RenderContext.h"

#include <GLFW/glfw3.h>



namespace Butter
{
	
	class WindowsWindow : public Window
	{

	public:
		
		WindowsWindow(const WindowProperties& properties);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return data.width; }
		inline unsigned int GetHeight() const override { return data.height; }

		// Window attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { data.eventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline virtual void * GetNativeWindow() const { return window; }
	private:

		virtual void Init(const WindowProperties& properties);
		virtual void Shutdown();

	private:

		GLFWwindow * window;
		Scope<RenderContext> renderContext;

		struct WindowData
		{
			std::string title;
			unsigned int width, height;
			bool vSync;

			EventCallbackFn eventCallback;
		};

		WindowData data;
	};
	
}