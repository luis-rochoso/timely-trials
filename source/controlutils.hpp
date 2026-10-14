#ifndef CONTROLUTILS_HPP
#define CONTROLUTILS_HPP

#include "playerCharacter.hpp"
#include "level.hpp"

#define PLAYER_HOR_SPD 200.0f

void UpdatePlayer(PlayerCharacter* player, std::vector<EnvItem>* envItems, float delta) {
    if (IsKeyDown(KEY_LEFT)) player->position.x -= PLAYER_HOR_SPD*delta;
    if (IsKeyDown(KEY_RIGHT)) player->position.x += PLAYER_HOR_SPD*delta;
    // if (IsKeyDown(KEY_SPACE) && player->get);
}


#endif