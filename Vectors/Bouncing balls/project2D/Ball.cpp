#include "Ball.h"
#include "Vector2.h"
#include <random>

Ball::Ball()
{
}

Ball::Ball(Vector2 pos)
{
	position = pos;
	size = 20;
} 

Ball::Ball(Vector2 pos, int s)
{
	updateTime = 0;
	position = pos;
	velocity = { rand()% 30 - 15.0f, rand() % 30 - 15.0f };
	size = rand()%s + 5;
	maxSize = s;
	myColour = { rand() % 100 / 100.0f, rand() % 100 / 100.0f , rand() % 100 / 100.0f , 1 };
	myLine.linePositions.push_back(position);
}

Ball::Ball(Vector2 pos, int s, Vector2 v)
{
	updateTime = 0;
	position = pos;
	velocity = { v.x, v.y };
	size = rand() % s + 5;
	maxSize = s;
	myColour = { rand() % 100 / 100.0f, rand() % 100 / 100.0f , rand() % 100 / 100.0f , 1 };
	myLine.linePositions.push_back(position);
}

void Ball::UpdatePhysics(Ball* sun, float deltaTime, float WindowWidth, float WindowHeight, float timer)
{

	Vector2 GravityDirection = (GetPosition().Subtract(sun->GetPosition())).GetNormalised() * -1;

	Vector2 displacementFromSun;
	displacementFromSun.x = GetPosition().x - sun->GetPosition().x;
	displacementFromSun.y = GetPosition().y - sun->GetPosition().y;

	velocity = velocity.Add(GravityDirection * sun->GetSize()* deltaTime);


	Vector2 posToMoveTo =
	{
		(position.x + velocity.x),
		(position.y + velocity.y)
	};

	SetPosition(posToMoveTo);
	if (timer > updateTime + 0.05f)
	{
		myLine.linePositions.push_back(posToMoveTo);
		updateTime = timer;
		if (myLine.linePositions.size() > 50)
		{
			myLine.linePositions.erase(myLine.linePositions.begin());
		}
	}
}

bool Ball::CheckCollision(Ball* other)
{
	PointToHit = GetPosition().Subtract(other->GetPosition());
	PointToHit = PointToHit.GetNormalised();
	PointToHit = PointToHit * (other->GetSize() + size);
	PointToHit = PointToHit.Add(other->GetPosition());

	displacementFromOther.x = GetPosition().x - other->GetPosition().x;
	displacementFromOther.y = GetPosition().y - other->GetPosition().y;

	if (displacementFromOther.GetMagnitude() < (other->GetSize() + size ))
	{
		// v - 2 * (v.n) * n
		Vector2 normal = (GetPosition().Subtract(other->GetPosition())).GetNormalised() * -1;
		Vector2 newVelocity = GetVelocity().Subtract(normal * 2.0f * GetVelocity().DotProduct(normal));
		newVelocity *= 1;

		SetPosition(PointToHit);
		SetVelocity(newVelocity);
		return true;
	}
	return false;
}

Line Ball::GetMyline()
{
	return myLine;
}

Ball* Ball::GetClosestSun(std::vector<Ball*>  &suns)
{
	Vector2 displacementFromSun = { GetPosition().x - suns[1]->GetPosition().x ,GetPosition().x - suns[1]->GetPosition().y };
	Ball* tempSun = nullptr;
	for (int i = 0; i < suns.size(); i++)
	{
		Vector2 tempDisplacement;
		tempDisplacement.x = GetPosition().x - suns[i]->GetPosition().x;
		tempDisplacement.y = GetPosition().y - suns[i]->GetPosition().y;
		if (tempSun == nullptr || tempDisplacement.GetMagnitude() < displacementFromSun.GetMagnitude())
		{
			displacementFromSun = tempDisplacement;
			tempSun = suns[i];
		}
	}
	return tempSun;
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

void Ball::SetSize(float newSize)
{
	size = newSize;
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
