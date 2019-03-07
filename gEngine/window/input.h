#pragma once
#include<iostream>
#include"../sprite/sprite2d.h"
using namespace std;

const unsigned int BUTTON_MAX = 1024;//GLFW中的鼠标与键盘的按键宏定义不重复

enum buttonState {  PRESS, RELEASE, REPEAT };


class Input
{
private:
	static buttonState m_Buttons[BUTTON_MAX];//改进 int -1释放 0按压 1持续按住
	static double m_x;
	static double m_y;
	static Sprite2D* m_SpriteSelete;
public:
	Input();
	~Input();
	static inline void resetSpriteSelete() { m_SpriteSelete = nullptr; }
	static inline Sprite2D* getSpriteSelete() { return m_SpriteSelete; }
	static void setSpriteSelete(Sprite2D* sprite);
	static void updateCursorPos(double x, double y);
	static void updateButton(int button,buttonState action);
	static void getCursorPos(int& x, int& y);
	static inline const vec2 getCursorPos() { return vec2(m_x, m_y); }
	static inline const double getCursorX() { return m_x; }
	static inline const double getCursorY() { return m_y; }

	static inline bool buttonIsPress(int button) {return m_Buttons[button]== PRESS; }
	static inline bool buttonIsRelease(int button) { return m_Buttons[button] == RELEASE; }
	static inline bool buttonIsHeld(int button) { return m_Buttons[button] == REPEAT; }
	static bool mouseButtonIsPress(int button);
	static bool mouseButtonIsHeld(int button);
	static bool mouseButtonIsRelease(int button);

	static buttonState getButtonState(int button);

	static void init();
};