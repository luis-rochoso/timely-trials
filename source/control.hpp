#ifndef CONTROL_HPP
#define CONTROL_HPP

#include "interface.hpp"

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

        renderEnvItems(map.getEnvItems());
        renderPlayer(map.player, playerColor);
        renderPlayerState(map.player);

        DrawText(TextFormat("Delta (frame time): %f", GetFrameTime()), 650, 10, 10, WHITE);

        // Render player state
        

    EndDrawing();
}

#endif