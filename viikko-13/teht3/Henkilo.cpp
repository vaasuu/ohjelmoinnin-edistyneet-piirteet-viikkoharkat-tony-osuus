#include <iostream>
#include "Henkilo.h"
#include <string>
using namespace std;

// Henkilö -luokan määrittely eli toteutus (implementation)
// Täällä toteutetaan luokan toiminnot eli metodit

Henkilo::Henkilo() : mNimi(""), mIka(0) // alustuslista
{
    cout << "Luodaan henkilö (parametriton rekentaja)" << endl;
}

Henkilo::Henkilo(string aNimi, int aIka) : mNimi(aNimi), mIka(aIka)
{
    cout << "Henkilö " << aNimi << " luotu. (2 parametrinen rakentaja)" << endl;
}

Henkilo::Henkilo(string aNimi, int aIka, Osoite aOsoite)
    : mNimi(aNimi), mIka(aIka), osoite(aOsoite)
{
    cout << "Luotu henkilö, jolla nimi, ikä ja osoite" << endl;
}

Henkilo::~Henkilo(){
    cout << "Henkilö -luokan purkaja" << endl;
}

void Henkilo::setNimi(string aNimi){
    // asetetaan henkilölle uusi nimi
    mNimi = aNimi; 
}

void Henkilo::setIka(int aIka){
    mIka = aIka;
}

string Henkilo::getNimi() const {
    return mNimi;
}

int Henkilo::getIka() const {
    return mIka;
}

void Henkilo::setOsoite(Osoite aOsoite) {
    osoite = aOsoite;
};
Osoite Henkilo::getOsoite() const {
    return osoite;
};

void Henkilo::tulostaHenkilonTiedot() const {
    cout << "Henkilön tiedot" << endl;
    cout << "Nimi: " << mNimi << endl;
    cout << "Ika: " << mIka << endl;
    cout << "Osoite:" << endl;
    osoite.tulostaTiedot();
}

void Henkilo::kysyTiedot() {
string name, address;
int age;

cin.clear();
cin.ignore();
cout << "Nimi: ";
getline(cin,name);
mNimi = name;

cin.clear();
cin.ignore();
cout << "Ikä: ";
cin >> age;
mIka = age;

cin.clear();
cin.ignore();
cout << "Katu: ";
getline(cin,address);
osoite.setKatuosoite(address);
cin.clear();
cin.ignore();
}