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
        Henkilo(const string& aNimi, const int& aIka);
        Henkilo(const string& aNimi, const int& aIka, const Osoite& aOsoite);
        Henkilo(const Henkilo& aHenkilo); // kopiorakentaja
        ~Henkilo();

        void setNimi(string aNimi);
        void setIka(const int& aIka);
        string getNimi() const;
        int getIka() const;
        void setOsoite(const Osoite& aOsoite);
        Osoite getOsoite() const;
        void tulostaTiedot() const;
        void kysyTiedot();

    // Luokan tietojäsenet (yleensä private)
    // Näihin päästään käsiksi vain luokan metodeissa
    private:
        string mNimi;
        int mIka;
        Osoite osoite;
};