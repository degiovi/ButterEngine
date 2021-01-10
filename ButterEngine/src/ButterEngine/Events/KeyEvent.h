#pragma once

#include "Event.h"
#include <map>

namespace Butter
{
	enum class BUTTER_API KeyCode
	{
		Num0, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9,
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Comma, Period, 
		ForwardSlash, BackSlash,
		SemiColon, Colon, Quotation, Apostrophe,
		CurlyLeftBrace, CurlyRightBrace, 
		SquareLeftBracket, SquareRightBracket, 
		LeftAngleBracket, RightAngleBracket,
		LeftShift, LeftCtrl, LeftAlt, LeftWinKey,
		RightShift, RightCtrl, RightAlt, RightWinKey,
		Enter, Backspace, 
		LeftArrow, RightArrow, DownArrow, UpArrow,
		Tab, CapsLock,
		Backtick, Tilde, Exclamation, At, Pound, Dollar, Percent, Carrot, Ampersand, Asterisk, 
		LeftParentheses, RightParentheses,
		Underscore, Hyphen, Plus, Equals,
		Esc, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, PrtScrn, ScrollLock, PauseBreak, NumLock,
		Home, End, Insert, Delete, PageUp, PageDown,
		NumPad0, NumPad1, NumPad2, NumPad3, NumPad4, NumPad5, NumPad6, NumPad7, NumPad8, NumPad9

	};

	static std::map<const char, KeyCode> KeyMap
	{
		{'0', KeyCode::Num0}, {'1', KeyCode::Num1}, {'2', KeyCode::Num2}, {'3', KeyCode::Num3}, {'4', KeyCode::Num4}, {'5', KeyCode::Num5}, {'6', KeyCode::Num6}, {'7', KeyCode::Num7},{'8', KeyCode::Num8}, {'9', KeyCode::Num9},

		{'Q', KeyCode::Q}, {'W', KeyCode::W}, {'E', KeyCode::E}, {'R', KeyCode::R}, {'T', KeyCode::T}, {'Y', KeyCode::Y}, {'U', KeyCode::U}, {'I', KeyCode::I}, {'O', KeyCode::O}, {'U', KeyCode::U}, {'P', KeyCode::P},
		{'A', KeyCode::A}, {'S', KeyCode::S}, {'D', KeyCode::D}, {'F', KeyCode::F}, {'G', KeyCode::G}, {'H', KeyCode::H}, {'J', KeyCode::J}, {'K', KeyCode::K}, {'L', KeyCode::L},
		{'Z', KeyCode::Z}, {'X', KeyCode::X}, {'C', KeyCode::C}, {'V', KeyCode::V}, {'B', KeyCode::B}, {'N', KeyCode::N}, {'M', KeyCode::M},

		{',', KeyCode::Comma}, {'.', KeyCode::Period},
		{'/', KeyCode::ForwardSlash}, {'\\', KeyCode::BackSlash},
		{';', KeyCode::SemiColon}, {':', KeyCode::Colon}, {'"', KeyCode::Quotation}, {'\'', KeyCode::Apostrophe},

		{'{', KeyCode::CurlyLeftBrace},		{'}', KeyCode::CurlyRightBrace},
		{'[', KeyCode::SquareLeftBracket},	{']', KeyCode::SquareRightBracket},
		{'<', KeyCode::LeftAngleBracket},	{'>', KeyCode::RightAngleBracket},

		{'I', KeyCode::LeftShift},	{'I', KeyCode::LeftCtrl},	{'I', KeyCode::LeftAlt},	{'I', KeyCode::LeftWinKey},
		{'I', KeyCode::RightShift}, {'I', KeyCode::RightCtrl},	{'I', KeyCode::RightAlt},	{'I', KeyCode::RightWinKey},

		{'I', KeyCode::Enter}, {'I', KeyCode::Backspace},

		{'I', KeyCode::LeftArrow}, {'I', KeyCode::RightArrow}, {'I', KeyCode::UpArrow}, {'I', KeyCode::DownArrow},

		{'I', KeyCode::Tab}, {'I', KeyCode::CapsLock},

		{'`', KeyCode::Backtick}, {'~', KeyCode::Tilde}, {'!', KeyCode::Exclamation}, {'@', KeyCode::At}, {'#', KeyCode::Pound}, {'$', KeyCode::Dollar}, {'%', KeyCode::Percent},{'^', KeyCode::Carrot}, {'&', KeyCode::Ampersand}, {'*', KeyCode::Asterisk}, 
		{'(', KeyCode::LeftParentheses}, {')', KeyCode::RightParentheses},
		{'_', KeyCode::Underscore}, {'-', KeyCode::Hyphen},{'+', KeyCode::Plus}, {'=', KeyCode::Equals},

		{'F1', KeyCode::F1}, {'F2', KeyCode::F2}, {'F3', KeyCode::F3}, {'F4', KeyCode::F4}, {'F5', KeyCode::F5}, {'F6', KeyCode::F6}, {'F7', KeyCode::F7}, {'F8', KeyCode::F8}, {'F9', KeyCode::F9},{'F10', KeyCode::F10}, {'F11', KeyCode::F11}, {'F12', KeyCode::F12},

		{'I', KeyCode::PrtScrn}, {'I', KeyCode::ScrollLock}, {'I', KeyCode::PauseBreak}, {'I', KeyCode::NumLock}, 
		{'I', KeyCode::Home}, {'I', KeyCode::End}, {'I', KeyCode::Insert}, {'I', KeyCode::Delete}, {'I', KeyCode::PageUp}, {'I', KeyCode::PageDown},
		
		{'I', KeyCode::NumPad0}, {'I', KeyCode::NumPad1}, {'I', KeyCode::NumPad2}, {'I', KeyCode::NumPad3}, {'I', KeyCode::NumPad4}, {'I', KeyCode::NumPad5}, {'I', KeyCode::NumPad6}, {'I', KeyCode::NumPad7}, {'I', KeyCode::NumPad8}, {'I', KeyCode::NumPad9},



	};


	class BUTTER_API KeyEvent : public Event
	{

		// This is a base for all KeyEvents (KeyPressedEvent, KeyReleasedEvent)
		// All KeyEvents share a KeyCode

	public:

		inline int GetKeyCode() const { return keyCode; }
		inline const char* GetKeyName() { return keyName; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:

		// Protected (only to be usable by itself and child classes
		// because nothing should be able to construct a KeyEvent itself - it is only derived from

		KeyEvent(int in_keyCode, const char * in_keyName) 
			: keyCode(in_keyCode), keyName(in_keyName) {};

		int keyCode;
		const char * keyName;

	};


	class BUTTER_API KeyPressedEvent : public KeyEvent
	{

	public:

		KeyPressedEvent(int in_keyCode, int in_repeatCount, const char * in_keyName)
			: KeyEvent(in_keyCode, in_keyName), repeatCount(in_repeatCount) {}

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
			
		KeyReleasedEvent(int in_keyCode, const char * in_keyName)
			: KeyEvent(in_keyCode, in_keyName) {}

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

		KeyTypedEvent(int in_keyCode, const char * in_keyName)
			: KeyEvent(in_keyCode, in_keyName) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)

	};

}