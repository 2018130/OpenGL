#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

int main(void)
{
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(640, 480, "Hello World!", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		cout << "Error\n";
	}

	float vertexes[6] = {
		-0.5f, -0.5f,
		 0.0f, 0.5f,
		 0.5f, -0.5f,
	};

	unsigned int bufferID;
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER,
		6 * sizeof(float),
		vertexes,
		GL_STATIC_DRAW);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	return 0;
}