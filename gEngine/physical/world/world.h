#pragma once

#include"../../sprite/sprite.h"
#include"../../renderer/simple_renderer2d.h"
#include"../../renderer/drawLine.h"


class World
{
private:
	std::vector<Sprite2D*>m_Sprites;
	SimpleRenderer2D* m_Renderer;
	DrawLine* m_Line;
public:
	World();
	~World();
	void addCircleSprite(const vec2& position, float radius=20.0f, const char* textueName="circle");
	void update(float duration);
	void render();
private:
	void init();
	void interfaceCycle();
	void friction(Sprite2D* sprite);
};


