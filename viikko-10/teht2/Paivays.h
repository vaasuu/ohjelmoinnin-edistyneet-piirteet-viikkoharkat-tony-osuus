#pragma once
#include <iostream>
#include <string>
using namespace std;

// Henkilö-luokan esittely (kirjoitetaan omaan .h tiedostoon)
// Esittely == declaration, API
class Paivays {
    // Luokan julkinen rajapinta (API), toiminnot, metodit
    public:
        void setPaiva(int);
        void setKuukausi(int);
        void setVuosi(int);
        int getPaiva();
        int getKuukausi();
        int getVuosi();
        void tulostaPaivays();

    // Luokan tietojäsenet (yleensä private)
    // Näihin päästään käsiksi vain luokan metodeissa
    private:
        int paiva;
        int kuukausi;
        int vuosi;
};