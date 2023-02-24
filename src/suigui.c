#include "suigui.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void generateWindow(const char* windowName, int windowWidth, int windowHeight, bool resizable) {
    // Register the window class.
    const char CLASS_NAME[] = "Window Class";

    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.
    DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;
    if (resizable) {
        style |= WS_THICKFRAME | WS_MAXIMIZEBOX;
    }

    HWND hWnd = CreateWindowEx(
        0,
        CLASS_NAME,
        windowName,
        style,
        CW_USEDEFAULT, CW_USEDEFAULT,
        windowWidth, windowHeight,
        NULL,
        NULL,
        GetModuleHandle(NULL),
        NULL
    );

    if (hWnd == NULL) {
        return;
    }

    // Show the window.
    ShowWindow(hWnd, SW_SHOWDEFAULT);
    UpdateWindow(hWnd);

    // Start the message loop.
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void addText(HWND hWnd, const char* text) {
    // Create a static control to display the text.
    HWND hStatic = CreateWindow(
        "STATIC",
        text,
        WS_CHILD | WS_VISIBLE | SS_LEFT,
        10, 10, 200, 20,
        hWnd,
        NULL,
        GetModuleHandle(NULL),
        NULL
    );

    if (hStatic == NULL) {
        return;
    }

    // Show the static control.
    ShowWindow(hStatic, SW_SHOW);
    UpdateWindow(hStatic);
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    default:
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
}
