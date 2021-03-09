#include "Henkilo.h"
#include <string>

// Henkilö -luokan määrittely eli toteutus (implementation)
// Täällä toteutetaan luokan toiminnot eli metodit

void Henkilo::setNimi(string aNimi){
    // asetetaan henkilölle uusi nimi
    nimi = aNimi; 
}

void Henkilo::setIka(int aIka){
    ika = aIka;
}

string Henkilo::getNimi(){
    return nimi;
}

int Henkilo::getIka(){
    return ika;
}

void Henkilo::tulostaHenkilonTiedot(){
    cout << "Henkilön tiedot" << endl;
    cout << "Nimi: " << nimi << endl;
    cout << "Ika: " << ika << endl;
}
