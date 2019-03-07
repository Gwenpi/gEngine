#pragma once
#include"vertex_buffer.h"
#include"buffer_layout.h"
#include<deque>
class VertexArray
{
private:
	unsigned int m_VAO;
	std::deque<VertexBuffer*>m_VBOs;
public:
	VertexArray();
	~VertexArray();
	void bind()const;
	void unbind()const;
	void addVBO(VertexBuffer* vbo, unsigned int index, int size, unsigned int stride, int initialPosition);
	void addVBO(VertexBuffer* vbo, BufferLayout* layout);
};
