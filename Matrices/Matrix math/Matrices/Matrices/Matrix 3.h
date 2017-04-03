#pragma once
#include "Vector3.h"

struct Mat2
{
	Vector3 Axis[3];	// array of two vectors x1 y1 z1
};						//						x2 y2 z2
						//						x3 y3 z3

class Matrix3
{

public:
	//constructor
	Matrix3();
	//operator overloads
	Vector3 operator * (Vector3 Vector);
	Vector3& operator [](int index);
	operator float*();
	//functions
	void Transpose();
	//deconstructor
	~Matrix3();

private:
	//variables
	Mat2 matrix3;
};

Matrix3::Matrix3()	// set the matrix to an idenity matrix
{
	matrix3.Axis[0] = { 1,0,0 };
	matrix3.Axis[1] = { 0,1,0 };
	matrix3.Axis[1] = { 0,0,1 };
}

Vector3 Matrix3::operator * (Vector3 vector)
{
	Vector3 newVector;
	newVector.x = vector.DotProduct(matrix3.Axis[0]);	// perform a dot product between the input vector and the first row or data
	newVector.y = vector.DotProduct(matrix3.Axis[1]);	// perform a dot product between the input vector and the second row or data
	newVector.z = vector.DotProduct(matrix3.Axis[2]);	// perform a dot product between the input vector and the third row or data
	return newVector;
}

void Matrix3::Transpose()
{														// transpose the data using a temp variable
	// first row										//	x1 y1 z1		->		x1 x2 x3
	Vector3 newVector = matrix3.Axis[0];				//	x2 y2 z2		->		y1 y2 y3
	matrix3.Axis[0] =									//	x3 y3 z3		->		z1 z2 z3
	{
		matrix3.Axis[0].x,
		matrix3.Axis[1].x,
		matrix3.Axis[2].x
	};
	
	matrix3.Axis[0].x = newVector.x;
	matrix3.Axis[1].x = newVector.y;
	matrix3.Axis[2].x = newVector.z;

	// second row
	newVector = matrix3.Axis[1];
	matrix3.Axis[1] =
	{
		matrix3.Axis[0].y,
		matrix3.Axis[1].y,
		matrix3.Axis[2].y
	};

	matrix3.Axis[0].y = newVector.x;
	matrix3.Axis[1].y = newVector.y;
	matrix3.Axis[2].y = newVector.z;

	// third row
	newVector = matrix3.Axis[2];
	matrix3.Axis[2] =
	{
		matrix3.Axis[0].z,
		matrix3.Axis[1].z,
		matrix3.Axis[2].z
	};

	matrix3.Axis[0].z = newVector.x;
	matrix3.Axis[1].z = newVector.y;
	matrix3.Axis[2].z = newVector.z;									
}											

Vector3& Matrix3::operator [](int index)	// return a pointer to the vector that they requested for them to modify
{
	return matrix3.Axis[index];
}

Matrix3::operator float*()
{
	return &matrix3.Axis[0].x;
}

Matrix3::~Matrix3()
{
}
