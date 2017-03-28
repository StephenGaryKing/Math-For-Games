#include "Vector2.h"


Vector2::Vector2()
{

}

Vector2::Vector2(float X, float Y)
{
	x = X;
	y = Y;
}

Vector2 Vector2::Translate(const Vector2& a_first, const Vector2& a_second)
{
	return Add(a_first, a_second);
}
Vector2 Vector2::Add(const Vector2& a_first, const Vector2& a_second)
{
	Vector2 newVector;
	newVector.x = a_first.x + a_second.x;
	newVector.y = a_first.y + a_second.y;
	return newVector;
}
Vector2 Vector2::Subtract(const Vector2& a_first, const Vector2& a_second)
{
	Vector2 newVector;
	newVector.x = a_first.x - a_second.x;
	newVector.y = a_first.y - a_second.y;
	return newVector;
}
Vector2 Vector2::Scale(const Vector2& a_point, float a_scalar)
{
	return Multiply(a_point, a_scalar);
}
Vector2 Vector2::Multiply(const Vector2& a_point, float a_scalar)
{
	Vector2 newVector;
	newVector.x = a_point.x * a_scalar;
	newVector.y = a_point.y * a_scalar;
	return newVector;
}
Vector2 Vector2::Divide(const Vector2& a_point, float a_scalar)
{
	Vector2 newVector;
	newVector.x = a_point.x / a_scalar;
	newVector.y = a_point.y / a_scalar;
	return newVector;
}


Vector2::~Vector2()
{
}
