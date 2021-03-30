#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH
#include <iostream>

#include "LZespolona.hh"
/**
 * @brief Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj,   /**< @brief Operacja dodawania*/
                Op_Odejmij, /**< @brief Operacja odejmowania*/
                Op_Mnoz,    /**< @brief Operacja mnozenia*/
                Op_Dziel    /**< @brief Operacja dzielenia*/
              };



/**
 * @brief Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego

  void Wyswietl() const;
  LZespolona Oblicz() const;
  WyrazenieZesp wczytaj_Wz() ;
};

  std::istream& operator>>(std::istream& in, WyrazenieZesp &temp);
  std::ostream& operator<<(std::ostream &out, const WyrazenieZesp &temp);


#endif
