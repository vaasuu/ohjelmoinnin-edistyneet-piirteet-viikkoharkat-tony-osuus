#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Opiskelija.h"
#include "Opettaja.h"
using namespace std;

class koulu
{
public:
    koulu();
    koulu(string aKoulunNimi);
    ~koulu();
    void lisaaOpiskelija(Opiskelija& aOpiskelija);
    void lisaaOpettaja(Opettaja& aOpettaja);
    void tulostaKaikkiTiedot() const;
    void tulostaOpettajat() const;
    void tulostaOpiskelijat() const;
    void setKoulunNimi(string& aKoulunNimi);
    string getKoulunNimi();
    void lisaaOpettajalleKurssi(string& aOpe, string& aKurssi);
    void lisaaOpiskelijalleKurssi(string& aOpiskelija, string& aKurssi);
private:
    vector <Opettaja*> opettajat_ptr;
    vector <Opiskelija*> opiskelijat_ptr;
    string koulunNimi;
};