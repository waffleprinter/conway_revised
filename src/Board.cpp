#include "Board.h"

Board::Board(int cellSize, int rows, int cols, sf::Vector2f position) {
    this->cellSize = cellSize;
    this->rows = rows;
    this->cols = cols;
    this->position = position;

    this->cells = std::vector<std::vector<bool>>(rows, std::vector<bool>(false));
}

void Board::toggleCell(int row, int col) {

}

void Board::update() {

}

void Board::draw(sf::RenderWindow &window) {

}
