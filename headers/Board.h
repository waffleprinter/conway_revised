#ifndef CONWAY_REVISED_BOARD_H
#define CONWAY_REVISED_BOARD_H

#include <vector>
#include <set>
#include <SFML/Graphics.hpp>

class Board {
private:
    int cellSize;
    int rows;
    int cols;
    sf::Vector2f position;

    std::vector<std::vector<bool>> cells;
    std::set<std::pair<int, int>> changedCells;

public:
    Board(int cellSize, int rows, int cols, sf::Vector2f position);

    void toggleCell(int row, int col);
    void update();
    void draw(sf::RenderWindow &window);
};


#endif //CONWAY_REVISED_BOARD_H
