#include "Application.h"

#include "RE/Logger/Log.h"

namespace RE {

	Application* Application::INSTANCE = nullptr;

	Application::Application(const std::string title, uint32_t width, uint32_t height)
		:m_Title(title), m_Width(width), m_Height(height)
	{
		m_Window = Window::Create(title, width, height);
		Log::INSTANCE = new Log;
	}

	Application::~Application() {
		delete Log::INSTANCE;
	}

	void Application::OnEvent(Event* e) const
	{
		// OnEvent method dispatch the occured event to the proper callback method

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
		// Run() method runs the application instance and runs the main loop

		m_Running = true;

		while (m_Running) {
			Loop();
			m_Window->Update(); // update the window 
		}
	}

	void Application::Start()
	{
	}

	void Application::Loop()
	{
	}

	// this event fires when sfml window closed
	void Application::OnWindowClosed(WindowClosed* e) const {
		m_Running = false;
	}

}
