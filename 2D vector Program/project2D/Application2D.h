#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Player.h"
#include "Pipe.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_pipeTexture;
	aie::Texture*		m_birdTexture;
	aie::Font*			m_font;

	Player* m_player;

	Pipe* m_pipes[2][8];

	float m_cameraX, m_cameraY;
	float m_timer;
	float spaceBetweenPipes = 200;
};