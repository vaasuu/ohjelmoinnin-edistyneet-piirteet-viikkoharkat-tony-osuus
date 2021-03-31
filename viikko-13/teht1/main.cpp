#include <iostream>
#include "Paivays.h"
#include "Kalenterimerkinta.h"
using namespace std;

int main(){
    Kalenterimerkinta muista;
    muista.kysyTiedot();
    muista.tulostaMerkinta();

    Paivays huominenPaiva(24,3,2021);
    Kalenterimerkinta huomenna(huominenPaiva, "Käy kaupassa", true);
    huomenna.tulostaMerkinta();

    return 0;
}