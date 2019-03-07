#include "circleSprite.h"
#include"../resourceManagement/resourceManagement.h"
#include"../physical/collisionDetection/collisionDetection.h"
#include"../window/input.h"
#include<GLFW\glfw3.h>

CircleSprite::CircleSprite(const vec2 & position, float radius, const char * textureName)
	:m_Radius(radius),Sprite2D(position, textureName)
{
	m_BasicModel.type = CIRCULAR;
}

CircleSprite::~CircleSprite()
{
}

vec2 CircleSprite::getSize() const
{
	return vec2(m_Radius);
}

bool CircleSprite::collisionHanding( Sprite2D* target)
{
	if (CollisionDetection::Circle_Circle(this->getPosition(), this->getRadius(), target->getPosition(), target->getRadius()))
	{
		//����Բ֮��ľ���
		float distance = sqrtf((this->getPosition().mx - target->getPosition().mx)*
			(this->getPosition().mx - target->getPosition().mx) +
			(this->getPosition().my - target->getPosition().my)*
			(this->getPosition().my - target->getPosition().my));
		//һ��������������
		//static collision
		float overlap = 0.5f*(this->getRadius() + target->getRadius() - distance);

		//����Բ����Ҫ���˵ľ���
		this->changePosition().mx += overlap * (this->getPosition().mx - target->getPosition().mx) / distance;
		this->changePosition().my += overlap * (this->getPosition().my - target->getPosition().my) / distance;

		target->changePosition().mx += overlap * (target->getPosition().mx - this->getPosition().mx) / distance;
		target->changePosition().my += overlap * (target->getPosition().my - this->getPosition().my) / distance;

		//������������
		//dynamic collsion
		//������������ԲԲ�ĵľ���
		distance = sqrtf((this->getPosition().mx - target->getPosition().mx)*
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

		//dot product tangent(����ٶ������߷����ͶӰ����)
		float dpTan1 = this->getVelocity().dotProduct(normalTangent);
		float dpTan2 = target->getVelocity().dotProduct(normalTangent);

		//������Բ��֮��ĵ�λ����*�ٶȣ���ʾ�ٶ�����ײ�켣�ĳ��ȼ�������������ײʱ����ײ�����ṩ���ٶȣ�
		float dpNorm1 = this->getVelocity().dotProduct(vec2(nx, ny));
		float dpNorm2 = target->getVelocity().dotProduct(vec2(nx, ny));
		//�ö����غ������ײ����ٶ�
		float v1 = (dpNorm1 * (this->getMass() - target->getMass()) + 2 * target->getMass()*dpNorm2) / (this->getMass() + target->getMass());
		float v2 = (dpNorm2 * (target->getMass() - this->getMass()) + 2 * this->getMass()*dpNorm1) / (this->getMass() + target->getMass());


		//change velocity direction�����ٶ���ͶӰ����ĳ���*���ߵĵ�λ����=�ٶ������߷����ϵ�������
		//���ö����غ㶨�ɼ�����ٶ�������ײ�����
		//���Խ�����������ӣ�����ĺ��ٶ������յķ����ٶ�
		this->changeVelocity() = vec2(tx*dpTan1 + nx * v1, ty*dpTan1 + ny * v1);
		target->changeVelocity() = vec2(tx*dpTan2 + nx * v2, ty*dpTan2 + ny * v2);

		return true;
	}
	return false;
}

void CircleSprite::update(float duration)
{
	m_BasicModel.velocity += m_BasicModel.acceleration*duration;
	m_BasicModel.position += m_BasicModel.velocity*duration;

	if (fabs(m_BasicModel.velocity.mx*m_BasicModel.velocity.mx + m_BasicModel.velocity.my*m_BasicModel.velocity.my) < 0.01f)
	{
		m_BasicModel.velocity = vec2(0.0f);
	}
}
