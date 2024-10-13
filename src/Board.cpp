#include "Board.h"

Board::Board(float cellSize, int rows, int cols, sf::Vector2f position) {
    this->cellSize = cellSize;
    this->rows = rows;
    this->cols = cols;
    this->position = position;

    this->cells = std::vector<std::vector<bool>>(this->rows, std::vector<bool>(this->cols, false));
}

sf::Vector2f Board::getPosition() {
    return this->position;
}

float Board::getCellSize() {
    return this->cellSize;
}

void Board::toggleCell(int row, int col) {
    this->cells[row][col] = !this->cells[row][col];
    this->changedCells.insert({row, col});
}

void Board::update() {
    std::set<std::pair<int, int>> cellsToCheck; // cellsToCheck = changedCells + neighbors of changedCells

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

    this->changedCells.clear(); // We want a clean slate for the new changes

    // Temporary vector since, otherwise, changing a cell would inadvertently affect the next cell
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

        // Update cells based on rules of Conway's Game of Life
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
    sf::VertexArray vertices(sf::Quads, this->rows * this->cols * 4);

    for (int row = 0; row < this->rows; row++) {
        for (int col = 0; col < this->cols; col++) {
            int index = (row * this->cols + col) * 4;

            float x = this->position.x + (float)col * (cellSize + 1);
            float y = this->position.y + (float)row * (cellSize + 1);

            vertices[index].position = sf::Vector2f(x, y);
            vertices[index + 1].position = sf::Vector2f(x + this->cellSize, y);
            vertices[index + 2].position = sf::Vector2f(x + this->cellSize, y + this->cellSize);
            vertices[index + 3].position = sf::Vector2f(x, y + this->cellSize);

            sf::Color color = this->cells[row][col] ? sf::Color::Green : sf::Color::Black;

            for (int i = 0; i < 4; i++) {
                vertices[index + i].color = color;
            }
        }
    }

    window.draw(vertices);
}
