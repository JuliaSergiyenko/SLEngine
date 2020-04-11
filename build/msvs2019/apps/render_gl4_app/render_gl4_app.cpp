// standard library
#include <iostream>
#include <direct.h>

// GLFW
#include <glfw/glfw3.h>

// ImGui
#include <imgui.h>
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl4.h"

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
	// select OpenGL version
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW OpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(0);

	// Setup Dear ImGui binding
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::GetIO().IniFilename = nullptr;
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL4_Init();

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
		ImGui_ImplOpenGL4_RenderDrawData(ImGui::GetDrawData());

		// display and process events through callbacks
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// delete engine
	engineDemo->ShutDown();
	delete engineDemo;

	// ImGui clean-up
	ImGui_ImplOpenGL4_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	// destroy GLFW window
	glfwDestroyWindow(window);

	// exit
	return EXIT_SUCCESS;
}