#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "timer.hpp"
#include "attack.hpp"
#include <string>

#define PLAYER_WIDTH 50
#define PLAYER_HEIGHT 80

enum EntityState {
    idle, running, airborne
};

enum EntityTag {
    enemy, player
};

enum EnemyTag {
    notEnemy, lizardfolk, rakshasa
};

enum PlayerTag {
    notPlayer, bakali, belos, switchy, valarash
};

class Entity {
    public:
    Vector2 position  {0, 0};
    EntityState state {idle};

    private:
    std::string name      {""};
    EntityTag tag         {enemy};
    EnemyTag enemyTag     {notEnemy};
    PlayerTag playerTag   {notPlayer};
    

    int maxHealth          {25};
    int currentHealth      {25};
    float verticalVelocity {0};
    float width            {25};
    float height           {25};

    // MeleeAttack meleeAtk;
    // ProjectileAttack rangedAtk;

    public:

    Entity() = default;

    // Parameterized constructors
    Entity(PlayerTag pTag) { // Player
        tag = player;
        playerTag = pTag;

        width = PLAYER_WIDTH;
        height = PLAYER_HEIGHT;

        maxHealth = 100;
        currentHealth = maxHealth;

        switch (playerTag)
        {
        case bakali:
            name = "Bala";
            break;
        
        case belos:
            name = "Belos";
            break;

        case switchy:
            name = "SWITCH";
            break;

        case valarash:
            name = "Valarash";
            break;
        
        default:
            break;
        }
    }

    Entity(EnemyTag enTag, int maxHP, Vector2 spawnPos) {
        tag = enemy;
        enemyTag = enTag;

        switch (enemyTag)
        {
        case lizardfolk:
            maxHealth = 25;
            width = 50;
            height = 90;
            break;

        case rakshasa:
            maxHealth = 50;
            width = 50;
            height = 80;
            break;
        
        default:
            maxHealth = 25;
            width = 50;
            height = 80;
            break;
        }

        currentHealth = maxHealth;
    }

    bool isEnemy()  {return enemyTag != notEnemy;}
    bool isPlayer() {return playerTag != notPlayer;}

    EnemyTag getEnemyTag() {return enemyTag;}
    PlayerTag getPlayerTag() {return playerTag;}
    std::string getName() {return name;}

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