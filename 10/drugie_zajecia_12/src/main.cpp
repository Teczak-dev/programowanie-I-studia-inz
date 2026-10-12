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

void zadanie1() {
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

void zadanie2() {
  int zasieg = 100;
  int liczba = 3;
  std::cout << "0)   0\n";

  int numerWiersza = 1;

  for (int i = 1; i <= zasieg; i += 10) {
    std::cout << numerWiersza << ")";
    numerWiersza++;

    int koniecPrzedzialu = i + 9;
    if (koniecPrzedzialu > zasieg) {
      koniecPrzedzialu = zasieg;
    }

    for (int j = i; j <= koniecPrzedzialu; j++) {
      if (j % liczba == 0) {
        std::cout.width(4);
        std::cout << j;
      }
    }
    std::cout << "\n";
  }
}

void zadanie3() {
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

void zadanie4() {
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

void zadanie4Rozszerzone() {
  int limit = std::stoi(pobierzWartosc("Podaj limit: "));
  for (int i = 2; i <= limit; i++) {
    if (liczbaDoskonala(i)) {
      std::cout << i << " ";
    }
  }
}

int main() {
  int wybor = std::stoi(
      pobierzWartosc("Wybierz zadanie (1, 2,3, 4 (rozszenone: 41): "));
  if (wybor == 1) {
    zadanie1();
  } else if (wybor == 2) {
    zadanie2();
  } else if (wybor == 3) {
    zadanie3();
  } else if (wybor == 4) {
    zadanie4();
  } else if (wybor == 41) {
    zadanie4Rozszerzone();
  } else {
    std::cout << "Niepoprawny wybor";
  }
  return 0;
}
