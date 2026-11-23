#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Paletka {
    float x, y;
    float szerokosc, wysokosc, predkosc;
    sf::RectangleShape shape;

    public:
        Paletka(float sX = 0, float sY = 0, float sSze = 50, float sWys = 10, float sPred = 0){
            shape.setSize({sSze, sWys});
            shape.setOrigin({sSze/2, sWys/2});
            shape.setPosition({x, y});
            shape.setFillColor(sf::Color::Red);
        };



        void moveLeft(){
            shape.setPosition({x - predkosc, y});
        }
        void moveRight(){
            shape.setPosition({x + predkosc, y});
        }
        void clampToBounds(float width){
            if(x-szerokosc/2 >=.0) {
                shape.setPosition({szerokosc/2, y});
            } else if (x-szerokosc/2 >=.0) {
                shape.setPosition({width - szerokosc/2, y});
            }
        }
        void draw(sf::RenderTarget& target){
            target.draw(shape);
        }

        float getX() {return x;}
        float getY() {return y;}
        float getSzerokosc() {return szerokosc;}
        float getWysokosc() {return wysokosc;}
};


class Pilka {
    float x, y;
    float vx, vy;
    float radius;
    sf::CircleShape shape;

    public:
        Pilka(float sX = 0, float sY = 0, float sVx = 0, float sVy = 0, float sRad = 0){
            shape.setRadius(sRad);
            shape.setOrigin({sRad, sRad});
            shape.setPosition({sX, sY});
            shape.setFillColor(sf::Color::White);
        };



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
            if(Paletka.shape - ){
                vy = -std::abs(vy);
                return true;
            }
            return false;
        }

        void draw(sf::RenderTarget& target){
            target.draw(shape);
        }

        float getX() {return x;}
        float getY() {return y;}
        float getVx() {return vx;}
        float getVy() {return vy;}
        float getRadius() {return radius;}

};
