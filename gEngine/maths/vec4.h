#pragma once


#include<iostream>

struct vec4
{
	float mx, my, mz, mw;
	vec4() :mx(0), my(0), mz(0), mw(0) {}
	vec4(float x, float y, float z, float w) :mx(x), my(y), mz(z), mw(w) {}
	vec4(float all) :mx(all), my(all), mz(all), mw(all) {}

	void operator+=(const vec4& right);
	friend const vec4 operator+(const vec4& left, const vec4& right);

	void operator-=(const vec4& right);
	friend const vec4 operator-(const vec4& left, const vec4& right);

	void operator*=(const vec4& right);
	friend const vec4 operator*(const vec4& left, const vec4& right);

	void operator/=(const vec4& right);
	friend const vec4 operator/(const vec4& left, const vec4& right);

	friend std::ostream& operator<<(std::ostream& os, const vec4& right);

	float getIndex(int i)const;
	float& getIndex(int i);
};
