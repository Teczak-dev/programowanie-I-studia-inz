#pragma once
#include <string>
#include <vector>

const double EUR = 4.40;
const double USD = 3.93;
const double NOK = 0.42;
const double G = 9.81;
const double PI = 3.14159265358979323846;

struct runda {
  int gracz;
  int komputer;
  int wynik;
};

int nwd(int a, int b);

int sumaCyfr(int n);

bool czyPierwsza(int n);

int potega(int podstawa, int wykladnik = 2);
double potega(double podstawa, int wykladnik = 2);
void potega(int &wynik, int podstawa, int wykladnik);

void ileMogeKupic(double zlotowki = 100);
void ileMogeKupic(double zlotowki, double kurs);
double przelicz(double pln, double kurs);

// w groszach
void reszta(int zaplata, int cena);

void obliczPlytki(int szerSciany, int szerPlytki);

void wypiszPunkty(double r);

int pobierzDodatnia(const std::string &etykieta);
void pobierzUlamek(int &licznik, int &mianownik, const std::string &nazwa);

bool czyAutomorficzna(int n);

// zadania 11-13
double naRadiany(double stopnie);
double pozycjaX(double v0, double rad, double t);
double pozycjaY(double v0, double rad, double t);
double czasLotu(double v0, double rad);

int losujRuch();
int wynikRundy(int gracz, int komputer);

void wynikHistorii(std::vector<runda> &historia);
