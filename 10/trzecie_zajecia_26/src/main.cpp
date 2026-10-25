#include <ctime>
#include <iostream>
#include <random>

std::string pobierzWartosc(const std::string &komunikat) {
  std::string wartosc;
  std::cout << komunikat;
  std::cin >> wartosc;
  return wartosc;
}

void zadanie1() {
  double a = 0, b = 0;
  char znak = ' ';
  do {
    std::cout
        << "Podaj działanie według wzoru: liczba1 (znak: +,-,*,/) liczba2 "
           "np. 2 + 4 \n";
    std::cin >> a >> znak >> b;
    switch (znak) {
    case '+':
      std::cout << a << " + " << b << " = " << a + b;
      break;
    case '-':
      std::cout << a << " - " << b << " = " << a - b;
      break;
    case '*':
      std::cout << a << " * " << b << " = " << a * b;
      break;
    case '/':
      if (b == 0) {
        std::cout << "Nie można dzielić przez 0";
      } else {
        std::cout << a << " / " << b << " = " << a / b;
        break;
      }
    }
    std::cout << "\nCzy chcesz kontynuować obliczenia?\n[t/n]: ";
    std::cin >> znak;
  } while (znak == 't' || znak == 'T');
}

void zadanie2() {
  std::mt19937 generator(time(nullptr));
  std::uniform_int_distribution<int> distribution(0, 100); // przedział <0, 100>
  int liczbaDoZgadniecia = distribution(generator);
  int liczbaUzytkownika = -1;
  std::cout << "Podaj liczbę: ";
  std::cin >> liczbaUzytkownika;
  while (liczbaUzytkownika != liczbaDoZgadniecia) {
    if (liczbaUzytkownika > liczbaDoZgadniecia)
      std::cout << "Twoja liczba jest wieksza niz wylosowana. Zgadnij liczbe: ";
    else
      std::cout
          << "Twoja liczba jest mniejsza niz wylosowana. Zgadnij liczbe: ";
    std::cin >> liczbaUzytkownika;
  }
  std::cout << "Brawo, zgadles!";
}

int main() {
  std::string wybor = pobierzWartosc("Wybierz zadanie:\n"
                                     "1 - kalkulator (operacje +,-,*,/)\n"
                                     "2 - zgadywanie liczby od 0 do 100\n"
                                     ": ");
  if (wybor == "1")
    zadanie1();
  else if (wybor == "2")
    zadanie2();
  else
    std::cout << "Niepoprawny wybor";

  return 0;
}
