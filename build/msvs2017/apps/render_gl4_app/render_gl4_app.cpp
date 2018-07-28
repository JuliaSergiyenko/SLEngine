#include <iostream>
#include <glfw/glfw3.h>
#include <SharedScene.hpp>

// main
int main(int argc, char** argv)
{
	//////////////////////////////////////////////////////////////////////////
	// set error handling
	glfwSetErrorCallback([](int error, const char* description) {
		std::cout << "Error: " << description << std::endl;
	});

	// init glfw
	glfwInit();

	// select OpenGL ES version
	// 	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
	// 	glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
	// 	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	// 	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	// select OpenGL version
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

	// create window
	GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW OpenGL 4.5", nullptr, nullptr);

	// set current context
	glfwMakeContextCurrent(window);

	// setup therender scene ready for rendering
	int width = 0, height = 0;
	glfwGetFramebufferSize(window, &width, &height);

	// create renderer
	ISLRenderer* renderer = SLRendererFabric::CreateRenderer(SL_RENDERER_TYPE_GL4);
	std::cout << renderer->GetDescription() << std::endl;
	CreateScene(renderer);

	// main loop
	double dt = 0, last_update_time = 0;
	while (!glfwWindowShouldClose(window))
	{
		// render!
		renderer->Render();

		// display and process events through callbacks
		glfwSwapBuffers(window);
		glfwPollEvents();

		// get frame time
		dt = glfwGetTime();
		if ((dt - last_update_time) > 0.2)
			last_update_time = dt;
	}

	// delete resource
	DeleteRenderScene(renderer);
	glfwTerminate();

	// exit
	return EXIT_SUCCESS;
}