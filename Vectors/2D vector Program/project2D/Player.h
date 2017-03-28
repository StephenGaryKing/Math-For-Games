#pragma once
class Player
{
public:
	Player();
	Player(float x, float y);
	void Jump();
	void UpdatePhysics();
	~Player();

private:
	Vector2 position;
	Vector2 velocity;
	float gravity = 10;
	float drag = 5;
};

