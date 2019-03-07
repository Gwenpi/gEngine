#pragma once
#include<GL/glew.h>
class VertexBuffer
{
private:
	unsigned int m_VBO;
public:
	VertexBuffer(float* data, unsigned int size);
	~VertexBuffer();
	void bind()const;
	void unbind()const;
};

