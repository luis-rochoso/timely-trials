#ifndef CONTROL_HPP
#define CONTROL_HPP

#include "raylib.h"
#include "playerCharacter.hpp"
#include "level.hpp"

// Constant definitions
short SCREEN_WIDTH = 800;
short SCREEN_HEIGHT = 450;
// PlayerCharacter BAKALI, BELOS, SWITCH, VALARASH;

// Global variables
std::vector<EnvItem> mapLayout = {
    {{200, 300, 500, 10}, 1, RED},
    {{300, 200, 500, 20}, 1, BLUE}
};

Level map = Level(mapLayout);

// Functions
void init() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Timely Trials");

    SetTargetFPS(60);
}

void update() {

}

void render() {
    Color playerColor = GREEN;
    // Color playerColor;

    // switch (map.player.getTag())
    // {
    // case bakali:
    //     playerColor = YELLOW;
    //     break;

    // case belos:
    //     playerColor = DARKGREEN;
    //     break;

    // case switchy:
    //     playerColor = GRAY;
    //     break;

    // case valarash:
    //     playerColor = GREEN;
    //     break;
    
    // default:
    //     break;
    // }

    BeginDrawing();
        ClearBackground(BLACK);

        for (auto it = map.getEnvItems()->begin(); it != map.getEnvItems()->end(); ++it) {
            DrawRectangleRec(it->hitbox, it->color);
        }

        DrawRectangleRec(map.player.getHitbox(), playerColor);

    EndDrawing();
}

#endif