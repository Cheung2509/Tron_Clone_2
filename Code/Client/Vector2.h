#pragma once


struct Vector2
{
	float x, y;
	
	
};

inline Vector2& operator+(Vector2 v1, Vector2 v2)
{
	Vector2 r;
	r.x = v1.x + v2.y;
	r.y = v1.x + v2.x;
	return r;
}