#include <Windows.h>

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

		// query performance info (Frequency.QuadPart* (1.0f / Elapsed.QuadPart))
		QueryPerformanceCounter(&EndingTime);
		Elapsed.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;
	}

	// destroy window
	DestroyWindow(hWnd);
	UnregisterClass(wcex.lpszClassName, wcex.hInstance);

	// exit
	return (int)msg.wParam;
}
