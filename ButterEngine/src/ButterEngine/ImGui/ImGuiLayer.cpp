#include "btrpch.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "ButterEngine/Platform/OpenGL/ImGuiOpenGLRenderer.h"

#include "ButterEngine/Application.h"

// TEMPORARY
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Butter
{
	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer")
	{
	}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO & io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		// Keymaps should eventually use Butter key codes
		io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_KeyPadEnter] = GLFW_KEY_KP_ENTER;
		io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
		io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
		io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
		io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
		io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

		ImGui_ImplOpenGL3_Init("#version 410");

	}

	void ImGuiLayer::OnUpdate()
	{


		ImGuiIO & io = ImGui::GetIO();

		Application & app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());
		
		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		// Time update
		float currTime = (float)glfwGetTime();

		io.DeltaTime = time > 0.0f ? (currTime - time) : (1.0f / 60.0f);
		time = currTime;

		static bool showDemoWindow = true;
		ImGui::ShowDemoWindow(&showDemoWindow);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());




	}

	void ImGuiLayer::OnEvent(Event & event)
	{
		// Check the event type when it comes into the layer
		// Forward it into our event

		// Create a dispatcher with the event
		EventDispatcher dispatcher(event);

		// If this event matches the event type we are trying to dispatch, it will call the function specified here ()
		dispatcher.Dispatch<MouseButtonPressedEvent>(BTR_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(BTR_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
		dispatcher.Dispatch<MouseMovedEvent>(BTR_BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
		dispatcher.Dispatch<MouseScrolledEvent>(BTR_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
		dispatcher.Dispatch<KeyPressedEvent>(BTR_BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
		dispatcher.Dispatch<KeyReleasedEvent>(BTR_BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
		dispatcher.Dispatch<KeyTypedEvent>(BTR_BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));
		dispatcher.Dispatch<WindowResizeEvent>(BTR_BIND_EVENT_FN(ImGuiLayer::OnWindowResizeEvent));

	}

	bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent & e)
	{
		ImGuiIO & io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = true;

		BTR_TRACE("Mouse Button Pressed");

		return false;
	}

	bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent & e)
	{
		ImGuiIO & io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = false;

		BTR_TRACE("Mouse Button Released");
		return false;
	}

	bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent & e)
	{
		ImGuiIO & io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetX(), e.GetY());

		return false;
	}

	bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent & e)
	{

		ImGuiIO & io = ImGui::GetIO();
		io.MouseWheelH += e.GetXOffset();
		io.MouseWheel += e.GetYOffset();

		return false;
	}

	bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent & e)
	{
		ImGuiIO & io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = true;

		io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL || GLFW_KEY_RIGHT_CONTROL];
		io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT || GLFW_KEY_RIGHT_SHIFT];
		io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT || GLFW_KEY_RIGHT_ALT];
		io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER || GLFW_KEY_RIGHT_SUPER];

		return false;
	}

	bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent & e)
	{
		ImGuiIO & io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = false;

		return false;
	}

	bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent & e)
	{
		//if (c > 0 && c < 0x10000)
		//	io.AddInputCharacter((unsigned short)c);

		return false;
	}

	bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent & e)
	{
		ImGuiIO & io = ImGui::GetIO();

		io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);

		// Make sure it renders to the new screen area after the resize happens
		glViewport(0, 0, e.GetWidth(), e.GetHeight());

		return false;
	}


	void ImGuiLayer::OnDetach()
	{

	}

}