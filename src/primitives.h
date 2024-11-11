#pragma once
#ifndef PRIMITIVES_H
#define PRIMITIVES_H
#endif

#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>

class line {
public:
	line(float xpos1, float ypos1, float xpos2, float ypos2);
	void setColor(float red, float green, float blue);
	void drawLine();
	void lineEvents(GLFWwindow* window);
	float getYPos();
private:
	float xpos1;
	float ypos1;
	float xpos2;
	float ypos2;
	float alphaYPos;
};


class triangle {
public:
	triangle(float xpos1, float ypos1, float xpos2, float ypos2, float xpos3, float ypos3);
	void drawTriangle();
private:
	float xpos1;
	float ypos1;
	float xpos2;
	float ypos2;
	float xpos3;
	float ypos3;
};