#include "Event.h"


WindowClosed::WindowClosed()
{
	m_Type = EventType::WindowClosed;
}

WindowClosed::~WindowClosed()
{}

WindowResized::WindowResized(int width, int height)
	:m_Width(width), m_Height(height)
{
	m_Type = EventType::WindowResized;
}

WindowResized::~WindowResized()
{
}

KeyPressed::KeyPressed(int key)
	:m_Key(key)
{
	m_Type = EventType::KeyPressed;
}

KeyPressed::~KeyPressed()
{}

KeyReleased::KeyReleased(int key)
	:m_Key(key)
{
	m_Type = EventType::KeyReleased;
}

KeyReleased::~KeyReleased()
{}

MouseMoved::MouseMoved(int x, int y)
	:m_Mx(x), m_My(y)
{
	m_Type = EventType::MouseMoved;
}

MouseMoved::~MouseMoved()
{}

MouseButtonPressed::MouseButtonPressed(int button)
	:m_Button(button)
{
	m_Type = EventType::MouseButtonPressed;
}

MouseButtonPressed::~MouseButtonPressed()
{}

MouseButtonReleased::MouseButtonReleased(int button)
	:m_Button(button)
{
	m_Type = EventType::MouseButtonReleased;
}

MouseButtonReleased::~MouseButtonReleased()
{}
