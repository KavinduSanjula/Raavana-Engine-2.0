#include "RE_Vector2.h"

namespace RE_MATH {
	
	Vector2::Vector2() :x(0.0f), y(0.0f) {}


	Vector2::Vector2(float _x, float _y) :x(_x), y(_y) {}

	float Vector2::Magnitude() const
	{
		return (float)sqrt(x * x + y * y);
	}

	Vector2 Vector2::Normalized() const
	{
		float mag = Magnitude();
		return Vector2(x / mag, y / mag);
	}

	Vector2 Vector2::Zero()
	{
		return Vector2(0, 0);
	}

	Vector2 Vector2::One()
	{
		return Vector2(1, 1);
	}

}