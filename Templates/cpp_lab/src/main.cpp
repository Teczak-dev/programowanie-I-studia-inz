#include <iostream>

std::string pobierzWartosc(const std::string &komunikat) {
  std::string wartosc;
  std::cout << komunikat;
  std::cin >> wartosc;
  return wartosc;
}

int main() {

  return 0;
}
