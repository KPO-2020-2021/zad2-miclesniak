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
  double  im;    /*! Pole repezentuje czesc urojona. */

  LZespolona  operator + (LZespolona  Skl2) const;
  LZespolona operator / (double Skl2) const;
  LZespolona  operator - (LZespolona  Skl2) const;
  LZespolona  operator * (LZespolona  Skl2) const;
  LZespolona  operator / (LZespolona  Skl2) const;
  LZespolona Sprzezenie() const;
  double Modul2() const;
  void Wyswietl() const;
  bool  operator == (LZespolona  Skl2) const;
  LZespolona wczytaj_l();

};
  std::istream& operator>>(std::istream& in,LZespolona &wynik);
  std::ostream& operator<<(std::ostream &out,LZespolona &Skl);
  
/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

#endif
