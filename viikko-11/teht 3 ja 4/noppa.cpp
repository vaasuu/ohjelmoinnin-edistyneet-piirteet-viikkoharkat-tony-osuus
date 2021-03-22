#include <iostream>
#include "noppa.h"
#include <time.h>
using namespace std;

noppa::noppa() : mNoppienLkm(1), mMaxNoppienLkm(5)
{
    int nopat[mMaxNoppienLkm];
    
    srand(time(NULL));
    for (int i = 0; i < mNoppienLkm; i++)
    {
        nopat[i] = rand() % 6 + 1;
    }
    // cout << "Alustetun nopan lukemaksi tuli " << noppa::getViimeisinLukema() << endl; 
}

noppa::noppa(int aNoppienLkm, int aMaxNoppienLkm) : mNoppienLkm(aNoppienLkm), mMaxNoppienLkm(5)
{
    int nopat[mMaxNoppienLkm];
    srand(time(NULL));
    for (int i = 0; i < mNoppienLkm; i++)
    {
        nopat[i] = rand() % 6 + 1;
    }
    // cout << "Alustetun nopan lukemaksi tuli " << noppa::getViimeisinLukema() << endl; 
}


int noppa::getViimeisinLukema(){
    int noppaSumma = 0;
    for (int i = 0; i < mNoppienLkm; i++)
    {
        noppaSumma += nopat[i];
    }
    return noppaSumma;
}

void noppa::heitaNoppaa(){
    srand(time(NULL));
    cout << "noppien lukemat:" << endl;
    for (int i = 0; i < mNoppienLkm; i++)
    {
        nopat[i] = rand() % 6 + 1;
        cout << nopat[i] << " ";
    }
    cout << endl;
    cout << "Noppien summa: " << getViimeisinLukema() << endl;
}

void noppa::kerroViimeisenHeitonLukema(){
    cout << "Viimeisin heitto oli yhteensä " << getViimeisinLukema() << ". Heitetty " << mNoppienLkm << " nopalla." << endl;
}

int noppa::getNoppienLkm(){
    return mNoppienLkm;
}

void noppa::setNoppienLkm(int aNoppienLkm){
    mNoppienLkm = aNoppienLkm;
}