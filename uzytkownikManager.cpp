#include <fstream>
#include <windows.h>
#include "uzytkownikManager.h"

using namespace std;


void UzytkownikManager::wypiszWszystkichUzytkownikow() {
    cout <<"Zapisani uzytkownicy to:" <<endl;

    for (int i=0; i<listaUzytkownikow.size(); i++) {
        cout<<listaUzytkownikow[i].pobierzId()<<endl;
        cout<<listaUzytkownikow[i].pobierzLogin()<<endl;
        cout<<listaUzytkownikow[i].pobierzHaslo()<<endl;
    }

    system("pause");
}


int UzytkownikManager:: stworzNowegoUzytkownika() {
    Uzytkownik buforZdanymiUzytkownikow;

    int id = 1;
    if (!listaUzytkownikow.empty()) {
        id = listaUzytkownikow.size()+1;
    }

    buforZdanymiUzytkownikow.ustawId(id);

    string login, haslo;
    cin.sync();
    cout<<"Podaj nazwe uzytkownika: "<<endl;
    getline(cin, login);
    buforZdanymiUzytkownikow.ustawLogin(login);

    cin.sync();
    cout<<"Podaj haslo: ";
    getline(cin, haslo);
    buforZdanymiUzytkownikow.ustawHaslo(haslo);

    cin.sync();

    listaUzytkownikow.push_back(buforZdanymiUzytkownikow);

    plikZuzytkownikami.zapiszUzytkownikowWpliku(buforZdanymiUzytkownikow);

    system("pause");
    return id;
}

int UzytkownikManager::zalogujSie () {

    int j=0;
    string hasloDoSprawdzenia;
    string nazwaUzytkownikaDoSprawdzenia;
    cout<<"Podaj swoja nazwe uzytkownika: ";
    cin>>nazwaUzytkownikaDoSprawdzenia;

    for (int i=0; i<listaUzytkownikow.size(); i++) {
        if( listaUzytkownikow[i].pobierzLogin() == nazwaUzytkownikaDoSprawdzenia ) {
            while (j<=2) {
                cout<<"Podaj swoje haslo uzytkownika: "<<endl;
                cin>>hasloDoSprawdzenia;
                if( listaUzytkownikow[i].pobierzHaslo() == hasloDoSprawdzenia ) {
                    cout<<"Zalogowales sie poprawnie jako "<<listaUzytkownikow[i].pobierzLogin()<<endl;
                    idZalogowanegoUzytkownika=listaUzytkownikow[i].pobierzId();
                    //  cout<<idZalogowanegoUzytkownika<<endl;
                    return idZalogowanegoUzytkownika;
                } else {
                    cout<<"Podane haslo jest bledne! "<<endl;
                    Sleep (600);
                    j++;
                }
            }
        }
        if (j > 2) {
            cout<<"Nie ma takiego uzytkownika! Sprobuj ponownie." <<endl;
        }
    }
    system("pause");
    return idZalogowanegoUzytkownika;
}

void UzytkownikManager::zmienHasloUzytkownika() {
    string noweHaslo;
    vector <Uzytkownik>::iterator itr;

    cout<<"Podaj swoje nowe haslo: "<<endl;
    cin.sync();
    getline(cin, noweHaslo);

    for (itr=listaUzytkownikow.begin(); itr <= listaUzytkownikow.end(); ++itr) {
        if (itr->pobierzId() == idZalogowanegoUzytkownika) {
            itr->ustawHaslo(noweHaslo);
        }
    }
    cout<<"nowe haslo zapisano jako: "<<noweHaslo<<endl;

    wypiszWszystkichUzytkownikow();
    plikZuzytkownikami.zapiszWektorUzytkownikow(listaUzytkownikow);
    system("pause");
}


int UzytkownikManager::wylogujSie() {
    idZalogowanegoUzytkownika=0;
    return idZalogowanegoUzytkownika;
}

int UzytkownikManager::pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}
