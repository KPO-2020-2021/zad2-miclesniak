#include "LZespolona.hh"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <cmath>

#define M_PI 3.14159265358979323846
#define MIN_DIFF 0.0001

using namespace std;

/**
 * @brief Realizuje porównanie dwoch liczb zespolonych.
 * 
 *   @param Skl2 - druga porównywana liczba zespolona.
 * 
 *    @return bool True dla równych liczb zespolonych.
 */

bool LZespolona::operator==(const LZespolona Skl2) const
{
  //alternatywnie, dla MIN_DIFF i wyników od użytkownika
  if (abs(this->re - Skl2.re) <= MIN_DIFF && abs(this->im - Skl2.im) <= MIN_DIFF)
    return true;
  else
    return false;
}

/**
 * @brief Realizuje dodanie dwoch liczb zespolonych.
 * 
 *    @param Skl2 - drugi skladnik dodawania.
 * 
 *    @return wynik Zwracamy sume dwoch LZespolonych
 */
LZespolona LZespolona::operator+(const LZespolona Skl2) const
{
  LZespolona wynik;
  wynik.re = this->re + Skl2.re;
  wynik.im = this->im + Skl2.im;
  return wynik;
}
/**
 * @brief Funkcja przeciazenia operatora odejmowania
 * 
 * @param Skl2 Odjemna typu LZespolona
 * @return LZespolona Zwracamy wynik odejmowania 2 LZespolonych
 */
LZespolona LZespolona::operator-(const LZespolona Skl2) const
{
  LZespolona wynik;
  wynik.re = this->re - Skl2.re;
  wynik.im = this->im - Skl2.im;
  return wynik;
}
/**
 * @brief Funkcja przeciazenia Operatora mnozenia
 * 
 * @param Skl2 Mnoznik typu LZespolona
 * @return LZespolona Zwracamy wynik mnozenia 2 LZespolonych
 */
LZespolona LZespolona::operator*(const LZespolona Skl2) const
{
  LZespolona wynik;
  wynik.re = (this->re * Skl2.re) - (this->im * Skl2.im);
  wynik.im = (this->re * Skl2.im) + (this->im * Skl2.re);
  return wynik;
}
/**
 * @brief Funkcja przeciazenia Operatora dzielenia 
 * 
 * @param Skl2 Dzielnik typu LZespolona
 * @return LZespolona Zwracamy wynik dzielenia 2 LZespolonych
 */
LZespolona LZespolona::operator/(const LZespolona Skl2) const
{
  return (*this * Skl2.Sprzezenie()) / Skl2.Modul2();
}

/*!
 * @brief Funkcja realizuje dzielenie liczby zespolonej przez skakar.
 *    @param Skl2 - skalar-dzielnik.
 * 
 *    @return Wynik Wynik dzielenia obiektu LZespolonej przez skalar
 */
LZespolona LZespolona::operator/(const double Skl2) const
{
  LZespolona Wynik;
  if (Skl2 == 0)
    throw runtime_error("Błąd matematyczny: próbowano podzielić przez zero\n");
  Wynik.re = this->re / Skl2;
  Wynik.im = this->im / Skl2;
  return Wynik;
}
/**
 * @brief Funkcja obliczyjace Sprzezenie LZespolonej
 * 
 * @return LZespolona Zwraca Sprzezona liczbe Zespolona
 */
LZespolona LZespolona::Sprzezenie() const
{
  LZespolona temp;
  temp.re = this->re;
  temp.im = -this->im;
  return temp;
}
/**
 * @brief Funkcja obliczajaca modul LZespolonej
 * 
 * @return double Zwracamy Modul z LZespolonej
 */
double LZespolona::Modul2() const
{
  return this->re * this->re + this->im * this->im;
}
/**
 * @brief Funkcja wyswietlajaca obiekt LZespolona 
 * 
 */

void LZespolona::Wyswietl() const
{
  cout << "(" << this->re;
  if (this->im >= 0)
    cout << "+";
  cout << this->im << "i)";
}

/**
 * @brief Funkcja wczytywania liczby Zespolonej
 * 
 * @return bool - status wczytywania
 * @retval true - wczytywanie zakonczone powodzeniem,liczba gotowa do uzycia
 * @retval false  - przekroczono ilosc bledow zapisu
 */

bool LZespolona::wczytaj_l()
{
  size_t ilosc_bledow = 0;
  while (ilosc_bledow < 3)
  {
    cin >> *this;
    if (cin.fail())
    {                          //Jeśli  bład wczytywania
      cin.clear();             //resetujemy failbit
      cin.ignore(99999, '\n'); //czyscimy bufor wejsciowy
      cout << "Błędny format odpowiedzi!\n";
      ilosc_bledow++;
    }
    else
    {
      return true; //w przeciwnym razie zwracamy true - wczytywanie zakonczone poprawnie
    }
  }
  return false;
}
/**
 * @brief Funkcja przeciażenie operatora bitowego w prawo dla LZespolonej 
 * 
 * @param in Strumień wejsciowy przez który wczytujemy wartosci
 * @param wynik Obiekt do ktorego przypisujemy wczytane wartosci
 * @return istream& Strumien wejsciowy z którego odczytano wartości 
 */
istream &operator>>(istream &in, LZespolona &wynik)
{
  char temp;
  in >> temp;
  if (in.fail())
  {
    return in;
  }
  if (temp != '(')
  {
    in.setstate(ios::failbit);
    return in;
  }
  in >> wynik.re;
  if (in.fail())
  {
    return in;
  }
  in >> wynik.im;
  if (in.fail())
  {
    return in;
  }
  in >> temp;
  if (in.fail())
  {
    return in;
  }
  if (temp != 'i')
  {
    in.setstate(ios::failbit);
    return in;
  }
  in >> temp;
  if (in.fail())
  {
    return in;
  }
  if (temp != ')')
  {
    in.setstate(ios::failbit);
    return in;
  }

  return in;
}

/**
 * @brief Funkcja przeciażenie operatora bitowego w lewo dla LZespolonej 
 * 
 * @param out Strumień na którym mają być wyświetlane wartości
 * @param Skl Obiekt który wyświetlamy
 * @return ostream& Strumien wyjsciowy z zapisana liczba zespolona
 */

ostream &operator<<(ostream &out, const LZespolona &Skl)
{
  out << "(" << Skl.re;
  if (Skl.im >= 0)
    out << "+";
  out << Skl.im << "i)";
  return out;
}

/**
 * @brief Funkcja przeciazenia opearatora /=
 * 
 * @param Skl dzielnik typu LZespolona
 * @return LZespolona Zwracany wynik działania
 */
LZespolona LZespolona::operator/=(const LZespolona &Skl) const
{
  return (*this * Skl.Sprzezenie()) / Skl.Modul2();
}

/**
 * @brief Funkcja przeciazenia operatora +=
 * 
 * @param Skl Obiekt dodawany typu LZespolona
 * @return LZespolona Zwracamy wynik dzialania
 */
LZespolona LZespolona::operator+=(const LZespolona &Skl) const
{
  LZespolona wynik = *this;
  wynik.re += Skl.re;
  wynik.im += Skl.im;
  return wynik;
}

/**
 * @brief Funkcja obliczajaca argument dla LZespolonej
 * 
 * @return double Zwracany argument w postaci zmiennoprzecinkowej
 */
double LZespolona::arg() const
{
  double arg;
  if (this->re == 0 && this->im == 0)
  {
    cout << "Argument nieokreślony" << endl;
  }
  else if (this->re == 0)
  {
    if (this->im < 0)
      arg = -M_PI / 2;
    else
      arg = M_PI / 2;
  }
  else
  {
    if (this->re > 0)
    {
      arg = atan(this->im/this->re);
    }
    else
    {
      arg = atan(this->im/this->re) + M_PI;
    }
  }
  return arg;
}