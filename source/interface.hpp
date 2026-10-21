#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "controlutils.hpp"

void renderEnvItems(std::vector<EnvItem>* envItems) {
    for (auto it = envItems->begin(); it != envItems->end(); ++it) {
            DrawRectangleRec(it->hitbox, it->color);
        }
}

void renderPlayer(Entity &player, Color playerColor) {
    DrawRectangleRec(player.getHitbox(), playerColor);
}

void renderPlayerState(Entity &player) {
    int width = MeasureText(player.stateToCString(), 12);
    
    DrawText(player.stateToCString(),
             player.position.x - (width/2), player.position.y - (1.2 * PLAYER_HEIGHT),
             12, WHITE);
}

#endif