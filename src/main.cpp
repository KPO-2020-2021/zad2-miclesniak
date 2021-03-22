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

LZespolona W1, W2, W3;
cin>>W1;
cin>>W2;
 cout<<W1;
 cout<<endl;
 cout<<W2;
 W3 = W1/W2;
 cout<<endl;
 cout<<W3;
 cout<<endl;
 WyrazenieZesp A1;
 cin>>A1;
 cout<<endl;
 cout<<A1;
 W3 = Oblicz(A1);
 cout<<endl;
 cout<<W3;

}
