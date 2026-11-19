#include "projekt2.h"

Pilka::Pilka(int sX, int sY, int svx, int svy, int sradius) {
  if (sradius >= 0) {
    radius = sradius;
  } else {
    radius = 1;
  }
  x = sX;
  y = sY;
  vx = svx;
  vy = svy;
}

void Pilka::przesun() {
  x += vx;
  y += vy;
}

int main() {
  Pilka p1(70, 30, -5, -8, 20);
  for (int i = 0; i < 100; i++) {
    p1.przesun();
    p1.kolizjaSciana();
    std::cout << "Krok: " << i << " | x= " << p1.getX() << " y= " << p1.getY()
              << " | vx= " << p1.getVx() << " vy= " << p1.getVy() << "\n";
  }
}
