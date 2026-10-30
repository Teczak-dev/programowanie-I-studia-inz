#include "zadania.hpp"
#include <iostream>

std::string pobierzWartosc(const std::string &komunikat) {
  std::string wartosc;
  std::cout << komunikat;
  std::cin >> wartosc;
  return wartosc;
}

int main() {
  int wybor;
  std::cout << "Wybierz zadanie (1-13): ";
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
  case 8:
    zadanie8();
    break;
  case 9:
    zadanie9();
    break;
  case 10:
    zadanie10();
    break;
  case 11:
    zadanie11();
    break;
  case 12:
    zadanie12();
    break;
  case 13:
    zadanie13();
    break;
  default:
    std::cout << "Nieprawidłowy wybór." << std::endl;
    break;
  }
  return 0;
}
