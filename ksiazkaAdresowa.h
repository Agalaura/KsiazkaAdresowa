#include <iostream>
#include <vector>
#include "uzytkownikManager.h"
#include "adresatManager.h"


class KsiazkaAdresowa {



    UzytkownikManager uzytkownikManager;
    AdresatManager *adresatManager;
    string nazwaPlikuAdresowego;

public:

    //konstruktor

    KsiazkaAdresowa(string nazwaPliku, string nazwaPlikuAdresaci):
    uzytkownikManager(nazwaPliku) {
        adresatManager=NULL;
        nazwaPlikuAdresowego=nazwaPlikuAdresaci;
    };
//destruktur

~KsiazkaAdresowa(){
    delete adresatManager;
    adresatManager=NULL;
}

    //metody:


    void wypiszWszystkichUzytkownikow();
    void stworzNowegoUzytkownika ();
    int zalogujSie();
    void zmienHasloUzytkownika();
    int wylogujSie();

    void wczytajAdresatowDanegoUzytkownika(int idZalogowanegoUzytkownika);
    int wczytanieIlosciAdresatowWpliku ();
    int dodajAdresata();
    void wyswietlAdresatow();
    void wyszukajAdresataPoImieniu();
    void wyszukajAdresataPoNazwisku();
    void usunAdresata();
    void edytujAdresata();


};
