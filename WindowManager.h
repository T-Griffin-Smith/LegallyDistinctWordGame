#pragma once

#include <windows.h>
#include <iostream>

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMSG, WPARAM wParam, LPARAM lParam);

class Window {

    public:
        Window();
        Window(const Window&) = delete;
        Window& operator =(const Window&) = delete;
        ~Window();

        bool ProcessMessages();

    private:
        HINSTANCE m_hInstance;
        HWND m_hWnd;
};

