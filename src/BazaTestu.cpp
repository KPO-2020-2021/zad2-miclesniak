#include <iostream>
#include <cstring>
#include <cassert>
#include "BazaTestu.hh"

using namespace std;

/**
 * @brief Tablica, Zawiera ona tresc latwego testu.
 */
static WyrazenieZesp  TestLatwy[] =
  { {{2,1}, Op_Dodaj, {1,2}},
    {{1,0}, Op_Odejmij, {0,1}},
    {{3,0}, Op_Mnoz, {0,3}},
    {{4,8}, Op_Dziel, {1,0}},
  };

/**
 * @brief Tablica, Zawiera ona tresc trudnego testu.
 *
 */
static WyrazenieZesp TestTrudny[] = 
  { {{3,4}, Op_Dodaj, {4,1}},
    {{34,11}, Op_Odejmij, {5,7}},
    {{2,5}, Op_Mnoz, {3,3}},
    {{7,11}, Op_Dziel, {3,4}},
  }; 





/**
 * @brief W bazie testu ustawia wybrany test jako biezacy test i indeks pytania
 *        ustawia na pierwsze z nich.
 * 
 *  
 *   @param wskTabTestu  - wskaznik na tablice zawierajaca wyrazenia arytmetyczne
 *                   bedace przedmiotem testu,
 *   @param  IloscPytan - ilosc pytan w tablicy.
 *   
 * 
 *      @pre Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      @pre Parametr wskTabTestu zawiera wskaznik na istniejaca tablice.
 *      @pre Parametr IloscPytan zawiera wartosc, ktora nie przekracza ilosci elementow
 *        w tablicy dostepnej poprzez wskTabTestu.
 */
void BazaTestu::UstawTest(WyrazenieZesp *wskTabTestu, unsigned int IloscPytan )
{
  this->wskTabTestu=wskTabTestu;
  this->IloscPytan = IloscPytan;
  this->IndeksPytania = 0;
}




/**
 * @brief Inicjalizuje test kojarzac zmienna dostepna poprzez wskaznik wskBazaTestu
 * z dana tablica wyrazen, ktora reprezentuje jeden z dwoch dopuszczalnych 
 * testow.
 * 
 *   
 *   @param sNazwaTestu  - wskaznik na napis wybranego typu testu.
 *
 * 
 *      @pre Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      @pre Parametr sNazwaTestu musi wskazywac na jedna z nazw tzn. "latwe" lub "trudne".
 *       
 *  @return bool
 *      @retval true - gdy operacja sie powiedzie i test zostanie poprawnie
 *              zainicjalizowany,
 *      @retval false - w przypadku przeciwnym.
 */
bool BazaTestu::InicjalizujTest(const char *sNazwaTestu ) 
{
  if (!strcmp(sNazwaTestu,"latwy")) {
    UstawTest(TestLatwy,sizeof(TestLatwy)/sizeof(WyrazenieZesp));
    return true;
  }
  /*
   * Analogicznie zrob inicjalizacje dla testu trudne
   */
  else if (!strcmp(sNazwaTestu,"trudny")) {
    UstawTest(TestTrudny,sizeof(TestTrudny)/sizeof(WyrazenieZesp));
    return true;
  }

  cerr << "Otwarcie testu '" << sNazwaTestu << "' nie powiodlo sie." << endl;
  return false;
}



/**
 *  @brief Funkcja udostepnia nastepne pytania o ile jest odpowiednia ich ilosc.
 * 
 *       
 *       @param wskWyrazenie - wskaznik na zmienna, do ktorej zostanie wpisane
 *                      kolejne wyrazenie z bazy testu.
 *
 * 
 *      @pre Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      @pre Parametr wskWyrazenie nie moze byc pustym wskaznikiem. Musi wskazywac na
 *        istniejaca zmienna.
 *
 *  @return bool
 *      @retval true - gdy operacja sie powiedzie i parametrowi *wskWyrazenie zostanie
 *              przypisane nowe wyrazenie zespolone z bazy,
 *      @retval false  w przypadku przeciwnym.
 */
bool BazaTestu::PobierzNastpnePytanie( WyrazenieZesp *wskWyrazenie )
{
  if (this->IndeksPytania >= this->IloscPytan) return false;

  *wskWyrazenie = this->wskTabTestu[this->IndeksPytania];
  ++this->IndeksPytania;
  return true;
}
