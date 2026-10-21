#ifndef CONTROLUTILS_HPP
#define CONTROLUTILS_HPP

#include "entity.hpp"
#include "level.hpp"

#define PLAYER_HOR_SPEED 200.0f
#define PLAYER_JUMP_SPEED 350.0F
#define G 700

void updatePlayer(Entity* player, std::vector<EnvItem>* envItems, float delta) {
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

// The player pushes the camera when approaching the screen borders
void updateCamera(Camera2D *camera, Entity *player, std::vector<EnvItem>* envItems, float delta, int width, int height) {

    // Create a smaller box around the center of the screen
    static Vector2 borderBox = { 0.2f, 0.2f }; //!< Multiplicative constants

    // Set the boundaries of the smaller box
    // NOTE: GetScreenToWorld2D returns the position in the map for a given
    // position in the camera screen
    Vector2 borderBoxWorldMin = GetScreenToWorld2D({ (1 - borderBox.x)*0.5f*width, (1 - borderBox.y)*0.5f*height }, *camera);
    Vector2 borderBoxWorldMax = GetScreenToWorld2D({ (1 + borderBox.x)*0.5f*width, (1 + borderBox.y)*0.5f*height }, *camera);

    // Offsetting the camera's position prevents it from sticking to the player's position 
    camera->offset = { (1 - borderBox.x)*0.5f*width, (1 - borderBox.y)*0.5f*height };

    // The camera only moves if the player moves out of the borderBox
    if (player->position.x < borderBoxWorldMin.x) camera->target.x = player->position.x;
    if (player->position.y < borderBoxWorldMin.y) camera->target.y = player->position.y;
    if (player->position.x > borderBoxWorldMax.x) camera->target.x = borderBoxWorldMin.x + (player->position.x - borderBoxWorldMax.x);
    if (player->position.y > borderBoxWorldMax.y) camera->target.y = borderBoxWorldMin.y + (player->position.y - borderBoxWorldMax.y);

}

void switchCharacter(Entity* player) {

    Vector2 currentPos = player->position;
    EntityState currentState = player->state;
    float currentVelocity = player->getVerticalVelocity();
    int currentHP = player->getCurrentHP();

    if (IsKeyPressed(KEY_ONE)) {
        *player = Entity(bakali);
    }
    else if (IsKeyPressed(KEY_TWO)) {
        *player = Entity(belos);
    }
    else if (IsKeyPressed(KEY_THREE)) {
        *player = Entity(switchy);
    }
    else if (IsKeyPressed(KEY_FOUR)) {
        *player = Entity(valarash);
    }

    player->position = currentPos;
    player->state = currentState;
    player->setVerticalVelocity(currentVelocity);
    player->setCurrentHP(currentHP);

}

#endif