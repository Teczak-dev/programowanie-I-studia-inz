#include <cmath>
#include <cstdarg>
#include <iomanip>
#include <iostream>
#if defined(_WIN32)
#include <windows.h>
#endif

std::string pobierzWartosc(const std::string &komunikat) {
  std::string wartosc;
  std::cout << komunikat;
  std::cin >> wartosc;
  return wartosc;
}

void zadanie1() {
  double a = std::stod(pobierzWartosc("Podaj a: "));
  double b = std::stod(pobierzWartosc("Podaj b: "));
  std::cout << std::fixed << std::setprecision(3);
  std::cout << a << " + " << b << " = " << (a + b) << "\n";
  std::cout << a << " - " << b << " = " << (a - b) << "\n";
  std::cout << a << " * " << b << " = " << (a * b) << "\n";
  std::cout << a << " / " << b << " = " << (a / b) << "\n";
  std::cout << "Srednia z " << a << " i " << b << " to " << ((a + b) / 2.0)
            << "\n";
}

void zadanie2() {
#if defined(_WIN32)
  // CP852 (Windows)
  SetConsoleCP(852);
  SetConsoleOutputCP(852);

  std::cout << "\xC9\xCD\xCD\xCD\xCD\xCD\xBB\n";
  std::cout << "\xBA     \xBA\n";
  std::cout << "\xBA \xBE\xA2\x88"
               "w \xBA\n";
  std::cout << "\xBA     \xBA\n";
  std::cout << "\xC8\xCD\xCD\xCD\xCD\xCD\xBC\n";
#else
  // macOS / Linux (UTF-8)
  std::cout << "╔══════╗\n";
  std::cout << "║      ║\n";
  std::cout << "║ żółw ║\n";
  std::cout << "║      ║\n";
  std::cout << "╚══════╝\n";
#endif
}

void zadanie3() {
  double xA = std::stod(pobierzWartosc("Podaj xA: "));
  double yA = std::stod(pobierzWartosc("Podaj yA: "));
  double xB = std::stod(pobierzWartosc("Podaj xB: "));
  double yB = std::stod(pobierzWartosc("Podaj yB: "));

  double a = (yB - yA) / (xB - xA);
  double b = yA - (a * xA);

  std::cout << "Rownanie prostej: y = " << a << "x + " << b << "\n";
}

void zadanie4() {
  std::cout << "*******************\n";
  double a = std::stod(pobierzWartosc("Podaj a: "));
  double b = std::stod(pobierzWartosc("Podaj b: "));
  double c = std::stod(pobierzWartosc("Podaj c: "));
  std::cout << "*******************\n";
  double x = std::stod(pobierzWartosc("Podaj x: "));
  std::cout << "*******************\n";

  std::cout << "f(x) = " << a << "x^2 + " << b << "x + " << c << "\n";
  std::cout << "*******************\n";

  double fx = a * x * x + b * x + c;
  std::cout << "f(" << x << ") = " << fx << "\n";
  std::cout << "*******************\n";
}

void zadanie5() {
  int rokUrodzenia = std::stoi(pobierzWartosc("Podaj rok urodzenia: "));
  int miesiacUrodzenia = std::stoi(pobierzWartosc("Podaj miesiac urodzenia: "));
  int dzienUrodzenia = std::stoi(pobierzWartosc("Podaj dzien urodzenia: "));

  int rokDzisiejszy = std::stoi(pobierzWartosc("Podaj dzisiejszy rok: "));
  int miesiacDzisiejszy =
      std::stoi(pobierzWartosc("Podaj dzisiejszy miesiac: "));
  int dzienDzisiejszy = std::stoi(pobierzWartosc("Podaj dzisiejszy dzien: "));

  int roznicaDni = (rokDzisiejszy - rokUrodzenia) * 365 +
                   (miesiacDzisiejszy - miesiacUrodzenia) * 30 +
                   (dzienDzisiejszy - dzienUrodzenia);

  std::cout << "Od urodzenia uplynelo: " << roznicaDni / 365 << " lat, "
            << (roznicaDni % 365) / 30 << " miesiecy, "
            << (roznicaDni % 365) % 30 << " dni." << std::endl;
}

void zadanie6() {
  int ciagSekund = std::stoi(pobierzWartosc("Podaj liczbe sekund: "));

  int godziny = ciagSekund / 3600;
  int resztaSekund = ciagSekund % 3600;
  int minuty = resztaSekund / 60;
  int sekundy = resztaSekund % 60;

  std::cout << ciagSekund << " sekund = " << godziny << ":" << minuty << ":"
            << sekundy << "\n";
}

void zadanie7() {
  double a = std::stod(pobierzWartosc("Podaj bok a: "));
  double b = std::stod(pobierzWartosc("Podaj bok b: "));
  double c = std::stod(pobierzWartosc("Podaj bok c: "));

  double p = (a + b + c) / 2.0;
  double area = std::sqrt(p * (p - a) * (p - b) * (p - c));

  std::cout << "Pole trojkata wynosi: " << area << "\n";
}

int main() {
  int wybor = std::stoi(pobierzWartosc("Wybierz zadanie (1-7): "));
  if (wybor < 1 || wybor > 7) {
    std::cout << "Nieprawidlowy wybor." << std::endl;
  } else {
    if (wybor == 1)
      zadanie1();
    else if (wybor == 2)
      zadanie2();
    else if (wybor == 3)
      zadanie3();
    else if (wybor == 4)
      zadanie4();
    else if (wybor == 5)
      zadanie5();
    else if (wybor == 6)
      zadanie6();
    else if (wybor == 7)
      zadanie7();
  }
  return 0;
}
