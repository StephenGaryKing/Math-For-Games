#pragma once
class Vector3
{
public:
	//constructor
	Vector3();
	Vector3(float X, float Y, float Z);
	//functions
	Vector3 Translate(const Vector3& a_first, const Vector3& a_second);
	Vector3 Add(const Vector3& a_first, const Vector3& a_second);
	Vector3 Subtract(const Vector3& a_first, const Vector3& a_second);
	Vector3 Scale(const Vector3& a_point, float a_scalar);
	Vector3 Multiply(const Vector3& a_point, float a_scalar);
	Vector3 Divide(const Vector3& a_point, float a_scalar);
	float DotProduct(const Vector3& other);
	Vector3 Vector3::CrossProduct(const Vector3& other);
	//deconstructor
	~Vector3();
	//variables
	float x, y, z;
};

