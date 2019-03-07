#include "vertex_buffer.h"


VertexBuffer::VertexBuffer(float* data, unsigned int size)
{
	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_VBO);
}

void VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
}

void VertexBuffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
}
