#pragma once

#include "ButterEngine/Core/Core.h"
#include "ButterEngine/Core/Window.h"
#include "ButterEngine/Core/LayerStack.h"

#include "ButterEngine/Events/Event.h"
#include "ButterEngine/Events/ApplicationEvent.h"

#include "ButterEngine/ImGui/ImGuiLayer.h"

namespace Butter
{

	class BUTTER_API Application
	{

	public:

		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event & e);

		void PushLayer(Layer * layer);
		void PushOverlay(Layer * overlay);

		inline Window & GetWindow() { return *window; }

		inline static Application & Get() { return *instance; }

	private:

		bool OnWindowClose(WindowCloseEvent & e);

	private:

		Scope<Window> window;

		bool bRunning = true;

		LayerStack layerStack;
	private:
		static Application * instance;

	};

	Application * CreateApplication();

}