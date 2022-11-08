#include <iostream>
#include <vector>
#include "plikZuzytkownikami.h"

using namespace std;

class UzytkownikManager {
    vector <Uzytkownik> listaUzytkownikow;
   int idZalogowanegoUzytkownika;
    PlikZuzytkownikami plikZuzytkownikami;

public:
    //konstruktor:
//w konstruktorze trzeba wywolac metode, ktora wczyta z pliku do wektora
//zrobic pliki do wczytywania z pliku, cpp i h
    UzytkownikManager(string nazwaPliku): plikZuzytkownikami(nazwaPliku) {
        // listaUzytkownikow = uzytkownicy;
       idZalogowanegoUzytkownika=0;
        listaUzytkownikow = plikZuzytkownikami.wczytajUzytkownikow();
    };


    void wypiszWszystkichUzytkownikow();
    int stworzNowegoUzytkownika ();
    int zalogujSie();
    void zmienHasloUzytkownika();
    int wylogujSie();
    int pobierzIdZalogowanegoUzytkownika();

};
