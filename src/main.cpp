#include "Board.h"
#include "Game.h"

int main() {
    Board board = Board(10, 10, 10, sf::Vector2f(0, 0));
    Game game = Game(board);

    game.run();

    return 0;
}
