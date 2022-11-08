#include "adresat.h"

using namespace std;

void Adresat:: ustawIdAdresata (int noweIdAdresata) {
    idAdresata=noweIdAdresata;
}

void Adresat::ustawIdUzytkownikaMajacegoDostep (int noweIdUzytkownikaMajacegoDostep) {
    idUzytkownikaMajacegoDostep=noweIdUzytkownikaMajacegoDostep;
}

void Adresat::ustawImie (string noweImie) {
    imie=noweImie;
}

void Adresat::ustawNazwisko (string noweNazwisko) {
    nazwisko=noweNazwisko;
}

void Adresat::ustawAdres (string nowyAdres) {
    adres=nowyAdres;
}

void Adresat::ustawEmail (string nowyEmail) {
    email=nowyEmail;
}

void Adresat::ustawNumerTelefonu (string nowyNumerTelefonu) {
    numerTelefonu=nowyNumerTelefonu;
}
//to powyzej to sa settery, a ponizej gettery

int Adresat::pobierzIdAdresata() {
    return idAdresata;
}

int Adresat::pobierzIdUzytkownikaMajacegoDostep() {
    return idUzytkownikaMajacegoDostep;
}

string Adresat::pobierzImie() {
    return imie;
}

string Adresat::pobierzNazwisko() {
    return nazwisko;
}

string Adresat::pobierzAdres() {
    return adres;
}

string Adresat::pobierzEmail() {
    return email;
}

string Adresat::pobierzNumerTelefonu() {
    return numerTelefonu;
}
