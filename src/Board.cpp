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
    updateLiveNeighbors(row, col, this->cells[row][col] ? 1 : -1);
}

void Board::updateLiveNeighbors(int row, int col, int change) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int neighborRow = row + i;
            int neighborCol = col + j;

            if (row == neighborRow && col == neighborCol)
                continue;

            if (0 <= neighborRow && neighborRow < this->rows && 0 <= neighborCol && neighborCol < this->cols)
                this->liveNeighbors[neighborRow][neighborCol] += change;
        }
    }
}

void Board::update() {

}

void Board::draw(sf::RenderWindow &window) {

}
