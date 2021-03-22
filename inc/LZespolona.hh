#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona operator / (LZespolona Skl1, double Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona Sprzezenie(LZespolona Skl);
double Modul2(LZespolona Skl);
void Wyswietl(LZespolona Skl);
LZespolona wczytaj_l();
std::istream& operator>>(std::istream& in,LZespolona &wynik);
std::ostream& operator<<(std::ostream &out,LZespolona &Skl);

#endif
