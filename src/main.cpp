#include <iostream>
#include "primitives.h"

int main() {
	if (!glfwInit()) {
		std::cout << "GLFW init failed" << std::endl;
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(800, 600, "Project Neptune", NULL, NULL);
	if (!window) {
		std::cout << "GLFW create window error" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Error initilizating GLAD" << std::endl;
		glfwTerminate();
		return -1;
	}

	glViewport(0, 0, 800, 600);

	//TODO: fps limiter
	const double FPS = 60.0;
	const double singleFrameTime = 1.0 / FPS;
	double lastTime = 0.0;
	double currentTime;

	line newline(0, 0, 0.3f, 0.8f);

	while (!glfwWindowShouldClose(window)) {
		currentTime = glfwGetTime();
		if (currentTime - lastTime >= singleFrameTime)
		{
			glClearColor(0.f, 0.f, 0.f, 1.f);
			glClear(GL_COLOR_BUFFER_BIT);
			newline.setColor(1.f, 1.f, 1.f);
			newline.drawLine();
			newline.lineEvents(window);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		

	}
	glfwTerminate();
	return 0;
}