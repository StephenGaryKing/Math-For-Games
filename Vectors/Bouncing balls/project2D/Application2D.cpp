#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Ball.h"
#include "Vector2.h"
#include <time.h>

Application2D::Application2D() {
	srand(time(NULL));
}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	centerOfTheWindow = { (float)getWindowWidth() / 2 , (float)getWindowHeight() / 2 };

	for (int i = 0; i < amountOfBalls; i++)
	{
		m_ball.push_back(new Ball({ rand() % 200 + centerOfTheWindow.x - 100, rand() % 200 + centerOfTheWindow.y - 100 }, 30));
	}

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;
	gravity = 20;

	return true;
}

void Application2D::shutdown() {
	for (int i = 0; i < amountOfBalls; i++)
	{
		delete m_ball[i];
	}
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {
	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	for (int i = 0; i < m_ball.size(); i++)
	{
		m_ball[i]->UpdatePhysics(gravity, deltaTime, getWindowWidth(), getWindowHeight());

		for (int a = 0; a < m_ball.size(); a++)
		{
			if (m_ball[i]->GetPosition() != m_ball[a]->GetPosition())
			m_ball[i]->CheckCollision(m_ball[a]);
		}
	}

	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
		m_ball.push_back(new Ball({ rand() % 200 + centerOfTheWindow.x - 100, rand() % 200 + centerOfTheWindow.y - 100 }, 30));
	
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();
	
	for (int i = 0; i < m_ball.size(); i++)
	{
		m_2dRenderer->setRenderColour(m_ball[i]->GetColour().R, m_ball[i]->GetColour().G, m_ball[i]->GetColour().B, 1);
		m_2dRenderer->drawCircle(m_ball[i]->GetPosition().x, m_ball[i]->GetPosition().y, m_ball[i]->GetSize());
	}

	// done drawing sprites
	m_2dRenderer->end();
}