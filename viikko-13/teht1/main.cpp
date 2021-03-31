#include <iostream>
#include "Paivays.h"
#include "Kalenterimerkinta.h"
using namespace std;

int main(){
    Kalenterimerkinta muista;
    muista.tulostaMerkinta();

    Kalenterimerkinta x(muista);

    x.tulostaMerkinta();

    muista.tulostaMerkinta();
    
    return 0;
}