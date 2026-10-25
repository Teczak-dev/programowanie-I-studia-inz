#include "domowe.hpp"
#include <iomanip>
#include <iostream>
#include <ostream>

std::string pobierzWartosc(const std::string &komunikat) {
  std::string wartosc;
  std::cout << komunikat;
  std::cin >> wartosc;
  return wartosc;
}

bool liczbaDoskonala(int liczba) {
  int suma = 0;
  for (int i = 1; i < liczba; i++) {
    if (liczba % i == 0) {
      suma += i;
    }
  }
  return suma == liczba;
}

int kolejnyWyrazC(int cN) {
  if (cN % 2 == 0)
    return cN / 2;
  else
    return (3 * cN) + 1;
}

// zadanie 2 z zajec
void zadanie2() {
  double a = std::stod(pobierzWartosc("Podaj a: "));
  double b = std::stod(pobierzWartosc("Podaj b: "));
  while (a > b) {
    std::cout << "a musi byc mniejsze od b\n";
    a = std::stod(pobierzWartosc("Podaj a: "));
    b = std::stod(pobierzWartosc("Podaj b: "));
  }
  int n = std::stoi(pobierzWartosc("Podaj n: "));
  while (n < 2) {
    std::cout << "n musi byc wieksze od 2\n";
    n = std::stoi(pobierzWartosc("Podaj n: "));
  }
  double krok = (b - a) / n;
  double liczba = a;

  while (liczba <= b) {
    std::cout << liczba << " ";
    liczba += krok;
  }
}

// zadanie drugie z zajec rozbudowane o polecenie rozszerzenia
void zadanie3() {
  int poczatekPrzedzialu =
      std::stoi(pobierzWartosc("Podaj poczatek przedzialu: "));
  int koniecPrzedzialu = std::stoi(pobierzWartosc("Podaj koniec przedzialu: "));
  while (poczatekPrzedzialu < 0 || koniecPrzedzialu < 0 ||
         poczatekPrzedzialu > koniecPrzedzialu) {
    if (poczatekPrzedzialu < 0 || koniecPrzedzialu < 0) {
      std::cout << "Przedzial musi skladac sie z liczb nieujemnych\n";
    } else {
      std::cout << "Poczatek przedzialu musi byc mniejszy lub rowny koncowi\n";
    }
    poczatekPrzedzialu =
        std::stoi(pobierzWartosc("Podaj poczatek przedzialu: "));
    koniecPrzedzialu = std::stoi(pobierzWartosc("Podaj koniec przedzialu: "));
  }
  int dzielnik = std::stoi(pobierzWartosc("Podaj dzielnik: "));
  while (dzielnik == 0) {
    std::cout << "Dzielnik nie moze byc rowny zero\n";
    dzielnik = std::stoi(pobierzWartosc("Podaj dzielnik: "));
  }

  int szerokoscNumeruWiersza = 1;
  int ostatniNumerWiersza = (koniecPrzedzialu - 1) / 10 + 1;
  while (ostatniNumerWiersza >= 10) {
    szerokoscNumeruWiersza++;
    ostatniNumerWiersza /= 10;
  }

  std::cout << std::setw(szerokoscNumeruWiersza) << 0 << ")   0\n";

  int poczatekWiersza = 1;
  if (poczatekPrzedzialu > 1) {
    poczatekWiersza = ((poczatekPrzedzialu - 1) / 10) * 10 + 1;
  }

  while (poczatekWiersza <= koniecPrzedzialu) {
    int numerWiersza = (poczatekWiersza - 1) / 10 + 1;
    std::cout << std::setw(szerokoscNumeruWiersza) << numerWiersza << ")";

    int koniecWiersza = poczatekWiersza + 9;
    if (koniecWiersza > koniecPrzedzialu) {
      koniecWiersza = koniecPrzedzialu;
    }

    for (int liczba = poczatekWiersza; liczba <= koniecWiersza; liczba++) {
      if (liczba >= poczatekPrzedzialu && liczba % dzielnik == 0) {
        std::cout << std::setw(4) << liczba;
      }
    }
    std::cout << "\n";
    poczatekWiersza += 10;
  }
}

// zadanie 3 z zajec
void zadanie7() {
  int c = std::stoi(pobierzWartosc("Podaj liczbę całkowitą: "));
  while (c == 0) {
    std::cout
        << "Zero nie jest dozwolone w ciagu Collatza! Podaj inna liczbe:\n";
    c = std::stoi(pobierzWartosc("Podaj liczbę całkowitą: "));
  }
  int kroki = 1;
  while (kroki < 1000) {
    std::cout << c << " -> ";
    c = kolejnyWyrazC(c);
    kroki++;
    if (c == 1 || c == -1) {
      std::cout << c;
      break;
    }
  }
  std::cout << "\n";
  if (kroki >= 1000)
    std::cout << "Liczba tak duza ze przekroczyla 1000 krokow";
  else
    std::cout << "Wykonano w " << kroki << " krokach";
}

// LICZBA DOSKONALA
// zadanie 4 z zajec
void zadanie8() {
  int liczba = std::stoi(pobierzWartosc("Podaj liczbę naturalna: "));
  while (liczba < 0) {
    std::cout << "Podaj cos dodatniego calkowitego\n";
    liczba = std::stoi(pobierzWartosc("Podaj liczbę naturalna: "));
  }
  int suma = 0;
  for (int i = 1; i < liczba; i++) {
    if (liczba % i == 0) {
      std::cout << i << " ";
      suma += i;
    }
  }
  if (suma == liczba)
    std::cout << "\nLiczba jest doskonala";
  else
    std::cout << "\nLiczba nie jest doskonala";
}
// LICZBY DOSKONALE z przedzialu [2, limit]
// zadanie 4 rozszerzenie z zajec
void zadanie8Rozszerzone() {
  int limit = std::stoi(pobierzWartosc("Podaj limit: "));
  for (int i = 2; i <= limit; i++) {
    if (liczbaDoskonala(i)) {
      std::cout << i << " ";
    }
  }
}

int main() {
  std::string wybor =
      pobierzWartosc("Wybierz zadanie:\n1 - Wspolczynniki funkcji kwadratowej\n"
                     "2 - Dzielenie [a,b] na n rownych czesci\n"
                     "3 - Wypisywanie liczb podzielnych w przedziale [a, b] "
                     "przez podany dzielnik (a >= 0)\n"
                     "4 - Odwrocony polowkowy trojkat\n"
                     "5 - Tabliczka mnozenia od 1 do 10\n"
                     "6 - Czy zdam Programowanie I?\n"
                     "7 - Hipoteza Collatza\n"
                     "8 - Liczby doskonale, rozszenone: 8-roz\n"
                     "9 - Trojkat Pascala \n: ");
  if (wybor == "1")
    zadanie1();
  else if (wybor == "2")
    zadanie2();
  else if (wybor == "3")
    zadanie3();
  else if (wybor == "4")
    zadanie4();
  else if (wybor == "5")
    zadanie5();
  else if (wybor == "6")
    zadanie6();
  else if (wybor == "7")
    zadanie7();
  else if (wybor == "8")
    zadanie8();
  else if (wybor == "8-roz")
    zadanie8Rozszerzone();
  else if (wybor == "9")
    zadanie9();
  else
    std::cout << "Niepoprawny wybor";

  return 0;
}
