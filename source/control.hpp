#ifndef CONTROL_HPP
#define CONTROL_HPP

#include "string.h"
#include "interface.hpp"

// Constant definitions
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;
// PlayerCharacter BAKALI, BELOS, SWITCH, VALARASH;

const std::vector<EnvItem> mapLayout = {
    {{0, 300, 500, 10}, 0, RED},
    {{300, 250, 500, 20}, 0, BLUE}
};

// Global variables
Level map = Level(mapLayout);
Camera2D cam = { 0 };

// Functions
void init() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Timely Trials");
    SetTargetFPS(60);

    cam.target = map.player.position;
    cam.offset = {GetRenderWidth()/2.0f, GetRenderHeight()/2.0f};
    cam.rotation = 0.0f;
    cam.zoom = 1.0f;
}

void update() {
    float delta = GetFrameTime();

    switchCharacter(&map.player);

    updatePlayer(&map.player, map.getEnvItems(), delta);
    updateCamera(&cam, &map.player, map.getEnvItems(), delta, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void render() {
    Color playerColor;

    switch (map.player.getPlayerTag())
    {
    case bakali:
        playerColor = YELLOW;
        break;

    case belos:
        playerColor = DARKGREEN;
        break;

    case switchy:
        playerColor = GRAY;
        break;

    case valarash:
        playerColor = GREEN;
        break;
    
    default:
        break;
    }

    BeginDrawing();
        ClearBackground(BLACK);

        // Things that are drawn relative to the camera position
        // are rendered inside the Mode2D
        BeginMode2D(cam);
            renderEnvItems(map.getEnvItems());
            renderPlayer(map.player, playerColor);
            renderPlayerState(map.player);
        EndMode2D();

        DrawText(map.player.getName().c_str(),
                 0.025*SCREEN_WIDTH, 0.025*SCREEN_HEIGHT, 30, WHITE);

        DrawText(TextFormat("HP: %i", map.player.getCurrentHP()),
                 0.025*SCREEN_WIDTH, 0.0975*SCREEN_HEIGHT, 30, WHITE);

        DrawText(TextFormat("Delta (frame time): %f", GetFrameTime()),
                 0.8*SCREEN_WIDTH, 0.02*SCREEN_HEIGHT, 10, WHITE);


    EndDrawing();
}

#endif