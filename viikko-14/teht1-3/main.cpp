#include <iostream>
#include "Opiskelija.h"
#include <string>
using namespace std;

int main() {
    Opiskelija tyyppi("Kalle", 25, Osoite("Aleksanterinkatu 1", "3345", "Tampere") ,"12345", 3);
    tyyppi.tulostaTiedot();
    tyyppi.lisaaKurssi("Integrointi");
    tyyppi.lisaaOpintopisteita(3);
    cout << "--------------------------" << endl;
    tyyppi.tulostaTiedot();
    return 0;
}