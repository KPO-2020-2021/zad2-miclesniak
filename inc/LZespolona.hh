#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>



/**
 * @brief Modeluje pojecie liczby zespolonej ktora zawiera czesc rzeczywista i zespolona typu double
 */
struct  LZespolona {
  double   re;    
  double  im;    
  LZespolona  operator + (const LZespolona  Skl2) const;
  LZespolona operator +=(const LZespolona &Skl) const;
  LZespolona operator / (const double Skl2) const;
  LZespolona  operator - (const LZespolona  Skl2) const;
  LZespolona  operator * (const LZespolona  Skl2) const;
  LZespolona  operator / (const LZespolona  Skl2) const;
  LZespolona operator /=(const LZespolona &Skl) const;
  LZespolona Sprzezenie() const;
  double arg() const;
  double Modul2() const;
  void Wyswietl() const;
  bool  operator == (const LZespolona  Skl2) const;
  bool wczytaj_l();

};
  std::istream& operator>>(std::istream& in,LZespolona &wynik);
  std::ostream& operator<<(std::ostream &out,const LZespolona &Skl);
  


#endif
