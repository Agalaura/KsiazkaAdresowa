#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include "uzytkownik.h"

using namespace std;

class PlikZuzytkownikami {

    string nazwaPlikuZuzytkownikami;
    Uzytkownik buforZdanymiUzytkownikow;

public:

    PlikZuzytkownikami(string nazwaPliku) {
        nazwaPlikuZuzytkownikami = nazwaPliku;
    };

    vector <Uzytkownik> wczytajUzytkownikow();
    void zapiszUzytkownikowWpliku(Uzytkownik daneNowegoUzytkownika);
    void zapiszWektorUzytkownikow(vector<Uzytkownik> uzytkownicy);
};

#endif
