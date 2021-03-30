#include "Statystyki.hh"
#include <iostream>

using namespace std;
/**
 * @brief Funkcja inkrementuje licznki poprawnych odpowiedzi
 * 
 */
void stat::dodaj_poprawna(){
l_poprawna++;
}
/**
 * @brief Funkcja inkrementuje licznik niepoprawnych odpowiedzi
 * 
 */
void stat::dodaj_niepoprawna(){
l_niepoprawna++;
}

/**
 * @brief Funkcja Wyswietla Liczbe poprawnych i niepoprawnych odpowiedzi, jak i procent poprawnych odpowiedzi
 * 
 */
void stat::wyswietl() const{
double procent= ((double)l_poprawna/((double)l_poprawna+(double)l_niepoprawna)) * 100;
cout<<"Ilosc odpowiedz poprawnych wynosi: "<<l_poprawna<<endl;
cout<<"Ilosc odpowiedzi niepoprawnych: "<<l_niepoprawna<<endl;
cout<<"Procent poprawnych odpowiedzi wynosi: "<<procent<<'%'<<endl;
}





