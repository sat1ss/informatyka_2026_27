#include <iostream>

class Pilka {
private:
  int x;
  int y;
  int vx;
  int vy;
  int radius;

public:
  Pilka(int sX, int sY, int svx, int svy, int sradius);
  void przesun();
  void odbijX() { vx = -vx; };
  void odbijY() { vy = -vy; };

  void kolizjaSciana() {
    if (getX() < 0 + radius || getX() > 640) {
      odbijX();
      std::cout << "Boom X\n";
    }
    if (getY() < 0 + radius || getY() > 480) {
      odbijY();
      std::cout << "Boom Y\n";
    }
  };

  int getX() { return x; }
  int getY() { return y; }
  int getVx() { return vx; }
  int getVy() { return vy; }
};
