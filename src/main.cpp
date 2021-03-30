#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"

using namespace std;

int main(int argc, char **argv)
{

  if (argc < 2) 
  {
    cout << endl; 
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

  BazaTestu BazaT = {nullptr, 0, 0}; 

  if (BazaT.InicjalizujTest(argv[1]) == false)
  {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }

  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp WyrZ_PytanieTestowe; 
  LZespolona Odpowiedz, Wynik; 
  stat s;
  while (BazaT.PobierzNastpnePytanie(&WyrZ_PytanieTestowe))
  {
    try
    {
      Wynik = WyrZ_PytanieTestowe.Oblicz();
      cout << endl
                << "Oblicz dzialanie: ";
      WyrZ_PytanieTestowe.Wyswietl();
      cout << endl
                << "Podaj poprawną odpowiedz" << endl;
      if (Odpowiedz.wczytaj_l() == false)
      {
        s.dodaj_niepoprawna();
        cout << "Poprawana odpowiedz to: " << endl;
        cout << Wynik << endl;
      }
      else
      {
        if (Odpowiedz == Wynik)
        {
          s.dodaj_poprawna();
          cout<<"Odpowiedz poprawna\n";
        }
        else
        {
          s.dodaj_niepoprawna();
          cout << "Twoja odpowiedz to: " << Odpowiedz << endl;
          cout << "Błąd! Poprawana odpowiedz to: " << endl;
          cout << Wynik << endl;
        }
      }
    }
    catch(runtime_error &e)
    {
      cerr<<"W pytaniu wyktuto błąd"<<e.what()<<"Pytanie zostało pominięte";
    }
  }
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

  s.wyswietl();
}
