#include "window.h"
#include <iostream>

int createWindow(const int WIDTH,const int HEIGHT, const char* title)
{
    InitWindow(WIDTH, HEIGHT, title);
    if (IsWindowReady())
    {
        std::cout << "Window created successfully: " << title << std::endl;
        return 0; // Success

    }
    else
    {
        std::cerr << "Failed to create window: " << title << std::endl;
        return -1; // Failure
    }
}