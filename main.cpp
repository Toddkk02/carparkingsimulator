#include "map.h"

int main() {
    InitWindow(WIDTH, HEIGHT, "My 3D Game");
    
    MapResources map = initMap();
    
    Camera3D camera = {0};
    camera.position = (Vector3){0.0f, 10.0f, 10.0f};  
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    
    while (!WindowShouldClose()) {
        
        BeginDrawing(); // Start drawing
        ClearBackground(SKYBLUE);   // Clear the background
        
        BeginMode3D(camera); // Begin 3D mode
                
        drawMap(map); // Draw the map
        
        EndMode3D(); // End 3D mode
        EndDrawing(); // End drawing
    }
    
    unloadMap(map); // Unload map resources
    CloseWindow(); // Close window and OpenGL context
    return 0; 
}