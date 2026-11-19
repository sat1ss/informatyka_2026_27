#include "projekt2b.h"

Paletka::Paletka(int sX, int sY, int sSzerokosc, int sVx) {
  x = sX;
  y = sY;
  szerokosc = sSzerokosc;
  vx = sVx;
}

int main() {
  Paletka p1(320, 450, 80, 10);
  for (int i = 0; i < 100; i++) {

    std::cout << "Krok: " << i << " | x: " << p1.getX() << " y: " << p1.getY()
              << " szerokosc: " << p1.getSzerokosc() << " | vx: " << p1.getVx()
              << "\n";
  }
}
