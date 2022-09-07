#pragma once

#include "Rect.h"

#include <SFML/Graphics.hpp>

namespace RE {

	class sfml_Rect : public Rect {

	public:
		sfml_Rect(float x, float y, float width, float height);
		~sfml_Rect();

		void Draw() override;

	private:
		sf::RectangleShape* m_Shape;

	};

}