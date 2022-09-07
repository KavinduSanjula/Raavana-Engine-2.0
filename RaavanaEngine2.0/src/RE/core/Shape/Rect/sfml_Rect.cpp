#include "sfml_Rect.h"
#include "RE/Application.h"

namespace RE {

	Rect* Rect::Create(float x, float y, float width, float height) {
		return new sfml_Rect(x, y, width, height);
	}

	sfml_Rect::sfml_Rect(float x, float y, float width, float height)
	{
		m_PosX = x;
		m_PosY = y;

		m_Width = width;
		m_Height = height;

		m_Shape = new sf::RectangleShape(sf::Vector2f(width, height));
		m_Shape->setPosition(x,y);
		m_Shape->setFillColor(sf::Color(255, 255, 0));
		m_Shape->setOutlineColor(sf::Color(0, 255, 0));
	}

	sfml_Rect::~sfml_Rect()
	{
		delete m_Shape;
	}

	void sfml_Rect::Draw() {
		sf::RenderWindow* window = (sf::RenderWindow*)Application::INSTANCE->GetWindow()->GetNativeWindow();
		window->draw(*m_Shape);
	}

}