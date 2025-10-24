#include "map.h"
#include <iostream>

int createWindow(const int WIDTH, const int HEIGHT, const char *title)
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

MapResources initMap()
{
        MapResources map;
        Mesh groundMesh = GenMeshPlane(2.0f, 2.0f, 10, 10); // Generate a plane mesh
        map.ground = LoadModelFromMesh(groundMesh);
        map.parkingTexture = LoadTexture("./assets/texture/parking_texture.png");

        if (map.parkingTexture.id > 0)
        {
            map.ground.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = map.parkingTexture;
        }
        map.isLoaded = (map.parkingTexture.id > 0);
        return map;
}

void drawMap(const MapResources &map)
{
    Vector3 groundPosition = {0.0f, 0.0f, 0.0f};
    DrawModel(map.ground, groundPosition, 10.0f, WHITE); // Scale the ground model
}

void unloadMap(MapResources &map)
{
    UnloadTexture(map.parkingTexture);
    UnloadModel(map.ground);
}