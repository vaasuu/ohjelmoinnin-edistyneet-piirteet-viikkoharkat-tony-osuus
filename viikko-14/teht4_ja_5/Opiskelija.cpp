#include <iostream>
#include "Opiskelija.h"
#include "Henkilo.h"
#include "Osoite.h"
#include <string>
#include <vector>
using namespace std;

Opiskelija::Opiskelija() // parametriton rakentaja 
{
    cout << "Opiskelija parametriton rakentaja" << endl;
} 

Opiskelija::Opiskelija(const string& aNimi, const int& aIka, const Osoite& aOsoite, const string& aOpNro, const int& aOpintopisteet) // 5 parametrinen oletusrakentaja
: Henkilo(aNimi, aIka, aOsoite), opNro(aOpNro), opintopisteet(aOpintopisteet) 
{
    cout << "Opiskelija 5 parametrinen oletusrakentaja" << endl;
} 

Opiskelija::Opiskelija(const Opiskelija& aOpiskelija) // kopiorakentaja
    : Henkilo(aOpiskelija.getNimi(), aOpiskelija.getIka(), Osoite(aOpiskelija.getOsoite())), opNro(aOpiskelija.opNro), suoritetutKurssit(aOpiskelija.suoritetutKurssit), opintopisteet(aOpiskelija.opintopisteet)
{
    cout << "Opiskelija kopiorakentaja" << endl;
}

Opiskelija::~Opiskelija() { // purkaja
    cout << "Opiskelija purkaja" << endl;
} 

void Opiskelija::setOpNro(const string& aOpNro) {
    opNro = aOpNro;
}
string Opiskelija::getOpNro() const {
    return opNro;
}

void Opiskelija::setSuoritetutKurssit(const vector <string>& aSuoritetutKurssit) {
    suoritetutKurssit = aSuoritetutKurssit;
}

vector <string> Opiskelija::getSuoritetutKurssit() const {
    return suoritetutKurssit;
} 

void Opiskelija::lisaaKurssi(string aKurssi) {
    suoritetutKurssit.push_back(aKurssi);
}

void Opiskelija::tulostaTiedot() {
    tulostaHenkilonTiedot();
    cout << "Opiskelijanumero: " << opNro << endl;
    cout << "Opintopisteet: " << opintopisteet << endl;
    cout << "Suoritetut kurssit: " << endl;
    for (string kurssi : suoritetutKurssit)
    {
        cout << " " << kurssi << endl;
    }
}

void Opiskelija::setOpintopisteet(const int& aOpintopisteet) {
    opintopisteet = aOpintopisteet;
}

int Opiskelija::getOpintopisteet() const {
    return opintopisteet;
}

void Opiskelija::lisaaOpintopisteita(const int& aOpintopisteet) {
    opintopisteet += aOpintopisteet;
}