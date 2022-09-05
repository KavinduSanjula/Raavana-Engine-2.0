#include "Input.h"

#include <SFML/Graphics.hpp>

bool Input::IsKeyPressed(RE_KEY key) {
	return sf::Keyboard::isKeyPressed((sf::Keyboard::Key)key);
}

std::tuple<int, int> Input::GetMousePosition()
{
	int x = sf::Mouse::getPosition().x;
	int y = sf::Mouse::getPosition().y;
	return { x,y };
}

bool Input::IsMouseButtonPressed(RE_BUTTON button) {
	return sf::Mouse::isButtonPressed((sf::Mouse::Button)button);
}


