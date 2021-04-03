#include <iostream>
#include <string>
#include <vector>
#include "Henkilo.h"
using namespace std;

int main(){
    vector <Henkilo> henkilot_oliot;
    
    cout << "CREATING HENKILÖ OLIOT" << endl;
    henkilot_oliot.push_back(Henkilo("tyyppi1", 1));
    henkilot_oliot.push_back(Henkilo("tyyppi2", 2));
    henkilot_oliot.push_back(Henkilo("tyyppi3", 3));
    henkilot_oliot.push_back(Henkilo("tyyppi4", 4));
    henkilot_oliot.push_back(Henkilo("tyyppi5", 5));
    cout << "CREATED HENKILÖ OLIOT" << endl;

    vector <Henkilo*> henkilot_pointers_2_oliot;
    cout << "CREATING POINTERS TO HENKILÖ OLIOT" << endl;
    henkilot_pointers_2_oliot.push_back(new Henkilo("tyyppi1", 1));
    henkilot_pointers_2_oliot.push_back(new Henkilo("tyyppi2", 2));
    henkilot_pointers_2_oliot.push_back(new Henkilo("tyyppi3", 3));
    henkilot_pointers_2_oliot.push_back(new Henkilo("tyyppi4", 4));
    henkilot_pointers_2_oliot.push_back(new Henkilo("tyyppi5", 5));
    cout << "CREATED POINTERS TO HENKILÖ OLIOT" << endl;
    return 0;
}

/* 

valtteri@Hackintosh:teht4$ ./main.out 
CREATING HENKILÖ OLIOT
Osoite -luokan oletusrakentaja (parametriton rakentaja)
Henkilö tyyppi1 luotu. (2 parametrinen rakentaja)
Henkilo –luokan kopiorakentaja
Henkilö -luokan purkaja
Osoite -luokan purkaja
Osoite -luokan oletusrakentaja (parametriton rakentaja)
Henkilö tyyppi2 luotu. (2 parametrinen rakentaja)
Henkilo –luokan kopiorakentaja
Henkilo –luokan kopiorakentaja
Henkilö -luokan purkaja
Osoite -luokan purkaja
Henkilö -luokan purkaja
Osoite -luokan purkaja
Osoite -luokan oletusrakentaja (parametriton rakentaja)
Henkilö tyyppi3 luotu. (2 parametrinen rakentaja)
Henkilo –luokan kopiorakentaja
Henkilo –luokan kopiorakentaja
Henkilo –luokan kopiorakentaja
Henkilö -luokan purkaja
Osoite -luokan purkaja
Henkilö -luokan purkaja
Osoite -luokan purkaja
Henkilö -luokan purkaja
Osoite -luokan purkaja
Osoite -luokan oletusrakentaja (parametriton rakentaja)
Henkilö tyyppi4 luotu. (2 parametrinen rakentaja)
Henkilo –luokan kopiorakentaja
Henkilö -luokan purkaja
Osoite -luokan purkaja
Osoite -luokan oletusrakentaja (parametriton rakentaja)
Henkilö tyyppi5 luotu. (2 parametrinen rakentaja)
Henkilo –luokan kopiorakentaja
Henkilo –luokan kopiorakentaja
Henkilo –luokan kopiorakentaja
Henkilo –luokan kopiorakentaja
Henkilo –luokan kopiorakentaja
Henkilö -luokan purkaja
Osoite -luokan purkaja
Henkilö -luokan purkaja
Osoite -luokan purkaja
Henkilö -luokan purkaja
Osoite -luokan purkaja
Henkilö -luokan purkaja
Osoite -luokan purkaja
Henkilö -luokan purkaja
Osoite -luokan purkaja
CREATED HENKILÖ OLIOT
CREATING POINTERS TO HENKILÖ OLIOT
Osoite -luokan oletusrakentaja (parametriton rakentaja)
Henkilö tyyppi1 luotu. (2 parametrinen rakentaja)
Osoite -luokan oletusrakentaja (parametriton rakentaja)
Henkilö tyyppi2 luotu. (2 parametrinen rakentaja)
Osoite -luokan oletusrakentaja (parametriton rakentaja)
Henkilö tyyppi3 luotu. (2 parametrinen rakentaja)
Osoite -luokan oletusrakentaja (parametriton rakentaja)
Henkilö tyyppi4 luotu. (2 parametrinen rakentaja)
Osoite -luokan oletusrakentaja (parametriton rakentaja)
Henkilö tyyppi5 luotu. (2 parametrinen rakentaja)
CREATED POINTERS TO HENKILÖ OLIOT
Henkilö -luokan purkaja
Osoite -luokan purkaja
Henkilö -luokan purkaja
Osoite -luokan purkaja
Henkilö -luokan purkaja
Osoite -luokan purkaja
Henkilö -luokan purkaja
Osoite -luokan purkaja
Henkilö -luokan purkaja
Osoite -luokan purkaja
valtteri@Hackintosh:teht4$ 

-------------------------------------------------------

Olioiden kopioinnilla vektoriin:
Henkilöluokan rakentajaa kutsuttiin 5 kertaa ja kopiorakentajaa kutsuttiin 12 kertaa

VS

Osoittimien kopiointi vektoriin:
Henkilöluokan rakentajaa kutsuttiin 5 kertaa

Koska osoittimien kanssa tarvitsee tehdä vähemmän muistin kopioimista, 
se on tehokkaampaa ja nopeampaa.
*/