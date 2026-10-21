#include "control.hpp"

int main() {

    init();

    map.player = Entity("Mario", 100);

    while(!WindowShouldClose()) {
        update();
        render();
    }

    CloseWindow();

    return 0;
}