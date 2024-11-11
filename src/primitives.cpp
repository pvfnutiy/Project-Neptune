#include "primitives.h"

line::line(float xpos1, float ypos1, float xpos2, float ypos2)
{
	this->xpos1 = xpos1;
	this->ypos1 = ypos1;
	this->xpos2 = xpos2;
	this->ypos2 = ypos2;
	this->alphaYPos = 0.001f;
}

void line::setColor(float red, float green, float blue)
{
	glColor3f(red, green, blue);
}

void line::drawLine()
{
	glBegin(GL_LINES);
	glVertex2f(xpos1, ypos1);
	glVertex2f(xpos2, ypos2);
	glEnd();
}

void line::lineEvents(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		this->ypos2 = this->ypos2 + this->alphaYPos;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		this->ypos2 = this->ypos2 - this->alphaYPos;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		this->xpos2 = this->xpos2 - this->alphaYPos;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		this->xpos2 = this->xpos2 + this->alphaYPos;
	}
}

float line::getYPos()
{
	return this->ypos2;
}

triangle::triangle(float xpos1, float ypos1, float xpos2, float ypos2, float xpos3, float ypos3)
{
	this->xpos1 = xpos1;
	this->xpos2 = xpos2;
	this->xpos3 = xpos3;
	this->ypos1 = ypos1;
	this->ypos2 = ypos2;
	this->ypos3 = ypos3;
}

void triangle::drawTriangle()
{
	glBegin(GL_TRIANGLES);
	glVertex2f(xpos1, ypos1);
	glVertex2f(xpos2, ypos2);
	glVertex2f(xpos3, ypos3);
	glEnd();
}


