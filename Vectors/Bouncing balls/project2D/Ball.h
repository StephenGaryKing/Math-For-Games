#pragma once
#include "Vector2.h"
#include <vector>

struct Colour
{
	float R, G, B, A;
};

struct Line
{
	std::vector<Vector2> linePositions;
};

class Ball
{
public:
	Ball();
	Ball(Vector2 pos);
	Ball(Vector2 pos, int s);
	Ball(Vector2 pos, int s, Vector2 v);
	void UpdatePhysics(Ball* Sun, float deltaTime, float WindowWidth, float WindowHeight, float timer);
	bool CheckCollision(Ball* other);
	Ball* GetClosestSun(std::vector<Ball*>  &suns);
	float GetSize();
	Vector2 GetPosition();
	Vector2 GetVelocity();
	Colour GetColour();
	Line GetMyline();
	void SetSize(float newSize);
	void SetPosition(Vector2 newPos);
	void SetVelocity(Vector2 newVel);
	~Ball();
private:
	Vector2 position;
	Vector2 velocity;
	float size;
	float maxSize;
	Vector2 PointToHit;
	Vector2 displacementFromOther;
	Colour myColour;
	Line myLine;
	float updateTime;
};

