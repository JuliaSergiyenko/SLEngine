// standard library
#include <iostream>
#include <chrono>

// GLFW
#include <glfw/glfw3.h>

// ImGui
#include <imgui.h>
#include "imgui_impl_glfw.h"
#include "imgui_impl_OpenGL2.h"

// scene (I WANT TO REFUCTOR THIS CODE)
#include <SharedScene.hpp>

// main
int main(int argc, char** argv)
{
	// create glfw window
	glfwSetErrorCallback([](int error, const char* description) { std::cout << "Error: " << description << std::endl; });
	glfwInit();
	// select OpenGL version
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW OpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(0);

	// Setup Dear ImGui binding
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.IniFilename = nullptr;
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL2_Init();
	ImGui::StyleColorsDark();

	// create SLRenderer
	ISLRenderer* renderer = CreateSLRenderer();
	ISLModel* model = nullptr;
	ISLCamera* camera = nullptr;
	CreateScene(renderer, &model, &camera);

	// camera position
	glm::vec3 eye = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 dir = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

	// get start time
	auto startTimeStamp = std::chrono::high_resolution_clock::now();
	auto currTimeStamp = std::chrono::high_resolution_clock::now();

	// main loop
	while (!glfwWindowShouldClose(window))
	{
		// get window size
		int width = 0, height = 0;
		glfwGetFramebufferSize(window, &width, &height);

		// get current time
		auto prevTimeStamp = currTimeStamp;
		currTimeStamp = std::chrono::high_resolution_clock::now();
		float newTime = std::chrono::duration_cast<std::chrono::microseconds>(currTimeStamp - startTimeStamp).count() * std::pow(10.0f, -6.0f);
		float frameTime = std::chrono::duration_cast<std::chrono::microseconds>(currTimeStamp - prevTimeStamp).count() * std::pow(10.0f, -6.0f);
		float frameRate = 1.0f / frameTime;

		// camera move 
		if (io.KeysDown[GLFW_KEY_W] || io.KeysDown[GLFW_KEY_UP]) eye += dir * frameTime;
		if (io.KeysDown[GLFW_KEY_S] || io.KeysDown[GLFW_KEY_DOWN]) eye -= dir * frameTime;
		if (io.KeysDown[GLFW_KEY_A] || io.KeysDown[GLFW_KEY_LEFT]) eye -= glm::normalize(glm::cross(dir, up)) * frameTime;
		if (io.KeysDown[GLFW_KEY_D] || io.KeysDown[GLFW_KEY_RIGHT]) eye += glm::normalize(glm::cross(dir, up)) * frameTime;
		if (io.KeysDown[GLFW_KEY_ESCAPE]) glfwSetWindowShouldClose(window, 1);

		// create matrices
		glm::mat4 modelMat = glm::rotate(glm::mat4(1.0f), (float)glfwGetTime(), glm::vec3(1.0f, 0.5f, 0.1f));
		glm::mat4 viewMat = glm::lookAt(eye, eye + dir, up);
		glm::mat4 projMat = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);

		// set camera matrices
		model->SetTransform(glm::value_ptr(modelMat));
		camera->SetTransform(glm::value_ptr(viewMat));
		camera->SetProjection(glm::value_ptr(projMat));
		camera->SetViewport(width, height);

		// Start the Dear ImGui frame
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		ImGui::SetNextWindowPos(ImVec2(0, 0));
		ImGui::Begin("Renderer info");
		ImGui::Text(renderer->GetDescription());
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / frameRate, frameRate);
		ImGui::Text("Application run time %.3f s", newTime);
		ImGui::Text("Eye: (%.3f,%.3f,%.3f)", eye.x, eye.y, eye.z);
		ImGui::Text("Dir: (%.3f,%.3f,%.3f)", dir.x, dir.y, dir.z);
		ImGui::End();
		ImGui::EndFrame();

		// render!
		ImGui::Render();
		renderer->Render();
		ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

		// display and process events through callbacks
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// destroy SLRenderer
	DeleteRenderScene(renderer);
	DestroySLRenderer(renderer);

	// ImGui clean-up
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	// destroy GLFW window
	glfwDestroyWindow(window);

	// exit
	return EXIT_SUCCESS;
}
