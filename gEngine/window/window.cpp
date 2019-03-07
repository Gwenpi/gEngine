#include "window.h"
#include<iostream>
#include"../tool/tool_macro.h"
#include"input.h"

void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods);
void mousebutton_callback(GLFWwindow * window, int button, int action, int mods);
void cursorpos_callback(GLFWwindow* window, double x, double y);
void windowsize_callback(GLFWwindow * window, int width, int height);

Window::Window()
{
}

Window::Window(unsigned int width, unsigned int height, const char * title)
	:m_Width(width),m_Height(height),m_Title(title)
{
	if (init())
		glfwTerminate();
	
}


Window::~Window()
{
	glfwTerminate();
}

bool Window::isClosed() const
{
	return glfwWindowShouldClose(m_Window)==1;
}

void Window::update() const
{
	glClearColor(0.2f, 0.2f, 0.2f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnd();
}

void Window::clear()
{
	glfwPollEvents();
	glfwSwapBuffers(m_Window);
}



bool Window::init()
{
	if (!glfwInit())
	{
		std::cout << "GLFW 初始化失败 " << std::endl;
		return true;
	}
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);
	
	if (!m_Window)
	{
		std::cout << "窗口创建 失败 " << std::endl;
		return true;
	}
	glfwMakeContextCurrent(m_Window);
	glfwSetWindowUserPointer(m_Window, this);//mark
	glfwSetKeyCallback(m_Window,key_callback);
	glfwSetMouseButtonCallback(m_Window, mousebutton_callback);
	glfwSetCursorPosCallback(m_Window, cursorpos_callback);
	glfwSetWindowSizeCallback(m_Window, windowsize_callback);

	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW 初始化失败 " << std::endl;
		return true;
	}
	std::cout << glGetString(GL_VERSION) << std::endl;


	return false;
}

void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	//GLFW按键有三种状况GLFW_PRESS（按压）, GLFW_RELEASE（释放） or GLFW_REPEAT（重复按压）.
	//当你按下时是GLFW_PRESS，按久了就是GLFW_REPEAT，所以这里用！=GLFW_RELEASE
	if (action == GLFW_PRESS)
	{
		Input::updateButton(key, PRESS);
	}
	else if (action == GLFW_REPEAT)
	{
		Input::updateButton(key, REPEAT);
	}
	else
	{
		Input::updateButton(key, RELEASE);
	}

	if (Input::buttonIsPress(GLFW_KEY_ESCAPE))
		glfwSetWindowShouldClose(win->m_Window, GLFW_TRUE);

}

void mousebutton_callback(GLFWwindow * window, int button, int action, int mods)
{

	if (action == GLFW_PRESS)
	{
		Input::updateButton(button, PRESS);
	}
	else
	{
		Input::updateButton(button, RELEASE);
	}
}
void cursorpos_callback(GLFWwindow* window, double x, double y)
{	
	Input::updateCursorPos(x, y);
}

void windowsize_callback(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
}
