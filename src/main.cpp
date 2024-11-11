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

	const char* fShaderCode =
		"#version 410 core\n"
		"out vec4 FragColor;\n"
		"void main() {\n"
		"	FragColor = vec4(0.8, 1.0, 1.0, 1.0);\n"
		"}\n";

	const char* vShaderCode = 
		"#version 410 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main() {\n"
		"	gl_Position = vec4(aPos, 1.0);\n"
		"}\n";

	unsigned int fShader;
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