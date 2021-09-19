#pragma once

#include "Vec2.h"

class Rect
{
public:
	Rect() {};
	Rect(float x, float y, float w, float h);
	~Rect() {}

public:
	bool Contains(const Vec2& point) { return ((point.x >= x) && (point.x <= (x + w)) && (point.y >= y) && (point.y <= (y + h))); }

	Rect operator+(const float f) { return Rect(x + f, y + f, w, h); }
	Rect operator+(const Vec2& vec) { return Rect(x + vec.x, y + vec.y, w, h); }

public:
	float x;
	float y;

	float w;
	float h;
};

