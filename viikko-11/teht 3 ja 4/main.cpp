#include <iostream>
#include "noppa.h"
using namespace std;

int main(){

    noppa heitto;
    cout << "Noppien lukumäärä = " << heitto.getNoppienLkm() << endl;
    heitto.heitaNoppaa();
    heitto.kerroViimeisenHeitonLukeama();

    noppa monta(3);
    
    cout << "Noppien lukumäärä = " << monta.getNoppienLkm() << endl;
    monta.setNoppienLkm(5);
    cout << "Noppien lukumäärä = " << monta.getNoppienLkm() << endl;
    return 0;
}
