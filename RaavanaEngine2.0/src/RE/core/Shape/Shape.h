#pragma once

#include "RE/core.h"

namespace RE {

	class RE_API Shape {
	public:
		~Shape(){}

		virtual void Draw() = 0;

	protected:
		float m_PosX, m_PosY;
		float m_Width, m_Height;
	};

}