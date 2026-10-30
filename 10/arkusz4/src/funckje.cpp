#include "funkcje.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>

int sumaCyfr(int n) {
  int suma = 0;
  while (n > 0) {
    suma += n % 10;
    n /= 10;
  }
  return suma;
}

int nwd(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

bool czyPierwsza(int n) {
  if (n <= 1) {
    return false;
  }
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int potega(int podstawa, int wykladnik) {
  int wynik = 1;
  for (int i = 0; i < wykladnik; ++i) {
    wynik *= podstawa;
  }
  return wynik;
}

double potega(double podstawa, int wykladnik) {
  double wynik = 1.0;
  for (int i = 0; i < wykladnik; ++i) {
    wynik *= podstawa;
  }
  return wynik;
}

void potega(int &wynik, int podstawa, int wykladnik) {
  wynik = 1;
  for (int i = 0; i < wykladnik; ++i) {
    wynik *= podstawa;
  }
}

void ileMogeKupic(double zlotowki) {
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "Za " << zlotowki << " PLN mogę kupić:" << std::endl;
  std::cout << przelicz(zlotowki, EUR) << " EUR" << std::endl;
  std::cout << przelicz(zlotowki, USD) << " USD" << std::endl;
  std::cout << przelicz(zlotowki, NOK) << " NOK" << std::endl;
}

void ileMogeKupic(double zlotowki, double kurs) {
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "Za " << zlotowki << " PLN mogę kupić:" << std::endl;
  std::cout << przelicz(zlotowki, kurs) << " w wybranej walucie" << std::endl;
}

double przelicz(double pln, double kurs) { return pln / kurs; }

void reszta(int zaplata, int cena) {
  if (zaplata < cena) {
    cena -= zaplata;
    std::cout << "Zbyt mała kwota zapłaty, brakuje: " << zaplata << std::endl;
    return;
  }
  int reszta = zaplata - cena;
  std::cout << "Reszta wynosi: " << reszta / 100 << "," << reszta % 100
            << " zl: ";

  int monety[4] = {1, 50, 20, 10};
  for (int i = 0; i < 4; ++i) {
    if (i == 0) {
      std::cout << reszta / (monety[i] * 100) << " x " << monety[i] << "zl, ";
      reszta %= (monety[i] * 100);
    } else {
      std::cout << reszta / monety[i] << " x " << monety[i] << "gr, ";
      reszta %= monety[i];
    }
  }
  std::cout << std::endl;
}

void obliczPlytki(int szerSciany, int szerPlytki) {
  if (szerSciany <= 0 || szerPlytki <= 0) {
    std::cout << "Nieprawidłowe wymiary." << std::endl;
    return;
  }
  int liczbaPlytek = szerSciany / szerPlytki;
  if (liczbaPlytek % 2 == 0) {
    liczbaPlytek--;
  }

  double odstep = (szerSciany - liczbaPlytek * szerPlytki) / 2.0;

  std::cout << "\n| ";
  for (int i = 0; i < liczbaPlytek; ++i) {
    if (i % 2 == 0) {
      std::cout << "B";
    } else {
      std::cout << "C";
    }
  }
  std::cout << " |" << std::endl;
  std::cout << "Liczba płytek:" << liczbaPlytek << std::endl;
  std::cout << "Odległość od ściany: " << odstep << std::endl;
  std::cout << "Sprawdzenie: " << liczbaPlytek << "*" << szerPlytki << " + 2*"
            << odstep << " = " << (liczbaPlytek * szerPlytki + 2 * odstep)
            << std::endl;
}

void wypiszPunkty(double r) {
  int max_val = static_cast<int>(r);
  int lp = 1;

  for (int x = -max_val; x <= max_val; x++) {
    for (int y = -max_val; y <= max_val; y++) {
      if (x * x + y * y <= r * r) {
        std::cout << "Punkt " << lp << ": (" << x << ", " << y << ")\n";
        lp++;
      }
    }
  }
}

int pobierzDodatnia(const std::string &etykieta) {
  int val = 0;
  std::cout << etykieta;
  while (!(std::cin >> val) || val <= 0) {
    std::cout << "Wartość musi być liczbą dodatnią! Spróbuj ponownie: ";
  }
  return val;
}

void pobierzUlamek(int &licznik, int &mianownik, const std::string &nazwa) {
  std::cout << "Podaj " << nazwa << " ulamek (licznik mianownik):\n";
  while (!(std::cin >> licznik >> mianownik) || mianownik <= 0) {
    std::cout << "Mianownik musi być liczbą dodatnią! Podaj ponownie (licznik "
                 "mianownik): ";
  }
}

bool czyAutomorficzna(int n) {
  int kwadrat = n * n;
  while (n > 0) {
    if (n % 10 != kwadrat % 10) {
      return false;
    }
    n /= 10;
    kwadrat /= 10;
  }
  return true;
}

// zadania 11-13
double naRadiany(double stopnie) { return stopnie * PI / 180.0; }

double pozycjaX(double v0, double rad, double t) {
  return v0 * std::cos(rad) * t;
}

double pozycjaY(double v0, double rad, double t) {
  return v0 * std::sin(rad) * t - (G * t * t) / 2.0;
}

double czasLotu(double v0, double rad) {
  return (2.0 * v0 * std::sin(rad)) / G;
}

int losujRuch() {
  static std::mt19937 generator(std::random_device{}());
  std::uniform_int_distribution<int> distribution(1, 3);
  return distribution(generator);
}

int wynikRundy(int gracz, int komputer) {
  if (gracz == komputer) {
    return 0;
  } else if ((gracz == 1 && komputer == 3) || (gracz == 2 && komputer == 1) ||
             (gracz == 3 && komputer == 2)) {
    return 1;
  } else {
    return -1;
  }
}
std::string ruchToString(int ruch) {
  switch (ruch) {
  case 1:
    return "Kamien";
  case 2:
    return "Papier";
  case 3:
    return "Nozyce";
  default:
    return "Nieznany ruch";
  }
}
void wynikHistorii(std::vector<runda> &r) {

  std::cout << "  Gracz   |   Komputer    | Wynik\n";
  std::cout << "-----------------------------------\n";
  for (size_t i = 0; i < r.size(); i++) {
    std::cout << "    " << r[i].gracz << "(" << ruchToString(r[i].gracz) << ")"
              << "   |     " << r[i].komputer << "("
              << ruchToString(r[i].komputer) << ")"
              << "    |  " << r[i].wynik << "\n";
  }
}
