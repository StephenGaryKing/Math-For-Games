#pragma once
class Vector2
{
public:
	//constructor
	Vector2();
	Vector2(float x, float y);
	//functions
	Vector2 Translate(const Vector2& other);
	Vector2 Add(const Vector2& other);
	Vector2 Subtract(const Vector2& other);
	float DotProduct(const Vector2& other);
	float GetMagnitude();
	Vector2 GetNormalised();
	//operators
	bool operator == (Vector2 &other);
	bool operator != (Vector2 &other);
	Vector2 operator + (float other);
	Vector2 operator += (float other);
	Vector2 operator - (float other);
	Vector2 operator -= (float other);
	Vector2 operator * (float other);
	Vector2 Vector2::operator *= (float other);
	//deconstructor
	~Vector2();
	//variables
	float x, y;
};

