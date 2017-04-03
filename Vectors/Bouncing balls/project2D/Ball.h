#pragma once
#include "Vector2.h"

struct Colour
{
	float R, G, B, A;
};

class Ball
{
public:
	Ball();
	Ball(Vector2 pos, int s);
	void UpdatePhysics(float gravity, float deltaTime, float WindowWidth, float WindowHeight);
	void CheckCollision(Ball* other);
	float GetSize();
	Vector2 GetPosition();
	Vector2 GetVelocity();
	Colour GetColour();
	void SetPosition(Vector2 newPos);
	void SetVelocity(Vector2 newVel);
	~Ball();
private:
	Vector2 position;
	Vector2 velocity;
	float size;
	float maxSize;
	Vector2 PointToHit;
	Vector2 DisplacementFromOther;
	Colour myColour;
};

