#pragma once
#include "ButterEngine/Core.h"
#include "ButterEngine/Layer.h"

#include "ButterEngine/Events/Event.h"
#include "ButterEngine/Events/ApplicationEvent.h"
#include "ButterEngine/Events/KeyEvent.h"
#include "ButterEngine/Events/MouseEvent.h"

namespace Butter
{
	class BUTTER_API ImGuiLayer : public Layer
	{
	public:

		ImGuiLayer();
		~ImGuiLayer() = default;

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event & in_event);
	private:
		// Implement our input events to IMGUI
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent & e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent & e);
		bool OnMouseMovedEvent(MouseMovedEvent & e);
		bool OnMouseScrolledEvent(MouseScrolledEvent & e);
		bool OnKeyPressedEvent(KeyPressedEvent & e);
		bool OnKeyReleasedEvent(KeyReleasedEvent & e);
		bool OnKeyTypedEvent(KeyTypedEvent & e);
		bool OnWindowResizeEvent(WindowResizeEvent & e);
	
	private:
	
		float time;

	};
}