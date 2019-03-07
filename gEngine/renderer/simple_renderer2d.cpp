#include "simple_renderer2d.h"

#include<GLFW\glfw3.h>
#include<Windows.h>



SimpleRenderer2D::SimpleRenderer2D(Shader & shader)
	:m_Shader(shader)
{
	init();
}

SimpleRenderer2D::~SimpleRenderer2D()
{
}

void SimpleRenderer2D::Renderer2D(const Texture2D & texture, const vec2 & position, const vec2 & size, float angle, const vec4 & color, rotationPosition rp) const
{
	m_Shader.use();
	mat4 result = mat4::translation(position);

	if (CENTER == rp)
	{
		result *= mat4::translation(0.5*size);//��Ϊ���εĳ�ʼ��С��1�������������մ�Сȡ����size�仯�Ĵ�С������������Ϊ������ת���ƶ����룩
		result *= mat4::rotation(angle, vec3(0.0, 0.0, 1.0));
		result *= mat4::translation(-0.5*size);
	}
	else if (UPPER_LEFT == rp)
	{

	}
	else if (UPPER_RIGHT == rp)
	{

	}
	else if (LOWER_RIGHT == rp)
	{

	}
	else if (LOWER_LEFT == rp)
	{

	}

	result *= mat4::scale(size);
	m_Shader.setUniformMatrix4("model_matrix", result);
	m_Shader.setUniform4f("color", color);

	texture.bind();
	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
}


void SimpleRenderer2D::Renderer2D(Sprite2D * sprite)
{
	m_Shader.use();
	mat4 result = mat4::translation(sprite->getPosition());
	if (sprite->getType() == CIRCULAR)
	{
		result*= mat4::translation(-vec2(sprite->getRadius()));
		result *= mat4::scale(2* vec2(sprite->getRadius()));
	}
	
	//������һ����ת�������о��о���ô���õ�������ģ����ʵ�е�������ת
	//result *= mat4::translation(sprite->getRotationPoint());
	//mark���ﲢ��������������Ƕȣ���ʱ����Ҫ������ģ����ʵʱ������ת����
	//�������ת�ǶȾ�Ȼ���ǻ�����
	//����ְ�
	//result *= mat4::rotation(sprite->getRotationAngle(), vec3(0.0, 0.0, 1.0));
	//result *= mat4::translation(-sprite->getRotationPoint());
	


	m_Shader.setUniformMatrix4("model_matrix", result);
	m_Shader.setUniform4f("color", sprite->getColor());

	sprite->getTexture()->bind();
	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);

}




void SimpleRenderer2D::init()
{
	float vertices[] =
	{
		 0.0,  0.0,
		 1.0,  0.0,
		 1.0,  1.0,
		 0.0,  1.0
	};
	unsigned int indeices[]
	{
		0,1,2,
		2,3,0
	};

	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);

	glGenBuffers(1, &m_EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeices), indeices, GL_STATIC_DRAW);//vertexShader�Ķ�����texture��һ��
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(POSITION_INDEX, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(TEXCOORD_INDEX, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

