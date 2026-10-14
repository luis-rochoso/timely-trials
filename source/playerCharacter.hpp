#ifndef PLAYERCHAR_HPP
#define PLAYERCHAR_HPP

#include "timer.hpp"
#include "attack.hpp"
#include <string>

#define PLAYER_WIDTH 50
#define PLAYER_HEIGHT 80

enum PlayerState {
    idle, running, airborne
};

// enum PlayerTag {
//     bakali, belos, switchy, valarash
// };

class PlayerCharacter {
    public:
    Vector2 position {0, 0};
    PlayerState state {idle};

    private:
    std::string name {""};
    // PlayerTag tag;

    int maxHealth {0};
    int currentHealth {0};
    float verticalVelocity {0};

    // MeleeAttack meleeAtk;
    // ProjectileAttack rangedAtk;

    public:

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
    void increaseVerticalVelocity(float increment) {
        verticalVelocity += increment;
    }
    void decreaseVerticalVelocity(float decrement) {
        verticalVelocity -= decrement;
    }
    Rectangle getHitbox() {
        return {position.x - (PLAYER_WIDTH/2), position.y - PLAYER_HEIGHT, PLAYER_WIDTH, PLAYER_HEIGHT};
    }
    const char* stateToCString() {
        switch (state)
        {
        case idle:
            return "idle";
        case running:
            return "running";
        case airborne:
            return "airborne";
        default:
            return "";
        }
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