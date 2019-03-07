#include "maths_algorithm.h"
#include<iostream>
using namespace std;
vec2 vertexOntoVectorProjection(const vec2& vertex, const vec2& vector)
{
	//vec2 u = vector.getNormalize();//������ɵ�λ���������ڴ�Ҷ��䣩
	vec2 result = vertex.dotProduct(vector)*vector;
	return result;
}

float absolute(const float & value)
{
	if (value < 0)
		return -value;
	return value;
}
