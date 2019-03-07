#include "maths_algorithm.h"
#include<iostream>
using namespace std;
vec2 vertexOntoVectorProjection(const vec2& vertex, const vec2& vector)
{
	//vec2 u = vector.getNormalize();//都不变成单位向量（等于大家都变）
	vec2 result = vertex.dotProduct(vector)*vector;
	return result;
}

float absolute(const float & value)
{
	if (value < 0)
		return -value;
	return value;
}
