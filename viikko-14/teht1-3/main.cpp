#include <iostream>
#include "Opiskelija.h"
#include "Opettaja.h"
#include <string>
using namespace std;

int main() {
    Opiskelija tyyppi("Kalle", 25, Osoite("Aleksanterinkatu 1", "3345", "Tampere") ,"12345", 3);
    tyyppi.tulostaTiedot();
    tyyppi.lisaaKurssi("Integrointi");
    tyyppi.lisaaOpintopisteita(3);
    cout << "--------------------------" << endl;
    tyyppi.tulostaTiedot();


    cout << "-------------------" << endl;
    Opettaja ope("Tony", 25, Osoite("Aleksanterinkatu 1", "3345", "Tampere"), "Tietotekniikka");
    ope.lisaaKurssi("IoT ja web dev");
    ope.lisaaKurssi("Integrointi");
    ope.tulostaTiedot();
    ope.poistaKurssi("Derivointi");
    ope.poistaKurssi("Integrointi");
    return 0;
}