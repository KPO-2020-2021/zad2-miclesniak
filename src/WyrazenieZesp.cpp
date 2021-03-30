#include "WyrazenieZesp.hh"
#include <iostream>

using namespace std;

/**
 * @brief Funkcja Oblicza wartosc Wyrazenia Zespolonego
 * 
 * @return LZespolona Zwracana wartosc dzialania typu LZespolona
 */
LZespolona WyrazenieZesp::Oblicz() const{
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

/**
 * @brief Funkcja wyswietla Wyrazenie Zespolone
 * 
 */
void WyrazenieZesp::Wyswietl() const{
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
/**
 * @brief Funkcja wczytuje Wyrazenie Zespolone
 * 
 * @return WyrazenieZesp Zwraca obiekt z wczytanymi danymi
 */
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
/**
 * @brief Funkcja przeciazenia operatora bitowego w prawo dla Wyrazen Zespolonych
 * 
 * @param in strumien wejsciowy z ktorego wczytujemy dane 
 * @param temp Obiekt do ktorego wczytujemy dane  
 * @return std::istream& strumien wejsciowy z ktorego pobralismy dane
 */
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
/**
 * @brief Funkcja przeciazenia bitowego w lewo 
 * 
 * @param out Strumien na ktory wypisujemy dane
 * @param temp Obiekt z ktorego wypisujemy dane 
 * @return std::ostream& Strumien z zapisanymi danymi 
 */
std::ostream& operator<<(ostream &out,const WyrazenieZesp &temp){
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