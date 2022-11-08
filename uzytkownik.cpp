#include "uzytkownik.h"

using namespace std;


void Uzytkownik:: ustawId (int noweId) {
           idUzytkownika=noweId;
    }

void Uzytkownik::ustawLogin (string nowyLogin) {
    nazwaUzytkownika=nowyLogin;
}

void Uzytkownik::ustawHaslo (string noweHaslo) {
    hasloUzytkownika=noweHaslo;
}

//to powyzej to sa settery, a ponizej gettery

int Uzytkownik::pobierzId() {
    return idUzytkownika;
}

string Uzytkownik::pobierzLogin() {
    return nazwaUzytkownika;
}

string Uzytkownik::pobierzHaslo() {
    return hasloUzytkownika;
}
