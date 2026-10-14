#ifndef CONTROLUTILS_HPP
#define CONTROLUTILS_HPP

#include "playerCharacter.hpp"
#include "level.hpp"

#define PLAYER_HOR_SPEED 200.0f
#define PLAYER_JUMP_SPEED 350.0F
#define G 700

void UpdatePlayer(PlayerCharacter* player, std::vector<EnvItem>* envItems, float delta) {
    // Handles jumping
    if (IsKeyDown(KEY_UP) && player->state != airborne) {
        player->setVerticalVelocity(-PLAYER_JUMP_SPEED);
        player->state = airborne;
    }

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
        player->increaseVerticalVelocity(G * delta);
        player->state = airborne;
    }
    else player->state = idle;

    // Handles horizontal movement
    bool isMovingHorizontally = false;
    if (IsKeyDown(KEY_LEFT)) {
        player->position.x -= PLAYER_HOR_SPEED*delta;
        isMovingHorizontally = true;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        player->position.x += PLAYER_HOR_SPEED*delta;
        isMovingHorizontally = true;
    }
    if (isMovingHorizontally && player->state != airborne) player->state = running;
}


#endif