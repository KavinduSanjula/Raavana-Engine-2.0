#pragma once

#include "RE/Window.h"

#include <SFML/Graphics.hpp>

class sfml_Window : public Window {

public:
	sfml_Window(const std::string title, uint32_t width, uint32_t height);
	~sfml_Window();

	void Update() override;

private:
	std::string m_Title;
	uint32_t m_Width, m_Height;

	sf::RenderWindow* m_NativeWindow;

};