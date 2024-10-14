#ifndef CONWAY_REVISED_GAME_H
#define CONWAY_REVISED_GAME_H

#include <SFML/Graphics.hpp>
#include <Board.h>

class Game {
private:
    sf::RenderWindow window;
    sf::Event event{};
    Board board;

    float updatesPerSecond = 1.0f;
    sf::Time updateInterval = sf::seconds(1.0f / updatesPerSecond);
    bool isPaused = true;

    void pollEvents();
    void update();
    void draw();

public:
    explicit Game(Board &board);

    void run();
};


#endif //CONWAY_REVISED_GAME_H
