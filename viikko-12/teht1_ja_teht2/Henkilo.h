#pragma once
#include <iostream>
#include <string>
using namespace std;

// Henkilö-luokan esittely (kirjoitetaan omaan .h tiedostoon)
// Esittely == declaration, API
class Henkilo {
    // Luokan julkinen rajapinta (API), toiminnot, metodit
    public:

        Henkilo();
        Henkilo(string aNimi, int aIka);
        ~Henkilo();

        void setNimi(string aNimi);
        void setIka(int aIka);
        string getNimi();
        int getIka();
        void tulostaHenkilonTiedot();

    // Luokan tietojäsenet (yleensä private)
    // Näihin päästään käsiksi vain luokan metodeissa
    private:
        string mNimi;
        int mIka;
};