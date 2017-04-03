#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Ball.h"
#include <vector>

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	Vector2 centerOfTheWindow;

	aie::Renderer2D*	m_2dRenderer;
	std::vector<Ball*>	m_ball;

	float m_cameraX, m_cameraY;
	float m_timer;
	float gravity;
	int amountOfBalls = 10;
};