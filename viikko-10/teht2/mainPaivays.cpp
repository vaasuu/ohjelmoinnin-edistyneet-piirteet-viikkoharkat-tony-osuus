#include <iostream>
#include "Paivays.h"
#include <string>
using namespace std;

int main(){
    Paivays tanaan, huomenna;
    tanaan.setPaiva(9);
    tanaan.setKuukausi(3);
    tanaan.setVuosi(2021);
    tanaan.tulostaPaivays();
    
    huomenna.setPaiva(10);
    huomenna.setKuukausi(3);
    huomenna.setVuosi(2021);
    huomenna.tulostaPaivays();

    return 0;
}