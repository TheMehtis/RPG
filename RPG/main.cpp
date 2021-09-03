#include <windows.h>
#include "game.h"

//LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

int main(int argc, char** argv)
{
	game_init();

	//GUI
	/*
	//FreeConsole();
	WNDCLASS windowClass = { 0 };
	windowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hInstance = NULL;
	windowClass.lpfnWndProc = WndProc;
	windowClass.lpszClassName = "GameWindow";
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	if (!RegisterClass(&windowClass))
		MessageBox(NULL, "Could not register class", "Error", MB_OK);
	HWND windowHandle = CreateWindow("GameWindow",
		"Game",
		WS_OVERLAPPEDWINDOW,
		100,
		100,
		500, //Height
		500, //Width
		NULL,
		NULL,
		NULL,
		NULL);
	ShowWindow(windowHandle, SW_RESTORE);
	MSG messages;
	while (GetMessage(&messages, NULL, 0, 0) > 0)
	{
		TranslateMessage(&messages);
		DispatchMessage(&messages);
	}
	DeleteObject(windowHandle); //doing it just in case
	return messages.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
	case WM_CHAR: //this is just for a program exit besides window's borders/task bar
		if (wparam == VK_ESCAPE)
		{
			DestroyWindow(hwnd);
		}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wparam, lparam);
	}
	return 0;
	*/
}