// standard library
#include <iostream>
#include <direct.h>

// GLFW
#include <glfw/glfw3.h>

// ImGui
#include <imgui.h>
#include "imgui_impl_glfw.h"
#include "imgui_impl_OpenGLES2.h"

// engine demo
#include <SLEngineDemo.hpp>

// main
int main(int argc, char** argv)
{
	// set working directory
	_chdir("../../../..");

	// create glfw window
	glfwSetErrorCallback([](int error, const char* description) { std::cout << "Error: " << description << std::endl; });
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
	glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW OpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(0);

	// Setup Dear ImGui binding
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::GetIO().IniFilename = nullptr;
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGLES2_Init();

	// cretae engine demo
	SLEngineDemo* engineDemo = new SLEngineDemo();
	engineDemo->Init();

	// main loop
	while (!glfwWindowShouldClose(window))
	{
		// ImGui new frame
		ImGui_ImplGlfw_NewFrame();

		// update engine
		engineDemo->Update();

		// check should close
		if (engineDemo->GetShouldClose())
			glfwSetWindowShouldClose(window, 1);

		// draw ImGui. it should handled by renderer
		ImGui_ImplOpenGLES2_RenderDrawData(ImGui::GetDrawData());

		// display and process events through callbacks
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// delete engine
	engineDemo->ShutDown();
	delete engineDemo;

	// ImGui clean-up
	ImGui_ImplOpenGLES2_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	// destroy GLFW window
	glfwDestroyWindow(window);

	// exit
	return EXIT_SUCCESS;
}