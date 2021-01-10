#pragma once

#include "btrpch.h"
#include "ButterEngine/Core/Core.h"


namespace Butter
{
	// ENUMS 

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};


	// MACROS

	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType(){ return EventType::##type; }\
																	virtual EventType GetEventType() const override { return GetStaticType(); }\
																	virtual const char* GetName() const override { return #type; }


	// EVENT BASE CLASS

	class BUTTER_API Event
	{
		friend class EventDispatcher;

	public:
		// Const getters (read-only), virtual (to be overridden by children)
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category) { return GetCategoryFlags() & category; }		// Test incoming category against category flags for this Event by bitwise AND operation

		bool isHandled = false;			// If an Event has already been absorbed, so that further layers need not handle it
														
	
	};



	// EVENT DISPATCHER CLASS

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:

		// CONSTRUCTOR

		EventDispatcher(Event& in_event)
			: event(in_event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			// Checks to see what type the current event we're trying to dispatch is
			// Whether or not it matches the template event type (no type safety to make sure it's an event)
			if (event.GetEventType() == T::GetStaticType())
			{
				event.isHandled = func(*(T*)&event);		// Dispatcher dispatches event appropriately and marks as handled/not
				return true;
			}
		}

	private:

		Event& event;
	};


	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}

