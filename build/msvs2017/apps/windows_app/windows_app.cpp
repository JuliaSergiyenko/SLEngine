#include <Windows.h>
#include <GL/GL.h>
#include <GL/wglext.h>
#include <chrono>
#include "glcore2.hpp"

// ImGui
#include <imgui.h>
#include "imgui_impl_win32.h"
#include "imgui_impl_opengl2.h"

// SharedScene
#include "SharedScene.hpp"

// define buttons codes
#define GLFW_KEY_W      0x57
#define GLFW_KEY_A      0x41
#define GLFW_KEY_S      0x53
#define GLFW_KEY_D      0x44
#define GLFW_KEY_UP     VK_UP
#define GLFW_KEY_DOWN   VK_DOWN
#define GLFW_KEY_LEFT   VK_LEFT
#define GLFW_KEY_RIGHT  VK_RIGHT
#define GLFW_KEY_ESCAPE VK_ESCAPE

// CreateWinGLContext
HGLRC CreateWinGLContext(HDC hDC, int majorVersion, int minorVersion)
{
	// resulting context
	HGLRC context = NULL;

	// set PIXELFORMATDESCRIPTOR
	PIXELFORMATDESCRIPTOR pfd = { 0 };
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.iLayerType = PFD_MAIN_PLANE;

	// choose pixel format
	int nPixelFormat = ChoosePixelFormat(hDC, &pfd);
	if (nPixelFormat == 0) return NULL;

	// set pixel format
	if (!SetPixelFormat(hDC, nPixelFormat, &pfd)) return NULL;

	// create and set temporary context
	HGLRC tempContext = wglCreateContext(hDC);
	wglMakeCurrent(hDC, tempContext);

	// context attribs
	const int attribs[] =
	{
		WGL_CONTEXT_MAJOR_VERSION_ARB, majorVersion,
		WGL_CONTEXT_MINOR_VERSION_ARB, minorVersion,
		WGL_CONTEXT_FLAGS_ARB, 0,
		WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
		0
	};

	// create OpenGL context by attribs
	PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
	if (wglCreateContextAttribsARB)
		context = wglCreateContextAttribsARB(hDC, 0, attribs);

	// disable vertical synk
	PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
	if (wglSwapIntervalEXT)
		wglSwapIntervalEXT(0);

	// unset and delete temporary context
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(tempContext);

	return context;
}

// ImGui_ImplWin32_WndProcHandler
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// WndProc
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// UmGui wnd proc call
	if (ImGui_ImplWin32_WndProcHandler(hWnd, message, wParam, lParam))
		return true;

	// native wnd proc call
	switch (message)
	{
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			PostQuitMessage(0);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}

// WinMain
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// The main window class name.
	TCHAR szWindowClass[] = L"win32app";

	// The string that appears in the application's title bar.
	TCHAR szTitle[] = L"SLRender application";

	// create and register window class
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = NULL;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = NULL;
	RegisterClassEx(&wcex);

	// create window
	HWND hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	// show and update window
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// create OpenGL context
	HDC hDC = GetDC(hWnd);
	HGLRC hGLRC = CreateWinGLContext(hDC, 3, 1);
	wglMakeCurrent(hDC, hGLRC);

	// get OpenGL version
	GLint OpenGLVersion[2] = { 0,0 };
	glGetIntegerv(GL_MAJOR_VERSION, &OpenGLVersion[0]);
	glGetIntegerv(GL_MINOR_VERSION, &OpenGLVersion[1]);

	// ImGui init
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.IniFilename = nullptr;
	ImGui_ImplWin32_Init(hWnd);
	ImGui_ImplOpenGL2_Init();
	ImGui::StyleColorsDark();

	// create scene
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
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		// get messages
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		} 
		else
		{
			// get client window rect
			RECT rect = { 0 };
			GetWindowRect(hWnd, &rect);
			int width = rect.right - rect.left;
			int height = rect.bottom - rect.top;

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
			if (io.KeysDown[GLFW_KEY_ESCAPE]) PostQuitMessage(0);

			// create matrices
			glm::mat4 modelMat = glm::rotate(glm::mat4(1.0f), newTime, glm::vec3(1.0f, 0.5f, 0.1f));
			glm::mat4 viewMat = glm::lookAt(eye, eye + dir, up);
			glm::mat4 projMat = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);

			// set camera matrices
			model->SetTransform(glm::value_ptr(modelMat));
			camera->SetTransform(glm::value_ptr(viewMat));
			camera->SetProjection(glm::value_ptr(projMat));
			camera->SetViewport(width, height);

			// Start the Dear ImGui frame
			ImGui_ImplWin32_NewFrame();
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

			// render
			ImGui::Render();
			renderer->Render();
			ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

			// swap buffers
			SwapBuffers(hDC);
		}
	}

	// destroy SLRenderer
	DeleteRenderScene(renderer);
	DestroySLRenderer(renderer);

	// ImGui shutdown
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	// destroy OprnGL context
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(hGLRC);

	// destroy window
	DestroyWindow(hWnd);
	UnregisterClass(wcex.lpszClassName, wcex.hInstance);

	// exit
	return (int)msg.wParam;
}
