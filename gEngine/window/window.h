#pragma once
#include<GL/glew.h>
#include<GLFW/glfw3.h>


//const unsigned int BUTTON_MAX = 1024;//GLFW中的鼠标与键盘的按键宏定义不重复

class Window
{
private:
	unsigned int m_Width;
	unsigned int m_Height;
	const char* m_Title;
	GLFWwindow* m_Window;
public:
	Window();
	Window(unsigned int widt=0, unsigned int height=0, const char* title="");
	~Window();

	bool isClosed()const;
	void update()const;
	void clear();
private:
	bool init();
	static friend void key_callback(GLFWwindow* window,int key,int scancode,int action,int mods);
	static friend void mousebutton_callback(GLFWwindow* window, int button, int action, int mods);
	static friend void cursorpos_callback(GLFWwindow* window, double x, double y);
	static friend void windowsize_callback(GLFWwindow* window, int width, int height);
};

