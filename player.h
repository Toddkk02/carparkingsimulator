#include <raylib.h>
#include <iostream>

// map.h - AGGIUNGI DOPO MapResources:

struct Player {
    Vector3 position;
    float rotation;
    float speed;
    Model carModel;
};

Player initPlayer();
void updatePlayer(Player& player);
void drawPlayer(const Player& player);
void unloadPlayer(Player& player);