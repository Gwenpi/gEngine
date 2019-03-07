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

	float dotProduct(const vec2& right)const;//���
	float crossProduct(const vec2& right)const;//���
	float getLength()const;//����
	float getNotSqrtLength()const;//δ���ŵĳ��ȣ�sqrt()��������ƽ����Ч�ʸߣ�
	float getLength_XIsPositive()const;//��XΪ�������Length
	float getLength_YIsPositive()const;//��YΪ�������Length
	vec2 getNormalize()const;//��׼��
	vec2 clockwiseRotat90()const;//˳ʱ����ת90��(�Ժ��Ҫʱ�Ὠһ��mat2)

	friend std::ostream& operator<<(std::ostream& os, const vec2& right);
};