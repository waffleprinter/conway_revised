#include "Game.h"

Game::Game(Board &board) : board(board) {
    this->window.create(sf::VideoMode(1080, 720), "Conway's Game of Life", sf::Style::Titlebar | sf::Style::Close);
}

void Game::pollEvents() {
    while (this->window.pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed)
            this->window.close();

        if (this->event.type == sf::Event::KeyPressed) {
            if (this->event.key.code == sf::Keyboard::Escape)
                this->window.close();

            if (this->event.key.code == sf::Keyboard::Space)
                this->isPaused = !this->isPaused;
        }
    }
}

void Game::update() {
    if (this->isPaused)
        return;

    this->board.update();
}

void Game::draw() {
    this->window.clear(sf::Color::White);

    this->board.draw(window);

    this->window.display();
}

void Game::run() {
    while (this->window.isOpen()) {
        this->pollEvents();
        this->update();
        this->draw();
    }
}

