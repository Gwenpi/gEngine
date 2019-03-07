#include "vec2.h"

const float precision = 0.01;

const vec2 operator+(const vec2 & left, const vec2 & right)
{
	return vec2(left.mx + right.mx, left.my + right.my);
}

const vec2 operator-(const vec2 & left, const vec2 & right)
{
	return vec2(left.mx - right.mx, left.my - right.my);
}

const vec2 operator*(const vec2 & left, const vec2 & right)
{
	return vec2(left.mx * right.mx, left.my * right.my);
}

const vec2 operator*(float leftV, vec2 & right)
{
	return right.operator*(leftV);
}

const vec2 operator/(const vec2 & left, const vec2 & right)
{
	return vec2(left.mx / right.mx, left.my / right.my);
}

const vec2 operator-(const vec2 & other)
{
	vec2 result(-other.mx, -other.my);
	return result;
}

bool operator==(const vec2 & left, const vec2 & right)
{
	//用一个 精度值 更加实用高效
	if ((right.mx - precision <= left.mx&&left.mx <= right.mx + precision) && (right.my - precision <= left.my&&left.my <= right.my + precision))
		return true;
	//if (int(left.mx) == int(right.mx) && int(left.my) == int(right.my))
	//	return true;
	//if (left.mx == right.mx&&left.my== right.my)//mark在旋转操作中会丧失精度,以上是两种解决方案感觉都不怎么好（如果可以从旋转中解决就好了）
	//	return true;
	return false;
}

std::ostream & operator<<(std::ostream & os, const vec2 & right)
{
	os << "x: " << right.mx << " y: " << right.my << std::endl;
	return os;
}

void vec2::operator+=(const vec2 & right)
{
	this->mx += right.mx;
	this->my += right.my;
}

void vec2::operator-=(const vec2 & right)
{
	this->mx -= right.mx;
	this->my -= right.my;
}

void vec2::operator*=(const vec2 & right)
{
	this->mx *= right.mx;
	this->my *= right.my;
}

const vec2 vec2::operator*(float value)
{
	return vec2(mx*value,my*value);
}

void vec2::operator/=(const vec2 & right)
{
	this->mx /= right.mx;
	this->my /= right.my;
}



float vec2::dotProduct(const vec2 & right) const
{
	return (this->mx  * right.mx  + this->my  * right.my );
}

float vec2::crossProduct(const vec2 & right) const
{
	return mx * right.my - my * right.mx;
}


float vec2::getLength() const
{
	return sqrt(mx*mx + my * my);
}

float vec2::getNotSqrtLength() const
{
	return mx * mx + my * my;
}

float vec2::getLength_XIsPositive() const
{
	if(mx<0)
		return -sqrt(mx*mx + my * my);
	return sqrt(mx*mx + my * my);
}

float vec2::getLength_YIsPositive() const
{
	if (my < 0)
		return -sqrt(mx*mx + my * my);
	return sqrt(mx*mx + my * my);
}

vec2 vec2::getNormalize() const
{
	float len = getLength();
	if (len == 0.0f)
		return vec2(0.0f);
	return vec2(mx / len, my / len);
}

vec2 vec2::clockwiseRotat90() const
{
	vec2 result;
	result.mx = this->my;
	result.my = -this->mx;
	return result;
}
