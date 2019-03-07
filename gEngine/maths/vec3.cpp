#include "vec3.h"

const vec3 operator+(const vec3 & left, const vec3 & right)
{
	return vec3(left.mx + right.mx, left.my + right.my, left.mz + right.mz);
}

const vec3 operator-(const vec3 & left, const vec3 & right)
{
	return vec3(left.mx - right.mx, left.my - right.my, left.mz - right.mz);
}

const vec3 operator*(const vec3 & left, const vec3 & right)
{
	return vec3(left.mx * right.mx, left.my * right.my, left.mz * right.mz);
}

const vec3 operator/(const vec3 & left, const vec3 & right)
{
	return vec3(left.mx / right.mx, left.my / right.my, left.mz / right.mz);
}

const vec3 operator-(const vec3 & other)
{
	vec3 result(-other.mx, -other.my, -other.mz);
	return result;
}

std::ostream & operator<<(std::ostream & os, const vec3 & right)
{
	os << "x: " << right.mx << " y: " << right.my << " z: " << right.mz << std::endl;
	return os;
}

void vec3::operator+=(const vec3 & right)
{
	this->mx += right.mx;
	this->my += right.my;
	this->mz += right.mz;
}

void vec3::operator-=(const vec3 & right)
{
	this->mx -= right.mx;
	this->my -= right.my;
	this->mz -= right.mz;
}

void vec3::operator*=(const vec3 & right)
{
	this->mx *= right.mx;
	this->my *= right.my;
	this->mz *= right.mz;
}

void vec3::operator/=(const vec3 & right)
{
	this->mx /= right.mx;
	this->my /= right.my;
	this->mz /= right.mz;
}

float vec3::dotProduct(const vec3 & right) const
{
	float lengthL = this->getLength();
	float lengthR = this->getLength();
	return (this->mx / lengthL * right.mx / lengthR + this->my / lengthL * right.my / lengthR + this->mz / lengthL * right.mz / lengthR);
}

float vec3::getLength() const
{
	return sqrt(mx*mx + my * my + mz * mz);
}

vec3 vec3::getNormalize() const
{
	float len = getLength();
	return vec3(mx / len, my / len, mz / len);
}
