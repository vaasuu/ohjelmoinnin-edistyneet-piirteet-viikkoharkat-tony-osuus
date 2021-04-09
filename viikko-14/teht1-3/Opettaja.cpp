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

Opettaja::Opettaja(const string& aNimi, const int& aIka, const Osoite& aOsoite, const string& aOpNro, const int& aOpintopisteet) // 4 parametrinen oletusrakentaja
: Henkilo(aNimi, aIka, aOsoite), opNro(aOpNro), opintopisteet(aOpintopisteet) 
{
    cout << "Opettaja 4 parametrinen oletusrakentaja" << endl;
} 

Opettaja::Opettaja(const Opettaja& aOpettaja) // kopiorakentaja
    : opNro(aOpettaja.opNro), suoritetutKurssit(aOpettaja.suoritetutKurssit), opintopisteet(aOpettaja.opintopisteet)
{
    cout << "Opettaja kopiorakentaja" << endl;
}

Opettaja::~Opettaja() { // purkaja
    cout << "Opettaja purkaja" << endl;
} 

void Opettaja::setOpNro(const string& aOpNro) {
    opNro = aOpNro;
}
string Opettaja::getOpNro() const {
    return opNro;
}

void Opettaja::setSuoritetutKurssit(const vector <string>& aSuoritetutKurssit) {
    suoritetutKurssit = aSuoritetutKurssit;
}

vector <string> Opettaja::getSuoritetutKurssit() const {
    return suoritetutKurssit;
} 

void Opettaja::lisaaKurssi(string aKurssi) {
    suoritetutKurssit.push_back(aKurssi);
}

void Opettaja::tulostaTiedot() {
    tulostaHenkilonTiedot();
    cout << "Opiskelijanumero: " << opNro << endl;
    cout << "Opintopisteet: " << opintopisteet << endl;
    cout << "Suoritetut kurssit: " << endl;
    for (string kurssi : suoritetutKurssit)
    {
        cout << " " << kurssi << endl;
    }
}

void Opettaja::setOpintopisteet(const int& aOpintopisteet) {
    opintopisteet = aOpintopisteet;
}

int Opettaja::getOpintopisteet() const {
    return opintopisteet;
}

void Opettaja::lisaaOpintopisteita(const int& aOpintopisteet) {
    opintopisteet += aOpintopisteet;
}