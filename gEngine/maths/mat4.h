#pragma once

#include<iostream>
#include<memory>
#include"vec4.h"
#include"vec3.h"

float toRadian(float angle);

struct mat4
{
	float elements[4 * 4];
	mat4(float num=0.0);


	//矩阵与标量
	void operator+=(const float& right);
	friend const mat4 operator+(const float& left, const mat4& right);
	friend const mat4 operator+(const mat4& left, const float& right);
	void operator-=(const float& right);
	//friend const mat4 operator-(const float& left, const mat4& right);
	friend const mat4 operator-(const mat4& left, const float& right);
	void operator*=(const float& right);
	friend const mat4 operator*(const float& left, const mat4& right);
	friend const mat4 operator*(const mat4& left, const float& right);

	//矩阵与向量
	const vec4 operator*(const vec4& vector4);

	//矩阵与矩阵
	void operator+=(const mat4& right);
	friend const mat4 operator+(const mat4& left, const mat4& right);
	void operator-=(const mat4& right);
	friend const mat4 operator-(const mat4& left, const mat4& right);
	void operator*=(const mat4& right);
	friend const mat4 operator*(const mat4& left, const mat4& right);
	
	//一些有用的矩阵
	static mat4 scale(const vec3& scale);
	static mat4 translation(const vec3& translation);
	static mat4 rotation(float angle, const vec3& rotation);
	static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);


	//输出
	friend std::ostream& operator<<(std::ostream& os, const mat4& matrix);
};
