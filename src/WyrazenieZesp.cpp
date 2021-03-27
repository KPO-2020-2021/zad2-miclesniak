#include "WyrazenieZesp.hh"
#include <iostream>

using namespace std;
/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
LZespolona WyrazenieZesp::Oblicz(){
    LZespolona Wynik;
    switch (this->Op)
    {
    case 0:
        Wynik = this->Arg1 + this->Arg2;
        break;
    
    case 1:
        Wynik = this->Arg1 - this->Arg2;
        break;

    case 2:
        Wynik = this->Arg1 * this->Arg2;
        break;
    
    case 3:
        Wynik = this->Arg1 / this->Arg2;
    
    default:
        break;
    }
    return Wynik;
}


void WyrazenieZesp::Wyswietl(){
    Arg1.Wyswietl();
    switch (this->Op)
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
    Arg2.Wyswietl();
}

WyrazenieZesp WyrazenieZesp::wczytaj_Wz(){
    Arg1.wczytaj_l();
    char znak;
    cin>>znak;
    switch (znak)
    {
    case '+':
        this->Op = Op_Dodaj;
        break;
    
    case '-':
        this->Op = Op_Odejmij;
        break;

    case '*':
        this->Op = Op_Mnoz;
        break;

    case '/':
        this->Op = Op_Dziel;
        break;

    default:
        break;
    }
    Arg2.wczytaj_l();
    return  *this;
}

std::istream& operator>>(istream& in, WyrazenieZesp &temp){
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

std::ostream& operator<<(ostream &out, WyrazenieZesp &temp){
    out<<temp.Arg1;
    switch (temp.Op)
    {
    case 0:
        out<<'+';
        break;
    
    case 1:
        out<<'-';
        break;

    case 2:
        out<<'*';
        break;

    case 3:
        out<<'/';
        break;

    default:
        break;
    }
    out<<temp.Arg2;
    return out;
}