#ifndef CONTROLUTILS_HPP
#define CONTROLUTILS_HPP

#include "playerCharacter.hpp"
#include "level.hpp"

#define PLAYER_HOR_SPD 200.0f
#define G 700

void UpdatePlayer(PlayerCharacter* player, std::vector<EnvItem>* envItems, float delta) {
    if (IsKeyDown(KEY_LEFT)) player->position.x -= PLAYER_HOR_SPD*delta;
    if (IsKeyDown(KEY_RIGHT)) player->position.x += PLAYER_HOR_SPD*delta;
    // if (IsKeyDown(KEY_SPACE) && player->get);

    // Handles standing
    bool hitObstacle = false;
    for (int i = 0; i < envItems->size(); i++)
    {
        EnvItem *envItem = &envItems->at(i);
        Vector2 *position = &(player->position);
        if (!envItem->traversable &&
            envItem->hitbox.x <= position->x &&
            envItem->hitbox.x + envItem->hitbox.width >= position->x &&
            envItem->hitbox.y >= position->y &&
            envItem->hitbox.y <= position->y + player->getVerticalVelocity()*delta)
        {
            hitObstacle = true;
            player->setVerticalVelocity(0.0f);
            position->y = envItem->hitbox.y;
            break;
        }
    }

    // Handles falling
    if (!hitObstacle)
    {
        player->position.y += player->getVerticalVelocity()*delta;
        player->setVerticalVelocity(G * delta);
        // player->canJump = false;
    }
    // else player->canJump = true;

}


#endif