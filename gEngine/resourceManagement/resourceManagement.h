#pragma once

#include"../tool/shader.h"
#include"../texture/texture2d.h"

#include<map>
#include<string>

using std::string;
using std::map;

class ResourceManagement
{
public:
	static map<const char*, Shader*>m_Shaders;
	static map<const char*, Texture2D*>m_Textures;
public:
	static void loadShader(const char* vertexShaderPath, const char* fragmentShaderPath, const char* name,const char* geometry=nullptr);
	static void loadTexture(const char* texturePath, const char* name);
	static Shader* getShader(const char* name);
	static Texture2D* getTexture(const char* name);
	static void clear();
	static void init();
	~ResourceManagement();
private:
	ResourceManagement();
};