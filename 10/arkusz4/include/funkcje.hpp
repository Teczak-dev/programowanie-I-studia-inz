#pragma once

int nwd(int a, int b);

int sumaCyfr(int n);

bool czyPierwsza(int n);

int potega(int podstawa, int wykladnik = 2);
double potega(double podstawa, int wykladnik = 2);
void potega(int &wynik, int podstawa, int wykladnik);

const double EUR = 4.40;
const double USD = 3.93;
const double NOK = 0.42;

void ileMogeKupic(double zlotowki = 100);
void ileMogeKupic(double zlotowki, double kurs);
double przelicz(double pln, double kurs);

// w groszach
void reszta(int zaplata, int cena);

void obliczPlytki(int szerSciany, int szerPlytki);
