#pragma once
#include"basicModel.h"

struct CircleModel
{
	BasicModel basicModel;
	float radius;
	CircleModel()
	{
		radius = 0.0f;
	}
};
