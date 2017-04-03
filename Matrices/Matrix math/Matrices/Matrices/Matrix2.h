#pragma once
#include "Vector2.h"

struct Mat2
{
	Vector2 Axis[2];	// array of two vectors x1 y1
};						//						x2 y2

class Matrix2
{

public:
	//constructor
	Matrix2();
	//operator overloads
	Vector2 operator *(Vector2 vector);
	Vector2& operator [](int index);
	operator float*();
	//functions
	void Transpose();
	Vector2 Multiply(Vector2 vector);
	//deconstructor
	~Matrix2();

private:
	//variables
	Mat2 matrix2;
};

Matrix2::Matrix2()	// set the matrix to an idenity matrix
{
	matrix2.Axis[0] = { 1,0 };
	matrix2.Axis[1] = { 0,1 };
}

Vector2 Matrix2::operator *(Vector2 vector)
{
	Vector2 newVector;
	newVector.x = vector.DotProduct(matrix2.Axis[0]);	// perform a dot product between the input vector and the first row or data
	newVector.y = vector.DotProduct(matrix2.Axis[1]);	// perform a dot product between the input vector and the second row or data
	return newVector;
}

void Matrix2::Transpose()
{
	float temp = matrix2.Axis[0].y;			// transpose the data using a temp variable
	matrix2.Axis[0].y = matrix2.Axis[1].x;	//	x1 y1		->		x1 x2
	matrix2.Axis[1].x = temp;				//	x2 y2		->		y1 y2
}

Vector2& Matrix2::operator [](int index)	// return a pointer to the vector that they requested for them to modify
{
	return matrix2.Axis[index];
}

Matrix2::operator float*()
{
	return &matrix2.Axis[0].x;
}

Matrix2::~Matrix2()
{
}
