#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include "adresat.h"

using namespace std;

class PlikZadresatami {

    const string NAZWA_PLIKU_Z_ADRESATAMI;
    Adresat buforZdanymiAdresatow;

public:

    PlikZadresatami(string nazwaPlikuAdresowego): NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuAdresowego) {};

    vector <Adresat> wczytajUzytkownikow();
    void zapiszNowegoAdresataWpliku(Adresat daneNowegoAdresata); //przekazac albo tlyko dodanego uzytkownika
    //albo nadpisac caly wektor i przejsc po petli
    //void zapiszNoweHasloWpliku (string noweHaslo);
    //void zapiszWektorAdresatowWpliku(vector<Adresat> adresaci);


    int wczytanieIlosciAdresatowWpliku ();
    vector <Adresat> wczytajAdresatowDanegoUzytkownika(int idZalogowanegoUzytkownika);
    void zapiszDanePoUsunieciuWplikuTymczasowym (int idUsuwanegoAdresata);
    void zapiszDanePoEdycjiWplikuTymczasowym (int idZmienianegoAdresata, vector <Adresat> listaAdresatowDanegoUzytkownika);
    void zamienPlikTymczasowyWdocelowy ();

};

#endif
