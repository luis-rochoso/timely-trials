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

void renderEnemies(std::vector<Entity> &enemies) {

    for (int i = 0; i < enemies.size(); ++i) {
        DrawRectangleRec(enemies[i].getHitbox(), enemies[i].getColor());
        const char* name = enemies[i].getName().c_str();
        int width = MeasureText(name, 12);
    
        DrawText(name,
                 enemies[i].position.x - (width/2), enemies[i].position.y - (1.2 * enemies[i].getHeight()),
                 12, WHITE);
    }

}

#endif