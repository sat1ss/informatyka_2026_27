#include "main.h"

int main() {
    const float WIDTH = 640.f;
    const float HEIGHT = 480.f;
    sf::RenderWindow window(sf::VideoMode({640u, 480u}), "Arkanoid test");

    Paletka pal(320.f, 440.f, 100.f, 20.f, 8.f); // x,y,szer,wys, predkosc
    Pilka pilka(320.f, 200.f, 4.f, 3.f, 8.f); // x,y,vx,vy,radius

    while (window.pollEvent(event)) { if (event.is<sf::Event::Closed>()) window.close(); }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) { pal.moveLeft(); }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) { pal.moveRight(); }
    pal.clampToBounds(WIDTH);

    pilka.move(); pilka.collideWalls(WIDTH, HEIGHT); if (pilka.collidePaddle(pal)) { std::cout << "HIT PADDLE\n"; }

    if (pilka.getY() - pilka.getRadius() > HEIGHT) { std::cout << "MISS! KONIEC GRY\n"; window.close();

        window.clear(sf::Color(20, 20, 30));
        pal.draw(window);
        pilka.draw(window);
        window.display();

    std::cout << "x=" << pilka.getX() << " y=" << pilka.getY() << " vx=" << pilka.getVx() << " vy=" << pilka.getVy() << std::endl;
    return 0;
}
