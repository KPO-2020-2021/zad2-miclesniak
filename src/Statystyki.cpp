#include "Statystyki.hh"
#include <iostream>

using namespace std;

void dodaj_poprawna(stat &s){
s.l_poprawna++;
}

void dodaj_niepoprawna(stat &s){
s.l_niepoprawna++;
}

void wyswietl(stat s){
double procent= ((double)s.l_poprawna/((double)s.l_poprawna+(double)s.l_niepoprawna)) * 100;
cout<<"Ilosc odpowiedz poprawnych wynosi: "<<s.l_poprawna<<endl;
cout<<"Ilosc odpowiedzi niepoprawnych: "<<s.l_niepoprawna<<endl;
cout<<"Procent poprawnych odpowiedzi wynosi: "<<procent<<'%'<<endl;
}

void inicjuj(stat &s){
s.l_poprawna = 0;
s.l_niepoprawna = 0;
}


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
