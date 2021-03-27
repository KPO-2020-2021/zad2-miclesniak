#include "LZespolona.hh"
#include <cmath>
#include <iostream>
#include <stdexcept>

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

bool  LZespolona::operator == (LZespolona  Skl2) const{
  if ((this->re == Skl2.re) && (this->im == Skl2.im))
    return true;
  else
    return false;
  //alternatywnie, dla MIN_DIFF i wyników od użytkownika
  if (abs(this->re - Skl2.re) <= MIN_DIFF && abs(this->im - Skl2.im) <= MIN_DIFF)
    return true;
  else
    return false;
  
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator + (LZespolona  Skl2) const{

  Skl2.re += this->re;
  Skl2.im += this->im;
  return Skl2;
}

LZespolona LZespolona::operator-(LZespolona Skl2) const
{
  Skl2.re -= this->re;
  Skl2.im -= this->im;
  return Skl2;
}

LZespolona LZespolona::operator*(LZespolona Skl2) const
{
  Skl2.re = (this->re * Skl2.re) - (this->im * Skl2.im);
  Skl2.im = (this->re * Skl2.im) + (this->im * Skl2.re);
  return Skl2;
}

LZespolona LZespolona::operator/(LZespolona Skl2) const
{
  try
  {
    Skl2 = (*this * Skl2.Sprzezenie()) / Skl2.Modul2();
  }
  catch(runtime_error & e)
  {
    cout<<"Wystapil wyjatek"<<endl<< e.what();
  }
  return Skl2;
}


/*!
 * Realizuje dzielenie liczby zespolonej przez skakar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - skalar-dzielnik.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator / (double  Skl2) const{
  LZespolona  Wynik;
  if (Skl2 ==0 )
    throw runtime_error("Błąd matematyczny: próbowano podzielić przez zero\n");
  Wynik.re = this->re / Skl2;
  Wynik.im = this->im / Skl2;
  return Wynik;
}
LZespolona LZespolona::Sprzezenie() const{
  LZespolona temp;
  temp.re = this->re;
  temp.im = - this->im;
  return temp;
}

double LZespolona::Modul2() const
{
  return this->re * this->re + this->im * this->im;
}

void LZespolona::Wyswietl() const{
  cout<<"("<<this->re;
  if(this->im>=0)
    cout<<"+";
  cout<<this->im<<"i)";
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
