#include "Player.h"



Player::Player()
{
	jumpForce = 10;
	gravity = 20;
}
Player::Player(float x, float y)
{
	position = {x,y};
	jumpForce = 10;
	gravity = 20;
}

Vector2 Player::GetPosition()
{
	return position;
}

float Player::GetRotation()
{
	return 0; // will return rotation in future
}

void Player::Jump()
{
	velocity.y = jumpForce;
}

void Player::UpdatePhysics(float deltaTime)
{
	velocity.y -= (gravity)*deltaTime;
	position.y += velocity.y;
}

Player::~Player()
{
}
