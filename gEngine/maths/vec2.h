#pragma once

#include<iostream>
#include<math.h>

struct vec2
{
	float mx, my;
	vec2() :mx(0), my(0) {}
	vec2(float x, float y) :mx(x), my(y) {}
	vec2(float all) :mx(all), my(all) {}
	
	void operator+=(const vec2& right);
	friend const vec2 operator+(const vec2& left, const vec2& right);

	void operator-=(const vec2& right);
	friend const vec2 operator-(const vec2& left, const vec2& right);

	void operator*=(const vec2& right);
	friend const vec2 operator*(const vec2& left, const vec2& right);
	const vec2 operator*(float value);
	friend const vec2 operator*(float leftV, vec2& right);

	void operator/=(const vec2& right);
	friend const vec2 operator/(const vec2& left, const vec2& right);

	friend const vec2 operator-(const vec2& other);
	friend bool operator==(const vec2& left, const vec2& right);

	float dotProduct(const vec2& right)const;//点积
	float crossProduct(const vec2& right)const;//叉积
	float getLength()const;//长度
	float getNotSqrtLength()const;//未开放的长度（sqrt()操作不如平方的效率高）
	float getLength_XIsPositive()const;//以X为正方向的Length
	float getLength_YIsPositive()const;//以Y为正方向的Length
	vec2 getNormalize()const;//标准化
	vec2 clockwiseRotat90()const;//顺时针旋转90度(以后必要时会建一个mat2)

	friend std::ostream& operator<<(std::ostream& os, const vec2& right);
};