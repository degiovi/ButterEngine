#include "btrpch.h"
#include "Application.h"

//#include <glad/glad.h>
#include "ButterEngine/Renderer/Renderer.h"
#include "ButterEngine/Core/DataTypes.h"

namespace Butter
{

	Application * Application::instance = nullptr;
	//EntityManager * Application::entityManager = nullptr;

	Application::Application()
	{
		BTR_CORE_ASSERT(!instance, "Application already exists!");
		instance = this;

		window = Window::Create();
		window->SetEventCallback(BTR_BIND_EVENT_FN(Application::OnEvent));


		Renderer::Init();
		
	}


	Application::~Application()
	{
		Renderer::Shutdown();
	}

	void Application::Run()
	{
		while (bRunning)
		{

			// Iterate through layers and update each
			for (Layer * layer : layerStack)
			{
				layer->BeginFrame();
				layer->OnUpdate();
				layer->EndFrame();
			}

			window->OnUpdate();

		}
	}

	void Application::OnEvent(Event & e)
	{
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowCloseEvent>(BTR_BIND_EVENT_FN(Application::OnWindowClose));

		// Iterate backwards through the layer stack
		for (auto it = layerStack.end(); it != layerStack.begin(); )
		{
			// Call OnEvent() on each layer
			(*--it)->OnEvent(e);

			// If the event has been handled, do not search any more to handle it
			if (e.isHandled)
				break;
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent & e)
	{
		bRunning = false;
		return true;
	}

	void Application::PushLayer(Layer * layer)
	{
		layerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer * overlay)
	{
		layerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

}
