#include "vertex_array.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_VAO);
}

VertexArray::~VertexArray()
{
	for (int i = 0;i < m_VBOs.size();i++)
	{
		delete m_VBOs[i];
	}
	glDeleteVertexArrays(1, &m_VAO);
}

void VertexArray::bind() const
{
	glBindVertexArray(m_VAO);
}

void VertexArray::unbind() const
{
	glBindVertexArray(0);
}

void VertexArray::addVBO(VertexBuffer* vbo,unsigned int index, int size, unsigned int stride, int initialPosition)
{
	m_VBOs.push_back(vbo);
	bind();
	vbo->bind();
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(initialPosition * sizeof(float)));
	vbo->unbind();
	unbind();
}

void VertexArray::addVBO(VertexBuffer * vbo, BufferLayout * layout)
{
	m_VBOs.push_back(vbo);
	bind();
	vbo->bind();
	unsigned int offset = 0;
	for (int i = 0;i < layout->getLayouts().size();i++)
	{
		BufferElement element = layout->getLayouts().at(i);
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.count, element.type, element.isNormalize, layout->getStride(), (const void*)offset);
		offset += element.count*BufferElement::getSizeOfType(element.type);
	}
	vbo->unbind();
	unbind();
}
