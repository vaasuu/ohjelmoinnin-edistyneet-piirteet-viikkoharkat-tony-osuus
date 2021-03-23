#include <iostream>
#include <string>
#include "Henkilo.h"
using namespace std;

int main(){
    Osoite kallenOsoite("Jokukatu", "12345", "JokuKunta");
    kallenOsoite.tulostaTiedot();

    Henkilo kalle("Kalle", 30, kallenOsoite);
    kalle.tulostaHenkilonTiedot();

    Henkilo ville("Ville", 20, Osoite("Nokiakatu 1", "54321", "Nokia"));
    ville.tulostaHenkilonTiedot();
    
    return 0;
}