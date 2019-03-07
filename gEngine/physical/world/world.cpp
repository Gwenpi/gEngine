#include "world.h"
#include"../../window/input.h"
#include<GLFW\glfw3.h>

World::World()
{
	init();
}

World::~World()
{
	for (int i = 0;i < m_Sprites.size();i++)
	{
		delete m_Sprites[i];
	}
	delete m_Renderer;
	delete m_Line;
}

void World::addCircleSprite(const vec2 & position, float radius, const char * textureName)
{
	m_Sprites.push_back(new CircleSprite(position, radius, textureName));
	int index = m_Sprites.size() - 1;
	m_Sprites[index]->changeId() = m_Sprites.size();
}

void World::update(float duration)
{
	//圆的拾取
	auto IsPointInCircle = [](float x1, float y1, float r1, float px, float py)
	{
		return fabs((x1 - px)*(x1 - px) + (y1 - py)*(y1 - py)) < (r1 * r1);
	};

	float cursorY= SCREEN_HEIGHT - Input::getCursorY();
	float cursorX= Input::getCursorX();

	if (Input::mouseButtonIsPress(GLFW_MOUSE_BUTTON_LEFT)||Input::mouseButtonIsPress(GLFW_MOUSE_BUTTON_RIGHT))
	{
		if (Input::getSpriteSelete() == nullptr)
		{
			for (auto &sprite : m_Sprites)
			{
				if (IsPointInCircle(sprite->getPosition().mx, sprite->getPosition().my, sprite->getRadius()
					, cursorX, cursorY))
				{
					Input::setSpriteSelete(sprite);
					break;
				}
			}

		}
	}
	if (Input::getSpriteSelete() != nullptr)
	{
		if(Input::mouseButtonIsHeld(GLFW_MOUSE_BUTTON_LEFT))
			Input::getSpriteSelete()->changePosition(cursorX, cursorY);
		else if (Input::mouseButtonIsRelease(GLFW_MOUSE_BUTTON_LEFT))
		{
			if (Input::mouseButtonIsRelease(GLFW_MOUSE_BUTTON_RIGHT))
			{
				Input::getSpriteSelete()->changeVelocity() = 3.8f*(Input::getSpriteSelete()->getPosition() - vec2(cursorX, cursorY));
				Input::resetSpriteSelete();
			}
		}
	}
	
	
	

	//draw cue
	if (Input::getSpriteSelete() != nullptr)
	{
		m_Line->drawLine(Input::getSpriteSelete()->getPosition(), vec2(cursorX, cursorY),vec4(0.1,0.1,1.0,1.0));
	}

	//圆的碰撞检测
	for (auto &ball : m_Sprites)
	{
		for (auto &target : m_Sprites)
		{
			if (target != ball)
			{
				if (ball->collisionHanding(target))
				{
					m_Line->drawLine(ball->getPosition(), target->getPosition(),vec4(0.8, 0.1, 0.1, 0.5));
				}
			}
		}
	}
	//圆的更新
	for (auto &ball : m_Sprites)
	{
		ball->update(duration);
		friction(ball);
	}



	interfaceCycle();
}

void World::render()
{
	for (int i = 0;i < m_Sprites.size();i++)
	{
		m_Renderer->Renderer2D(m_Sprites[i]);
	}
}

void World::init()
{
	m_Renderer = new SimpleRenderer2D(*ResourceManagement::getShader("texture2d_shader"));
	m_Line = new DrawLine();

	addCircleSprite(vec2(0.0f), 25.0f);
	addCircleSprite(vec2(150.0f), 25.0f);
	addCircleSprite(vec2(200.0f), 25.0f);
	addCircleSprite(vec2(250.0f), 25.0f);
	addCircleSprite(vec2(280.0f,100.0f), 25.0f);
	addCircleSprite(vec2(310.0f), 25.0f);
	addCircleSprite(vec2(340.0f), 25.0f);
	addCircleSprite(vec2(370.0f), 25.0f);
}

void World::interfaceCycle()
{
	for (auto &sprite : m_Sprites)
	{
		if (sprite->getPosition().mx < 0)sprite->changePosition().mx += SCREEN_WIDTH;
		if (sprite->getPosition().mx >=SCREEN_WIDTH)sprite->changePosition().mx -= SCREEN_WIDTH;


		if (sprite->getPosition().my < 0)sprite->changePosition().my += SCREEN_HEIGHT;
		if (sprite->getPosition().my >= SCREEN_HEIGHT)sprite->changePosition().my -= SCREEN_HEIGHT;
	}
}

void World::friction(Sprite2D * sprite)
{
	sprite->changeAcceleration() = -sprite->getVelocity()*0.8f;
}
