#include "Paivays.h"
#include <string>

// Henkilö -luokan määrittely eli toteutus (implementation)
// Täällä toteutetaan luokan toiminnot eli metodit

Paivays::Paivays() : mPaiva(1), mKuukausi(1), mVuosi(2000) // alustuslista
{
    cout << "Luodaan päiväys (parametriton rekentaja)" << endl;
}

Paivays::Paivays(int aPaiva, int aKuukausi, int aVuosi)
    : mPaiva(aPaiva), mKuukausi(aKuukausi), mVuosi(aVuosi) 
{
    cout << "Luodaan päiväys (3 parametrinen rakentaja)" << endl;
}

Paivays::~Paivays(){
    cout << "Päiväys -luokan purkaja" << endl;
}

void Paivays::setPaiva(int aPaiva){
    mPaiva = aPaiva;
}

void Paivays::setKuukausi(int aKuukausi){
    mKuukausi = aKuukausi;
}

void Paivays::setVuosi(int aVuosi){
    mVuosi = aVuosi;
}

int Paivays::getPaiva(){
    return mPaiva;
}
int Paivays::getKuukausi(){
    return mKuukausi;
}

int Paivays::getVuosi(){
    return mVuosi;
}

void Paivays::tulostaPaivays(){
    cout << mPaiva << '.' << mKuukausi << '.' << mVuosi << endl;
}

void Paivays::kysyPaivamaara(){
    int aPaiva, aKuukausi, aVuosi;
    
    cout << "päivä: ";
    cin >> aPaiva;
    setPaiva(aPaiva);

    cout << "kuukausi: ";
    cin >> aKuukausi;
    setKuukausi(aKuukausi);
    
    cout << "vuosi: ";
    cin >> aVuosi;
    setVuosi(aVuosi);
}

// ei oteta karkausvuotta huomioon
void Paivays::lisaaPaiva(){
    int kuukaudenkesto;

    if (mKuukausi == 2)
    {
        kuukaudenkesto = 28; // helmikuu 28 päivää, ei oteta karkausvuotta huomioon
    }
    else if ((mKuukausi == 4) or (mKuukausi == 6) or (mKuukausi == 9) or (mKuukausi == 11)) // huhti, kesä, syys, marras 
                                                                                            // jne on 30 päivää
    {
        kuukaudenkesto = 30;
    }
    else  // tammi, maalis, jne on 31 päivää
    {
        kuukaudenkesto = 31;
    }

    mPaiva++;
    if (mPaiva > kuukaudenkesto)
    {
        mPaiva = 1;
        mKuukausi++;
    }
    if (mKuukausi>12)
    {
        mKuukausi = 1;
        mVuosi++;
    }
}