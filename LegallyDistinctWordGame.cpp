#include "LegallyDistinctWordGame.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    std::cout << "Creating Window\n";

    Window* pWindow = new Window();

    bool running = true;

    // Game Setup

    srand(time(NULL)); // Seed RNG

    while (running) {

        if (!pWindow->ProcessMessages()) {
            std::cout << "Closing Window\n";
            running = false;
        }

        // Insert Rendering Here

        Sleep(10);

    }

    delete pWindow;

    return 0;
}