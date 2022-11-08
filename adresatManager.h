#include <iostream>
#include <vector>
#include "plikZadresatami.h"

using namespace std;

class AdresatManager {
    vector <Adresat> listaAdresatowDanegoUzytkownika;
    PlikZadresatami plikZadresatami;

public:
    //konstruktor:
//w konstruktorze trzeba wywolac metode, ktora wczyta z pliku do wektora
//zrobic pliki do wczytywania z pliku, cpp i h
    AdresatManager(string nazwaPlikuAdresowego, int zalogowany): plikZadresatami(nazwaPlikuAdresowego) {
        wczytajAdresatowDanegoUzytkownika(zalogowany);
    };

    void wczytajAdresatowDanegoUzytkownika(int idZalogowanegoUzytkownika);
    int wczytanieIlosciAdresatowWpliku ();
    int dodajAdresata(int idZalogowanegoUzytkownika);
    void wyszukajAdresataPoImieniu();
    void wyszukajAdresataPoNazwisku();
    void wyswietlAdresatow();
    void edytujAdresata();
    void usunAdresata();
//
};
