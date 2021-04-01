#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH



#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
/**
 * @brief Modeluje pojecie statystyki ktora zawiera l_poprawne i l_niepoprawna typu iny
 * 
 */
struct stat
{
    int l_poprawna;
    int l_niepoprawna;

    stat():l_poprawna(0),l_niepoprawna(0){}
    void dodaj_poprawna();
    void dodaj_niepoprawna();
    void wyswietl() const;
    double procent() const;
};


#endif
