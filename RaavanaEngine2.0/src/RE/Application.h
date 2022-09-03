#pragma once

#include "core.h"
#include "Window.h"
#include "RE/core/Event/Event.h"

#include <string>

class RE_API Application
{

public:
	Application(const std::string title, uint32_t width, uint32_t height);
	void OnEvent(Event* e) const;
	virtual ~Application() {}

	virtual void Run();
	virtual void Loop();

	//Event callbacks
	virtual void OnWindowClosed(WindowClosed* e) const;
	virtual void OnWindowResized(WindowResized* e) const {}
	virtual void OnKeyPressed(KeyPressed* e) const {}
	virtual void OnKeyReleased(KeyReleased* e) const {}
	virtual void OnMouseMoved(MouseMoved* e) const {}
	virtual void OnMouseButtonPressed(MouseButtonPressed* e) const {}
	virtual void OnMouseButtonReleased(MouseButtonReleased* e) const {}

protected:
	mutable bool m_Running = false;

private:
	std::string m_Title;
	uint32_t m_Width, m_Height;

	Window* m_Window;

public:
	static Application* INSTANCE;

};

