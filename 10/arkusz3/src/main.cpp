#include <cmath>
#include <cstddef>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>

struct Zadanie {
  std::string opis;
  void (*funkcja)();
};

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

void zadanie3() {
  char wyborFigury;
  std::cout << "Wybierz figure (t - trojkat, k - kwadrat): ";
  std::cin >> wyborFigury;
  switch (wyborFigury) {
  case 't': {
    int a = 0, b = 0, c = 0;
    std::cout << "Podaj dlugosci bokow trojkata: ";
    a = std::stod(pobierzWartosc("a = "));
    b = std::stod(pobierzWartosc("b = "));
    c = std::stod(pobierzWartosc("c = "));
    if (a + b > c && a + c > b && b + c > a) {
      double obwod = a + b + c;
      double polowaObwodu = obwod / 2.0;
      double pole = std::sqrt(polowaObwodu * (polowaObwodu - a) *
                              (polowaObwodu - b) * (polowaObwodu - c));
      std::cout << "Pole trojkata: " << pole << "\n";
      std::cout << "Obwod trojkata: " << obwod << "\n";
    } else {
      std::cout << "Nie moze istniec taki trojkat!\n";
    }
    break;
  }
  case 'k': {
    int bok = 0;
    std::cout << "Podaj dlugosc boku kwadratu: ";
    bok = std::stod(pobierzWartosc("bok = "));
    if (bok <= 0) {
      std::cout << "Nie moze istniec taki kwadrat!\n";
    } else {
      double poleKwadratu = bok * bok;
      double obwodKwadratu = 4 * bok;
      std::cout << "Pole kwadratu: " << poleKwadratu << "\n";
      std::cout << "Obwod kwadratu: " << obwodKwadratu << "\n";
    }
    break;
  }
  default:
    std::cout << "Niepoprawny wybor figury.\n";
  }
}

void zadanie4() {
  int n = 0;
  std::cout << "Podaj rozmiar n: ";
  if (!(std::cin >> n) || n <= 0) {
    std::cout << "Niepoprawny rozmiar n.\n";
    return;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j || i + j == n - 1)
        std::cout << "1 ";
      else
        std::cout << "0 ";
    }
    std::cout << "\n";
  }
}

void zadanie5() {
  int rozmiar = 0;
  std::cout << "Podaj rozmiar n: ";
  if (!(std::cin >> rozmiar) || rozmiar <= 0) {
    std::cout << "Niepoprawny rozmiar n.\n";
    return;
  }
  for (int i = 0; i < rozmiar; i++) {
    for (int j = 0; j < rozmiar; j++) {
      if (i == 0 || i == rozmiar - 1 || j == 0 || j == rozmiar - 1) {
        std::cout << "1";
      } else {
        int dystansDoGory = i;
        int dystansDoDolu = rozmiar - 1 - i;
        int dystansDoLewej = j;
        int dystansDoPrawej = rozmiar - 1 - j;

        int minDystans = std::min(
            {dystansDoGory, dystansDoDolu, dystansDoLewej, dystansDoPrawej});
        std::cout << minDystans + 1;
      }
    }
    std::cout << "\n";
  }
}

void zadanie6() {
  int godzina = 0, minuta = 0, sekunda = 0, liczbaSekund = 0;
  std::cout << "Podaj godzine w formacie HH MM SS w zakresie(0-23 0-59 0-59): ";
  while (!(std::cin >> godzina >> minuta >> sekunda) || godzina < 0 ||
         godzina > 23 || minuta < 0 || minuta > 59 || sekunda < 0 ||
         sekunda > 59) {
    std::cout << "Niepoprawny format godziny.\n";
    std::cout
        << "Podaj godzine w formacie HH MM SS w zakresie(0-23 0-59 0-59): ";
  }

  std::cout << "Podaj liczbe sekund do dodania: ";
  while (!(std::cin >> liczbaSekund) || liczbaSekund < 0) {
    std::cout << "Niepoprawna liczba sekund.\n";
    std::cout << "Podaj liczbe sekund do dodania: ";
  }

  std::cout << "\n" << godzina << ":" << minuta << ":" << sekunda << ", ";
  for (int i = 0; i < liczbaSekund; i++) {
    sekunda++;
    if (sekunda >= 60) {
      sekunda = 0;
      minuta++;
      if (minuta >= 60) {
        minuta = 0;
        godzina++;
        if (godzina >= 24) {
          godzina = 0;
        }
      }
    }
    if (godzina < 10)
      std::cout << "0" << godzina;
    else
      std::cout << godzina;
    if (minuta < 10)
      std::cout << ":0" << minuta;
    else
      std::cout << ":" << minuta;
    if (sekunda < 10)
      std::cout << ":0" << sekunda;
    else
      std::cout << ":" << sekunda;
    if (i == liczbaSekund - 1)
      std::cout << "\n";
    else
      std::cout << ", ";
  }
}

long long reverseNumber(long long number) {
  long long reversed = 0;
  while (number > 0) {
    reversed = reversed * 10 + number % 10;
    number /= 10;
  }
  return reversed;
}
void zadanie7() {
  int wybor = 0;
  std::cout << "1 - normalne, 2 - rozszerzone: ";
  while (!(std::cin >> wybor) || (wybor != 1 && wybor != 2)) {
    std::cout << "Niepoprawny wybor.\n";
    std::cout << "1 - normalne, 2 - rozszerzone: ";
  }
  if (wybor == 1) {
    int liczba = 0;
    std::cout << "Podaj liczbe: ";
    while (!(std::cin >> liczba) || liczba < 0) {
      std::cout << "Niepoprawna liczba.\n";
      std::cout << "Podaj liczbe: ";
    }

    int odwroconaLiczba = 0, oryginalnaLiczba = liczba;
    while (liczba > 0) {
      odwroconaLiczba = odwroconaLiczba * 10 + liczba % 10;
      liczba /= 10;
    }

    if (oryginalnaLiczba == odwroconaLiczba) {
      std::cout << "Liczba " << oryginalnaLiczba << " jest palindromem.\n";
    } else {
      std::cout << "Liczba " << oryginalnaLiczba << " nie jest palindromem.\n";
    }
  } else {
    long long limit = 0;
    std::cout << "Podaj limit: ";
    while (!(std::cin >> limit) || limit < 0) {
      std::cout << "Niepoprawny limit.\n";
      std::cout << "Podaj limit: ";
    }
    for (int i = 0; i <= limit; i++) {
      if (i == reverseNumber(i)) {
        std::cout << i << ", ";
      }
    }
  }
}

void zadanie8() {
  int wybor = 0;
  std::cout << "1 - normalne, 2 - rozszerzone: ";
  while (!(std::cin >> wybor) || (wybor != 1 && wybor != 2)) {
    std::cout << "Niepoprawny wybor.\n";
    std::cout << "1 - normalne, 2 - rozszerzone: ";
  }
  int a = 0, b = 0, ile = 0;
  std::cout << "Podaj przedzial (a, b): ";
  while (!(std::cin >> a >> b) || a < 2 || a > b) {
    std::cout << "Niepoprawny przedzial.\n";
    std::cout << "Podaj przedzial (a, b): ";
  }
  if (wybor == 1) {
    for (int i = a; i <= b; ++i) {
      bool czyPierwsza = true;

      for (int j = 2; j < i; ++j) {
        if (i % j == 0) {
          czyPierwsza = false;
          break;
        }
      }

      if (czyPierwsza) {
        std::cout << i << " ";
        ile++;
      }
    }
  } else {
    for (int i = a; i <= b; ++i) {
      bool czyPierwsza = true;

      int granica = static_cast<int>(std::sqrt(i));
      for (int j = 2; j <= granica; ++j) {
        if (i % j == 0) {
          czyPierwsza = false;
          break;
        }
      }

      if (czyPierwsza) {
        std::cout << i << " ";
        ile++;
      }
    }
  }
}

// odpowiedz na pytanie: 7 prób
void zadanie9() {
  std::cout << "Pomyśl liczbę od 0 do 100, a ja spróbuję ją zgadnąć.\n";

  int min = 1;
  int max = 100;
  int odpowiedz = 0;
  bool zgadlem = false;

  while (!zgadlem) {
    if (min > max) {
      std::cout << "Ojej! Wykryłem sprzeczność w odpowiedziach. Oszukujesz "
                   "albo się pomyliłeś!\n";
      return;
    }

    int propozycja = (min + max) / 2;

    std::cout << "Czy twoja liczba to " << propozycja << "?\n";
    std::cout << "1 - za mała, 2 - za duża, 3 - trafiona: ";

    while (!(std::cin >> odpowiedz) || (odpowiedz < 1 || odpowiedz > 3)) {
      std::cout << "Niepoprawna odpowiedź. Wpisz 1, 2 lub 3: ";
    }

    switch (odpowiedz) {
    case 1: {
      min = propozycja + 1;
      break;
    }
    case 2: {
      max = propozycja - 1;
      break;
    }
    case 3: {
      std::cout << "Hura! Zgadłem Twoją liczbę.\n";
      zgadlem = true;
      break;
    }
    }
  }
}

void zadanie10() {
  int rok, miesiac, dzienTygodnia, dniMiesiaca;
  bool czyPrzestepny = false;
  std::cout << "Rok, miesiac (1-12), dzien tygodnia (1-7): ";
  std::cin >> rok >> miesiac >> dzienTygodnia;
  if (rok % 4 == 0 && (rok % 100 != 0 || rok % 400 == 0)) {
    czyPrzestepny = true;
  }
  switch (miesiac) {
  case 1:
    dniMiesiaca = 31;
    break;
  case 2:
    dniMiesiaca = czyPrzestepny ? 29 : 28;
    break;
  case 3:
    dniMiesiaca = 31;
    break;
  case 4:
    dniMiesiaca = 30;
    break;
  case 5:
    dniMiesiaca = 31;
    break;
  case 6:
    dniMiesiaca = 30;
    break;
  case 7:
    dniMiesiaca = 31;
    break;
  case 8:
    dniMiesiaca = 31;
    break;
  case 9:
    dniMiesiaca = 30;
    break;
  case 10:
    dniMiesiaca = 31;
    break;
  case 11:
    dniMiesiaca = 30;
    break;
  case 12:
    dniMiesiaca = 31;
    break;
  }

  std::cout << " Pn Wt Śr Cz Pt So Nd\n";
  for (int i = 1; i < dzienTygodnia; i++) {
    std::cout << "   ";
  }
  for (int i = 1; i <= dniMiesiaca; i++) {
    std::cout << (i < 10 ? " " : "") << i << " ";
    if ((i + dzienTygodnia - 1) % 7 == 0) {
      std::cout << "\n";
    }
  }
}

// do pomocy aby dzialac bez cmath
int abs_val(int x) { return (x < 0) ? -x : x; }

void zadanie11() {
  int n = 0;
  std::cout << "Podaj nieparzyste n (1..9): ";
  while (!(std::cin >> n) || n < 1 || n > 9 || n % 2 == 0) {
    std::cout << "Niepoprawna wartość! Podaj nieparzyste n z zakresu 1..9: ";
  }

  const int srodek = n / 2;
  const long long najwiekszaWartosc = 1LL * n * n;
  int szerokosc = 1;
  for (long long liczba = najwiekszaWartosc; liczba >= 10;
       liczba /= 10) {
    ++szerokosc;
  }

  for (int wiersz = 0; wiersz < n; ++wiersz) {
    for (int kolumna = 0; kolumna < n; ++kolumna) {
      const int odSrodkaWiersz = wiersz - srodek;
      const int odSrodkaKolumna = kolumna - srodek;
      const int warstwa =
          (abs_val(odSrodkaWiersz) > abs_val(odSrodkaKolumna))
              ? abs_val(odSrodkaWiersz)
              : abs_val(odSrodkaKolumna);

      long long wartosc = 1;
      if (warstwa > 0) {
        const long long poczatekWarstwy =
            1LL * (2 * warstwa - 1) * (2 * warstwa - 1) + 1;

        if (odSrodkaKolumna == warstwa &&
            odSrodkaWiersz < warstwa) {
          wartosc = poczatekWarstwy + warstwa - 1 -
                    odSrodkaWiersz;
        } else if (odSrodkaWiersz == -warstwa &&
                   odSrodkaKolumna < warstwa) {
          wartosc = poczatekWarstwy + 2 * warstwa +
                    warstwa - 1 - odSrodkaKolumna;
        } else if (odSrodkaKolumna == -warstwa &&
                   odSrodkaWiersz > -warstwa) {
          wartosc = poczatekWarstwy + 4 * warstwa +
                    odSrodkaWiersz + warstwa - 1;
        } else {
          wartosc = poczatekWarstwy + 6 * warstwa +
                    odSrodkaKolumna + warstwa - 1;
        }
      }

      std::cout << std::setw(szerokosc) << wartosc << " ";
    }
    std::cout << "\n";
  }
}

void zadanie12() {}

int main() {

  std::vector<Zadanie> listaZadan = {
      {"kalkulator (operacje +,-,*,/)", zadanie1},
      {"zgadywanie liczby od 0 do 100", zadanie2},
      {"obsluga trojkata i kwadratu", zadanie3},
      {"udawana macierz n x n z 1 i 0", zadanie4},
      {"rysowanie liczbami ala tarczy", zadanie5},
      {"symulacja czasu", zadanie6},
      {"liczby palindromiczne", zadanie7},
      {"liczby pierwsze w przedziale", zadanie8},
      {"komputer zgaduje liczbe", zadanie9},
      {"kalendarz miesieczny", zadanie10},
      {"spirala liczbowa", zadanie11},
      {"Bankomat", zadanie12}};

  std::cout << "Wybierz zadanie:\n";
  for (size_t i = 0; i < listaZadan.size(); i++) {
    std::cout << i + 1 << " - " << listaZadan[i].opis << "\n";
  }
  std::cout << ": ";

  int wybor = 0;
  if (std::cin >> wybor && wybor >= 1 &&
      wybor <= static_cast<int>(listaZadan.size())) {
    listaZadan[wybor - 1].funkcja();
  } else {
    std::cout << "Niepoprawny wybór.";
  }

  return 0;
}
