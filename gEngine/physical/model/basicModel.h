#pragma once

#include"../../maths/maths.h"

enum Type
{
	INTANGIBLE,
	CIRCULAR,
	RECTANGULAR,
	CONVEX_POLYGON
};

struct BasicModel
{
	vec2 position;
	vec2 velocity;
	vec2 acceleration;

	float inverseMass;
	float density;

	Type type;

	int id;
	BasicModel(const vec2& p = vec2(0.0f), const vec2& v = vec2(0.0f), const vec2& a=vec2(0.0f),float im=1.0f,float d=1.0f,int i=0,Type t= INTANGIBLE)
		:position(p),velocity(v),acceleration(a),inverseMass(im),density(d),id(i),type(t)
	{
	}
};