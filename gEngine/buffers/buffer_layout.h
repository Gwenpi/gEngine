#pragma once

#include<vector>
#include<GL/glew.h>

struct BufferElement
{
	GLint count;
	GLenum type;
	GLboolean isNormalize;

	static unsigned int getSizeOfType(GLenum type)
	{
		switch (type)
		{
		case GL_FLOAT:return 4;break;
		case GL_UNSIGNED_INT:return 4;break;
		case GL_UNSIGNED_BYTE:return 1;break;
		}
		_ASSERT(false);
		return 0;
	}
};


class BufferLayout
{
private:
	std::vector<BufferElement>m_Layouts;
	unsigned int m_Stride;
public:
	BufferLayout() :m_Stride(0) {}
	

	template<typename T>
	void addBufferLayout(int count)
	{
		static_assert(false);
	}
	template<>
	void addBufferLayout<float>(int count)
	{
		m_Layouts.push_back({ count,GL_FLOAT,GL_FALSE });
		m_Stride += count * BufferElement::getSizeOfType(GL_FLOAT);
	}
	template<>
	void addBufferLayout<unsigned int>(int count)
	{
		m_Layouts.push_back({ count,GL_FLOAT,GL_FALSE });
		m_Stride += count * BufferElement::getSizeOfType(GL_UNSIGNED_INT);
	}
	template<>
	void addBufferLayout<unsigned char>(int count)
	{
		m_Layouts.push_back({ count,GL_FLOAT,GL_FALSE });
		m_Stride += count * BufferElement::getSizeOfType(GL_UNSIGNED_BYTE);
	}

	inline const std::vector<BufferElement>& getLayouts() { return m_Layouts; };
	inline unsigned int getStride() { return m_Stride; }
};