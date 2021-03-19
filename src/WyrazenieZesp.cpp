#include "WyrazenieZesp.hh"
#include <iostream>
using namespace std;
/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
LZespolona Oblicz(WyrazenieZesp  WyrZ){
    LZespolona Wynik;
    switch (WyrZ.Op)
    {
    case 0:
        Wynik = WyrZ.Arg1 + WyrZ.Arg2;
        break;
    
    case 1:
        Wynik = WyrZ.Arg1 - WyrZ.Arg2;
        break;

    case 2:
        Wynik = WyrZ.Arg1 * WyrZ.Arg2;
        break;
    
    case 3:
        Wynik = WyrZ.Arg1 / WyrZ.Arg2;
    
    default:
        break;
    }
    return Wynik;
}

void Wyswietl(WyrazenieZesp  WyrZ){
    Wyswietl(WyrZ.Arg1);
    switch (WyrZ.Op)
    {
    case 0:
        cout<<'+';
        break;
    
    case 1:
        cout<<'-';
        break;

    case 2:
        cout<<'*';
        break;

    case 3:
        cout<<'/';
        break;

    default:
        break;
    }
    Wyswietl(WyrZ.Arg2);
}

WyrazenieZesp wczytaj_Wz(){
    WyrazenieZesp temp;
    temp.Arg1 = wczytaj_l();
    char znak;
    cin>>znak;
    switch (znak)
    {
    case '+':
        temp.Op = Op_Dodaj;
        break;
    
    case '-':
        temp.Op = Op_Odejmij;
        break;

    case '*':
        temp.Op = Op_Mnoz;
        break;

    case '/':
        temp.Op = Op_Dziel;
        break;

    default:
        break;
    }
    temp.Arg2 = wczytaj_l();
    return  temp;
}

istream& operator>>(istream& in, WyrazenieZesp &temp){
    in>>temp.Arg1;
    char znak;
    in>>znak;
    if(in.fail()){
    return in;
    }
    switch (znak)
    {
    case '+':
        temp.Op = Op_Dodaj;
        break;
    
    case '-':
        temp.Op = Op_Odejmij;
        break;

    case '*':
        temp.Op = Op_Mnoz;
        break;

    case '/':
        temp.Op = Op_Dziel;
        break;

    default:
        in.setstate(ios::failbit);
        return in;
        break;
    }
    in>>temp.Arg2;
    return  in;
}
