#include <windows.h>
#include <cstdio>
#include <ctime>
#include <bits/stdc++.h>

int count = 0;  // Global variable to keep track of button's count
time_t start;   // Global variable to store the start time


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	
    switch (message)
    {
    case WM_CREATE:
    {
        // Create a button
        HWND button = CreateWindowEx(0, "BUTTON", "0", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            50, 50, 100, 50, hwnd, (HMENU)1, NULL, NULL);
        
        // Create a label to display the click rate
        CreateWindowEx(0, "STATIC", "Click Rate: 0 cps", WS_VISIBLE | WS_CHILD,
            50, 100, 200, 50, hwnd, (HMENU)2, NULL, NULL);
        
        start = time(NULL);  // Store the start time
        break;
    }
    case WM_COMMAND:
    {
        if (LOWORD(wParam) == 1)
        {
            count++;  // Increment the click count
            char buffer[10];
            sprintf(buffer, "%d", count);
            SetWindowText(GetDlgItem(hwnd, 1), buffer);  // Update the button text
            
            // Calculate the click rate and update the label
            time_t end = time(NULL);
            double seconds = difftime(end, start);
            double clickRate = (double)count / seconds;
            sprintf(buffer, "Click Rate: %.2f cps", clickRate);
            SetWindowText(GetDlgItem(hwnd, 2), buffer);
        }
        break;
    }
    case WM_DESTROY:
	{
	PostQuitMessage(0);
	break;
	}
	default:
	return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
	}
	
	int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
	{
		printf("CPS测试工具 按钮上将显示总点击次数 下方计算CPS（计算中所用时间为从程序启动到计算时的时间 若想重新开始需重启程序）");
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;
	

// Registering the Window Class
wc.cbSize        = sizeof(WNDCLASSEX);
wc.style         = 0;
wc.lpfnWndProc   = WndProc;
wc.cbClsExtra    = 0;
wc.cbWndExtra    = 0;
wc.hInstance     = hInstance;
wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
wc.lpszMenuName  = NULL;
wc.lpszClassName = "ButtonCounter";
wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

if(!RegisterClassEx(&wc))
{
    MessageBox(NULL, "Window Registration Failed!", "Error!",
        MB_ICONEXCLAMATION | MB_OK);
    return 0;
}

// Creating the Window
hwnd = CreateWindowEx(
    WS_EX_OVERLAPPEDWINDOW,
    "ButtonCounter",
    "Button Counter",
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, 500, 500,
    NULL, NULL, hInstance, NULL);

if(hwnd == NULL)
{
MessageBox(NULL, "Window Creation Failed!", "Error!",
MB_ICONEXCLAMATION | MB_OK);
return 0;
}
ShowWindow(hwnd, nCmdShow);
UpdateWindow(hwnd);

// The Message Loop
while(GetMessage(&Msg, NULL, 0, 0) > 0)
{
    TranslateMessage(&Msg);
    DispatchMessage(&Msg);
}
return Msg.wParam;
}



