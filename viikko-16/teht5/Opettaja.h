#pragma once
#include <string>
#include <vector>
#include "Henkilo.h"
using namespace std;

class Opettaja : public Henkilo
{
public:
    Opettaja(); // parametriton oletusrakentaja
    Opettaja(const string& aNimi, const int& aIka, const Osoite& aOsoite, const string& aKoulutusala); // 4 parametrinen oletusrakentaja
    Opettaja(const Opettaja& aOpettaja); // kopiorakentaja
    ~Opettaja(); // purkaja
    
    void setKoulutusala(const string& aKoulutusala);
    string getKoulutusala() const;
    
    void setVastuukurssit(const vector <string>& aVastuukurssit);
    vector <string> getVastuukurssit() const; 
    void lisaaKurssi(string aKurssi);
    void poistaKurssi(string aKurssi);
    void tulostaTiedot() const;

private:
    string Koulutusala;
    vector <string> Vastuukurssit;
};