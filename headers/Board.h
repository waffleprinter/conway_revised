#ifndef CONWAY_REVISED_BOARD_H
#define CONWAY_REVISED_BOARD_H

#include <vector>
#include <SFML/Graphics.hpp>

class Board {
private:
    int cellSize;
    int rows;
    int cols;
    sf::Vector2f position;

    std::vector<std::vector<bool>> cells;
    std::vector<std::vector<int>> liveNeighbors;

public:
    Board(int cellSize, int rows, int cols, sf::Vector2f position);

    void toggleCell(int row, int col);
    void updateLiveNeighbors(int row, int col, int change);
    void update();
    void draw(sf::RenderWindow &window);
};


#endif //CONWAY_REVISED_BOARD_H
