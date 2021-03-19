#include <iostream>
#include "BazaTestu.hh"

using namespace std;




int main(int argc, char **argv)
{

 /* if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " Czesc rzeczywista pierwszego argumentu: ";
    cout << WyrZ_PytanieTestowe.Arg1.re << endl;
  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
*/

/*LZespolona W1, W2, W3;
 W1.re = 20;
 W1.im = 9;
 W2.re = 6;
 W2.im = -1;
 Wyswietl(W1);
 cout<<endl;
 Wyswietl(W2);
 W3 = W1/W2;
 cout<<endl;
 Wyswietl(W3);
 cout<<endl;
 WyrazenieZesp A1;
 A1.Arg1 = W1;
 A1.Op = Op_Dziel;
 A1.Arg2 = W2;
 cout<<endl;
 Wyswietl(A1);
 W3 = Oblicz(A1);
 cout<<endl;
 Wyswietl(W3);*/



WyrazenieZesp wynik;
wynik = wczytaj_Wz();
Wyswietl(wynik);
LZespolona W1;
cin>>W1;

}
