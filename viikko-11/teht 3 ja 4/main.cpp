#include <iostream>
#include "noppa.h"
using namespace std;
/* 
Tässä versiossa voi olla niin monta noppaa kuin haluaa, kunhan noppa konstruktorille antaa 1. parametrina noppien määrän ja 
toisena parametrina noppien maximi määrän.
Jos aloittaa kahdella nopalla, niin noppien määrää voi kasvataa default 5 noppaan asti:
    noppa monopoli(2);
    monopoli.setNoppienLkm(5);

maximin voi asettaa suuremmaksi kuin 5, antamalla sen konstruktorin toisessa parametrissa:
    noppa noppapeli(1,7); <- tässä aluksi 1 noppa, mutta noppien määrää voi kasvattaa 7 noppaan.
    noppapeli.heitaNoppaa();

Jos menee yli max, niin saattaa toimia silti tai sitten ei, mutta en tiedä varmasti miksi, ehkä se kirjoittelee muistiin randomisti???
 */

int main(){

    noppa Kimble;
    cout << "Kimblessä on " << Kimble.getNoppienLkm() << " noppa." << endl;
    Kimble.heitaNoppaa();
    Kimble.kerroViimeisenHeitonLukema();



    // Luodaan noppapari
    noppa monopoli(2);
    cout << "Monopolissa on " << monopoli.getNoppienLkm() << " noppaa." << endl;
    // käyttää sisäisesti nyt kahta noppaa, joille arpoo lukemat
    monopoli.heitaNoppaa();

    monopoli.kerroViimeisenHeitonLukema();

    noppa noppapeli(1,5); // <- toinen parametri antaa max käytettävissä olevien noppien rajan
    noppapeli.heitaNoppaa();

    cout << "Lisätään noppien määrää kesken kaiken." << endl;

    noppapeli.setNoppienLkm(4);
    noppapeli.heitaNoppaa();
    noppapeli.kerroViimeisenHeitonLukema();

    noppapeli.setNoppienLkm(5);
    noppapeli.heitaNoppaa();
    noppapeli.kerroViimeisenHeitonLukema();


    noppa liikaaNoppia;
    liikaaNoppia.heitaNoppaa();
    liikaaNoppia.setNoppienLkm(10); // ei määriteltyä toimintaa, array on default 5 pitkä, mutta nyt se toimii vaikka sen yli
    liikaaNoppia.heitaNoppaa();     // ehkä se kirjoittelee niitä random muistipaikkoihin?
    liikaaNoppia.kerroViimeisenHeitonLukema();
    liikaaNoppia.kerroViimeisenHeitonLukema();
    liikaaNoppia.setNoppienLkm(3);
    liikaaNoppia.kerroViimeisenHeitonLukema();
    liikaaNoppia.heitaNoppaa();
    liikaaNoppia.kerroViimeisenHeitonLukema();

    return 0;
}