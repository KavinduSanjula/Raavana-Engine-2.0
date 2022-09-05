#include "Application.h"

#include <iostream>

Application* Application::INSTANCE = nullptr;

Application::Application(const std::string title, uint32_t width, uint32_t height)
	:m_Title(title), m_Width(width), m_Height(height)
{
	m_Window = Window::Create(title, width, height);
}

void Application::OnEvent(Event* e) const
{
	switch (e->GetType()) {

		case EventType::WindowClosed: OnWindowClosed((WindowClosed*)e); break;
		case EventType::WindowResized: OnWindowResized((WindowResized*)e); break;
		case EventType::KeyPressed: OnKeyPressed((KeyPressed*)e); break;
		case EventType::KeyReleased: OnKeyReleased((KeyReleased*)e); break;
		case EventType::MouseMoved: OnMouseMoved((MouseMoved*)e); break;
		case EventType::MouseButtonPressed: OnMouseButtonPressed((MouseButtonPressed*)e); break;
		case EventType::MouseButtonReleased: OnMouseButtonReleased((MouseButtonReleased*)e); break;
		default: break;

	}

	delete e;
}

void Application::Run()
{
	m_Running = true;

	while (m_Running) {
		Loop();
		m_Window->Update();
	}
}

void Application::Start()
{
}

void Application::Loop()
{
}

void Application::OnWindowClosed(WindowClosed* e) const {
	m_Running = false;
}
