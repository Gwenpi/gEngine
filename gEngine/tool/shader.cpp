#include "shader.h"

#include"read_file.h"


Shader::Shader()
{
}

Shader::Shader(const char * vertexPath, const char * fragmentPath, const char* geometryPath)
{
	init(vertexPath, fragmentPath,geometryPath);
}


Shader::~Shader()
{
	glDeleteProgram(m_ProgramID);
}

Shader& Shader::use()
{
	glUseProgram(m_ProgramID);
	return *this;
}

void Shader::setUniform1i(const char * name, int value)
{
	glUniform1i(glGetUniformLocation(m_ProgramID,name), value);
}

void Shader::setUniform1f(const char * name, float v0) 
{
	glUniform1f(glGetUniformLocation(m_ProgramID,name), v0);
}

void Shader::setUniform2f(const char * name, float v0, float v1) 
{
	glUniform2f(glGetUniformLocation(m_ProgramID,name), v0, v1);
}

void Shader::setUniform2f(const char * name, const vec2 & v2) 
{
	glUniform2f(glGetUniformLocation(m_ProgramID,name), v2.mx, v2.my);
}

void Shader::setUniform3f(const char * name, float v0, float v1, float v2) 
{
	glUniform3f(glGetUniformLocation(m_ProgramID,name), v0, v1, v2);
}

void Shader::setUniform3f(const char * name, const vec3 & v3) 
{
	glUniform3f(glGetUniformLocation(m_ProgramID,name), v3.mx, v3.my, v3.mz);
}

void Shader::setUniform4f(const char * name, float v0, float v1, float v2, float v3) 
{
	glUniform4f(glGetUniformLocation(m_ProgramID,name), v0, v1, v2, v3);
}

void Shader::setUniform4f(const char * name, const vec4 & v4) 
{
	glUniform4f(glGetUniformLocation(m_ProgramID,name), v4.mx, v4.my, v4.mz, v4.mw);
}

void Shader::setUniformMatrix4(const char * name, const mat4 & m4)
{
	glUniformMatrix4fv(glGetUniformLocation(m_ProgramID,name), 1,GL_FALSE, m4.elements);
}

void Shader::init(const char * vertexPath, const char * fragmentPath, const char* geometryPath)
{
	m_ProgramID = glCreateProgram();

	int success;
	char infoLog[1024];

	//Vertex
	unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
	std::string vectexStringCode = readFile(vertexPath);
	const char* vectexCode = vectexStringCode.c_str();
	glShaderSource(vertex, 1, &vectexCode, NULL);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (success!= GL_TRUE)
	{
		glGetShaderInfoLog(vertex, 1024, NULL, infoLog);
		std::cout << "¶¥µã×ÅÉ«Æ÷ ±àÒë´íÎó :" << infoLog << std::endl;
	}

	//Fragment
	unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
	std::string fragmentStringCode = readFile(fragmentPath);
	const char* fragmentCode = fragmentStringCode.c_str();
	glShaderSource(fragment, 1, &fragmentCode, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (success != GL_TRUE)
	{
		glGetShaderInfoLog(fragment, 1024, NULL, infoLog);
		std::cout << "Æ¬¶Î×ÅÉ«Æ÷ ±àÒë´íÎó :" << infoLog << std::endl;
	}
	//Geometry
	unsigned int geometry = 5;//Ëæ»ú³õÖµ
	if (geometryPath != nullptr)
	{
		geometry = glCreateShader(GL_GEOMETRY_SHADER);
		std::string geometryStringCode = readFile(geometryPath);
		const char* geometryCode = geometryStringCode.c_str();
		glShaderSource(geometry, 1, &geometryCode, NULL);
		glCompileShader(geometry);
		glGetShaderiv(geometry, GL_COMPILE_STATUS, &success);
		if (success != GL_TRUE)
		{
			glGetShaderInfoLog(geometry, 1024, NULL, infoLog);
			std::cout << "¼¸ºÎ×ÅÉ«Æ÷ ±àÒë´íÎó :" << infoLog << std::endl;
		}
	}
	
	//ShaderProgram
	glAttachShader(m_ProgramID, vertex);
	glAttachShader(m_ProgramID, fragment);
	if (geometryPath != nullptr)
	{
		glAttachShader(m_ProgramID, geometry);
	}
	glLinkProgram(m_ProgramID);
	glGetProgramiv(m_ProgramID, GL_LINK_STATUS, &success);
	if (success != GL_TRUE)
	{
		glGetProgramInfoLog(m_ProgramID, 1024, NULL, infoLog);
		std::cout << "×ÅÉ«Æ÷³ÌÐò Á´½Ó´íÎó :" << infoLog << std::endl;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);
	if (geometryPath != nullptr)
	{
		glDeleteShader(geometry);
	}
}
/*
int Shader::getUniformLocation(const char * name)
{
	if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
		return m_UniformLocationCache[name];
	int location = glGetUniformLocation(m_ProgramID,name);
	if (location == -1)
		std::cout << "uniform: " << name << " ²»´æÔÚ " << std::endl;
	m_UniformLocationCache[name] = location;
	return location;
}
*/
