#include "domowe.hpp"
#include <bit>
#include <iomanip>
#include <iostream>
#include <ostream>

void zadanie1() {
  int a = 0, b = 0, c = 0;
  std::cout << "Wspolczynniki funkcji kwadratowej\n";
  while (a == 0) {
    std::cout << "Podaj a: ";
    std::cin >> a;
  }
  std::cout << "Podaj b: ";
  std::cin >> b;
  std::cout << "Podaj c: ";
  std::cin >> c;

  std::cout << "*****************************************************\n";
  std::cout << "Funkcja kwadratowa: f(x) = ";
  if (a != 1)
    std::cout << a;
  std::cout << "x^2 ";
  if (b > 0)
    std::cout << "+ " << b << "x ";
  else if (b < 0)
    std::cout << "- " << -b << "x ";
  if (c > 0)
    std::cout << "+ " << c << " ";
  else if (c < 0)
    std::cout << "- " << -c << " ";
  std::cout << "\n*****************************************************\n";

  double delta = b * b - 4 * a * c;
  if (delta > 0) {
    double x1 = (-b - sqrt(delta)) / (2 * a);
    double x2 = (-b + sqrt(delta)) / (2 * a);
    std::cout << "Funkcja posiada dwa miejsca zerowe: x1 = " << x1
              << ", x2 = " << x2 << std::endl;
  } else if (delta == 0) {
    double x = -b / (2 * a);
    std::cout << "Funkcja posiada jedno miejsce zerowe: x = " << x << std::endl;
  } else {
    std::cout << "Funkcja nie posiada miejsc zerowych." << std::endl;
  }
}

void zadanie4() {
  int dlugosc = 0;
  std::cout << "Podaj dlugosc ciagu: ";
  std::cin >> dlugosc;
  while (dlugosc <= 1) {
    std::cout << "Dlugosc musi byc wieksza od 1. Podaj dlugosc ciagu: ";
    std::cin >> dlugosc;
  }
  while (dlugosc >= 1) {
    int liczbaGwiazd = 0;
    while (liczbaGwiazd < dlugosc) {
      std::cout << "*";
      liczbaGwiazd++;
    }
    std::cout << "\n";
    dlugosc--;
  }
}

// tabliczka mnozenia 10x10
void zadanie5() {
  std::cout << std::setw(4) << "*|";
  for (int i = 1; i <= 10; i++) {
    std::cout << std::setw(4) << i;
  }
  std::cout << std::endl;
  std::cout << std::setfill('-') << std::setw(44) << "" << std::setfill(' ')
            << std::endl;

  std::cout.fill(' ');
  for (int idx = 1; idx <= 10; idx++) {
    std::cout << std::setw(3) << idx << "|";
    for (int row = 1; row <= 10; row++) {
      int wynik = idx * row;
      std::cout << std::setw(4) << wynik;
    }

    std::cout << std::endl;
  }
}

// zaliczenie przedmiotu Programowanie I
void zadanie6() {
  double punkty[5]; // kolos1, kolos2, projekt, aktywnosc, egzamin
  int maxPunkty[5] = {25, 25, 20, 10, 20};
  bool czyZdane[5];
  int ileZle = 0, sumaPunktow = 0;
  std::cout
      << "Podaj punkty uzyskane w nastepujacej kolejnosci oddzielajac je "
         "spacja: Kolokwium 1, Kolokwium 2, projekt, aktywnosc, egzamin\n: ";
  std::cin >> punkty[0] >> punkty[1] >> punkty[2] >> punkty[3] >> punkty[4];
  for (int idx = 0; idx < 5; idx++) {
    double minimum = maxPunkty[idx] * 0.4;
    if (punkty[idx] >= minimum)
      czyZdane[idx] = true;
    else {
      czyZdane[idx] = false;
      ileZle++;
    }
    sumaPunktow += punkty[idx];
  }
  if (ileZle == 0) {
    std::cout << "Gratulacje udalo Ci sie uzyskac ";
    if (sumaPunktow >= 41 && sumaPunktow <= 60)
      std::cout << "3.0\n";
    else if (sumaPunktow >= 61 && sumaPunktow <= 70)
      std::cout << "3.5\n";
    else if (sumaPunktow >= 71 && sumaPunktow <= 80)
      std::cout << "4.0\n";
    else if (sumaPunktow >= 81 && sumaPunktow <= 90)
      std::cout << "4.5\n";
    else if (sumaPunktow >= 91 && sumaPunktow <= 100)
      std::cout << "5.0\n";
  } else {
    std::cout << "Niezaliczono: ";
    if (czyZdane[0] == false)
      std::cout << "Kolokwium 1, ";
    if (czyZdane[1] == false)
      std::cout << "Kolokwium 2, ";
    if (czyZdane[2] == false)
      std::cout << "projekt, ";
    if (czyZdane[3] == false)
      std::cout << "aktywnosc, ";
    if (czyZdane[4] == false)
      std::cout << "egzamin, ";
  }
}

// trojkat pascala
void zadanie9() {
  int liczbaWierszy = 0;
  std::cout << "Podaj ile wierszy trojkata Pascala chcesz wypisac: ";
  std::cin >> liczbaWierszy;

  while (liczbaWierszy < 1) {
    std::cout << "Liczba wierszy musi byc wieksza od 0. Podaj ponownie: ";
    std::cin >> liczbaWierszy;
  }

  for (int numerWiersza = 1; numerWiersza <= liczbaWierszy;
       numerWiersza++) {
    for (int i = 0; i < (liczbaWierszy - numerWiersza) * 2; i++) {
      std::cout << " ";
    }

    int element = 1;
    for (int numerElementu = 0; numerElementu < numerWiersza;
         numerElementu++) {
      std::cout << std::setw(4) << element;
      element = element * (numerWiersza - numerElementu - 1) /
                (numerElementu + 1);
    }
    std::cout << "\n";
  }
}
