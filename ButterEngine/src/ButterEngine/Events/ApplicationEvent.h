#pragma once

#include "Event.h"

namespace Butter
{
	class BUTTER_API WindowResizeEvent : public Event
	{
	public:
		
		WindowResizeEvent(unsigned int in_width, unsigned int in_height)
			: width(in_width), height(in_height) {}

		inline unsigned int GetWidth() const { return width; }
		inline unsigned int GetHeight() const { return height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << width << ", " << height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int width, height;
	};


	class BUTTER_API WindowCloseEvent : public Event
	{

	public:

		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};

	class BUTTER_API AppTickEvent : public Event
	{

	public:

		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};


	class BUTTER_API AppUpdateEvent : public Event
	{

	public:

		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};


	class BUTTER_API AppRenderEvent : public Event
	{

	public:

		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};
}