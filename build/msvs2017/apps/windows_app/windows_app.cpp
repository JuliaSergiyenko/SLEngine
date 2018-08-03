#include <Windows.h>
#include <GL/GL.h>
#include <GL/wglext.h>
#include "glcore3.hpp"

// ImGui
#include <imgui.h>
#include "imgui_impl_win32.h"
#include "imgui_impl_opengl3.h"

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

	// get wglCreateContextAttribsARB address
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

// WndProc
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
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
	TCHAR szTitle[] = L"Win32 Guided Tour Application";

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
	HGLRC hGLRC = CreateWinGLContext(hDC, 3, 3);
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
	ImGui_ImplOpenGL3_Init();
	ImGui::StyleColorsDark();

	// main loop
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		// query performance info types
		LARGE_INTEGER StartingTime, EndingTime, Elapsed;
		LARGE_INTEGER Frequency;

		// query performance info
		QueryPerformanceFrequency(&Frequency);
		QueryPerformanceCounter(&StartingTime);

		// get messages
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		} 
		//else
		{
			// draw scene
			glClearColor(0.0f, 0.2f, 0.4f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// Start the Dear ImGui frame
			ImGui_ImplWin32_NewFrame();
			ImGui::NewFrame();
			ImGui::Begin("Renderer info");
			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			ImGui::End();
			ImGui::EndFrame();

			// render
			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			// swap buffers
			SwapBuffers(hDC);
		}

		// query performance info (Frequency.QuadPart* (1.0f / Elapsed.QuadPart))
		QueryPerformanceCounter(&EndingTime);
		Elapsed.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;
	}

	// ImGui shutdown
	ImGui_ImplOpenGL3_Shutdown();
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
