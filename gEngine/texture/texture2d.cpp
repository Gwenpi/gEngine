#include "texture2d.h"
#include<iostream>

Texture2D::Texture2D(const char* filePath)
{
	stbi_set_flip_vertically_on_load(true);
	glGenTextures(1, &m_TextureID);
	glBindTexture(GL_TEXTURE_2D, m_TextureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	
	int width, height, nrChannels;

	//m_Buffer = stbi_load(filePath, &m_Width, &m_Height, &m_NrChannels, 0);
	//m_Buffer = stbi_load(filePath, &width, &height, &nrChannels, 0);
	unsigned char* buffer = stbi_load(filePath, &width, &height, &nrChannels, 0);
	GLint format;
	/*
	if (m_NrChannels == 1)
		format = GL_RED;
	else if (m_NrChannels == 3)
		format = GL_RGB;
	else if (m_NrChannels == 4)
		format = GL_RGBA;
	else
		format = GL_RGBA;
	*/
	if (nrChannels == 1)
		format = GL_RED;
	else if (nrChannels == 3)
		format = GL_RGB;
	else if (nrChannels == 4)
		format = GL_RGBA;
	else
		format = GL_RGBA;
	/*
	if (m_Buffer)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, format, m_Width, m_Height, 0, format, GL_UNSIGNED_BYTE, m_Buffer);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	*/
	if (buffer)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, buffer);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "载入纹理失败: " << filePath << std::endl;
	}
	stbi_image_free(buffer);
}

Texture2D::~Texture2D()
{
	glDeleteTextures(1, &m_TextureID);
}

void Texture2D::bind(unsigned int unit) const
{
	if (unit < 32)
	{
		glActiveTexture(GL_TEXTURE0 + unit);
		glBindTexture(GL_TEXTURE_2D, m_TextureID);
	}
	else
		std::cout << "超出纹理单元范围：" << unit << std::endl;
}

void Texture2D::unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
