#pragma once

//
//		Event class
// 
// This is the main event system for Raavana Engine 2.0
// 
// Every event is a class derrived from Event class.
//

#include "RE/core.h"

#include <tuple>

namespace RE {

	// main event types
	enum class EventType
	{
		None = 0,
		KeyPressed, KeyReleased,
		MouseMoved, MouseButtonPressed, MouseButtonReleased,
		WindowClosed, WindowResized
	};

	class RE_API Event {

	public:
		virtual ~Event() {}
		EventType GetType() const { return m_Type; }

	protected:
		EventType m_Type;

	};

	////////////////////////Window Event/////////////////////////////

	class WindowClosed : public Event {
	public:
		WindowClosed();
		~WindowClosed();

	};

	class WindowResized : public Event {
	public:
		WindowResized(int width, int height);
		~WindowResized();

		inline std::tuple<int, int> GetSize() const { return { m_Width,m_Height }; }
		inline int GetWidth() const { return m_Width; }
		inline int GetHeight() const { return m_Height; }

	private:
		int m_Width, m_Height;

	};

	/////////////////////////////////////////////////////////////////


	////////////////////////Keyboard Event///////////////////////////

	class KeyPressed : public Event {
	public:
		KeyPressed(int key);
		~KeyPressed();

		inline KEY GetKey() const { return m_Key; }

	private:
		KEY m_Key;
	};

	class KeyReleased : public Event {
	public:
		KeyReleased(int key);
		~KeyReleased();

		inline KEY GetKey() { return m_Key; }

	private:
		KEY m_Key;

	};

	////////////////////////////////////////////////////////////////

	/////////////////////Mouse Event////////////////////////////////

	class MouseMoved : public Event {
	public:
		MouseMoved(int x, int y);
		~MouseMoved();

		inline std::tuple<int, int> GetMousePosition() const { return { m_Mx,m_My }; }
		inline int GetMouseX() { return m_Mx; }
		inline int GetMouseY() { return m_My; }

	private:
		int m_Mx, m_My;
	};

	class MouseButtonPressed : public Event {
	public:
		MouseButtonPressed(int button, int x, int y);
		~MouseButtonPressed();

		inline std::tuple<int, int> GetMousePosition() const { return { m_Mx,m_My }; }
		inline BUTTON GetButton() { return m_Button; }

	private:
		BUTTON m_Button;
		int m_Mx, m_My;
	};

	class MouseButtonReleased : public Event {
	public:
		MouseButtonReleased(int button, int x, int y);
		~MouseButtonReleased();

		inline std::tuple<int, int> GetMousePosition() const { return { m_Mx,m_My }; }
		inline BUTTON GetButton() { return m_Button; }

	private:
		BUTTON m_Button;
		int m_Mx, m_My;
	};

	///////////////////////////////////////////////////////////////

}