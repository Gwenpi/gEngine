#pragma once

#include<GL\glew.h>
#include"stb_image.h"

class Texture2D
{
private:
	unsigned int m_TextureID;
public:
	Texture2D() {}
	Texture2D(const char* filePath);
	~Texture2D();

	void bind(unsigned int unit = 0)const;
	void unbind()const;
};