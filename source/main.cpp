#include "control.hpp"

int main() {

    init();

    map.player = PlayerCharacter("Mario", 100);

    while(!WindowShouldClose()) {
        update();
        render();
    }

    CloseWindow();

    return 0;
}