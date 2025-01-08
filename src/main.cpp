#include "StandardGame.hpp"

int main() {

    StandardGame game = StandardGame();

    game.start();
    game.loop();
    game.end();

    return 0;
}
