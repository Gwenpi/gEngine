#include "vec4.h"

const vec4 operator+(const vec4 & left, const vec4 & right)
{
	return vec4(left.mx + right.mx, left.my + right.my, left.mz + right.mz, left.mw + right.mw);
}

const vec4 operator-(const vec4 & left, const vec4 & right)
{
	return vec4(left.mx - right.mx, left.my - right.my, left.mz - right.mz, left.mw - right.mw);
}

const vec4 operator*(const vec4 & left, const vec4 & right)
{
	return vec4(left.mx * right.mx, left.my * right.my, left.mz * right.mz, left.mw * right.mw);
}

const vec4 operator/(const vec4 & left, const vec4 & right)
{
	return vec4(left.mx / right.mx, left.my / right.my, left.mz / right.mz, left.mw / right.mw);
}

std::ostream & operator<<(std::ostream & os, const vec4 & right)
{
	os << "x: " << right.mx << " y: " << right.my << " z: " << right.mz << " w: " << right.mw << std::endl;
	return os;
}

void vec4::operator+=(const vec4 & right)
{
	this->mx += right.mx;
	this->my += right.my;
	this->mz += right.mz;
	this->mw += right.mw;
}

void vec4::operator-=(const vec4 & right)
{
	this->mx -= right.mx;
	this->my -= right.my;
	this->mz -= right.mz;
	this->mw -= right.mw;
}

void vec4::operator*=(const vec4 & right)
{
	this->mx *= right.mx;
	this->my *= right.my;
	this->mz *= right.mz;
	this->mw *= right.mw;
}

void vec4::operator/=(const vec4 & right)
{
	this->mx /= right.mx;
	this->my /= right.my;
	this->mz /= right.mz;
	this->mw /= right.mw;
}

float vec4::getIndex(int i)const
{
	switch (i)
	{
	case 0:return mx;break;
	case 1:return my;break;
	case 2:return mz;break;
	case 3:return mw;break;
	default: return -1.0f;break;
	}
}

float & vec4::getIndex(int i)
{
	switch (i)
	{
	case 0:return mx;break;
	case 1:return my;break;
	case 2:return mz;break;
	case 3:return mw;break;
	}
}
