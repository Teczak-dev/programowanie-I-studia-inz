#include "zadania.hpp"
#include "funkcje.hpp"
#include <iomanip>
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

void zadanie11() {
  double v0 = 0.0;
  double alpha = 0.0;

  std::cout << "Podaj predkosc poczatkowa v0 (m/s): ";
  while (!(std::cin >> v0) || v0 <= 0) {
    std::cout << "Prędkość musi być większa od 0! Podaj v0 ponownie: ";
  }

  std::cout << "Podaj kat alpha (w stopniach, 0 < alpha < 90): ";
  while (!(std::cin >> alpha) || alpha <= 0 || alpha >= 90) {
    std::cout
        << "Kąt musi mieścić się w przedziale (0, 90)! Podaj alpha ponownie: ";
  }

  double rad = naRadiany(alpha);

  // Wartości lotu
  double T = czasLotu(v0, rad);
  double H =
      (std::pow(v0 * std::sin(rad), 2)) / (2.0 * G); // Wysokość maksymalna
  double R = pozycjaX(v0, rad, T);                   // Zasięg całkowity

  std::cout << std::fixed << std::setprecision(3);
  std::cout << "\nParametry lotu:\n";
  std::cout << "  Czas lotu (T): " << T << " s\n";
  std::cout << "  Maksymalna wysokosc (H): " << H << " m\n";
  std::cout << "  Zasieg (R): " << R << " m\n\n";

  std::cout << std::setw(8) << "t [s]" << std::setw(12) << "x(t) [m]"
            << std::setw(12) << "y(t) [m]" << "\n";
  std::cout << "------------------------------------\n";

  double t = 0.0;
  double dt = 0.1; // Krok czasowy co 0.1s

  while (t < T) {
    double x = pozycjaX(v0, rad, t);
    double y = pozycjaY(v0, rad, t);

    if (y < 0.0)
      y = 0.0;

    std::cout << std::setw(8) << t << std::setw(12) << x << std::setw(12) << y
              << "\n";

    t += dt;
  }

  if (std::abs((t - dt) - T) > 1e-5) {
    double x_end = pozycjaX(v0, rad, T);
    double y_end = 0.0;

    std::cout << std::setw(8) << T << std::setw(12) << x_end << std::setw(12)
              << y_end << " (Upadek)\n";
  }
}

void zadanie12() {
  int wyniki[2] = {0, 0}; // gracz, komputer
  int wyborGracza;
  std::vector<runda> historia;
  while (wyniki[0] < 5 || wyniki[1] < 5) {
    std::cout << "Wybierz ruch (1 - Kamień, 2 - Papier, 3 - Nożyce): ";
    std::cin >> wyborGracza;
    if (wyborGracza < 1 || wyborGracza > 3) {
      std::cout << "Nieprawidłowy wybór. Spróbuj ponownie." << std::endl;
      continue;
    }
    int wyborKomputera = losujRuch();
    int wynik = wynikRundy(wyborGracza, wyborKomputera);
    historia.push_back({wyborGracza, wyborKomputera, wynik});
    if (wynik == 1) {
      wyniki[0]++;
      std::cout << "Wygrałeś rundę!" << std::endl;
    } else if (wynik == -1) {
      wyniki[1]++;
      std::cout << "Przegrałeś rundę!" << std::endl;
    } else {
      std::cout << "Remis!" << std::endl;
    }
    wynikHistorii(historia);
  }
  if (wyniki[0] == 5) {
    std::cout << "Gratulacje! Wygrałeś grę!" << std::endl;
  } else {
    std::cout << "Niestety, przegrałeś grę." << std::endl;
  }
}

void zadanie13() {}
