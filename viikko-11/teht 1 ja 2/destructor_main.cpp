#include <iostream>
#include "Henkilo.h"
#include "Paivays.h"
#include <string>
using namespace std;


void Villefunktion(){
    cout << "Inside funktion" << endl;
    Henkilo ville("Ville", 19);
    cout << "End of funktion" << endl;
} // Ville kuolee

int main(){

    Henkilo pekka("Pekka", 20);
    
    cout << "Entering if-block" << endl;
    if (true)
    {
        cout << "Inside if-block" << endl;
        Henkilo kalle("Kalle", 23);
        cout << "End of if-block" << endl;
    } // Kalle kuolee
    
    cout << "Outside of if-block" << endl;

    cout << "Entering for-loop" << endl;
    for (size_t i = 0; i < 3; i++)
    {
        cout << "Inside for-loop" << endl;
        Henkilo mikko("Mikko", 25);
        cout << "End of for-loop" << endl;
    } // Mikko kuolee

    cout << "Outside of for-loop" << endl;
   
    cout << "Entering VilleFunction" << endl;
    Villefunktion();
    cout << "Outside of VilleFunction" << endl;

    Henkilo* lassi = new Henkilo("Lassi",30);
    cout << "Created pointer to Lassi-henkilö" << endl;
    cout << "Going to delete pointer to Lassi" << endl;
    delete lassi; // Lassi kuolee
    cout << "Pointer to Lassi deleted" << endl;

    cout << "End of main()" << endl;
    return 0; // Pekka kuolee
}