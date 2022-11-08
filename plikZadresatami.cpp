#include "plikZadresatami.h"

vector <Adresat> PlikZadresatami:: wczytajAdresatowDanegoUzytkownika(int idZalogowanegoUzytkownika) {
    Adresat buforZadresami;
    vector <Adresat> wczytaneAdresyDlaDanegoUzytkownika;
    string linia="";
    string buforNaWyrazy="";
    int nrLinii=1;
    int licznikKresek=0;
    int sprawdzIdUzytkownika=0;

    fstream plik;
    plik.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    if(plik.good()==true) {

        cout<<"plik adresowy otwarto poprawnie do odczytu"<<endl;
        Sleep (800);
        while(getline(plik,linia)) {
            for (int counter=0; counter<linia.length(); counter++) {
                if (linia[counter] != '|') {
                    buforNaWyrazy+=linia[counter];
                } else {
                    licznikKresek++;
                    if (licznikKresek==1) {
                        buforZadresami.ustawIdAdresata(stoi(buforNaWyrazy));
                        buforNaWyrazy="";
                    } else if (licznikKresek==2) {
                        sprawdzIdUzytkownika=stoi(buforNaWyrazy);
                        if (sprawdzIdUzytkownika==idZalogowanegoUzytkownika) {
                            buforZadresami.ustawIdUzytkownikaMajacegoDostep(sprawdzIdUzytkownika);
                            buforNaWyrazy="";
                        } else {
                            buforNaWyrazy="";
                        }
                    } else if (licznikKresek==3) {
                        if (sprawdzIdUzytkownika==idZalogowanegoUzytkownika) {
                            buforZadresami.ustawImie(buforNaWyrazy);
                            buforNaWyrazy="";
                        } else {
                            buforNaWyrazy="";
                        }

                    } else if (licznikKresek==4) {
                        if (sprawdzIdUzytkownika==idZalogowanegoUzytkownika) {
                            buforZadresami.ustawNazwisko(buforNaWyrazy);
                            buforNaWyrazy="";
                        } else {
                            buforNaWyrazy="";
                        }
                    } else if (licznikKresek==5) {
                        if (sprawdzIdUzytkownika==idZalogowanegoUzytkownika) {
                            buforZadresami.ustawAdres(buforNaWyrazy);
                            buforNaWyrazy="";
                        } else {
                            buforNaWyrazy="";
                        }
                    } else if (licznikKresek==6) {
                        if (sprawdzIdUzytkownika==idZalogowanegoUzytkownika) {
                            buforZadresami.ustawEmail(buforNaWyrazy);
                            buforNaWyrazy="";
                        } else {
                            buforNaWyrazy="";
                        }
                    } else if (licznikKresek==7) {
                        if (sprawdzIdUzytkownika==idZalogowanegoUzytkownika) {
                            buforZadresami.ustawNumerTelefonu(buforNaWyrazy);
                            buforNaWyrazy="";
                            wczytaneAdresyDlaDanegoUzytkownika.push_back(buforZadresami);
                            licznikKresek=0;
                        } else {
                            buforNaWyrazy="";
                            licznikKresek=0;
                        }
                    }
                }
            }
        }
    }
    plik.close();
    return wczytaneAdresyDlaDanegoUzytkownika;
}

int PlikZadresatami::wczytanieIlosciAdresatowWpliku () {

    int IdOstatniegoZapisanegoAdresata=0;
    string buforNaWyrazy="";
    string linia="";
    int licznikKresek=0;

    fstream plik;
    plik.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    if(plik.good()==true) {
        while(getline(plik,linia)) {
            for (int counter=0; counter<linia.length(); counter++) {
                if (linia[counter] != '|') {
                    buforNaWyrazy+=linia[counter];
                } else {
                    licznikKresek++;
                    if (licznikKresek==1) {
                        IdOstatniegoZapisanegoAdresata=stoi(buforNaWyrazy);
                        buforNaWyrazy="";
                    } else if (licznikKresek==7) {
                        buforNaWyrazy="";
                        licznikKresek=0;
                    } else {
                        buforNaWyrazy="";
                    }
                }
            }
        }
    }
    return IdOstatniegoZapisanegoAdresata;
}


void PlikZadresatami::zapiszDanePoUsunieciuWplikuTymczasowym (int idUsuwanegoAdresata) {
    string calaLinia;
    string IdAdresataTymczasowe;
    int IdAdresata;
    fstream plikZadresami;

    plikZadresami.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    if(plikZadresami.good()==true) {
        while(getline(plikZadresami,calaLinia)) {
            int i=0;
            while (calaLinia[i]!='|') {
                IdAdresataTymczasowe+=calaLinia[i];
                i++;
            }
            IdAdresata=stoi(IdAdresataTymczasowe);
            if (IdAdresata!=idUsuwanegoAdresata) {
                fstream plikTymczasowy;
                plikTymczasowy.open("plikTymczasowy.txt", ios::out | ios::app);
                plikTymczasowy<<calaLinia<<endl;
                plikTymczasowy.close();
            }
            IdAdresata=0;
            IdAdresataTymczasowe="";
        }
    }
    plikZadresami.close();
}

void PlikZadresatami::zamienPlikTymczasowyWdocelowy () {
    remove(NAZWA_PLIKU_Z_ADRESATAMI.c_str());
    rename ("plikTymczasowy.txt", NAZWA_PLIKU_Z_ADRESATAMI.c_str());
}


void PlikZadresatami::zapiszDanePoEdycjiWplikuTymczasowym (int idZmienianegoAdresata, vector <Adresat> listaAdresatowDanegoUzytkownika) {

    string calaLinia="";
    string idAdresataTymczasowe="";
    int idAdresata;

    fstream plikZadresami;
    plikZadresami.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    fstream plikTymczasowy;
    plikTymczasowy.open("plikTymczasowy.txt", ios::out | ios::app);
    if(plikZadresami.good()==true) {
        while(getline(plikZadresami,calaLinia)) {
            int i=0;
            while (calaLinia[i]!='|') {
                idAdresataTymczasowe+=calaLinia[i];
                i++;
            }
            idAdresata=stoi(idAdresataTymczasowe);
            idAdresataTymczasowe="";


            if (idAdresata!=idZmienianegoAdresata) {
                plikTymczasowy<<calaLinia<<endl;
            } else {
                cout << idZmienianegoAdresata << endl;
                system("pause");
                cout<< listaAdresatowDanegoUzytkownika.size() << endl;
                system("pause");
                for (int j=0; j<listaAdresatowDanegoUzytkownika.size(); j++) {
                   if (listaAdresatowDanegoUzytkownika[j].pobierzIdAdresata()==idZmienianegoAdresata) {
                        plikTymczasowy<<idZmienianegoAdresata<<"|"<<listaAdresatowDanegoUzytkownika[j].pobierzIdUzytkownikaMajacegoDostep()<<"|"<<listaAdresatowDanegoUzytkownika[j].pobierzImie()<<"|"<<listaAdresatowDanegoUzytkownika[j].pobierzNazwisko()<<"|"<<listaAdresatowDanegoUzytkownika[j].pobierzAdres()<<"|"<<listaAdresatowDanegoUzytkownika[j].pobierzEmail()<<"|"<<listaAdresatowDanegoUzytkownika[j].pobierzNumerTelefonu()<<"|"<<endl;
                        break;
                    }
                }
            }
        }
        plikZadresami.close();
        plikTymczasowy.close();
    }
}
