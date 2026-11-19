#include <cstdlib>
#include <cstring>
#include <ctime>
#include <stdio.h>

struct Pomiar {
  char czas[26];
  float temperatura;
  float wilgotnosc;
  float cisnienie;
};

struct Stacja {
  int id;
  char nazwa[40];
  char lokalizacja[60];
};

struct Rekord {
  Stacja stacja;
  Pomiar pomiar;
};

struct Stacja stacje[] = {
    {1, "Gdansk", "Gdansk, Politechniczna 1"},
    {2, "Sopot", "Sopot, Niepodleglosci 2"},
    {3, "Gdynia", "Gdynia, Swietojanska 3"},
};

int main() {
  // struct Stacja s1 = {1, "Gdansk", "Gdansk, Politechniczna 1"};
  struct Rekord dane[10];

  srand(time(NULL));

  time_t currentTime;
  time(&currentTime);
  for (int i = 0; i < 10; i++) {
    dane[i].stacja = stacje[1];

    strcpy(dane[i].pomiar.czas, ctime(&currentTime));
    dane[i].pomiar.czas[strlen(dane[i].pomiar.czas) - 1] = '\0';

    dane[i].pomiar.temperatura = rand() % 75 - 35;
    dane[i].pomiar.wilgotnosc = rand() % 101;
    dane[i].pomiar.cisnienie = 980 + rand() % 50;
  }

  printf("id: %d, nazwa: %s, lokalizacja: %s\n", dane[0].stacja.id,
         dane[0].stacja.nazwa, dane[0].stacja.lokalizacja);

  float temp_max = -100;
  float temp_min = 100;
  float pre_sum = 0;
  float hum_sum = 0;

  for (int i = 0; i < 10; i++) {
    printf("czas: %s, t: %.2f C, h: %.2f %%, p: %.2f hPa\n",
           dane[i].pomiar.czas, dane[i].pomiar.temperatura,
           dane[i].pomiar.wilgotnosc, dane[i].pomiar.cisnienie);

    pre_sum += dane[i].pomiar.cisnienie;
    hum_sum += dane[i].pomiar.wilgotnosc;

    if (dane[i].pomiar.temperatura > temp_max) {
      temp_max = dane[i].pomiar.temperatura;
    }
    if (dane[i].pomiar.temperatura < temp_min) {
      temp_min = dane[i].pomiar.temperatura;
    }
  }
  printf(
      "Maksmalna temperatura wynosi: %.2f, Minimalna: %.2f, Średnie cisnienie "
      "to: %.2f, a wilgotność to : %.2f\n",
      temp_max, temp_min, pre_sum / 10, hum_sum / 10);

  return 0;
}

// Zdanie B

struct ProbaMocy {
  char czas[30];
  float moc_w;
};
