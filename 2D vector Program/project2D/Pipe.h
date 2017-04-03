#pragma once
#include "Vector2.h"
class Pipe
{
public:
	Pipe();
	Pipe(float x, float y, float windWidth);
	void UpdatePhysics(float deltaTime);
	~Pipe();
private:
	Vector2 position;
	float pipeSpeed = 10;
	float windowWidth;
};

