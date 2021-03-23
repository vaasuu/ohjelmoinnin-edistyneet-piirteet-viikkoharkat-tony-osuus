#include "Henkilo.h"
#include <string>

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

void Henkilo::tulostaHenkilonTiedot() const {
    cout << "Henkilön tiedot" << endl;
    cout << "Nimi: " << mNimi << endl;
    cout << "Ika: " << mIka << endl;
}
