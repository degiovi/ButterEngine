#pragma once
#include "ButterEngine/Core/Core.h"
#include "ButterEngine/Core/Layer.h"

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

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;

		virtual void BeginFrame() override;
		virtual void EndFrame() override;

		virtual void OnEvent(Event & in_event) override {};
	/*
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
	*/
	private:
	
		float time;

	};
}