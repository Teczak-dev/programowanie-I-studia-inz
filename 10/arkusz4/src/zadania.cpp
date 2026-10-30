#include "zadania.hpp"
#include "funkcje.hpp"
#include <iostream>

void zadanie1() {
  for (int i = 1; i <= 1000; i++) {
    if (i % sumaCyfr(i) == 0) {
      std::cout << i << ", ";
    }
  }
  std::cout << std::endl;
}

void zadanie2() {
  std::cout << "NWD dla 16 i 12: " << nwd(16, 12) << std::endl;
  std::cout << "NWD dla 17 i 5: " << nwd(17, 5) << std::endl;
  std::cout << "NWD dla 24 i 24: " << nwd(24, 24) << std::endl;
}

void zadanie3() {
  for (int i = 1; i <= 100; ++i) {
    if (czyPierwsza(i)) {
      std::cout << i << " ";
    }
  }
}

void zadanie4() {
  std::cout << "Potęga (int): " << potega(3) << std::endl;
  std::cout << "Potęga (double): " << potega(3.0, 3) << std::endl;

  int wynik;
  potega(wynik, 2, 5);
  std::cout << "Potęga (referencja): " << wynik << std::endl;
}

void zadanie5() {
  int wybor;
  std::cout << "1 - podstawa, 2- rozszerzenie: ";
  std::cin >> wybor;
  if (wybor == 1) {
    ileMogeKupic();
    std::cout << "*************************************************\n";
    ileMogeKupic(200);
  } else if (wybor == 2) {
    while (true) {
      double kwota;
      int kurs;
      std::cout << "Podaj kurs:\n1 - EUR\n2 - USD\n3 - NOK\n0 - zakończenie "
                   "programu\n: ";
      std::cin >> kurs;
      if (kurs < 0 || kurs > 3) {
        std::cout << "Nieprawidłowy wybór kursu." << std::endl;
      } else {
        if (kurs == 0) {
          break;
        }
        do {
          std::cout << "Podaj kwotę w PLN (powyżej 0): ";
          std::cin >> kwota;
        } while (kwota <= 0);
        switch (kurs) {
        case 1:
          ileMogeKupic(kwota, EUR);
          break;
        case 2:
          ileMogeKupic(kwota, USD);
          break;
        case 3:
          ileMogeKupic(kwota, NOK);
          break;
        }
      }
    }
  } else {
    std::cout << "Nieprawidłowy wybór." << std::endl;
  }
}

void zadanie6() {
  int zaplata, cena;
  std::cout << "Podaj kwotę zapłaty w groszach: ";
  std::cin >> zaplata;
  std::cout << "Podaj cenę w groszach: ";
  std::cin >> cena;
  reszta(zaplata, cena);
}

void zadanie7() {
  int szerSciany, szerPlytki;
  std::cout << "Podaj szerokość ściany w cm: ";
  std::cin >> szerSciany;
  std::cout << "Podaj szerokość plytki w cm: ";
  std::cin >> szerPlytki;
  obliczPlytki(szerSciany, szerPlytki);
}

void zadanie8() {
  double r = 0.0;
  std::cout << "Podaj r: ";

  while (!(std::cin >> r) || r <= 0) {
    std::cout << "Promień r musi być liczbą dodatnią! Podaj r ponownie: ";
  }

  wypiszPunkty(r);
}

void zadanie9() {
  int l1 = 0, m1 = 0;
  int l2 = 0, m2 = 0;
  char operacja;

  // Wczytanie danych bez powielania pętli
  pobierzUlamek(l1, m1, "pierwszy");

  std::cout << "Podaj operację (+, -, *, /): ";
  while (!(std::cin >> operacja) || (operacja != '+' && operacja != '-' &&
                                     operacja != '*' && operacja != '/')) {
    std::cout << "Nieprawidłowa operacja! Podaj operację ponownie: ";
  }

  pobierzUlamek(l2, m2, "drugi");

  int lWynik = 0, mWynik = 0;

  switch (operacja) {
  case '+':
    lWynik = l1 * m2 + l2 * m1;
    mWynik = m1 * m2;
    break;
  case '-':
    lWynik = l1 * m2 - l2 * m1;
    mWynik = m1 * m2;
    break;
  case '*':
    lWynik = l1 * l2;
    mWynik = m1 * m2;
    break;
  case '/':
    lWynik = l1 * m2;
    mWynik = m1 * l2;
    break;
  }

  int dz = nwd(lWynik, mWynik);
  lWynik /= dz;
  mWynik /= dz;

  if (mWynik < 0) {
    lWynik = -lWynik;
    mWynik = -mWynik;
  }
  std::cout << "Wynik: " << lWynik << "/" << mWynik << "\n";
}

void zadanie10() {
  int n;
  std::cout << "Podaj do ktorej liczby chcesz sprawdzić czy sa liczby "
               "automorficzne: ";
  while (!(std::cin >> n) || n < 0) {
    std::cout << "Wartość musi być liczbą dodatnią! Spróbuj ponownie: ";
  }
  for (int i = 0; i <= n; i++) {
    if (czyAutomorficzna(i)) {
      std::cout << i << " ";
    }
  }
}

void zadanie11() {}

void zadanie12() {}

void zadanie13() {}
