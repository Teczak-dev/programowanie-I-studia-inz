#include <iostream>
#include <ostream>

std::string pobierzWartosc(const std::string &komunikat) {
  std::string wartosc;
  std::cout << komunikat;
  std::cin >> wartosc;
  return wartosc;
}
std::vector<int> pobierzLiczby(int liczba, int zasieg) {
  std::vector<int> liczbyPodzielne;
  for (int i = 0; i <= zasieg; i++) {
    if (i % liczba == 0)
      liczbyPodzielne.push_back(i);
  }
  return liczbyPodzielne;
}

void zadanie2() {
  int zasieg = 100;
  int liczba = 3;
  std::cout << "0)" << std::cout.width(4) << "0\n";
  for (int i = 1; i <= zasieg; i += 10) {
    std::cout << i / 10 << ")";
    for (int j = i; j <= i + 1; j++) {
      if (j % liczba == 0) {
        std::cout.width(4);
        std::cout << j;
      }
    }
    std::cout << std::endl;
  }
  // ma byc
  // 0)   0
  // 1)   3   6   9
}

int kolejnyWyrazC(int cN) {
  if (cN % 2 == 0)
    return cN / 2;
  else
    return (3 * cN) + 1;
}

void zadanie3() {
  // dodatnia calkowita dowolna C0
  // np. 6 kolejny w zaleznosci albo
  int c = std::stoi(pobierzWartosc("Podaj liczbę całkowitą: "));
  while (c < 0) {
    std::cout << "Podaj cos dodatniego calkowitego\n";
    c = std::stoi(pobierzWartosc("Podaj liczbę całkowitą: "));
  }
  int kroki = 0;
  while (kroki < 1000) {
    std::cout << c << " -> ";
    c = kolejnyWyrazC(c);
    if (c == 1) {
      std::cout << c;
      break;
    }
    kroki++;
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

bool liczbaDoskonala(int liczba) {
  int suma = 0;
  for (int i = 1; i < liczba; i++) {
    if (liczba % i == 0) {
      suma += i;
    }
  }
  return suma == liczba;
}

void zad4Big() {
  int limit = std::stoi(pobierzWartosc("Podaj limit: "));
  for (int i = 2; i <= limit; i++) {
    if (liczbaDoskonala(i)) {
      std::cout << i << " ";
    }
  }
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

int main() {
  zadanie4();
  zad4Big();
  return 0;
}
