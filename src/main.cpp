#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Board.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Conway Revised", sf::Style::Titlebar | sf::Style::Close);
    sf::Event event;

    Board board = Board(10, 100, 100, sf::Vector2f(0, 0));
    board.toggleCell(0, 1);
    board.toggleCell(1, 2);
    board.toggleCell(2, 0);
    board.toggleCell(2, 1);
    board.toggleCell(2, 2);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
        }

        board.update();

        window.clear(sf::Color::White);

        board.draw(window);

        window.display();
    }

    return 0;
}
