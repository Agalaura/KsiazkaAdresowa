#include <fstream>
#include <windows.h>
#include "adresatManager.h"

using namespace std;


void AdresatManager::wczytajAdresatowDanegoUzytkownika(int idZalogowanegoUzytkownika) {
    listaAdresatowDanegoUzytkownika=plikZadresatami.wczytajAdresatowDanegoUzytkownika(idZalogowanegoUzytkownika);
}

int AdresatManager::dodajAdresata(int idZalogowanegoUzytkownika) {
    Adresat buforZadresami;

    int idNowegoAdresata = plikZadresatami.wczytanieIlosciAdresatowWpliku()+1;
    buforZadresami.ustawIdAdresata(idNowegoAdresata);
    string nowaDanaAdresata;

    cin.sync();
    cout<<"Podaj imie: "<<endl;
    cin >> nowaDanaAdresata;
    buforZadresami.ustawImie(nowaDanaAdresata);


    cin.sync();
    cout<<"Podaj nazwisko: ";
    cin >> nowaDanaAdresata;
    buforZadresami.ustawNazwisko(nowaDanaAdresata);

    cin.sync();
    cout<<"Podaj adres: ";
    cin >> nowaDanaAdresata;
    buforZadresami.ustawAdres(nowaDanaAdresata);

    cin.sync();
    cout<<"Podaj email: ";
    cin >> nowaDanaAdresata;
    buforZadresami.ustawEmail(nowaDanaAdresata);

    cin.sync();
    cout<<"Podaj numer telefonu: ";
    cin >> nowaDanaAdresata;
    buforZadresami.ustawNumerTelefonu(nowaDanaAdresata);

    buforZadresami.ustawIdUzytkownikaMajacegoDostep(idZalogowanegoUzytkownika);

    listaAdresatowDanegoUzytkownika.push_back(buforZadresami);

    fstream plik;
    plik.open("adresy.txt", ios::out | ios::app);

    plik<<buforZadresami.pobierzIdAdresata()<<"|"<<buforZadresami.pobierzIdUzytkownikaMajacegoDostep()<<"|"<<buforZadresami.pobierzImie()<<"|"<<buforZadresami.pobierzNazwisko()<<"|"<<buforZadresami.pobierzAdres()<<"|"<<buforZadresami.pobierzEmail()<<"|"<<buforZadresami.pobierzNumerTelefonu()<<"|"<<endl;

    plik.close();

    system("pause");
    return idNowegoAdresata;
}


void AdresatManager::wyszukajAdresataPoImieniu() {
    string kryteriumImie;
    cout<<"Podaj imie do wyszukania: ";
    cin>>kryteriumImie;

    for (int i=0; i<listaAdresatowDanegoUzytkownika.size(); i++) {
        if(listaAdresatowDanegoUzytkownika[i].pobierzImie() == kryteriumImie ) {
            cout<<endl<<listaAdresatowDanegoUzytkownika[i].pobierzIdAdresata()<<endl;
            cout<<listaAdresatowDanegoUzytkownika[i].pobierzImie()<<endl;
            cout<<listaAdresatowDanegoUzytkownika[i].pobierzNazwisko()<<endl;
            cout<<listaAdresatowDanegoUzytkownika[i].pobierzAdres()<<endl;
            cout<<listaAdresatowDanegoUzytkownika[i].pobierzEmail()<<endl;
            cout<<listaAdresatowDanegoUzytkownika[i].pobierzNumerTelefonu()<<endl;
        }
    }
    system("pause");
}

void AdresatManager::wyszukajAdresataPoNazwisku() {
    string kryteriumNazwisko;
    cout<<"Podaj nazwisko do wyszukania: ";
    cin>>kryteriumNazwisko;

    for (int i=0; i<listaAdresatowDanegoUzytkownika.size(); i++) {
        if( listaAdresatowDanegoUzytkownika[i].pobierzNazwisko() == kryteriumNazwisko ) {
            cout<<endl<<listaAdresatowDanegoUzytkownika[i].pobierzIdAdresata()<<endl;
            cout<<listaAdresatowDanegoUzytkownika[i].pobierzImie()<<endl;
            cout<<listaAdresatowDanegoUzytkownika[i].pobierzNazwisko()<<endl;
            cout<<listaAdresatowDanegoUzytkownika[i].pobierzAdres()<<endl;
            cout<<listaAdresatowDanegoUzytkownika[i].pobierzEmail()<<endl;
            cout<<listaAdresatowDanegoUzytkownika[i].pobierzNumerTelefonu()<<endl;
        }
    }
    system("pause");
}

void AdresatManager::wyswietlAdresatow() {
    cout <<"Zapisani adresaci to:" <<endl;

    for (int i=0; i<listaAdresatowDanegoUzytkownika.size(); i++) {
        cout<<listaAdresatowDanegoUzytkownika[i].pobierzIdAdresata()<<endl;
        cout<<listaAdresatowDanegoUzytkownika[i].pobierzImie()<<endl;
        cout<<listaAdresatowDanegoUzytkownika[i].pobierzNazwisko()<<endl;
        cout<<listaAdresatowDanegoUzytkownika[i].pobierzAdres()<<endl;
        cout<<listaAdresatowDanegoUzytkownika[i].pobierzEmail()<<endl;
        cout<<listaAdresatowDanegoUzytkownika[i].pobierzNumerTelefonu()<<endl;
    }

    system("pause");
}

void AdresatManager::edytujAdresata() {
    char wybor;
    int idZmienianegoAdresata;
    string zmienianyParametr;
    Adresat daneZmienianegoAdresata;

    cout<<"Podaj id adresata, ktorego chcesz edytowac: "<<endl;
    cin>>idZmienianegoAdresata;


    for (int i=0; i<listaAdresatowDanegoUzytkownika.size(); i++) {
        if (idZmienianegoAdresata==listaAdresatowDanegoUzytkownika[i].pobierzIdAdresata())  {
              //  daneZmienianegoAdresata.ustawId(idZmienianegoAdresata);
            while (true) {
                cout << "1. edycja imienia" << endl;
                cout << "2. edycja nazwiska" << endl;
                cout << "3. edycja adresu" << endl;
                cout << "4. edycja emaila" << endl;
                cout << "5. edycja numeru telefonu" << endl;
                cout << "6. wroc do menu glownego" <<endl;

                cin>>wybor;

                if (wybor=='1') {
                    cout<<"Podaj nowe imie: "<<endl;
                    cin.sync();
                    getline(cin, zmienianyParametr);
                    listaAdresatowDanegoUzytkownika[i].ustawImie(zmienianyParametr);
                   // daneZmienianegoAdresata.ustawImie(zmienianyParametr);
                } else if (wybor=='2') {
                    cout<<"Podaj nowe nazwisko: "<<endl;
                    cin.sync();
                    getline(cin, zmienianyParametr);
                    listaAdresatowDanegoUzytkownika[i].ustawNazwisko(zmienianyParametr);
                   // daneZmienianegoAdresata.ustawNazwisko(zmienianyParametr);
                } else if (wybor=='3') {
                    cout<<"Podaj nowy adres: "<<endl;
                    cin.sync();
                    getline(cin, zmienianyParametr);
                    listaAdresatowDanegoUzytkownika[i].ustawAdres(zmienianyParametr);
                   // daneZmienianegoAdresata.ustawAdres(zmienianyParametr);
                } else if (wybor=='4') {
                    cout<<"Podaj nowy email: "<<endl;
                    cin.sync();
                    getline(cin, zmienianyParametr);
                    listaAdresatowDanegoUzytkownika[i].ustawEmail(zmienianyParametr);
                   // daneZmienianegoAdresata.ustawEmail(zmienianyParametr);
                } else if (wybor=='5') {
                    cout<<"Podaj nowy telefon: "<<endl;
                    cin.sync();
                    getline(cin, zmienianyParametr);
                    listaAdresatowDanegoUzytkownika[i].ustawNumerTelefonu(zmienianyParametr);
                   // daneZmienianegoAdresata.ustawNumerTelefonu(zmienianyParametr);
                } else if (wybor=='6') {
                    break;
                } else {
                    cout<< "Nie ma takiej opcji w menu!" <<endl;
                    Sleep (500);
                }
            }
            system("cls");
           plikZadresatami.zapiszDanePoEdycjiWplikuTymczasowym (listaAdresatowDanegoUzytkownika[i]);
           plikZadresatami.zamienPlikTymczasowyWdocelowy ();
        }
    }

}

void AdresatManager::usunAdresata() {
    char potwierdzenieUsuwania;
    int idUsuwanegoAdresata;

    cout<<"Podaj id adresata, ktorego chcesz usunac: "<<endl;
    cin>>idUsuwanegoAdresata;

    for (int i=0; i<listaAdresatowDanegoUzytkownika.size(); i++) {
        if (idUsuwanegoAdresata==listaAdresatowDanegoUzytkownika[i].pobierzIdAdresata())  {
            cout<<"Czy na pewno chcesz usunac adresata o id "<<idUsuwanegoAdresata<<" ? Wcisnij t (tak) lub n (nie)"<<endl;
            cin>>potwierdzenieUsuwania;

            if (potwierdzenieUsuwania=='t') {
                vector <Adresat>::iterator itr;

                for (itr=listaAdresatowDanegoUzytkownika.begin(); itr <= listaAdresatowDanegoUzytkownika.end(); ++itr) {
                    if (itr->pobierzIdAdresata() == idUsuwanegoAdresata) {
                        listaAdresatowDanegoUzytkownika.erase(itr);
                        cout<<"Adresat zostal poprawnie usuniety"<<endl;
                    }
                }
            } else cout<<"Brak potwierdzenia. Adresat nie zostal usuniety!"<<endl;
            Sleep (1000);
        }
    }

    plikZadresatami.wczytanieIlosciAdresatowWpliku ();
    plikZadresatami.zapiszDanePoUsunieciuWplikuTymczasowym (idUsuwanegoAdresata);
    plikZadresatami.zamienPlikTymczasowyWdocelowy ();

    system("pause");
}


int AdresatManager::wczytanieIlosciAdresatowWpliku () {
    plikZadresatami.wczytanieIlosciAdresatowWpliku();
}



