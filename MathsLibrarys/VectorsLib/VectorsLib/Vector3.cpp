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

Vector3 Vector3::Translate(const Vector3& a_first, const Vector3& a_second)
{
	return Add(a_first, a_second);
}
Vector3 Vector3::Add(const Vector3& a_first, const Vector3& a_second)
{
	Vector3 newVector;
	newVector.x = a_first.x + a_second.x;
	newVector.y = a_first.y + a_second.y;
	newVector.z = a_first.z + a_second.z;
	return newVector;
}
Vector3 Vector3::Subtract(const Vector3& a_first, const Vector3& a_second)
{
	Vector3 newVector;
	newVector.x = a_first.x - a_second.x;
	newVector.y = a_first.y - a_second.y;
	newVector.z = a_first.z - a_second.z;
	return newVector;
}
Vector3 Vector3::Scale(const Vector3& a_point, float a_scalar)
{
	return Multiply(a_point, a_scalar);
}
Vector3 Vector3::Multiply(const Vector3& a_point, float a_scalar)
{
	Vector3 newVector;
	newVector.x = a_point.x * a_scalar;
	newVector.y = a_point.y * a_scalar;
	newVector.z = a_point.z * a_scalar;
	return newVector;
}
Vector3 Vector3::Divide(const Vector3& a_point, float a_scalar)
{
	Vector3 newVector;
	newVector.x = a_point.x / a_scalar;
	newVector.y = a_point.y / a_scalar;
	newVector.z = a_point.z / a_scalar;
	return newVector;
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
