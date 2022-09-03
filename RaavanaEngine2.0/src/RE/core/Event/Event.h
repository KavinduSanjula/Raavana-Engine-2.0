#pragma once

#include "RE/core.h"

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

	inline int GetKey() const { return m_Key; }

private:
	int m_Key;
};

class KeyReleased : public Event {
public:
	KeyReleased(int key);
	~KeyReleased();

	inline int GetKey() { return m_Key; }

private:
	int m_Key;

};

////////////////////////////////////////////////////////////////

/////////////////////Mouse Event////////////////////////////////

class MouseMoved : public Event {
public:
	MouseMoved(int x, int y);
	~MouseMoved();

	inline int GetMouseX() { return m_Mx; }
	inline int GetMouseY() { return m_My; }

private:
	int m_Mx, m_My;
};

class MouseButtonPressed : public Event {
public:
	MouseButtonPressed(int button);
	~MouseButtonPressed();

	inline int GetButton() { return m_Button; }

private:
	int m_Button;
};

class MouseButtonReleased : public Event {
public:
	MouseButtonReleased(int button);
	~MouseButtonReleased();

	inline int GetButton() { return m_Button; }

private:
	int m_Button;
};

///////////////////////////////////////////////////////////////