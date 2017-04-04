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

	m_suns.push_back(new Ball({ centerOfTheWindow.x + 400, centerOfTheWindow.y }));
	m_suns.push_back(new Ball({ centerOfTheWindow.x - 400,  centerOfTheWindow.y }));

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;
	m_gravity = 20;

	return true;
}

void Application2D::shutdown() {
	for (int i = 0; i < m_ball.size(); i++)
	{
		delete m_ball[i];
	}
	delete m_suns[0];
	delete m_suns[1];
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {
	m_timer += deltaTime;
	// input
	aie::Input* input = aie::Input::getInstance();

	Vector2 newVec;

	if (input->isMouseButtonUp(0))
	{
		centerOfTheWindow = { (float)getWindowWidth() / 2 , (float)getWindowHeight() / 2 };

		m_suns[0]->SetPosition({ centerOfTheWindow.x + 400, centerOfTheWindow.y });
		m_suns[1]->SetPosition({ centerOfTheWindow.x - 400, centerOfTheWindow.y });

		//find closest sun
		for (int i = 0; i < m_ball.size(); i++)
		{
			Ball* currentClosestSun = m_ball[i]->GetClosestSun(m_suns);
			m_ball[i]->UpdatePhysics(currentClosestSun, deltaTime, getWindowWidth(), getWindowHeight(), m_timer);

			for (int a = 0; a < m_ball.size(); a++)
			{
				if (m_ball[i]->GetPosition() != m_ball[a]->GetPosition())
					m_ball[i]->CheckCollision(m_ball[a]);
			}
			if (m_ball[i]->CheckCollision(currentClosestSun))
			{
				currentClosestSun->SetSize(currentClosestSun->GetSize() + m_ball[i]->GetSize());
				m_ball[i] = m_ball[m_ball.size() - 1];
				m_ball.pop_back();
				i--;
			}
		}

		if (input->wasKeyPressed(aie::INPUT_KEY_UP))
		{
			m_suns[0]->SetSize(m_suns[0]->GetSize() + 10);
			m_suns[1]->SetSize(m_suns[1]->GetSize() - 10);
		}

		if (input->wasKeyPressed(aie::INPUT_KEY_DOWN))
		{
			m_suns[0]->SetSize(m_suns[0]->GetSize() - 10);
			m_suns[1]->SetSize(m_suns[1]->GetSize() + 10);
		}

		if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
			m_ball.push_back(new Ball({ centerOfTheWindow.x, centerOfTheWindow.y }, 10));

		// exit the application
		if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
			quit();
	}
	else
	{
		
		if (input->wasMouseButtonPressed(0))
		{
			m_ballSpawn[0] = { input->getMouseX() * 1.0f, input->getMouseY() * 1.0f };
		}

		m_ballSpawn[1] = { input->getMouseX() * 1.0f, input->getMouseY() * 1.0f };
		newVec = m_ballSpawn[1].Subtract(m_ballSpawn[0]);
	}
	if (input->wasMouseButtonPressed(0))
	{
		m_ball.push_back(new Ball({ m_ballSpawn[0].x, m_ballSpawn[0].y }, 10, newVec));
	}
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	m_2dRenderer->setRenderColour(1.0f, 0.5f, 0.0f, 1);
	m_2dRenderer->drawCircle(m_suns[0]->GetPosition().x, m_suns[0]->GetPosition().y, m_suns[0]->GetSize());
	m_2dRenderer->setRenderColour(1.0f, 0.5f, 0.0f, 1);
	m_2dRenderer->drawCircle(m_suns[1]->GetPosition().x, m_suns[1]->GetPosition().y, m_suns[1]->GetSize());
	
	for (int i = 0; i < m_ball.size(); i++)
	{
		m_2dRenderer->setRenderColour(m_ball[i]->GetColour().R, m_ball[i]->GetColour().G, m_ball[i]->GetColour().B, 1);
		m_2dRenderer->drawCircle(m_ball[i]->GetPosition().x, m_ball[i]->GetPosition().y, m_ball[i]->GetSize());
		if (m_ball[i]->GetMyline().linePositions.size() > 1)
		{
			for (int j = 0; j < m_ball[i]->GetMyline().linePositions.size() - 1; j++)
			{
				m_2dRenderer->drawLine(m_ball[i]->GetMyline().linePositions[j].x, m_ball[i]->GetMyline().linePositions[j].y, m_ball[i]->GetMyline().linePositions[j + 1].x, m_ball[i]->GetMyline().linePositions[j + 1].y);
			}
		}
	}	

	m_2dRenderer->drawLine(m_ballSpawn[0].x, m_ballSpawn[0].y, m_ballSpawn[1].x, m_ballSpawn[1].y);

	// done drawing sprites
	m_2dRenderer->end();
}