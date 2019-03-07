#pragma once



#include<iostream>
#include<math.h>
#include"vec2.h"

struct vec3
{
	float mx, my, mz;
	vec3() :mx(0), my(0), mz(0) {}
	vec3(float x, float y, float z) :mx(x), my(y), mz(z) {}
	vec3(float all) :mx(all), my(all), mz(all) {}
	vec3(const vec2& v2) :mx(v2.mx), my(v2.my), mz(0) {}

	void operator+=(const vec3& right);
	friend const vec3 operator+(const vec3& left, const vec3& right);

	void operator-=(const vec3& right);
	friend const vec3 operator-(const vec3& left, const vec3& right);

	void operator*=(const vec3& right);
	friend const vec3 operator*(const vec3& left, const vec3& right);

	void operator/=(const vec3& right);
	friend const vec3 operator/(const vec3& left, const vec3& right);

	friend const vec3 operator-(const vec3& other);


	float dotProduct(const vec3& right)const;//点积
	float getLength()const;//长度
	vec3 getNormalize()const;//标准化
	//叉乘（留着）

	friend std::ostream& operator<<(std::ostream& os, const vec3& right);
};
