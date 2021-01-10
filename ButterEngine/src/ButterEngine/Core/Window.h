#pragma once

#include "btrpch.h"

#include "ButterEngine/Core/Core.h"
#include "ButterEngine/Events/Event.h"

namespace Butter
{
	
	struct WindowProperties
	{
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProperties(const std::string& in_title = "Butter Engine",
			unsigned int in_width = 1024,
			unsigned int in_height = 1024)
			: title(in_title), width(in_width), height(in_height) {}

	};

	class BUTTER_API Window
	{

	public:

		// Interface representing a desktop system based Window (platform independent)
		// Purely virtual interface that needs to be implemented per platform

		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;
		
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void * GetNativeWindow() const = 0;

		static Scope<Window> Create(const WindowProperties& properties = WindowProperties());

	};
	
}