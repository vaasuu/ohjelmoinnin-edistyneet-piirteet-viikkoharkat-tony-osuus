#include <iostream>
#include "Henkilo.h"
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
    // C++ ohjelma (prosessi) alkaa tästä
    cout << "Hello" << endl;
    // luodaan henkilö pekka == luodaan olio luokasta Henkilö
    Henkilo pekka;
    pekka.setNimi("Pekka");
    pekka.setIka(20);
    
    pekka.tulostaHenkilonTiedot();

    Henkilo kalle;
    kalle.setNimi("Kalle");
    kalle.setIka(21);
    kalle.tulostaHenkilonTiedot();
    
    return 0;
}