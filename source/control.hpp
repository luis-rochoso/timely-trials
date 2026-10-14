#ifndef CONTROL_HPP
#define CONTROL_HPP

#include "raylib.h"
#include "controlutils.hpp"

// Constant definitions
short SCREEN_WIDTH = 800;
short SCREEN_HEIGHT = 450;
// PlayerCharacter BAKALI, BELOS, SWITCH, VALARASH;

// Global variables
std::vector<EnvItem> mapLayout = {
    {{0, 300, 500, 10}, 0, RED},
    {{300, 250, 500, 20}, 0, BLUE}
};

Level map = Level(mapLayout);

// Functions
void init() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Timely Trials");

    SetTargetFPS(60);
}

void update() {
    float delta = GetFrameTime();
    UpdatePlayer(&map.player, map.getEnvItems(), delta);
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
        DrawText(TextFormat("Delta (frame time): %f", GetFrameTime()), 650, 10, 10, WHITE);

        // Render player state
        int width = MeasureText(map.player.stateToCString(), 12);
        DrawText(map.player.stateToCString(), map.player.position.x - (width/2),
                 map.player.position.y - (1.2 * PLAYER_HEIGHT), 12, WHITE);

    EndDrawing();
}

#endif