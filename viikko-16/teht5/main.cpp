#include <iostream>
#include "Opiskelija.h"
#include "Opettaja.h"
#include <string>
#include <vector>
using namespace std;

int main() {

    // teht 5

    vector <Henkilo*> henkilot;

    henkilot.push_back(new Henkilo);
    henkilot.push_back(new Opettaja);
    henkilot.push_back(new Opiskelija);

    for (Henkilo* x : henkilot)
    {
        x->tulostaTiedot();
    }
    
    return 0;
}