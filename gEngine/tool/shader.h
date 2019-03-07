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
	Shader(const char* vertexPath, const char* fragmentPath,const char* geometryPath=nullptr);//�Ժ�Ӧ�û��õ�������ɫ��
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

	//......����д
	void setUniformMatrix4(const char* name, const mat4& m4);
	

private:
	void init(const char* vertexPath, const char* fragmentPath, const char* geometryPath);
	//int getUniformLocation(const char* name);//��map�д���ͼ���������uniform�������ٵ�shader��˵�����ƺ�����

};

