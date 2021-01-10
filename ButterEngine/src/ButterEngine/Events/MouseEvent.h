#pragma once

#include "Event.h"

namespace Butter
{

	class BUTTER_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float in_x, float in_y, float in_deltaX, float in_deltaY)
			: x(in_x), y(in_y), deltaX(in_deltaX), deltaY(in_deltaY) {}

		inline float GetX() const { return x; }
		inline float GetY() const { return y; }
		inline float GetDeltaX() const { return deltaX; }
		inline float GetDeltaY() const { return deltaY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << x << ", " << y;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float x, y;
		float deltaX, deltaY;

	};


	class BUTTER_API MouseScrolledEvent : public Event
	{
	public:

		MouseScrolledEvent(float in_xOffset, float in_yOffset)
			: xOffset(in_xOffset), yOffset(in_yOffset) {}


		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << xOffset << ", " << yOffset;
			return ss.str();
		}

		inline const float GetXOffset() { return xOffset; }
		inline const float GetYOffset() { return yOffset; }

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:

		float xOffset, yOffset;
	};




	class BUTTER_API MouseButtonEvent : public Event
	{

	public:

		inline int GetMouseButton() const { return button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:

		MouseButtonEvent(int in_button)
			: button(in_button) {}

		int button;

	};


	class BUTTER_API MouseButtonPressedEvent : public MouseButtonEvent
	{

	public:
			
		MouseButtonPressedEvent(int in_button)
			: MouseButtonEvent(in_button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)

	};


	class BUTTER_API MouseButtonReleasedEvent : public MouseButtonEvent
	{

	public:

		MouseButtonReleasedEvent(int in_button)
			: MouseButtonEvent(in_button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};



}