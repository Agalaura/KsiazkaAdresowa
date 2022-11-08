#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>

using namespace std;

class Uzytkownik
{

int idUzytkownika;
string nazwaUzytkownika;
string hasloUzytkownika;

public:
    void ustawId (int noweId);
    void ustawLogin (string nowyLogin);
    void ustawHaslo (string noweHaslo);

    //to powyzej to sa settery, a ponizej gettery

    int pobierzId();
    string pobierzLogin();
    string pobierzHaslo();

};

#endif
