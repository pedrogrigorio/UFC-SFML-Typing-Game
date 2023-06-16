#include <SFML/Graphics.hpp>
#include <iostream>

/*
g++ -Wall -Wextra -Werror solver.cpp -o app.exe -lsfml-graphics -lsfml-window -lsfml-system
.\app.exe
*/

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Bubbles");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        
        window.display();
    }

    return 0;
}