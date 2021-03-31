#include <iostream>
#include "Kalenterimerkinta.h"
using namespace std;

Kalenterimerkinta::Kalenterimerkinta() : mPaivays(1,1,1970), mAsia("N/A"), mMuistutus(false)
{
    cout << "Kalenterimerkintä-luokan parametriton rakentaja" << endl;
};

Kalenterimerkinta::Kalenterimerkinta(Paivays aPaivays, string aAsia, bool aMuistutus) 
    : mPaivays(aPaivays), mAsia(aAsia), mMuistutus(aMuistutus)
{
    cout << "Kalenterimerkintä-luokan parametrillinen rakentaja" << endl;
}

Kalenterimerkinta::Kalenterimerkinta(const Kalenterimerkinta& aKalenterimerkinta)
    : mAsia(aKalenterimerkinta.mAsia), mMuistutus(aKalenterimerkinta.mMuistutus)
{
    cout << "Kalenterimerkinta-luokan Kopiorakentaja kysyy päivää" << endl;
    mPaivays.kysyPaivamaara();
    cout << "Kalenterimerkinta-luokan Kopiorakentaja" << endl;
}

Kalenterimerkinta::~Kalenterimerkinta() {
    cout << "Kalenterimerkintä Purkaja" << endl;
};

Paivays Kalenterimerkinta::getPaivays() {
    return mPaivays;
};

string Kalenterimerkinta::getAsia() {
    return mAsia;
};

bool Kalenterimerkinta::getMuistutus() {
    return mMuistutus;
};

void Kalenterimerkinta::setPaivays(Paivays aPaivays) {
    mPaivays = aPaivays;
};

void Kalenterimerkinta::setAsia(string aAsia) {
    mAsia = aAsia;
};

void Kalenterimerkinta::setMuistutus(bool aMuistutus) {
    mMuistutus = aMuistutus;
};

void Kalenterimerkinta::tulostaMerkinta() {
    cout << "\n\nKalenterimerkintä:" << endl;
    cout << "Muistutus [";
    
    if(mMuistutus)
    {
        cout << "X";
    }
    else
    {
        cout << " ";
    }
    
    cout << "]" << endl;
    mPaivays.tulostaPaivays();
    cout << mAsia << "\n" << endl;
};

void Kalenterimerkinta::kysyTiedot() {
    string asia;
    char muistutusStatus;

    mPaivays.kysyPaivamaara();
    cout << "Mitä asiaa muistutus koskee: ";
    cin.clear();
    cin.ignore();
    getline(cin, asia);
    setAsia(asia);
    cout << "Laitetaanko muistutus päälle? (Y/N): ";
    muistutusStatus = getchar();
    if (muistutusStatus == 'Y')
    {
        setMuistutus(true);
    }
    else
    {
        setMuistutus(false);
    }
};