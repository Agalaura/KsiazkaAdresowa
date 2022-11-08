#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include "uzytkownik.h"

using namespace std;

class PlikZuzytkownikami{

 string nazwaPlikuZuzytkownikami; //tutaj Artur chce wprowadzic stala i nazwac ja duzymi literami, ale ja mam blad
 // i u mnie to nie dziala, dlaczego?
  Uzytkownik buforZdanymiUzytkownikow;

  public:

    PlikZuzytkownikami(string nazwaPliku) {
        nazwaPlikuZuzytkownikami = nazwaPliku;
    };

  vector <Uzytkownik> wczytajUzytkownikow();
  void zapiszUzytkownikowWpliku(Uzytkownik daneNowegoUzytkownika); //przekazac albo tlyko dodanego uzytkownika
  //albo nadpisac caly wektor i przejsc po petli
  //void zapiszNoweHasloWpliku (string noweHaslo);
  void zapiszWektorUzytkownikow(vector<Uzytkownik> uzytkownicy);
};

#endif
