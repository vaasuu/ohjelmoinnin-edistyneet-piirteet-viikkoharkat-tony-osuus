#include <iostream>
#include "Opiskelija.h"
#include "Opettaja.h"
#include <string>
using namespace std;

int main() {

    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
    
    Henkilo a;
    Opettaja b;
    Opiskelija c;

    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;

    Henkilo d("Dee", 23);
    Opettaja e("Eee", 40, Osoite("Katu", "67123", "Tampere"), "Tietotekniikka");
    Opiskelija f("Äff", 24, Osoite("Kuja", "4321", "Tampere"), "1234", 53);

    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;

    Henkilo g(d);
    Opettaja h(e);
    Opiskelija i(f); 
    
    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;

    return 0;
}