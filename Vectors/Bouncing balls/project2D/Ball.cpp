#include "Ball.h"
#include "Vector2.h"
#include <random>

Ball::Ball()
{
}

Ball::Ball(Vector2 pos, int s)
{
	position = pos;
	velocity = { rand()% 20 - 10.0f, rand() % 10 * 1.0f };
	size = rand()%s +20;
	maxSize = s;
	myColour = { rand() % 100 / 100.0f, rand() % 100 / 100.0f , rand() % 100 / 100.0f , 1 };
}

void Ball::UpdatePhysics(float gravity, float deltaTime, float WindowWidth, float WindowHeight)
{
	velocity.y -= gravity * deltaTime;

	Vector2 posToMoveTo =
	{
		(position.x + velocity.x),
		(position.y + velocity.y)
	};

	SetPosition(posToMoveTo);

	if (position.x < size)
	{
		position.x = size;
		velocity.x = -velocity.x;
	}
	if (position.x > WindowWidth - size)
	{
		position.x = WindowWidth - size;
		velocity.x = -velocity.x;
	}
	if (position.y < size)
	{
		position.y = size;
		velocity.y = -velocity.y;
	}
	if (position.y > WindowHeight - size)
	{
		position.y = WindowHeight - size;
		velocity.y = -velocity.y;
	}
}

void Ball::CheckCollision(Ball* other)
{
	PointToHit = GetPosition().Subtract(other->GetPosition());
	PointToHit = PointToHit.GetNormalised();
	PointToHit = PointToHit * (other->GetSize() + size);
	PointToHit = PointToHit.Add(other->GetPosition());

	DisplacementFromOther.x = GetPosition().x - other->GetPosition().x;
	DisplacementFromOther.y = GetPosition().y - other->GetPosition().y;

	if (DisplacementFromOther.GetMagnitude() < (other->GetSize() + size ))
	{
		// v - 2 * (v.n) * n
		Vector2 normal = (GetPosition().Subtract(other->GetPosition())).GetNormalised() * -1;
		Vector2 newVelocity = GetVelocity().Subtract(normal * 2.0f * GetVelocity().DotProduct(normal));
		newVelocity *= 1;

		SetPosition(PointToHit);
		SetVelocity(newVelocity);
		//find reflection vector and apply it to m_innerball
	}
}

float Ball::GetSize()
{
	return size;
}

Vector2 Ball::GetPosition()
{
	return position;
}

Vector2 Ball::GetVelocity()
{
	return velocity;
}

Colour Ball::GetColour()
{
	return myColour;
}

void Ball::SetPosition(Vector2 newPos)
{
	position = newPos;
}

void Ball::SetVelocity(Vector2 newVel)
{
	velocity = newVel;
}

Ball::~Ball()
{
}
