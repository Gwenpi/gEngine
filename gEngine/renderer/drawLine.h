#pragma once

#include"../tool/shader.h"

class DrawLine
{
private:
	unsigned int m_VAO;
	Shader& m_Shader;
public:
	DrawLine();
	void setColor(const vec4& color);
	void drawLine(const vec2 & vertex1, const vec2 & vertex2, const vec4& color=vec4(1.0f));
private:
	void init();
};
