#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>

void InitGlfw()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void InitGlad()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	std::cout << "[framebuffer_size_callback]" + width + "-" + height << std::endl;
	glViewport(0, 0, width, height);
}

int main()
{

	InitGlfw();
	InitGlad();

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glViewport(0, 0, 800, 600);

	return 0;
}