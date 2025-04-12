#include "WindowManager.h"

#define IDI_MYICON 101

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        case WM_CLOSE:
            DestroyWindow(hWnd);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

Window::Window() 
    : m_hInstance(GetModuleHandle(nullptr)) {
    const wchar_t* CLASS_NAME = L"Legally Distinct Word Game";
    
    WNDCLASSW wndClass = {};
    wndClass.lpszClassName = CLASS_NAME;
    wndClass.hInstance = m_hInstance;
    wndClass.hIcon = (HICON)LoadImageW(m_hInstance, L"resources/Tile.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.lpfnWndProc = WindowProc;

    RegisterClassW(&wndClass);

    DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;
    
    int width = 500;
    int height = 500;
    RECT rect = { 69, 69, 69 + width, 69 + height };

    AdjustWindowRect(&rect, style, FALSE);

    m_hWnd = CreateWindowExW(
        0,
        CLASS_NAME,
        L"Legally Distinct Word Game",
        style, 
        rect.left,
        rect.top, 
        rect.right - rect.left,
        rect.bottom - rect.top,
        NULL,
        NULL,
        m_hInstance, 
        NULL
    );

    ShowWindow(m_hWnd, SW_SHOW);

    // Explicitly set the icon for both taskbar and title bar
    HICON hIcon = (HICON)LoadImageW(m_hInstance, L"resources/Tile.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
    if (hIcon != NULL) {
        SendMessage(m_hWnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);  // Set large icon for taskbar
        SendMessage(m_hWnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);  // Set small icon for title bar
    } else {
        MessageBoxW(NULL, L"Failed to load icon!", L"Error", MB_OK | MB_ICONERROR);
    }
}

Window::~Window() {
    const wchar_t* CLASS_NAME = L"Legally Distinct Word Game";
    UnregisterClassW(CLASS_NAME, m_hInstance);
}

bool Window::ProcessMessages() {
    MSG msg = {};

    while (PeekMessageW(&msg, nullptr, 0u, 0u, PM_REMOVE)) {
        
        if (msg.message == WM_QUIT) {
            return false;
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return true;
}