#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Input.h"
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

	std::vector<Ball*>  m_suns;
	float				m_cameraX, m_cameraY;
	Vector2				m_mousePosition;
	float				m_timer;
	float				m_gravity;
	int					m_amountOfBalls = 10;
	Vector2				m_ballSpawn[2];
};