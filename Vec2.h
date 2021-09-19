#pragma once

#include <math.h>

class Vec2
{
public:
	Vec2(float x, float y);
	~Vec2() {}

public:
	Vec2 GetRotated(double r)
	{
		auto sin_ang = sin(r);
		auto cos_ang = cos(r);

		return Vec2(
			(float)cos_ang * x + (float)sin_ang * y,
			(float)cos_ang * y - (float)sin_ang * x);
	}

public:
	Vec2 operator+(const float s) { return Vec2(x + s, y + s); }
	Vec2 operator+(const Vec2& vec) { return Vec2(x + vec.x, y + vec.y); }

	Vec2 operator-(const float s) { return Vec2(x - s, y - s); }
	Vec2 operator-(const Vec2& vec) { return Vec2(x - vec.x, y - vec.y); }

	Vec2 operator*(const float m) { return Vec2(m * x, m * y); }
	float operator*(const Vec2& vec) { return x * vec.x + y * vec.y; }

	Vec2 operator/(const float d) { return Vec2(x / d, y / d); }
	Vec2 operator/(const Vec2& vec) { return Vec2(x / vec.x, y / vec.y); }

public:
	float x;
	float y;
};

