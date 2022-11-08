#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat {

    int idAdresata;
    int idUzytkownikaMajacegoDostep;
    string imie;
    string nazwisko;
    string adres;
    string email;
    string numerTelefonu;

public:
    void ustawIdAdresata (int noweIdAdresata);
    void ustawIdUzytkownikaMajacegoDostep (int noweIdUzytkownikaMajacegoDostep);
    void ustawImie (string noweImie);
    void ustawNazwisko (string noweNazwisko);
    void ustawAdres (string nowyAdres);
    void ustawEmail (string nowyEmail);
    void ustawNumerTelefonu (string nowNumerTelefonu);

    //to powyzej to sa settery, a ponizej gettery

    int pobierzIdAdresata();
    int pobierzIdUzytkownikaMajacegoDostep();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzAdres();
    string pobierzEmail();
    string pobierzNumerTelefonu();

};

#endif
