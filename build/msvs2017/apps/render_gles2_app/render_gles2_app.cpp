// imgui
#include <imgui.h>

// context and renderer
#include <iostream>
#include <glfw/glfw3.h>
#include <SharedScene.hpp>

// main
int main(int argc, char** argv)
{
	// set error handling
	glfwSetErrorCallback([](int error, const char* description) {
		std::cout << "Error: " << description << std::endl;
	});

	// init GLFW
	glfwInit();

	// select OpenGL ES version
	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
	glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

// 	// select OpenGL version
// 	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
// 	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
// 	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// create window
	GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW OpenGL", nullptr, nullptr);

	// set current context
	glfwMakeContextCurrent(window);
	glfwSwapInterval(0);

	// get window size
	int width = 0, height = 0;
	glfwGetFramebufferSize(window, &width, &height);

	// destroy SLRenderer
	ISLRenderer* renderer = CreateSLRenderer();
	std::cout << renderer->GetDescription() << std::endl;

	// create scene
	ISLModel* model = nullptr;
	ISLCamera* camera = nullptr;
	CreateScene(renderer, &model, &camera);

	// main loop
	double dt = 0, last_update_time = 0;
	while (!glfwWindowShouldClose(window))
	{
		// create matrices
		glm::mat4 modelMat = glm::rotate(glm::mat4(1.0f), (float)glfwGetTime(), glm::vec3(1.0f, 0.5f, 0.1f));
		glm::mat4 viewMat = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glm::mat4 projMat = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);

		// set camera matrices
		model->SetTransform(glm::value_ptr(modelMat));
		camera->SetTransform(glm::value_ptr(viewMat));
		camera->SetProjection(glm::value_ptr(projMat));

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

	// destroy SLRenderer
	DeleteRenderScene(renderer);
	DestroySLRenderer(renderer);

	// destroy GLFW window
	glfwDestroyWindow(window);
	std::cout << "Exit!" << std::endl;

	// exit
	return EXIT_SUCCESS;
}