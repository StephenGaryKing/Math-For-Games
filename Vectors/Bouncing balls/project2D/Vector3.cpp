#include "Vector3.h"



Vector3::Vector3()
{

}
Vector3::Vector3(float X, float Y, float Z)
{
	x = X;
	y = Y;
	z = Z;
}

//comparison operators
bool Vector3::operator == (Vector3 &other)
{
	return x == other.x && y == other.y && z == other.z;
}

bool Vector3::operator != (Vector3 &other)
{
	return x != other.x && y != other.y && z != other.z;
}

//Plus operators
Vector3 Vector3::operator + (float other)
{
	Vector3 temp;
	temp.x = x + other;
	temp.y = y + other;
	temp.z = z + other;
	return temp;
}

Vector3 Vector3::operator += (float other)
{
	this->x += other;
	this->y += other;
	this->z += other;
	return *this;
}

Vector3 Vector3::operator - (float other)
{
	Vector3 temp;
	temp.x = x - other;
	temp.y = y - other;
	temp.z = z - other;
	return temp;
}

Vector3 Vector3::operator -= (float other)
{
	this->x -= other;
	this->y -= other;
	this->z -= other;
	return *this;
}

//multiplication
Vector3 Vector3::operator * (float other)
{
	Vector3 temp;
	temp.x = x * other;
	temp.y = y * other;
	temp.z = z * other;
	return temp;
}

Vector3 Vector3::operator *= (float other)
{
	this->x *= other;
	this->y *= other;
	this->z *= other;
	return *this;
}

//other maths functions
Vector3 Vector3::Add(const Vector3& other)
{
	Vector3 newVector;
	newVector.x = this->x + other.x;
	newVector.y = this->y + other.y;
	newVector.z = this->z + other.z;
	return newVector;
}
Vector3 Vector3::Subtract(const Vector3& other)
{
	Vector3 newVector;
	newVector.x = this->x - other.x;
	newVector.y = this->y - other.y;
	newVector.z = this->z - other.z;
	return newVector;
}

float Vector3::GetMagnitude()
{
	//return sqrtf(x* x + y* y);
}

Vector3 Vector3::GetNormalised()
{
	/*
	Vector3 newVector;
	float magnitude = GetMagnitude();
	newVector.x = x / magnitude;
	newVector.y = y / magnitude;
	return newVector;
	*/
}

float Vector3::DotProduct(const Vector3& other)
{
	return x * other.x + y * other.y + z * other.z ;
}

Vector3 Vector3::CrossProduct(const Vector3& other)
{
	Vector3 newVector;
	newVector.x = y * other.z - z * other.y;
	newVector.y = z * other.x - x * other.z;
	newVector.z = x * other.y - y * other.x;
	return newVector;
}

Vector3::~Vector3()
{
}
