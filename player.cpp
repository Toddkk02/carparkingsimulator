#include <raylib.h>
#include "raymath.h"
#include "player.h"
#include <cmath>

Player initPlayer() {
    Player player;
    player.position = (Vector3){0.0f, 0.5f, 0.0f};
    player.rotation = 0.0f;
    player.speed = 0.0f;
    player.carModel = LoadModel("./assets/models/car.glb");
    player.carModel.transform = MatrixScale(0.01f, 0.01f, 0.01f);
    return player;
}

void updatePlayer(Player& player) {
    if (IsKeyDown(KEY_W)) {
        player.speed += 0.0001f;
    }
    if (IsKeyDown(KEY_S)) {
        player.speed -= 0.0001f;
    }
    
    player.speed *= 0.95f;
    
    if (player.speed > 0.5f) player.speed = 0.5f;
    if (player.speed < -0.3f) player.speed = -0.3f;
    
    if (IsKeyDown(KEY_A)) {
        player.rotation += 0.0003f;
    }
    if (IsKeyDown(KEY_D)) {
        player.rotation -= 0.0003f;
    }
    
    player.position.x += sinf(player.rotation) * player.speed;
    player.position.z += cosf(player.rotation) * player.speed;
    
    float mapSize = 10.0f;
    if (player.position.x > mapSize) player.position.x = mapSize;
    if (player.position.x < -mapSize) player.position.x = -mapSize;
    if (player.position.z > mapSize) player.position.z = mapSize;
    if (player.position.z < -mapSize) player.position.z = -mapSize;
}

void drawPlayer(const Player& player) {
    DrawModelEx(
        player.carModel,
        player.position,
        (Vector3){0, 1, 0},
        player.rotation * RAD2DEG,
        (Vector3){1.0f, 1.0f, 1.0f},
        WHITE
    );
}

void unloadPlayer(Player& player) {
    UnloadModel(player.carModel);
}