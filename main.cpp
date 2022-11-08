#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include "ksiazkaAdresowa.h"

using namespace std;

int main() {

    char wybor;

    KsiazkaAdresowa ksiazkaAdresowa ("uzytkownicy.txt", "adresy.txt");

    int idZalogowanegoUzytkownika;

    int idUsuwanegoAdresata;



    while (true) {
        cout <<"1. Rejestracja"<<endl;
        cout <<"2. Logowanie" <<endl;
        cout <<"3. Wypisz wszystkich uzytkownikow"<<endl;
        cout <<"4. Koniec"<<endl;

        cin>>wybor;

        switch (wybor) {
        case '1': {
            ksiazkaAdresowa.stworzNowegoUzytkownika();
        }
        break;
        case '2': {
            idZalogowanegoUzytkownika=ksiazkaAdresowa.zalogujSie();
            Sleep (600);
            system("cls");

            while (idZalogowanegoUzytkownika>0) {
                cout << "1. Dodaj adresata" << endl;
                cout << "2. Wyszukaj po imieniu" << endl;
                cout << "3. Wyszukaj po nazwisku" << endl;
                cout << "4. Wyswietl wszystkich adresatow" << endl;
                cout << "5. Edytuj wybranego adresata" << endl;
                cout << "6. Usun wybranego adresata" <<endl;
                cout << "7. zmien swoje haslo" << endl;
                cout << "8. wyloguj sie" << endl;
                cout << "9. Zakoncz program" << endl;

                cin>>wybor;
                switch (wybor) {
                case '1': {
                    ksiazkaAdresowa.dodajAdresata();
                }
                break;
                case '2': {
                    ksiazkaAdresowa.wyszukajAdresataPoImieniu();
                }
                break;
                case '3': {
                    ksiazkaAdresowa.wyszukajAdresataPoNazwisku();
                }
                break;
                case '4': {
                    ksiazkaAdresowa.wyswietlAdresatow();
                }
                break;
                case '5': {
                    ksiazkaAdresowa.edytujAdresata();
                }
                break;
                case '6': {
                    ksiazkaAdresowa.usunAdresata();
                }
                break;

                case '7': {
                    ksiazkaAdresowa.zmienHasloUzytkownika();
                }
                break;

                case '8': {
                    idZalogowanegoUzytkownika=ksiazkaAdresowa.wylogujSie();
                }
                break;
                case '9': {
                    exit (0);
                }
                break;

                default:
                    cout<< "Nie ma takiej opcji w menu!" <<endl;
                }
                system("cls");
            }
        }
        break;
        case '3': {
            ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
        }
        break;

        case '4': {
            exit(0);
        }
        break;

        default:
            cout<< "Nie ma takiej opcji w menu!" <<endl;
        }
        system("cls");
    }
    return 0;
}



/*testy AdresatManager

#include "adresatManager.h"

int main()
{
    AdresatManager adresatManager ("adresy.txt", 2)
}*/
