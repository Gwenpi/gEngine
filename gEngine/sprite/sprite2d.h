#pragma once

#include"../texture/texture2d.h"
#include"../physical/model/circleModel.h"
#include"../tool/tool_macro.h"
#include"../resourceManagement/resourceManagement.h"

class Sprite2D
{
protected:
	BasicModel m_BasicModel;
	Texture2D* m_Texture;
	vec4 m_Color;
public:
	Sprite2D(const vec2& position=vec2(SCREEN_WIDTH/2.0,SCREEN_HEIGHT/2.0), const char* name = "none");
	inline const vec2& getPosition()const { return m_BasicModel.position; }
	inline const vec2& getVelocity()const { return m_BasicModel.velocity; }
	inline const vec2& getAcceleration()const { return m_BasicModel.acceleration; }
	inline float getMass()const { return 1.0 / m_BasicModel.inverseMass; }
	inline float getDensity()const { return m_BasicModel.density; }
	inline int getId()const { return m_BasicModel.id; }
	inline Texture2D* getTexture()const { return m_Texture; }
	inline const vec4& getColor()const { return m_Color; }
	inline Type getType()const { return m_BasicModel.type; }

	inline void changePosition(float x, float y) {
		m_BasicModel.position.mx = x;m_BasicModel.position
			.my = y;
	}
	inline vec2& changePosition() { return m_BasicModel.position; }
	inline vec2& changeVelocity() { return m_BasicModel.velocity; }
	inline vec2& changeAcceleration() { return m_BasicModel.acceleration; }
	inline float& changeInverseMass() { return m_BasicModel.inverseMass; }
	inline float& changeDensity() { return m_BasicModel.density; }
	inline int& changeId() { return m_BasicModel.id; }
	inline vec4& changeColor() { return m_Color; }
	inline Type& changeType() { return m_BasicModel.type; }

	virtual vec2 getSize()const = 0;
	virtual bool collisionHanding(Sprite2D* target) = 0;
	virtual void update(float duration) = 0;
	//circle
	inline virtual float getRadius()const = 0 { return 0.0f; }

};

