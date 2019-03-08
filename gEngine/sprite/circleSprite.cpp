#include "circleSprite.h"
#include"../resourceManagement/resourceManagement.h"
#include"../physical/collisionDetection/collisionDetection.h"
#include"../window/input.h"
#include<GLFW\glfw3.h>

CircleSprite::CircleSprite(const vec2 & position, float radius, const char * textureName)
	:Sprite2D(position, textureName), m_Radius(radius)
{
	m_BasicModel.type = CIRCULAR;
	//m=p*V  因为是二维这里就用 m=p*S(密度乘面积)
	m_BasicModel.inverseMass = 1.0f / (m_BasicModel.density*PI*m_Radius*m_Radius);
}

CircleSprite::~CircleSprite()
{
}

vec2 CircleSprite::getSize() const
{
	return vec2(m_Radius);
}

bool CircleSprite::collisionDeetection(Sprite2D* target)
{
	if (CollisionDetection::Circle_Circle(this->getPosition(), this->getRadius(), target->getPosition(), target->getRadius()))
		return true;

	return false;
}

void CircleSprite::staticCollision(Sprite2D * target)
{
	//两个圆之间的距离
	float distance = sqrtf((this->getPosition().mx - target->getPosition().mx)*
		(this->getPosition().mx - target->getPosition().mx) +
		(this->getPosition().my - target->getPosition().my)*
		(this->getPosition().my - target->getPosition().my));
	//一、分离两个物体
	//static collision
	float overlap = 0.5f*(this->getRadius() + target->getRadius() - distance);

	//两个圆各自要回退的距离
	this->changePosition().mx += overlap * (this->getPosition().mx - target->getPosition().mx) / distance;
	this->changePosition().my += overlap * (this->getPosition().my - target->getPosition().my) / distance;

	target->changePosition().mx += overlap * (target->getPosition().mx - this->getPosition().mx) / distance;
	target->changePosition().my += overlap * (target->getPosition().my - this->getPosition().my) / distance;
}

void CircleSprite::dynamicCollision(Sprite2D * target)
{
	//二、反弹处理
		//dynamic collsion
		//计算两个触碰圆圆心的距离
	float distance = sqrtf((this->getPosition().mx - target->getPosition().mx)*
		(this->getPosition().mx - target->getPosition().mx) +
		(this->getPosition().my - target->getPosition().my)*
		(this->getPosition().my - target->getPosition().my));
	//normal
	float nx = (target->getPosition().mx - this->getPosition().mx) / distance;
	float ny = (target->getPosition().my - this->getPosition().my) / distance;

	//tangent
	float tx = -ny;
	float ty = nx;
	vec2 normalTangent = (tx, ty);

	//dot product tangent(获得速度在切线方向的投影长度)
	float dpTan1 = this->getVelocity().dotProduct(normalTangent);
	float dpTan2 = target->getVelocity().dotProduct(normalTangent);

	//用两个圆心之间的单位向量*速度（表示速度在碰撞轨迹的长度即：两个物体碰撞时在碰撞方向提供的速度）
	float dpNorm1 = this->getVelocity().dotProduct(vec2(nx, ny));
	float dpNorm2 = target->getVelocity().dotProduct(vec2(nx, ny));
	//用动量守恒计算碰撞后的速度
	float v1 = (dpNorm1 * (this->getMass() - target->getMass()) + 2 * target->getMass()*dpNorm2) / (this->getMass() + target->getMass());
	float v2 = (dpNorm2 * (target->getMass() - this->getMass()) + 2 * this->getMass()*dpNorm1) / (this->getMass() + target->getMass());


	//change velocity direction（将速度在投影方向的长度*切线的单位向量=速度在切线方向上的向量）
	//而用动量守恒定律计算的速度是沿碰撞方向的
	//所以将两个向量相加，计算的和速度是最终的反弹速度
	this->changeVelocity() = vec2(tx*dpTan1 + nx * v1, ty*dpTan1 + ny * v1);
	target->changeVelocity() = vec2(tx*dpTan2 + nx * v2, ty*dpTan2 + ny * v2);
}

void CircleSprite::update(float duration)
{
	m_BasicModel.oldPosition = m_BasicModel.position;				//记录上移时间段的位置
	m_BasicModel.velocity += m_BasicModel.acceleration*duration;
	m_BasicModel.position += m_BasicModel.velocity*duration;

	if (fabs(m_BasicModel.velocity.mx*m_BasicModel.velocity.mx + m_BasicModel.velocity.my*m_BasicModel.velocity.my) < 0.01f)
	{
		m_BasicModel.velocity = vec2(0.0f);
	}
}
