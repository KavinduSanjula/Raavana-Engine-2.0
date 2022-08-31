#include "sfml_window.h"

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
		if (e.type == e.Closed) {
			m_NativeWindow->close();
			shouldClose = true;
		}
	}
	m_NativeWindow->display();

}
