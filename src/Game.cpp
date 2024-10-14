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

            if (this->event.key.code == sf::Keyboard::Right && this->isPaused) {
                this->board.update();
            }

            if (this->event.key.code == sf::Keyboard::Up) {
                this->updatesPerSecond *= 2;
                this->updateInterval = sf::seconds(1.0f / updatesPerSecond);
            }

            if (this->event.key.code == sf::Keyboard::Down) {
                this->updatesPerSecond /= 2;
                this->updateInterval = sf::seconds(1.0f / updatesPerSecond);
            }
        }

        if (this->event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                float cellSize = this->board.getCellSize();
                sf::Vector2f boardPosition = this->board.getPosition();

                int row = (this->event.mouseButton.y - boardPosition.y) / (cellSize + 1);
                int col = (this->event.mouseButton.x - boardPosition.x) / (cellSize + 1);

                this->board.toggleCell(row, col);
            }
        }
    }
}

void Game::update() {
    if (!this->isPaused)
        this->board.update();
}

void Game::draw() {
    this->window.clear(sf::Color::White);

    this->board.draw(window);

    this->window.display();
}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (this->window.isOpen()) {
        this->pollEvents();

        sf::Time elapsed = clock.restart();
        timeSinceLastUpdate += elapsed;

        while (timeSinceLastUpdate >= updateInterval) {
            this->update();
            timeSinceLastUpdate -= updateInterval;
        }

        this->draw();
    }
}

