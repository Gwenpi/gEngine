#include "collisionDetection.h"

bool CollisionDetection::Circle_Circle(const vec2 & center1, float raduis1, const vec2 & center2, float raduis2)
{
	if ((raduis1 + raduis2)*(raduis1 + raduis2) > (center1.mx - center2.mx)*(center1.mx - center2.mx) + (center1.my - center2.my)*(center1.my - center2.my))
		return true;
	return false;
}
