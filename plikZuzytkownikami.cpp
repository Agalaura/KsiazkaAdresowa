#include "plikZuzytkownikami.h"

vector <Uzytkownik> PlikZuzytkownikami::wczytajUzytkownikow() {
    Uzytkownik buforZuzytkownikami;
    vector <Uzytkownik> wczytaniUzytkownicy;
    string linia="";
    string buforNaWyrazy="";
    int nrLinii=1;
    int licznikKresek=0;

    fstream plikZuzytkownikami;
    plikZuzytkownikami.open(nazwaPlikuZuzytkownikami, ios::in);

    if(plikZuzytkownikami.good()==true) {
        while(getline(plikZuzytkownikami,linia)) {
            for (int counter=0; counter<linia.length(); counter++) {
                if (linia[counter] != '|') {
                    buforNaWyrazy+=linia[counter];
                } else {
                    licznikKresek++;
                    if (licznikKresek==1) {
                        buforZuzytkownikami.ustawId(stoi(buforNaWyrazy));
                        buforNaWyrazy="";
                    } else if (licznikKresek==2) {
                        buforZuzytkownikami.ustawLogin(buforNaWyrazy);
                        buforNaWyrazy="";
                    } else if (licznikKresek==3) {
                        buforZuzytkownikami.ustawHaslo(buforNaWyrazy);
                        buforNaWyrazy="";
                        wczytaniUzytkownicy.push_back(buforZuzytkownikami);
                        licznikKresek=0;
                    }
                }
            }
        }
    }
    plikZuzytkownikami.close();

    return wczytaniUzytkownicy;
}

void PlikZuzytkownikami::zapiszUzytkownikowWpliku(Uzytkownik daneNowegoUzytkownika) {

    fstream plikZuzytkownikami;
    if(plikZuzytkownikami.good()==true) {
        plikZuzytkownikami.open(nazwaPlikuZuzytkownikami, ios::out | ios::app);

        cout<<"plik otwarto poprawnie do zapisu"<<endl;
        Sleep (800);

        plikZuzytkownikami<<daneNowegoUzytkownika.pobierzId()<<"|"<<daneNowegoUzytkownika.pobierzLogin()<<"|"<<daneNowegoUzytkownika.pobierzHaslo()<<"|"<<endl;
    }
    plikZuzytkownikami.close();
}
void PlikZuzytkownikami::zapiszWektorUzytkownikow(vector<Uzytkownik> uzytkownicy) {
    fstream plikZuzytkownikami;
    plikZuzytkownikami.open(nazwaPlikuZuzytkownikami, ios::out);

    for(int i = 0; i < uzytkownicy.size(); i++) {
        plikZuzytkownikami<<uzytkownicy[i].pobierzId()<<"|"<<uzytkownicy[i].pobierzLogin()<<"|"<<uzytkownicy[i].pobierzHaslo()<<"|"<<endl;
    }
    plikZuzytkownikami.close();
}
