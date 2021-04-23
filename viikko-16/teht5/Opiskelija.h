#pragma once
#include <string>
#include <vector>
#include "Henkilo.h"
using namespace std;

class Opiskelija : public Henkilo
{
public:
    Opiskelija(); // parametriton oletusrakentaja
    Opiskelija(const string& aNimi, const int& aIka, const Osoite& aOsoite, const string& aOpNro, const int& aOpintopisteet); // 4 parametrinen oletusrakentaja
    Opiskelija(const Opiskelija& aOpiskelija); // kopiorakentaja
    ~Opiskelija(); // purkaja
    
    void setOpNro(const string& aOpNro);
    string getOpNro() const;
    
    void setSuoritetutKurssit(const vector <string>& aSuoritetutKurssit);
    vector <string> getSuoritetutKurssit() const; 
    void lisaaKurssi(string aKurssi);
    
    void tulostaTiedot() const;
    
    void setOpintopisteet(const int& aOpintopisteet);
    int getOpintopisteet() const;
    void lisaaOpintopisteita(const int& aOpintopisteet);

private:
    string opNro;
    vector <string> suoritetutKurssit;
    int opintopisteet;
};