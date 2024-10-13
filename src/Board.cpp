#include "Board.h"

Board::Board(int cellSize, int rows, int cols, sf::Vector2f position) {
    this->cellSize = cellSize;
    this->rows = rows;
    this->cols = cols;
    this->position = position;

    this->cells = std::vector<std::vector<bool>>(this->rows, std::vector<bool>(this->cols, false));
    this->liveNeighbors = std::vector<std::vector<int>>(this->rows, std::vector<int>(this->cols, 0));
}

void Board::toggleCell(int row, int col) {
    this->cells[row][col] = !this->cells[row][col];
}

void Board::update() {

}

void Board::draw(sf::RenderWindow &window) {
    for (int row = 0; row < this->rows; row++) {
        for (int col = 0; col < this->cols; col++) {
            sf::RectangleShape cell;
            cell.setSize(sf::Vector2f(this->cellSize, this->cellSize));
            cell.setPosition(this->position.x + col * (this->cellSize + 1), this->position.y + row * (this->cellSize + 1));
            cell.setFillColor(this->cells[row][col] ? sf::Color::Green : sf::Color::Black);

            window.draw(cell);
        }
    }
}
