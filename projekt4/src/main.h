#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>

class Paletka {
    float x, y;
    float szerokosc, wysokosc, predkosc;
    sf::RectangleShape shape;

    public:
        Paletka(float sX = 0, float sY = 0, float sSze = 50, float sWys = 10, float sPred = 0)
        : x(sX), y(sY), szerokosc(sSze), wysokosc(sWys), predkosc(sPred){
            shape.setSize({szerokosc, wysokosc});
            shape.setOrigin({szerokosc/2, wysokosc/2});
            shape.setPosition({x, y});
            shape.setFillColor(sf::Color::Red);
        }

        void moveLeft(){
            shape.setPosition({x -= predkosc, y});
        }
        void moveRight(){
            shape.setPosition({x += predkosc, y});
        }
        void clampToBounds(float width){
            if(x-szerokosc/2 <=.0) {
                x = szerokosc / 2;
            } else if (x+szerokosc/2 >= width) {
                x = width - szerokosc/2;
            }
            shape.setPosition({x, y});
        }
        void draw(sf::RenderTarget& target){
            target.draw(shape);
        }

        float getX() const {return x;}
        float getY() const {return y;}
        float getSzerokosc() const {return szerokosc;}
        float getWysokosc() const {return wysokosc;}
};


class Pilka {
    float x, y;
    float vx, vy;
    float radius;
    sf::CircleShape shape;

    public:
        Pilka(float sX = 0, float sY = 0, float sVx = 0, float sVy = 0, float sRad = 0)
        : x(sX), y(sY), vx(sVx), vy(sVy), radius(sRad) {
            shape.setRadius(radius);
            shape.setOrigin({radius, radius});
            shape.setPosition({x, y});
            shape.setFillColor(sf::Color::White);
        }


        void move() {
            x += vx;
            y += vy;
            shape.setPosition({x, y});
        }
        void bounceX(){
            vx = - vx;
        }
        void bounceY(){
            vy = -vy;
        }
        void collideWalls(float width, float height) {
            if(x - radius <= 0 || x + radius >= width) {
                bounceX();
            }
            if(y - radius <= 0) {
                bounceY();
            }
        }

        bool collidePaddle(const Paletka& p){
            float pilkaLewa = x - radius;
            float pilkaPrawa = x + radius;
            float pilkaGora = y - radius;
            float pilkaDol = y + radius;

            float paletkaLewa = p.getX() - p.getSzerokosc()/2;
            float paletkaPrawa = p.getX() + p.getSzerokosc()/2;
            float paletkaGora = p.getY() - p.getWysokosc()/2;
            float paletkaDol =  p.getY() + p.getWysokosc()/2;


            bool nakladaSie = pilkaPrawa >= paletkaLewa && pilkaLewa <= paletkaPrawa && pilkaDol >= paletkaGora && pilkaGora <= paletkaDol;

            if(nakladaSie && vy > 0){
                vy = -std::abs(vy);
                y = paletkaGora - radius;
                shape.setPosition({x, y});
                return true;
            }
            return false;
        }

        void draw(sf::RenderTarget& target){
            target.draw(shape);
        }

        float getX() const {return x;}
        float getY() const {return y;}
        float getVx() const {return vx;}
        float getVy() const {return vy;}
        float getRadius() const {return radius;}

};
