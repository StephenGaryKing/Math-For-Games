#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_birdTexture = new aie::Texture("./textures/flappyBird.png");
	m_pipeTexture = new aie::Texture("./textures/Pipe.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	for (int i = 0; i < 8; i++)
	{
		m_pipes[0][i] = new Pipe(getWindowWidth() + i* spaceBetweenPipes, 0.0f, getWindowWidth());
		m_pipes[1][i] = new Pipe(getWindowWidth() + i* spaceBetweenPipes, getWindowHeight(), getWindowWidth());
	}

	m_player = new Player(getWindowWidth()/8, getWindowHeight()/2);

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() {
	
	delete m_font;
	delete m_pipeTexture;
	delete m_birdTexture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	m_player->UpdatePhysics(deltaTime);

	for (int i = 0; i < 8; i++)
	{
		m_pipes[0][i]->UpdatePhysics(deltaTime);
		m_pipes[1][i]->UpdatePhysics(deltaTime);
	}

	// make player jump
	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
		m_player->Jump();

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
	
	m_2dRenderer->setUVRect(0, 0, 1, 1);
	m_2dRenderer->drawSprite(m_birdTexture, m_player->GetPosition().x, m_player->GetPosition().y, 60, 60);

	// done drawing sprites
	m_2dRenderer->end();
}