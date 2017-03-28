#pragma once
class Vector2
{
public:
	//constructor
	Vector2();
	Vector2(float x, float y);
	//functions
	Vector2 Translate(const Vector2& a_first, const Vector2& a_second);
	Vector2 Add(const Vector2& a_first, const Vector2& a_second);
	Vector2 Subtract(const Vector2& a_first, const Vector2& a_second);
	Vector2 Scale(const Vector2& a_point, float a_scalar);
	Vector2 Multiply(const Vector2& a_point, float a_scalar);
	Vector2 Divide(const Vector2& a_point, float a_scalar);
	//deconstructor
	~Vector2();
	//variables
	float x, y;
};

