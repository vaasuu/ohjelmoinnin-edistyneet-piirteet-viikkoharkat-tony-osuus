#include <iostream>
#include "Paivays.h"
#include <string>
using namespace std;

int main(){
    Paivays tanaan, huomenna, joskus;
    tanaan.setPaiva(9);
    tanaan.setKuukausi(3);
    tanaan.setVuosi(2021);
    tanaan.tulostaPaivays();
    
    huomenna.setPaiva(10);
    huomenna.setKuukausi(3);
    huomenna.setVuosi(2021);
    huomenna.tulostaPaivays();

    cout << "teht3 lisäys" << endl;

    joskus.kysyPaivamaara();
    joskus.tulostaPaivays();

    cout << "Lisätään asken kysyttyyn päivämäärään 1 päivä lisää." << endl;

    joskus.lisaaPaiva();
    
    cout << "Uusi päivämäärä:" << endl; 
    joskus.tulostaPaivays();

    return 0;
}