#include<iostream>
#include"maths\maths.h"
#include"tool\shader.h"
#include"window\window.h"
#include"buffers\buffers.h"
#include"texture\texture2d.h"
#include"renderer\simple_renderer2d.h"

#include"tool\tool_macro.h"
#include"resourceManagement\resourceManagement.h"

#include"sprite\sprite.h"
#include"physical\world\world.h"
#include"renderer\drawLine.h"
#include"window\input.h"

#include<chrono>


#include<GL\glew.h>
#include<GLFW\glfw3.h>

#include<Windows.h>

using namespace std;

#define FLAG 1

int main()
{
	Window window(SCREEN_WIDTH, SCREEN_HEIGHT, "gEngine");


	ResourceManagement::init();
	Input::init();
#if FLAG
	World world;

	DrawLine drawLine;
#else


#endif


	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glBlendEquation(GL_FUNC_REVERSE_SUBTRACT);
	glEnable(GL_BLEND);

	auto tp1 = chrono::system_clock::now();
	auto tp2 = chrono::system_clock::now();



	float lag = 0.0f;
	while (!window.isClosed())
	{
		tp2 = chrono::system_clock::now();
		chrono::duration<float>elapsedTime = tp2 - tp1;
		tp1 = tp2;
		float ElapsedTime = elapsedTime.count();
		//cout << "FPS: " << 1.0 / ElapsedTime << endl;

		window.update();
		//glClearColor(0.0, 0.5, 0.0, 1.0);



#if FLAG
		world.render();

		lag += ElapsedTime;
		if (lag >= MS_PER_UPDATE)
		{
			world.update(MS_PER_UPDATE);
			lag -= MS_PER_UPDATE;
		}
#else

#endif
		window.clear();
	}

	return 0;
}