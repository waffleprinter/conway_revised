#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(720, 480), "Conway Revised", sf::Style::Titlebar | sf::Style::Close);
    sf::Event event;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
        }

        window.clear();

        window.display();
    }

    return 0;
}
