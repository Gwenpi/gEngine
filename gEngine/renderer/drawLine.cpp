#include "drawLine.h"
#include"../resourceManagement/resourceManagement.h"
#include"../tool/tool_macro.h"

DrawLine::DrawLine()
	:m_Shader(*ResourceManagement::getShader("line_shader"))
{
	init();
}

void DrawLine::setColor(const vec4 & color)
{
	ResourceManagement::getShader("line_shader")->setUniform4f("color", color);
}

void DrawLine::drawLine(const vec2 & vertex1,const vec2 & vertex2,const vec4& color)
{
	ResourceManagement::getShader("line_shader")->setUniform4f("color", color);
	ResourceManagement::getShader("line_shader")->use();
	ResourceManagement::getShader("line_shader")->setUniform2f("vertex1", vertex1);
	ResourceManagement::getShader("line_shader")->setUniform2f("vertex2", vertex2);
	glBindVertexArray(m_VAO);
	glDrawArrays(GL_POINTS, 0, 1);
}

void DrawLine::init()
{
	float vertices[]
	{
		0.0f,0.0f,0.0f
	};

	unsigned int vbo;
	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &vbo);

	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
	
}
