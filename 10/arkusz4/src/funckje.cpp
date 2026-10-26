#include "funkcje.hpp"
#include <iomanip>
#include <iostream>

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
