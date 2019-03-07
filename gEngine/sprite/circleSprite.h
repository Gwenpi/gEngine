#pragma once

#include"sprite2d.h"

//mark 考虑在model 还是在sprite2d中加一个角速度和角度

class CircleSprite:public Sprite2D
{
private:
	float m_Radius;
public:
	CircleSprite(const vec2& position = vec2(SCREEN_WIDTH / 2.0, SCREEN_HEIGHT / 2.0), float radius=5.0f,const char* name = "circle");
	~CircleSprite();

	vec2 getSize()const override;
	bool collisionHanding( Sprite2D* target)override;
	void update(float duration)override;

	float getRadius()const override { return m_Radius; }
};
