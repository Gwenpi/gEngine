#include "input.h"


buttonState Input::m_Buttons[BUTTON_MAX];
double Input::m_x;
double Input::m_y;
Sprite2D* Input::m_SpriteSelete;

Input::Input()
{
	init();
}

Input::~Input()
{
}

void Input::setSpriteSelete(Sprite2D * sprite)
{
	m_SpriteSelete = sprite;
}

void Input::updateCursorPos(double x,double y)
{
	m_x = x;
	m_y = y;
}

void Input::updateButton(int button, buttonState action)
{
	m_Buttons[button] = action;
}

void Input::getCursorPos(int & x, int & y)
{
	x = m_x;
	y = m_y;
}

bool Input::mouseButtonIsPress(int button)
{
	return m_Buttons[button] == PRESS;
}

bool Input::mouseButtonIsHeld(int button)
{
	if (m_Buttons[button] == REPEAT)
	{
		return true;
	}
	
	if (m_Buttons[button] == PRESS)
	{
		m_Buttons[button] = REPEAT;
		return true;
	}
	return false;
}

bool Input::mouseButtonIsRelease(int button)
{
	return m_Buttons[button] == RELEASE;
}

buttonState Input::getButtonState(int button)
{
	return m_Buttons[button];
}

void Input::init()
{
	m_SpriteSelete = nullptr;
	for (int i = 0;i < BUTTON_MAX;i++)
		m_Buttons[i] = RELEASE;
}
