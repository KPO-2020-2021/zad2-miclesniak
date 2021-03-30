#ifndef BAZATESTU_HH
#define BAZATESTU_HH


#include "WyrazenieZesp.hh"


/**
 * @brief Modeluje pojecie baze testu z zestawem pytan w tablicy
 * oraz informacji o maksymalnej ilosci pytan, jak
 * tez indeksem nastepnego pytania.
 */
struct BazaTestu {
  WyrazenieZesp  *wskTabTestu;  
  unsigned int    IloscPytan;
  unsigned int    IndeksPytania; 
 
  bool InicjalizujTest(const char*  sNazwaTestu );
  bool PobierzNastpnePytanie(WyrazenieZesp *wskWyr );
  void UstawTest(WyrazenieZesp *wskTabTestu, unsigned int IloscPytan );
};



#endif
