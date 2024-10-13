#include "Board.h"

Board::Board(int cellSize, int rows, int cols, sf::Vector2f position) {
    this->cellSize = cellSize;
    this->rows = rows;
    this->cols = cols;
    this->position = position;

    this->cells = std::vector<std::vector<bool>>(this->rows, std::vector<bool>(this->cols, false));
}

void Board::toggleCell(int row, int col) {
    this->cells[row][col] = !this->cells[row][col];
    this->changedCells.insert({row, col});
}

void Board::update() {
    std::set<std::pair<int, int>> cellsToCheck;

    for (const std::pair<int, int> &cell : this->changedCells) {
        cellsToCheck.insert(cell);

        int row = cell.first;
        int col = cell.second;

        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr == 0 && dc == 0) continue; // Skip the cell itself

                int neighborRow = row + dr;
                int neighborCol = col + dc;

                if (0 <= neighborRow && neighborRow < this->rows && 0 <= neighborCol && neighborCol < this->cols)
                    cellsToCheck.insert({neighborRow, neighborCol});
            }
        }
    }

    this->changedCells.clear();

    std::vector<std::vector<bool>> newCells = this->cells;

    for (const std::pair<int, int> &cell : cellsToCheck) {
        int row = cell.first;
        int col = cell.second;

        int liveNeighbors = 0;

        // THIS IS REPEATED RIGHT ABOVE, SHOULD MAKE ITERABLE FOR NEIGHBORS OF CELL
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr == 0 && dc == 0) continue; // Skip the cell itself

                int neighborRow = row + dr;
                int neighborCol = col + dc;

                if (0 <= neighborRow && neighborRow < this->rows && 0 <= neighborCol && neighborCol < this->cols)
                    if (cells[neighborRow][neighborCol])
                        liveNeighbors++;
            }
        }

        if (this->cells[row][col]) {
            if (liveNeighbors < 2 || liveNeighbors > 3) {
                newCells[row][col] = false;
                this->changedCells.insert({row, col});
            }
        } else {
            if (liveNeighbors == 3) {
                newCells[row][col] = true;
                this->changedCells.insert({row, col});
            }
        }
    }

    this->cells = newCells;
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
