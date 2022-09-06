#pragma once

#include "RE/core.h"

#include <iostream>

namespace RE_MATH {

	class RE_API Vector2 {

	public:
		float x;
		float y;

	public:
		Vector2();
		Vector2(float x, float y);
		~Vector2() {}

		float Magnitude() const;
		Vector2 Normalized() const;

	public:
		static Vector2 Zero();
		static Vector2 One();

	};

	/////////////////////////// Operators //////////////////////////


	Vector2 operator+(Vector2& lhs, Vector2& rhs) {
		return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
	}

	Vector2 operator-(Vector2& lhs, Vector2& rhs) {
		return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
	}

	Vector2& operator+=(Vector2& lhs, Vector2& rhs) {
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		return lhs;
	}

	Vector2& operator-=(Vector2& lhs, Vector2& rhs) {
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		return lhs;
	}


	Vector2 operator+(Vector2& vec, float val) {
		return Vector2(vec.x + val, vec.y + val);
	}

	Vector2 operator-(Vector2& vec, float val) {
		return Vector2(vec.x - val, vec.y - val);
	}

	Vector2 operator*(Vector2& vec, float val) {
		return Vector2(vec.x * val, vec.y * val);
	}

	Vector2 operator/(Vector2& vec, float val) {
		if (val == 0) return vec;
		return Vector2(vec.x / val, vec.y / val);
	}


	bool operator==(Vector2 lhs, Vector2 rhs) {
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}

	bool operator!=(Vector2 lhs, Vector2 rhs) {
		return !(lhs == rhs);
	}

}

std::ostream& operator<< (std::ostream& stream, RE_MATH::Vector2 vec) {
	stream << "(" << vec.x << ", " << vec.y << ")";
	return stream;
}