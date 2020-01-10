#pragma once

#include "Event.h"

namespace Butter
{
	class BUTTER_API KeyEvent : public Event
	{

		// This is a base for all KeyEvents (KeyPressedEvent, KeyReleasedEvent)
		// All KeyEvents share a KeyCode

	public:

		inline int GetKeyCode() const { return keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:

		// Protected (only to be usable by itself and child classes
		// because nothing should be able to construct a KeyEvent itself - it is only derived from

		KeyEvent(int in_keyCode) 
			: keyCode(in_keyCode) {};

		int keyCode;

	};


	class BUTTER_API KeyPressedEvent : public KeyEvent
	{

	public:

		KeyPressedEvent(int in_keyCode, int in_repeatCount)
			: KeyEvent(in_keyCode), repeatCount(in_repeatCount) {}

		inline int GetRepeatCount() const { return repeatCount; }
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << keyCode << " (" << repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		
		int repeatCount;
	
	};


	class BUTTER_API KeyReleasedEvent : public KeyEvent
	{

	public: 
			
		KeyReleasedEvent(int in_keyCode)
			: KeyEvent(in_keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)

	};


	class BUTTER_API KeyTypedEvent : public KeyEvent
	{

	public:

		KeyTypedEvent(int in_keyCode)
			: KeyEvent(in_keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)

	};

}