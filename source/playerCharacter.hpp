#ifndef PLAYERCHAR_HPP
#define PLAYERCHAR_HPP

#include "timer.hpp"
#include "attack.hpp"
#include <string>

int PLAYER_WIDTH {50};
int PLAYER_HEIGHT {80};

// enum PlayerState {
//     idle, running, jumping, falling
// };

// enum PlayerTag {
//     bakali, belos, switchy, valarash
// };

class PlayerCharacter {
    std::string name {""};
    // PlayerState state {idle};
    // PlayerTag tag;

    int maxHealth {0};
    int currentHealth {0};
    float verticalVelocity {0};

    // MeleeAttack meleeAtk;
    // ProjectileAttack rangedAtk;

    public:
    Vector2 position {0, 0};

    PlayerCharacter() = default;

    // Parameterized constructor
    PlayerCharacter(std::string charName, int maxHP) {
        name = charName;
        maxHealth = maxHP;
    }

    std::string getName() {return name;}
    // PlayerState getState() {return state;}
    // PlayerTag getTag() {return tag;}
    int getMaxHP() {return maxHealth;}
    int getCurrentHP() {return currentHealth;}
    float getVerticalVelocity() {return verticalVelocity;}
    void setVerticalVelocity(float newVelocity) {
        verticalVelocity = newVelocity;
    }
    Rectangle getHitbox() {
        return {position.x - (PLAYER_WIDTH/2), position.y - PLAYER_HEIGHT, PLAYER_WIDTH, PLAYER_HEIGHT};
    }

    void takeDamage(int damage) {

        currentHealth -= damage;

        if (currentHealth < 0) currentHealth = 0;
        if (currentHealth > maxHealth) currentHealth = maxHealth;

    }

    void heal(int healing) {

        currentHealth += healing;

        if (currentHealth < 0) currentHealth = 0;
        if (currentHealth > maxHealth) currentHealth = maxHealth;
        
    }

};

#endif