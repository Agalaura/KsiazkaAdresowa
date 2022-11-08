#include "ksiazkaAdresowa.h"

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::stworzNowegoUzytkownika () {
    uzytkownikManager.stworzNowegoUzytkownika();
}

int KsiazkaAdresowa::zalogujSie() {
    int zalogowany=uzytkownikManager.zalogujSie();
    if (zalogowany>0) {
        adresatManager = new AdresatManager(nazwaPlikuAdresowego, zalogowany);
    }
}

void KsiazkaAdresowa::zmienHasloUzytkownika() {
    uzytkownikManager.zmienHasloUzytkownika();
}

int KsiazkaAdresowa::wylogujSie() {
    uzytkownikManager.wylogujSie();
}

void KsiazkaAdresowa:: wczytajAdresatowDanegoUzytkownika(int idZalogowanegoUzytkownika) {
    adresatManager->wczytajAdresatowDanegoUzytkownika(idZalogowanegoUzytkownika);
}

int KsiazkaAdresowa::wczytanieIlosciAdresatowWpliku () {
    adresatManager->wczytanieIlosciAdresatowWpliku();
}

int KsiazkaAdresowa::dodajAdresata() {
    adresatManager->dodajAdresata(uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::wyswietlAdresatow() {
    adresatManager->wyswietlAdresatow();
}

void KsiazkaAdresowa:: wyszukajAdresataPoImieniu() {
    adresatManager->wyszukajAdresataPoImieniu();
}

void KsiazkaAdresowa:: wyszukajAdresataPoNazwisku() {
    adresatManager->wyszukajAdresataPoNazwisku();
}

void KsiazkaAdresowa::usunAdresata() {
    adresatManager->usunAdresata();
}

void KsiazkaAdresowa::edytujAdresata() {
    adresatManager->edytujAdresata();
}
