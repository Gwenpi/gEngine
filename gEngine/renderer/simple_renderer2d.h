#pragma once

#include"../tool/shader.h"
#include"../maths/maths.h"
#include"../sprite/sprite.h"

#define POSITION_INDEX 0
#define TEXCOORD_INDEX 1



class SimpleRenderer2D
{
private:
	enum rotationPosition { CENTER, UPPER_LEFT, UPPER_RIGHT, LOWER_RIGHT, LOWER_LEFT };//mark 这个换成旋转点
	unsigned int m_VAO;
	unsigned int m_VBO;
	unsigned int m_EBO;
	Shader& m_Shader;
public:

	SimpleRenderer2D( Shader& shader);
	~SimpleRenderer2D();
	void Renderer2D(const Texture2D& texture,const vec2& position = vec2(0.0f),const vec2& size = vec2(1.0f),float angle=0.0f, const vec4& color=vec4(1.0f), rotationPosition rp=CENTER)const;
	void Renderer2D( Sprite2D* sprite);
private:
	void init();
};