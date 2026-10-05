#include <cmath>
#include <cstdarg>
#include <iomanip>
#include <iostream>
#if defined(_WIN32)
#include <windows.h>
#endif

void zadanie1() {
  double a, b;
  std::cout << "Podaj a: ";
  std::cin >> a;
  std::cout << "Podaj b: ";
  std::cin >> b;
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
  double xA, yA, xB, yB;
  std::cout << "Podaj xA: ";
  std::cin >> xA;
  std::cout << "Podaj yA: ";
  std::cin >> yA;
  std::cout << "Podaj xB: ";
  std::cin >> xB;
  std::cout << "Podaj yB: ";
  std::cin >> yB;

  double a = (yB - yA) / (xB - xA);
  double b = yA - a * xA;

  std::cout << "Rownanie prostej: y = " << a << "x + " << b << "\n";
}

void zadanie4() {
  double a, b, c, x;
  std::cout << "*******************\n";
  std::cout << "Podaj a: ";
  std::cin >> a;
  std::cout << "Podaj b: ";
  std::cin >> b;
  std::cout << "Podaj c: ";
  std::cin >> c;
  std::cout << "*******************\n";
  std::cout << "Podaj x: ";
  std::cin >> x;
  std::cout << "*******************\n";

  std::cout << "f(x) = " << a << "x^2 + " << b << "x + " << c << "\n";
  std::cout << "*******************\n";

  double fx = a * x * x + b * x + c;
  std::cout << "f(" << x << ") = " << fx << "\n";
  std::cout << "*******************\n";
}

void zadanie5() {
  int rokUrodzenia, miesiacUrodzenia, dzienUrodzenia;
  int rokDzisiejszy, miesiacDzisiejszy, dzienDzisiejszy;

  std::cout << "Podaj date urodzenia (rok miesiac dzien): ";
  std::cin >> rokUrodzenia >> miesiacUrodzenia >> dzienUrodzenia;

  std::cout << "Podaj dzisiejsza date (rok miesiac dzien): ";
  std::cin >> rokDzisiejszy >> miesiacDzisiejszy >> dzienDzisiejszy;

  int roznicaDni = (rokDzisiejszy - rokUrodzenia) * 365 +
                   (miesiacDzisiejszy - miesiacUrodzenia) * 30 +
                   (dzienDzisiejszy - dzienUrodzenia);

  std::cout << "Od urodzenia uplynelo: " << roznicaDni / 365 << " lat, "
            << (roznicaDni % 365) / 30 << " miesiecy, "
            << (roznicaDni % 365) % 30 << " dni." << std::endl;
}

void zadanie6() {
  int total_seconds;
  std::cout << "Podaj liczbe sekund: ";
  std::cin >> total_seconds;

  int hours = total_seconds / 3600;
  int remainder = total_seconds % 3600;
  int minutes = remainder / 60;
  int seconds = remainder % 60;

  std::cout << total_seconds << " sekund = " << hours << ":" << minutes << ":"
            << seconds << "\n";
}

void zadanie7() {
  double a, b, c;
  std::cout << "Podaj bok a: ";
  std::cin >> a;
  std::cout << "Podaj bok b: ";
  std::cin >> b;
  std::cout << "Podaj bok c: ";
  std::cin >> c;

  double p = (a + b + c) / 2.0;
  double area = std::sqrt(p * (p - a) * (p - b) * (p - c));

  std::cout << "Pole trojkata wynosi: " << area << "\n";
}

int main() {
  int wybor;
  std::cout << "Wybierz zadanie (1-7): ";
  std::cin >> wybor;
  switch (wybor) {
  case 1:
    zadanie1();
    break;
  case 2:
    zadanie2();
    break;
  case 3:
    zadanie3();
    break;
  case 4:
    zadanie4();
    break;
  case 5:
    zadanie5();
    break;
  case 6:
    zadanie6();
    break;
  case 7:
    zadanie7();
    break;
  default:
    std::cout << "Nieprawidlowy wybor." << std::endl;
  }
  return 0;
}
