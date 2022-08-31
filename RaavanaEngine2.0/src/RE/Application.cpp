#include "Application.h"

Application::Application(const std::string title, uint32_t width, uint32_t height)
	:m_Title(title), m_Width(width), m_Height(height)
{
	m_Window = Window::Create(title, width, height);
}

void Application::Run()
{
	while (!m_Window->ShouldClose()) {
		Loop();
		m_Window->Update();
	}
}

void Application::Loop()
{
}
