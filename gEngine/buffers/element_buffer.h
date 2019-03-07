#pragma once
#include<GL\glew.h>

class ElementBuffer
{
private:
	unsigned int m_EBO;
	unsigned int m_VertexNumber;//��Ҫ���ƶ��������
public:
	ElementBuffer(unsigned int* data,unsigned int number);
	~ElementBuffer();
	inline unsigned int getVertexNumber()const { return m_VertexNumber; }
	void bind();
	void unbind();
};
