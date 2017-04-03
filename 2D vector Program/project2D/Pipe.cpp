#include "Pipe.h"



Pipe::Pipe()
{

}

Pipe::Pipe(float x, float y, float windWidth)
{
	windowWidth = windWidth;
	position = { x, y };
}

void Pipe::UpdatePhysics(float deltaTime)
{
	position.x -= pipeSpeed * deltaTime;
	if (position.x < 0)
	{
		position.x += windowWidth;
	}
}

Pipe::~Pipe()
{
}
