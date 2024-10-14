#include "Board.h"
#include "Game.h"

int main() {
    Board board = Board(10, 50, 80, sf::Vector2f(100, 85));
    Game game = Game(board);

    game.run();

    return 0;
}
