#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "raylib.h"
#include "playerCharacter.hpp"
#include <vector>

// Environment Item: hitbox, traversable, color
struct EnvItem {
    Rectangle hitbox;
    bool traversable;
    Color color;
};

class Level {

    std::vector<EnvItem> environmentItems;

    public:
    PlayerCharacter player;

    Level();

    Level(std::vector<EnvItem> layout) {
        environmentItems = layout;
    }

    std::vector<EnvItem>* getEnvItems() {return &environmentItems;}

};

#endif