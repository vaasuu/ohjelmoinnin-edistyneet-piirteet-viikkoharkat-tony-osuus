#pragma once
#include <string>
#include <vector>
#include "Henkilo.h"
using namespace std;

class Opettaja : public Henkilo
{
public:
    Opettaja(); // parametriton oletusrakentaja
    Opettaja(const string& aNimi, const int& aIka, const Osoite& aOsoite, const string& aOpNro, const int& aOpintopisteet); // 4 parametrinen oletusrakentaja
    Opettaja(const Opettaja& aOpettaja); // kopiorakentaja
    ~Opettaja(); // purkaja
    
    void setOpNro(const string& aOpNro);
    string getOpNro() const;
    
    void setSuoritetutKurssit(const vector <string>& aSuoritetutKurssit);
    vector <string> getSuoritetutKurssit() const; 
    void lisaaKurssi(string aKurssi);
    
    void tulostaTiedot();
    
    void setOpintopisteet(const int& aOpintopisteet);
    int getOpintopisteet() const;
    void lisaaOpintopisteita(const int& aOpintopisteet);

private:
    string opNro;
    vector <string> suoritetutKurssit;
    int opintopisteet;
};