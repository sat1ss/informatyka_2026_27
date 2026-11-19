#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <optional>


int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Pierwszy program :)");
    window.setFramerateLimit(60);

    //prostokat
    sf::RectangleShape prostokat(sf::Vector2f(150,100));
    prostokat.setFillColor(sf::Color::Red);
    prostokat.setPosition(sf::Vector2f(25, 300));

    //slonce
    sf::CircleShape slonce(50);
    slonce.setFillColor(sf::Color::Yellow);
    slonce.setPosition(sf::Vector2f(500,100));

    while (window.isOpen()) {
        while(const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear();
        window.draw(prostokat);
        window.draw(slonce);
        window.display();
    }
}
