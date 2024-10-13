#include "Board.h"
#include "Game.h"

int main() {
    Board board = Board(10, 50, 50, sf::Vector2f(0, 0));

    board.toggleCell(0, 1);
    board.toggleCell(1, 2);
    board.toggleCell(2, 0);
    board.toggleCell(2, 1);
    board.toggleCell(2, 2);


    Game game = Game(board);

    game.run();

    return 0;
}
