#include <iostream>
#include "Henkilo.h"
#include "Paivays.h"
#include <string>
using namespace std;

// Määritellään struct henkilötiedoille (nimi ja ikä)
// struct == rakenteinen tietotyyppi (koostuu useammasta muuttujasta)
// luokka (class) == rakenteinen tietotyyppi, jolla toimintoja
// 1. tiedot == jäsenmuuttujat (attributes, member variables)
// 2. toiminnot = metodit (methods, jäsenfunktiot)

// olio == luokasta luotu "muuttuja", esim. Pekka
// oletuksena kaikki luokan tiedot (kapseloitu) eli private
// => niihin ei päästä suoraan koodissa käsiksi

// Henkilö-luokan esittely (kirjoitetaan omaan .h tiedostoon)


int main(){

    Paivays joulu; // kutsutaan oletusrakentajaa (parametriton rakentaja)
    joulu.tulostaPaivays();

    Paivays kesa(15,6,2021);
    kesa.tulostaPaivays();

    Henkilo kaapo;
    kaapo.tulostaHenkilonTiedot();

    Henkilo pekka("Pekka", 20);
    pekka.tulostaHenkilonTiedot();

    Henkilo henkilot[10]; // käyttää parametritonta rakentajaa
    
    return 0;
}