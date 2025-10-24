#include <iostream>
#include <raylib.h>
const int WIDTH = 1600;
const int HEIGHT = 900;
 
struct MapResources
{
    Model ground;
    Texture2D parkingTexture;
    bool isLoaded;
};
MapResources initMap();



int createWindow(const int WIDTH, const int HEIGHT, const char* title);

void drawMap(const MapResources& map);

void unloadMap(MapResources& map);
 
