#pragma once
#include <iostream>
#include <string>
using namespace std;

// Henkilö-luokan esittely (kirjoitetaan omaan .h tiedostoon)
// Esittely == declaration, API
class Paivays {
    // Luokan julkinen rajapinta (API), toiminnot, metodit
    public:

        // Rakentajat == metodi, joka alustaa olion (tietojäsenet)
        // Rakentaja on metodi, jolla on luokan nimi ilman paluuarvoa
        // Jos enme kirjoita yhtään rakentajaa, kääntäjä tuottaa ns. oletusrakentajan,
        // Joka on parametriton rakentaja.

        Paivays();
        Paivays(int aPaiva, int aKuukausi, int aVuosi);
 


        void setPaiva(int aPaiva);
        void setKuukausi(int aKuukausi);
        void setVuosi(int aVuosi);
        int getPaiva();
        int getKuukausi();
        int getVuosi();
        void tulostaPaivays();
        
        // teht3 lisäys
        void kysyPaivamaara();
        void lisaaPaiva();

    // Luokan tietojäsenet (yleensä private)
    // Näihin päästään käsiksi vain luokan metodeissa
    private:
        int mPaiva;
        int mKuukausi;
        int mVuosi;
};