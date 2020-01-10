#include "btrpch.h"
#include "WindowsWindow.h"

#include "ButterEngine/Events/ApplicationEvent.h"
#include "ButterEngine/Events/KeyEvent.h"
#include "ButterEngine/Events/MouseEvent.h"

#include "ButterEngine/Platform/OpenGL/OpenGLContext.h"
//#include <glad/glad.h>

namespace Butter
{
	
	static bool bGLFWInitialized = false;						// Static because we only want to initialize GLFW once (despite having multiple windows)

	static void GLFWErrorCallback(int error, const char* description)
	{
		BTR_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	Scope<Window> Window::Create(const WindowProperties& properties)
	{
		return CreateScope<WindowsWindow>(properties);
	}


	WindowsWindow::WindowsWindow(const WindowProperties& properties)
	{
		Init(properties);
	}


	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}


	void WindowsWindow::Init(const WindowProperties& properties)
	{
		data.title = properties.title;
		data.width = properties.width;
		data.height = properties.height;

		BTR_CORE_INFO("Creating window {0} ({1}, {2})", properties.title, properties.width, properties.height);

		if (!bGLFWInitialized)
		{
			// glfwTerminate on system shutdown

			int success = glfwInit();
			BTR_CORE_ASSERT(success, "Could not initialize GLFW!");

			bGLFWInitialized = true;
		}

		window = glfwCreateWindow((int)properties.width, (int)properties.height, data.title.c_str(), nullptr, nullptr);
		
		renderContext = RenderContext::Create(window);
		renderContext->Init();
		// ^----
		//glfwMakeContextCurrent(window);
		//int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		//BTR_CORE_ASSERT(status, "Failed to initialize Glad!");

		glfwSetWindowUserPointer(window, &data);

		SetVSync(true);

		// Set GLFW callbacks

		// WINDOW RESIZE
		glfwSetWindowSizeCallback(window, [](GLFWwindow * in_window, int in_width, int in_height)
		{
			// Returns a void pointer (We set the user pointer to be WindowData struct)
			// Dereference and cast to WindowData *
			WindowData & data = *(WindowData*)glfwGetWindowUserPointer(in_window);

			// Construct a window resize event
			WindowResizeEvent event(in_width, in_height);

			// Dispatch the event
			data.eventCallback(event);

			// Update width and height
			data.width = in_width;
			data.height = in_height;
		});


		// WINDOW CLOSE
		glfwSetWindowCloseCallback(window, [](GLFWwindow * inWindow)
		{
			WindowData & data = *(WindowData*)glfwGetWindowUserPointer(inWindow);
			WindowCloseEvent event;
			data.eventCallback(event);
		});

		// KEY CALLBACK
		glfwSetKeyCallback(window, [](GLFWwindow * in_window, int in_key, int in_scanCode, int in_action, int in_mods)
		{
			WindowData & data = *(WindowData*)glfwGetWindowUserPointer(in_window);

			switch (in_action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(in_key, 0);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(in_key);
					data.eventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(in_key, 1);
					data.eventCallback(event);
					break;
				}
				default:
					break;
			}
		});

		// MOUSE BUTTON CALLBACK
		glfwSetMouseButtonCallback(window, [](GLFWwindow * in_window, int in_button, int in_action, int in_mods)
		{
			WindowData & data = *(WindowData*)glfwGetWindowUserPointer(in_window);

			switch (in_action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(in_button);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(in_button);
					data.eventCallback(event);
					break;
				}
				default:
					break;
			}
		
		});

		glfwSetScrollCallback(window, [](GLFWwindow * in_window, double in_xOffset, double in_yOffset)
		{
			WindowData & data = *(WindowData*)glfwGetWindowUserPointer(in_window);

			MouseScrolledEvent event((float)in_xOffset, (float)in_yOffset);
			data.eventCallback(event);
		});

		glfwSetCursorPosCallback(window, [](GLFWwindow * in_window, double in_xPos, double in_yPos)
		{
			WindowData & data = *(WindowData*)glfwGetWindowUserPointer(in_window);

			MouseMovedEvent event((float)in_xPos, (float)in_yPos);
			data.eventCallback(event);
		});
	}


	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(window);							// Don't want to terminate GLFW because there may be (likely) more than one window
	}


	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		renderContext->SwapBuffers();
		// ^--
		//glfwSwapBuffers(window);
	}


	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		data.vSync = enabled;
	}
	

	bool WindowsWindow::IsVSync() const
	{
		return data.vSync;
	}
}