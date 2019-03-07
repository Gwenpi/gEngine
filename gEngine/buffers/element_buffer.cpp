#include "element_buffer.h"

ElementBuffer::ElementBuffer(unsigned int * data, unsigned int number)
	:m_VertexNumber(number)
{
	glGenBuffers(1, &m_EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_VertexNumber*sizeof(unsigned int), data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

ElementBuffer::~ElementBuffer()
{
	glDeleteBuffers(1, &m_EBO);
}

void ElementBuffer::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
}

void ElementBuffer::unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
