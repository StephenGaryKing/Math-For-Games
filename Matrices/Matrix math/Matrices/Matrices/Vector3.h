#pragma once
class Vector3
{
public:
	//constructor
	Vector3();
	Vector3(float X, float Y, float Z);
	//functions
	Vector3 Add(const Vector3& other);
	Vector3 Subtract(const Vector3& other);
	float DotProduct(const Vector3& other);
	float GetMagnitude();
	Vector3 GetNormalised();
	//operators
	bool operator == (Vector3 &other);
	bool operator != (Vector3 &other);
	Vector3 operator + (float other);
	Vector3 operator += (float other);
	Vector3 operator - (float other);
	Vector3 operator -= (float other);
	Vector3 operator * (float other);
	Vector3 Vector3::operator *= (float other);
	float DotProduct(const Vector3& other);
	Vector3 Vector3::CrossProduct(const Vector3& other);
	//deconstructor
	~Vector3();
	//variables
	float x, y, z;
};

