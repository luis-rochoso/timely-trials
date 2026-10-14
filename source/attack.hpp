#ifndef ATTACK_HPP
#define ATTACK_HPP

#include "raylib.h"
#include "timer.hpp"
#include <string>

class MeleeAttack {

    std::string name;
    int damage;

    Rectangle hurtbox;

    Timer uptime;

};

class ProjectileAttack {

};

#endif