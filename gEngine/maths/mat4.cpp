#include "mat4.h"

float toRadian(float angle)
{
	return angle * 3.1415926 / 180;
}

mat4::mat4(float num)
{
	for (int i = 0;i < 16;i++)
	{
		elements[i] = 0;
	}
	elements[0 + 0 * 4] = num;
	elements[1 + 1 * 4] = num;
	elements[2 + 2 * 4] = num;
	elements[3 + 3 * 4] = num;
}

void mat4::operator+=(const float & right)
{
	for (int i = 0;i < 16;i++)
	{
		elements[i] += right;
	}
}

void mat4::operator-=(const float & right)
{
	for (int i = 0;i < 16;i++)
	{
		elements[i] -= right;
	}
}

void mat4::operator*=(const float & right)
{
	for (int i = 0;i < 16;i++)
	{
		elements[i] *= right;
	}
}



const vec4 mat4::operator*(const vec4 & vector4)
{
	vec4 result;
	for (int i = 0;i < 4;i++)
	{
		float sum = 0.0f;
		for (int j = 0;j < 4;j++)
		{
			sum += elements[j * 4 + i] * vector4.getIndex(j);
		}
		result.getIndex(i) = sum;
	}
	return result;
}

void mat4::operator+=(const mat4 & right)
{
	for (int i = 0;i < 16;i++)
	{
		elements[i] += right.elements[i];
	}
}

void mat4::operator-=(const mat4 & right)
{
	for (int i = 0;i < 16;i++)
	{
		elements[i] -= right.elements[i];
	}
}

void mat4::operator*=(const mat4 & right)
{
	float result[16];
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			float sum = 0.0f;
			for (int k = 0;k < 4;k++)
			{
				//OpenGL是列主序，所以数据进入GLSL时，是以列填充的方式依次填充（猜测）
				//所以两个列主序的矩阵不能用线性代数一样的“行乘列”的方式进行计算，应该按照“列
				//乘行”的方式计算，这样才能得到正确的答案
				sum += elements[k * 4 + i] * right.elements[j * 4 + k];
				//sum += elements[i * 4 + k] * right.elements[k * 4 + j];
			}
			result[j * 4 + i] = sum;//最后要将正确的答案 按列排序的顺序放入数组（即列*行  放入 列）
		}
	}
	memcpy(elements, result, 16 * sizeof(float));
}

mat4 mat4::scale(const vec3 & scale)
{
	mat4 result(1.0f);
	result.elements[0 + 0 * 4] = scale.mx;
	result.elements[1 + 1 * 4] = scale.my;
	result.elements[2 + 2 * 4] = scale.mz;

	return result;
}

mat4 mat4::translation(const vec3 & translation)
{
	mat4 result(1.0f);
	result.elements[0 + 3 * 4] = translation.mx;
	result.elements[1 + 3 * 4] = translation.my;
	result.elements[2 + 3 * 4] = translation.mz;

	return result;
}

mat4 mat4::rotation(float angle,const vec3 & rotation)
{
	mat4 result(1.0f);
	float Cos = cos(toRadian(angle));
	float Sin = sin(toRadian(angle));
	//行排序的第一行 即 列排序的第一列
	result.elements[0 + 0 * 4] = Cos + rotation.mx*rotation.mx*(1 - Cos);
	result.elements[0 + 1 * 4] = rotation.mx*rotation.my*(1 - Cos) - rotation.mz*Sin;
	result.elements[0 + 2 * 4] = rotation.mx*rotation.mz*(1 - Cos) + rotation.my*Sin;

	result.elements[1 + 0 * 4] = rotation.my*rotation.mx*(1 - Cos) + rotation.mz*Sin;
	result.elements[1 + 1 * 4] = Cos + rotation.my*rotation.my*(1 - Cos);
	result.elements[1 + 2 * 4] = rotation.my*rotation.mz*(1 - Cos) - rotation.mx*Sin;

	result.elements[2 + 0 * 4] = rotation.mz*rotation.mx*(1 - Cos) - rotation.my*Sin;
	result.elements[2 + 1 * 4] = rotation.mz*rotation.my*(1 - Cos) + rotation.mx*Sin;
	result.elements[2 + 2 * 4] = Cos + rotation.mz*rotation.mz*(1 - Cos);

	return result;
}

mat4 mat4::orthographic(float left, float right, float bottom, float top, float near, float far)
{
	mat4 result(1.0);

	result.elements[0 + 0 * 4] = 2.0f / (right - left);
	result.elements[0 + 3 * 4] = -(right + left) / (right - left);

	result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
	result.elements[1 + 3 * 4] = -(top + bottom) / (top- bottom);

	result.elements[2 + 2 * 4] = -2.0f / (far - near);
	result.elements[2 + 3 * 4] = -(far + near) / (far - near);
	return result;
}



const mat4 operator+(const float & left,const mat4 & right)
{
	mat4 result = right;
	result += left;
	return result;
}

const mat4 operator+(const mat4 & left, const float & right)
{
	return right+left;
}


const mat4 operator-(const mat4 & left, const float & right)
{
	mat4 result = left;
	result -= right;
	return result;
}

const mat4 operator*(const float & left, const mat4 & right)
{
	mat4 result = right;
	result *= left;
	return result;
}

const mat4 operator*(const mat4 & left, const float & right)
{
	return right * left;
}




const mat4 operator+(const mat4 & left, const mat4 & right)
{
	mat4 result;
	for (int i = 0;i < 16;i++)
	{
		result.elements[i] = left.elements[i] + right.elements[i];
	}
	return result;
}

const mat4 operator-(const mat4 & left, const mat4 & right)
{
	mat4 result;
	for (int i = 0;i < 16;i++)
	{
		result.elements[i] = left.elements[i] - right.elements[i];
	}
	return result;
}

const mat4 operator*(const mat4 & left, const mat4 & right)
{
	mat4 result;
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			float sum = 0.0f;
			for (int k = 0;k < 4;k++)
			{
				sum += left.elements[k * 4 + i] * right.elements[j * 4 + k];
			}
			result.elements[j * 4 + i] = sum;
		}
	}
	return result;
}



std::ostream & operator<<(std::ostream & os, const mat4 & matrix)
{
	//
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			os << matrix.elements[i*4+j] << " ";
		}
		os << std::endl;
	}
	return os;
}
