#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "raylib.h"
#include "entity.hpp"
#include <vector>
// #include <unordered_map>

// Environment Item: hitbox, traversable, color
struct EnvItem {
    Rectangle hitbox;
    bool traversable;
    Color color;
};

class Level {

    std::vector<EnvItem> environmentItems;

    public:
    Entity player;
    std::vector<Entity> enemies;

    Level() = default;

    void setLayout(std::vector<EnvItem> layout) {
        environmentItems = layout;
    }

    std::vector<EnvItem>* getEnvItems() {return &environmentItems;}

};

#endif