#include "sfml_window.h"

#include "RE/Application.h"
#include "RE/core/Event/Event.h"

Window* Window::Create(const std::string title, uint32_t width, uint32_t height) {
	return new sfml_Window(title, width, height);
}

sfml_Window::sfml_Window(const std::string title, uint32_t width, uint32_t height)
	:m_Title(title), m_Width(width), m_Height(height)
{
	m_NativeWindow = new sf::RenderWindow(sf::VideoMode(m_Width, m_Height), m_Title);
}

sfml_Window::~sfml_Window()
{
	delete m_NativeWindow;
}

void sfml_Window::Update()
{
	m_NativeWindow->clear(sf::Color(20, 20, 20));
	sf::Event e;
	while (m_NativeWindow->pollEvent(e)) {

		Event* currunt_event = nullptr;

		switch (e.type) {

		case sf::Event::Closed: { 
			currunt_event = new WindowClosed(); 
			m_NativeWindow->close(); 
			break; 
		}
		case sf::Event::Resized: {
			int width = e.size.width;
			int height = e.size.height;
			currunt_event = new WindowResized(width, height);
			break;
		}
		case sf::Event::KeyPressed: {
			currunt_event = new KeyPressed(e.key.code);
			break;
		}
		case sf::Event::KeyReleased: {
			currunt_event = new KeyReleased(e.key.code);
			break;
		}
		case sf::Event::MouseMoved: {
			currunt_event = new MouseMoved(e.mouseMove.x, e.mouseMove.y);
			break;
		}
		case sf::Event::MouseButtonPressed: {
			currunt_event = new MouseButtonPressed(e.mouseButton.button, e.mouseButton.x, e.mouseButton.y);
			break;
		}
		case sf::Event::MouseButtonReleased: {
			currunt_event = new MouseButtonReleased(e.mouseButton.button, e.mouseButton.x, e.mouseButton.y);
			break;
		}
		default: break;
		}

		if (currunt_event) {
			Application::INSTANCE->OnEvent(currunt_event);
		}

	}
	m_NativeWindow->display();

}
