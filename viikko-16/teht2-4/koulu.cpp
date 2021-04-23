#include <iostream>
#include "Opiskelija.h"
#include "Henkilo.h"
#include "Osoite.h"
#include "koulu.h"
#include <string>
#include <vector>
using namespace std;

koulu::koulu() {
    cout << "koulu parametriton rakentaja" << endl;
}

koulu::koulu(string aKoulunNimi) : koulunNimi(aKoulunNimi) {
    cout << "koulu 1 parametrinen rakentaja" << endl;
}

koulu::~koulu() {
    cout << "koulu purkaja" << endl;
}



void koulu::lisaaOpiskelija(Opiskelija& aOpiskelija) {
    opiskelijat_ptr.push_back(new Opiskelija(aOpiskelija));    
}

void koulu::lisaaOpettaja(Opettaja& aOpettaja) {
    opettajat_ptr.push_back(new Opettaja(aOpettaja));
}

void koulu::tulostaKaikkiTiedot() const {
    cout << "Koulun nimi: " << koulunNimi << endl;
    cout << "Opettajien lukumäärä: " << opettajat_ptr.size() << endl; 
    cout << "Opettajat:" << endl;
    tulostaOpettajat();
    cout << "Opiskelijoiden lukumäärä: " << opiskelijat_ptr.size() << endl;
    cout << "Opiskelijat:" << endl;
    tulostaOpiskelijat();
}

void koulu::tulostaOpettajat() const {
    for (auto &&i : opettajat_ptr)
    {
        cout << "\n" << endl;
        i->tulostaTiedot();
        cout << "\n" << endl;
    }
}

void koulu::tulostaOpiskelijat() const {

    for (auto &&i : opiskelijat_ptr)
    {
        cout << "\n" << endl;
        i->tulostaTiedot();
        cout << "\n" << endl;
    }
}

void koulu::setKoulunNimi(string& aKoulunNimi) {
    koulunNimi = aKoulunNimi;
}

string koulu::getKoulunNimi() {
    return koulunNimi;
}

void koulu::lisaaOpettajalleKurssi(string& aOpe, string& aKurssinNimi) {

    bool found_ope = false;

    for (auto &&ope : opettajat_ptr)
    {
        if (ope->getNimi() == aOpe)
        {
            ope->lisaaKurssi(aKurssinNimi);
            cout << aKurssinNimi << " on nyt lisätty!" << endl;
            found_ope = true;
        }
        
    }
    if (!found_ope)
    {
        cout << "Ei löydy opettajaa nimeltä \"" << aOpe << "\"" << endl;
    }
}

void koulu::lisaaOpiskelijalleKurssi(string& aOpiskelija, string& aKurssinNimi) {

    bool found_opiskelija = false;

    for (auto &&opiskelija : opiskelijat_ptr)
    {
        if (opiskelija->getNimi() == aOpiskelija)
        {
            opiskelija->lisaaKurssi(aKurssinNimi);
            cout << aKurssinNimi << " on nyt lisätty!" << endl;
            found_opiskelija = true;
        }
        
    }
    if (!found_opiskelija)
    {
        cout << "Ei löydy opiskelijaa nimeltä \"" << aOpiskelija << "\"" << endl;
    }
}