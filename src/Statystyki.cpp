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
cout<<"Ilosc odpowiedz poprawnych wynosi: "<<l_poprawna<<endl;
cout<<"Ilosc odpowiedzi niepoprawnych: "<<l_niepoprawna<<endl;
cout<<"Procent poprawnych odpowiedzi wynosi: "<<this->procent()<<'%'<<endl;
}
/**
 * @brief Funkcja obliczajaca procent poprawnych odpowiedzi
 * 
 * @return double Zwraca procent
 */
double stat::procent() const{
    return ((double)this->l_poprawna/((double)this->l_poprawna+(double)this->l_niepoprawna)) * 100;
}





