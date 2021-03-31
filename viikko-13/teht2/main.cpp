#include <iostream>
#include "Paivays.h"
#include "Kalenterimerkinta.h"
using namespace std;

void doSomethingArvoparametri(Kalenterimerkinta aKalenterimerkinta){
    cout << "inside doSomethingArvoparametri-function" << endl;
    aKalenterimerkinta.setAsia("Joku asia");
    aKalenterimerkinta.tulostaMerkinta();
}

void doSomethingViittausparametri(Kalenterimerkinta& aKalenterimerkinta){
    cout << "inside doSomethingViittausparametri-function" << endl;
    aKalenterimerkinta.setAsia("Joku asia");
    aKalenterimerkinta.tulostaMerkinta();
}

void doSomethingViittausparametriConst(const Kalenterimerkinta& aKalenterimerkinta){
    cout << "inside doSomethingViittausparametriConst-function" << endl;
    aKalenterimerkinta.getAsia(); // Nyt pystyy kutsumaan vain niitä metodeja jotka ovat const tyyppiä. 
    // Ei voi kutsua esim setter-metodeja koska const tyyppi estää tiedon muuttamisen.
    // Const-sana tulee laittaa parametriviitteen yhteyteen, jos ei ole tarvetta muuttaa alkuperäistä oliota
}

int main(){
    Kalenterimerkinta muista;
    muista.tulostaMerkinta();

    doSomethingArvoparametri(muista); // kopiorakentajaa kutsutaan
    cout << "outside doSomethingArvoparametri" << endl;
    muista.tulostaMerkinta();

    doSomethingViittausparametri(muista); // kopiorakentajaa ei kutsuta
    cout << "outside doSomethingViittausparametri" << endl;
    muista.tulostaMerkinta();

    /*  
        Olioparametrin välitystä arvoparametrina ei tulisi käyttää, koska siinä kopioidaan tietoa "turhaan" 
        ja se on raskaampaa kuin viittausparametrit
     */

    doSomethingViittausparametriConst(muista);

return 0;
}