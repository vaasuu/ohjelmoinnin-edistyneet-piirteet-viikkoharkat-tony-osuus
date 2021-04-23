#include <iostream>
#include "Opettaja.h"
#include "Henkilo.h"
#include "Osoite.h"
#include <string>
#include <vector>
using namespace std;

Opettaja::Opettaja() // parametriton rakentaja 
{
    cout << "Opettaja parametriton rakentaja" << endl;
} 

Opettaja::Opettaja(const string& aNimi, const int& aIka, const Osoite& aOsoite, const string& aKoulutusala) // 4 parametrinen oletusrakentaja
: Henkilo(aNimi, aIka, aOsoite), Koulutusala(aKoulutusala) 
{
    cout << "Opettaja 4 parametrinen oletusrakentaja" << endl;
} 

Opettaja::Opettaja(const Opettaja& aOpettaja) // kopiorakentaja
    : Henkilo(aOpettaja.getNimi(), aOpettaja.getIka(), Osoite(aOpettaja.getOsoite())), Koulutusala(aOpettaja.Koulutusala), Vastuukurssit(aOpettaja.Vastuukurssit)
{
    cout << "Opettaja kopiorakentaja" << endl;
}

Opettaja::~Opettaja() { // purkaja
    cout << "Opettaja purkaja" << endl;
} 

void Opettaja::setKoulutusala(const string& aKoulutusala) {
    Koulutusala = aKoulutusala;
}
string Opettaja::getKoulutusala() const {
    return Koulutusala;
}

void Opettaja::setVastuukurssit(const vector <string>& aVastuukurssit) {
    Vastuukurssit = aVastuukurssit;
}

vector <string> Opettaja::getVastuukurssit() const {
    return Vastuukurssit;
} 

void Opettaja::lisaaKurssi(string aKurssi) {
    Vastuukurssit.push_back(aKurssi);
}

void Opettaja::poistaKurssi(string aKurssi) {
    bool deleted = false;
    for (size_t i = 0; i < Vastuukurssit.size(); i++)
    {
        if (Vastuukurssit[i] == aKurssi)
        {
            Vastuukurssit.erase(Vastuukurssit.begin()+i);
            cout << aKurssi << " on nyt poistettu!" << endl;
            deleted = true;
        }
        
    }
    if (!deleted)
    {
        cout << "Ei löydy kurssia nimeltä \"" << aKurssi << "\"" << endl;
    }
}

void Opettaja::tulostaTiedot() const {
    Henkilo::tulostaTiedot();
    cout << "Koulutusala: " << Koulutusala << endl;
    cout << "Vastuukurssit: " << endl;
    for (string kurssi : Vastuukurssit)
    {
        cout << " " << kurssi << endl;
    }
}