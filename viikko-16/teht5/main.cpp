#include <iostream>
#include "Opiskelija.h"
#include "Opettaja.h"
#include <string>
#include <vector>
using namespace std;

int main() {

    // teht 4
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

    // teht 5

    vector <Henkilo*> henkilo_ptr_vektori;

    henkilo_ptr_vektori.push_back(new Henkilo);
    henkilo_ptr_vektori.push_back(new Opettaja);
    henkilo_ptr_vektori.push_back(new Opiskelija);

    // Vektorin kautta voi kutsua vain Henkilö-luokan metodeja, koska ne ovat Henkilö-tyyppisiä.

    for (Henkilo* x : henkilo_ptr_vektori)
    {
        x->tulostaHenkilonTiedot();
    }
    
    return 0;
}