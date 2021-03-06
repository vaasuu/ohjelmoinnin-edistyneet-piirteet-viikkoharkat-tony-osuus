#pragma once
#include <iostream>
#include <string>
#include "Osoite.h"
using namespace std;

// Henkilö-luokan esittely (kirjoitetaan omaan .h tiedostoon)
// Esittely == declaration, API
class Henkilo {
    // Luokan julkinen rajapinta (API), toiminnot, metodit
    public:
        Henkilo();
        Henkilo(string aNimi, int aIka);
        Henkilo(string aNimi, int aIka, Osoite aOsoite);
        ~Henkilo();

        void setNimi(string aNimi);
        void setIka(int aIka);
        string getNimi() const;
        int getIka() const;
        void setOsoite(Osoite aOsoite);
        Osoite getOsoite() const;
        void tulostaHenkilonTiedot() const;
        void kysyTiedot();

    // Luokan tietojäsenet (yleensä private)
    // Näihin päästään käsiksi vain luokan metodeissa
    private:
        string mNimi;
        int mIka;
        Osoite osoite;
};