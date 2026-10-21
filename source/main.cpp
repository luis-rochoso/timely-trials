#include "control.hpp"

int main() {

    init();

    map.player = Entity(bakali);

    while(!WindowShouldClose()) {
        update();
        render();
    }

    CloseWindow();

    return 0;
}