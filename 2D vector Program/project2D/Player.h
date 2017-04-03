#pragma once
#include "Vector2.h"

class Player
{
public:
	Player();
	Player(float x, float y);
	Vector2 GetPosition();
	float GetRotation();
	void Jump();
	void UpdatePhysics(float deltaTime);
	~Player();

private:
	Vector2 position;
	Vector2 velocity{0,0};
	float gravity;
	float jumpForce;
};

