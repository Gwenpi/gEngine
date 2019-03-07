#include "resourceManagement.h"
#include"../tool/tool_macro.h"

map<const char*, Shader*> ResourceManagement::m_Shaders;
map<const char*, Texture2D*> ResourceManagement::m_Textures;

void ResourceManagement::loadShader(const char * vertexShaderPath, const char * fragmentShaderPath, const char * name, const char* geometry)
{
	m_Shaders[name] = new Shader(vertexShaderPath, fragmentShaderPath,geometry);
}

void ResourceManagement::loadTexture(const char * texturePath, const char * name)
{
	m_Textures[name] = new Texture2D(texturePath);
}

Shader* ResourceManagement::getShader(const char * name)
{
	return m_Shaders[name];
}

Texture2D* ResourceManagement::getTexture(const char * name)
{
	return m_Textures[name];
}

void ResourceManagement::clear()
{
	m_Shaders.clear();
	m_Textures.clear();
}

ResourceManagement::ResourceManagement()
{
}

void ResourceManagement::init()
{
	//Shaders
		//basic
	loadShader("shaders/basic.vert", "shaders/basic.frag", "basic_shader");
	m_Shaders["basic_shader"]->use();
	m_Shaders["basic_shader"]->setUniformMatrix4("projection_matrix", mat4::orthographic(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, -1, 1));
		//texture2d
	loadShader("shaders/texture2d.vert", "shaders/texture2d.frag", "texture2d_shader");
	m_Shaders["texture2d_shader"]->use();
	m_Shaders["texture2d_shader"]->setUniformMatrix4("projection_matrix", mat4::orthographic(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, -1, 1));
	m_Shaders["texture2d_shader"]->setUniform1i("Texture1", 0);
		//line
	loadShader("shaders/line.vert", "shaders/line.frag", "line_shader","shaders/line.geom");
	m_Shaders["line_shader"]->use();
	m_Shaders["line_shader"]->setUniformMatrix4("projection_matrix", mat4::orthographic(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, -1, 1));
	m_Shaders["line_shader"]->setUniform4f("color", vec4(0.8, 0.2, 0.2, 0.8f));

	//Textuers
	loadTexture("Textures/circle.png", "circle");
	loadTexture("Textures/messi.png", "messi");
}

ResourceManagement::~ResourceManagement()
{
}

