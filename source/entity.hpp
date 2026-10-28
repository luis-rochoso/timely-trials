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
    PlayerTag playerTag   {notPlayer};
    

    int maxHealth          {25};
    int currentHealth      {25};
    float verticalVelocity {0};
    float width            {25};
    float height           {25};
    Color color            {255, 255, 255, 255};

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

    // Entity(EnemyTag enTag, Vector2 spawnPos) { // Enemy
    //     tag = enemy;
    //     enemyTag = enTag;

    //     switch (enemyTag)
    //     {
    //     case lizardfolk:
    //         maxHealth = 25;
    //         width = 50;
    //         height = 90;
    //         break;

    //     case rakshasa:
    //         maxHealth = 50;
    //         width = 50;
    //         height = 80;
    //         break;
        
    //     default:
    //         maxHealth = 25;
    //         width = 50;
    //         height = 80;
    //         break;
    //     }

    //     currentHealth = maxHealth;
    //     position = spawnPos;
    // }

    bool isEnemy()  {return tag == enemy;}
    bool isPlayer() {return tag == player;}

    PlayerTag getPlayerTag() {return playerTag;}
    std::string getName() {return name;}
    void setName(std::string newName) {
        name = newName;
    }

    float getVerticalVelocity() {
        return verticalVelocity;
    }
    void setVerticalVelocity(float newVelocity) {
        verticalVelocity = newVelocity;
    }
    void increaseVerticalVelocity(float increment) {
        verticalVelocity += increment;
    }
    void decreaseVerticalVelocity(float decrement) {
        verticalVelocity -= decrement;
    }

    void setWidth(int newW) {
        width = newW;
    }
    int getWidth() {return width;}
    void setHeight(int newH) {
        height = newH;
    }
    int getHeight() {return height;}
    Rectangle getHitbox() {
        return {position.x - (width/2), position.y - height, width, height};
    }
    void setColor(Color newColor) {
        color = newColor;
    }
    Color getColor() {return color;}

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


    int getMaxHP() {return maxHealth;}
    void setMaxHP(int newHP) {
        maxHealth = newHP;
    }
    int getCurrentHP() {return currentHealth;}
    void setCurrentHP(int newHP) {
        currentHealth = newHP;
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