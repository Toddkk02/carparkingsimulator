#include <raylib.h>
#include <iostream>
#include "window.h"


int main(void)
{
    {
        if (createWindow(WIDTH, HEIGHT, "My Raylib Window") == 0)
        {
            // Main loop
            while (!WindowShouldClose())
            {
                BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawText("Hello, Raylib!", 190, 200, 20, LIGHTGRAY);
                EndDrawing();
            }

            CloseWindow(); // Close window and OpenGL context
            return 0; // Success
        }
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
}