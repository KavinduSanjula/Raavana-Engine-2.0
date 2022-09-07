#pragma once

#include "../Shape.h"

namespace RE {

	class RE_API Rect : public Shape {

	public:
		~Rect() {}

		static Rect* Create(float x, float y, float width, float height);

	};

}