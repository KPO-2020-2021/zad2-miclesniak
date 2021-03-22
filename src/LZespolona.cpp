#include "LZespolona.hh"
#include <cmath>
#include <iostream>

#define MIN_DIFF 0.00001

using namespace std;

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2){
  if ((Skl1.re == Skl2.re) && (Skl1.im == Skl2.im))
    return true;
  else
    return false;
  //alternatywnie, dla MIN_DIFF i wyników od użytkownika
  /*
  if abs(Skl1.re - Skl2.re) <= MIN_DIFF && abs(Skl1.im - Skl2.im) <= MIN_DIFF
    return true;
  else
    return false;
  */
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona operator-(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona operator*(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = (Skl1.re * Skl2.re) - (Skl1.im * Skl2.im);
  Wynik.im = (Skl1.re * Skl2.im) + (Skl1.im * Skl2.re);
  return Wynik;
}

LZespolona operator/(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;
  Wynik = (Skl1 * Sprzezenie(Skl2)) / Modul2(Skl2);
  return Wynik;
}


/*!
 * Realizuje dzielenie liczby zespolonej przez skakar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - skalar-dzielnik.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  double  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re / Skl2;
  Wynik.im = Skl1.im / Skl2;
  return Wynik;
}
LZespolona Sprzezenie(LZespolona Skl){
  LZespolona temp;
  temp.re = Skl.re;
  temp.im = - Skl.im;
  return temp;
}

double Modul2(LZespolona Skl)
{
  return Skl.re * Skl.re + Skl.im * Skl.im;
}

void Wyswietl(LZespolona Skl){
  cout<<"("<<Skl.re;
  if(Skl.im>=0)
    cout<<"+";
  cout<<Skl.im<<"i)";
}

LZespolona wczytaj_l(){
  char temp;
  LZespolona wynik;
  cin>>temp;
  if(temp != '('){
    cout<<"blad";
    return wynik;
  }
  cin>>wynik.re;
  if(cin.fail()){
    return wynik;
  }
  cin>>wynik.im;
  if(cin.fail()){
    return wynik;
  }
  cin>>temp;
  if(temp != 'i'){
    cout<<"blad";
    return wynik;
  }
  cin>>temp;
  if(temp != ')'){
    cout<<"blad";
    return wynik;
  }

  return wynik;
}

istream& operator>>(istream& in,LZespolona &wynik){
  char temp;
  in>>temp;
  if(in.fail()){
    return in;
  }
  if(temp != '('){
    in.setstate(ios::failbit);
    return in;
  }
  in>>wynik.re;
  if(in.fail()){
    return in;
  }
  in>>wynik.im;
  if(in.fail()){
    return in;
  }
  in>>temp;
  if(in.fail()){
    return in;
  }
  if(temp != 'i'){
    in.setstate(ios::failbit);
    return in;
  }
  in>>temp;
  if(in.fail()){
    return in;
  }
  if(temp != ')'){
    in.setstate(ios::failbit);
    return in;
  }

  return in;
}

ostream& operator<<(ostream &out,LZespolona &Skl){
   out<<"("<<Skl.re;
  if(Skl.im>=0)
    out<<"+";
  out<<Skl.im<<"i)";
  return out;
}
