#include <SFML/Graphics.hpp>
#include <iostream>

/*
g++ -Wall -Wextra -Werror solver.cpp -o app.exe -lsfml-graphics -lsfml-window -lsfml-system
.\app.exe
*/

struct Pincel {
    sf::Font font;
    sf::Text text;
    sf::RenderWindow& window;

    Pincel(sf::RenderWindow& window) : window(window) {
        if (font.loadFromFile("FiraCode-Bold.ttf")) {
            std::cout << "Font loaded" << std::endl;
        }
        else {
            std::cout << "Font not loaded" << std::endl;
        }
        text.setFont(font);
    }

    void write(std::string str, int x, int y, int size, sf::Color color) {
        text.setString(str);
        text.setCharacterSize(size);
        text.setPosition(x, y);
        text.setFillColor(color);
        window.draw(text);
    }
};

struct Bubble {
    int x;
    int y;
    int speed;
    char letter;
    bool alive { true };
    static const int radius { 10 };

    Bubble(int x, int y, char letter, int speed) {
        this->x = x;
        this->y = y;
        this->speed = speed;
        this->letter = letter;
    }

    void update() {
        this->y += this->speed;
    }

    void draw(sf::RenderWindow& window) {
        sf::CircleShape bubble (Bubble::radius);
        bubble.setPosition(x, y);
        bubble.setFillColor(sf::Color::White);
        window.draw(bubble);

        static Pincel pencil(window);
        pencil.write(std::string(1, letter), x + 0.2 * Bubble::radius, y, Bubble::radius * 1.5, sf::Color::Blue);
    }
};

struct Game {
    sf::RenderWindow window;

    Game(): window(sf::VideoMode(800, 600), "Bubbles") {
        window.setFramerateLimit(60);
    }

    void process_events() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    void draw() {
        window.clear();

        static Bubble bubble(200, 100, 'B', 2);
        bubble.update();
        bubble.draw(window);

        window.display();
    }

    void main_loop() {
        while (window.isOpen()) {
            process_events();
            draw();
        }
    }
};

int main() {

    Game game;
    game.main_loop();
    return 0;
}