#include <glfw/glfw3.h>
#include <iostream>

static void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

int main(int argc, char** argv)
{
	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
		exit(EXIT_FAILURE);

	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW OpenGL3 Heightmap demo", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	
	glfwMakeContextCurrent(window);

	/* setup the scene ready for rendering */
	int width = 0, height = 0;
	glfwGetFramebufferSize(window, &width, &height);

	double dt = 0, last_update_time = 0;
	while (!glfwWindowShouldClose(window))
	{
		/* display and process events through callbacks */
		glfwSwapBuffers(window);
		glfwPollEvents();

		/* Check the frame rate and update the heightmap if needed */
		dt = glfwGetTime();
		if ((dt - last_update_time) > 0.2)
			last_update_time = dt;
	}

	glfwTerminate();
	exit(EXIT_SUCCESS);
}

