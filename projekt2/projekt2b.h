#include <iostream>

class Paletka {
private:
  int x, y, szerokosc, vx;

public:
  Paletka(int sX, int sY, int sSzerokosc, int sVx);
  int getX() { return x; }
  int getY() { return y; }
  int getVx() { return vx; }
  int getSzerokosc() { return szerokosc; }

  void przesunLewo() { x -= vx; }
  void przesunPrawo() { x += vx; }

  void ograniczRuch(int width) {
    if (x <= 0) {
      vx = -vx;
      std::cout << "Lewa Granica\n";
    } else if (x >= 640) {
      vx = -vx;
      std::cout << "Prawa Granica\n";
    }
  }
};
