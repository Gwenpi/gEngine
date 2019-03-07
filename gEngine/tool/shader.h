#pragma once
#include"../maths/maths.h"
#include<GL\glew.h>
#include<unordered_map>

class Shader
{
private:
	unsigned int m_ProgramID;
	//std::unordered_map<const char*, int>m_UniformLocationCache;
public:
	Shader();
	Shader(const char* vertexPath, const char* fragmentPath,const char* geometryPath=nullptr);//以后应该会用到几何着色器
	~Shader();

	Shader& use();

	void setUniform1i(const char* name, int value);
	void setUniform1f(const char* name, float v0);
	void setUniform2f(const char* name, float v0, float v1);
	void setUniform2f(const char* name, const vec2& v2);
	void setUniform3f(const char* name, float v0, float v1, float v2);
	void setUniform3f(const char* name, const vec3& v3);
	void setUniform4f(const char* name, float v0, float v1, float v2, float v3);
	void setUniform4f(const char* name, const vec4& v4);

	//......马上写
	void setUniformMatrix4(const char* name, const mat4& m4);
	

private:
	void init(const char* vertexPath, const char* fragmentPath, const char* geometryPath);
	//int getUniformLocation(const char* name);//在map中存入和检索，对于uniform变量较少的shader来说性能似乎很烂

};

