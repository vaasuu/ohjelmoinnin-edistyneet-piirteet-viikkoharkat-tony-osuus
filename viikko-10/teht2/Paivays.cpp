#include "Paivays.h"
#include <string>

// Henkilö -luokan määrittely eli toteutus (implementation)
// Täällä toteutetaan luokan toiminnot eli metodit

void Paivays::setPaiva(int apaiva){
    paiva = apaiva;
}

void Paivays::setKuukausi(int akuukausi){
    kuukausi = akuukausi;
}

void Paivays::setVuosi(int avuosi){
    vuosi = avuosi;
}

int Paivays::getPaiva(){
    return paiva;
}
int Paivays::getKuukausi(){
    return kuukausi;
}

int Paivays::getVuosi(){
    return vuosi;
}

void Paivays::tulostaPaivays(){
    cout << paiva << '.' << kuukausi << '.' << vuosi << endl;
}

void Paivays::kysyPaivamaara(){
    int apaiva, akuukausi, avuosi;
    
    cout << "päivä: ";
    cin >> apaiva;
    setPaiva(apaiva);

    cout << "kuukausi: ";
    cin >> akuukausi;
    setKuukausi(akuukausi);
    
    cout << "vuosi: ";
    cin >> avuosi;
    setVuosi(avuosi);
}

// ei oteta karkausvuotta huomioon
void Paivays::lisaaPaiva(){
    int kuukaudenkesto;

    if (kuukausi == 2)
    {
        kuukaudenkesto = 28; // helmikuu 28 päivää, ei oteta karkausvuotta huomioon
    }
    else if (kuukausi % 2 == 0) // parillenen kuukausi, helmi, huhti, jne on 30 päivää
    {
        kuukaudenkesto = 30;
    }
    else  // pariton kuukausi, tammi, maalis, jne on 31 päivää
    {
        kuukaudenkesto = 31;
    }
    
    if (kuukausi >= 8)
    {
        if (kuukausi % 2 == 0) // parillenen kuukausi, helmi, huhti, jne on 30 päivää
        {
            kuukaudenkesto = 31;
        }
        else  // pariton kuukausi, tammi, maalis, jne on 31 päivää
        {
            kuukaudenkesto = 30;
        }
    }

    paiva++;
    if (paiva > kuukaudenkesto)
    {
        paiva = 1;
        kuukausi++;
    }
    if (kuukausi>12)
    {
        kuukausi = 1;
        vuosi++;
    }
}