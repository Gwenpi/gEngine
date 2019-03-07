#include "sprite2d.h"

Sprite2D::Sprite2D(const vec2& position, const char* name)
	:m_BasicModel(position), m_Texture(ResourceManagement::getTexture(name))
{
	m_Color = vec4(1.0f,1.0f,1.0f,1.0f);
}
