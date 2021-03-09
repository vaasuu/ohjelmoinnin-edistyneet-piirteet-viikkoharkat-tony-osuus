#include "Paivays.h"
#include <string>

// Henkilö -luokan määrittely eli toteutus (implementation)
// Täällä toteutetaan luokan toiminnot eli metodit

void Paivays::setPaiva(int apaiva){
    paiva = apaiva;
}

void Paivays::setKuukausi(int akuukausi){
    kuukausi = akuukausi;
}

void Paivays::setVuosi(int avuosi){
    vuosi = avuosi;
}

void Paivays::tulostaPaivays(){
    cout << paiva << '.' << kuukausi << '.' << vuosi << endl;
}