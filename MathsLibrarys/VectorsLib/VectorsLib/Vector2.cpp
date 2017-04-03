#include "Vector2.h"
#include <math.h>

Vector2::Vector2()
{

}

Vector2::Vector2(float X, float Y)
{
	x = X;
	y = Y;
}

//comparison operators
bool Vector2::operator == (Vector2 &other)
{
	return x == other.x && y == other.y;
}

bool Vector2::operator != (Vector2 &other)
{
	return x != other.x && y != other.y;
}

//Plus operators
Vector2 Vector2::operator + (float other)
{
	Vector2 temp;
	temp.x = x + other;
	temp.y = y + other;
	return temp;
}

Vector2 Vector2::operator += (float other)
{
	this->x += other;
	this->y += other;
	return *this;
}

Vector2 Vector2::operator - (float other)
{
	Vector2 temp;
	temp.x = x - other;
	temp.y = y - other;
	return temp;
}

Vector2 Vector2::operator -= (float other)
{
	this->x -= other;
	this->y -= other;
	return *this;
}

//multiplication
Vector2 Vector2::operator * (float other)
{
	Vector2 temp;
	temp.x = x * other;
	temp.y = y * other;
	return temp;
}

Vector2 Vector2::operator *= (float other)
{
	this->x *= other;
	this->y *= other;
	return *this;
}

//other maths functions
Vector2 Vector2::Translate(const Vector2 &other)
{
	Vector2 newVector;
	newVector.x = this->x + other.x;
	newVector.y = this->y + other.y;
	return newVector;
}
Vector2 Vector2::Add(const Vector2& other)
{
	Vector2 newVector;
	newVector.x = this->x + other.x;
	newVector.y = this->y + other.y;
	return newVector;
}
Vector2 Vector2::Subtract(const Vector2& other)
{
	Vector2 newVector;
	newVector.x = this->x - other.x;
	newVector.y = this->y - other.y;
	return newVector;
}

float Vector2::DotProduct(const Vector2 &other)
{
	Vector2 newVector;
	newVector.x = this->x * other.x;
	newVector.y = this->y * other.y;
	return newVector.x + newVector.y;
}

float Vector2::GetMagnitude()
{
	return sqrtf(x* x + y* y);
}

Vector2 Vector2::GetNormalised()
{
	Vector2 newVector;
	float magnitude = GetMagnitude();
	newVector.x = x / magnitude;
	newVector.y = y / magnitude;
	return newVector;
}

Vector2::~Vector2()
{
}
