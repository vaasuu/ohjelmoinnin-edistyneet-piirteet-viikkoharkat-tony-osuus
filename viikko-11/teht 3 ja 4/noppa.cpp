#include <iostream>
#include "noppa.h"
#include <time.h>
using namespace std;

noppa::noppa() : mNoppienLkm(1)
{
    heitaNoppaa();
    // cout << "Alustetun nopan lukemaksi tuli " << noppa::getViimeisinLukema() << endl; 
}

noppa::noppa(int aNoppienLkm) : mNoppienLkm(aNoppienLkm)
{
    heitaNoppaa();
    // cout << "Alustetun nopan lukemaksi tuli " << noppa::getViimeisinLukema() << endl; 
}


int noppa::getViimeisinLukema(){
    return mNopanViimeisinLuku;
}

void noppa::heitaNoppaa(){
    srand(time(NULL));
    mNopanViimeisinLuku = rand() % 6 + 1;
}

void noppa::kerroViimeisenHeitonLukeama(){
    cout << "Viimeisin heitto oli " << mNopanViimeisinLuku << endl;
}

int noppa::getNoppienLkm(){
    return mNoppienLkm;
}

void noppa::setNoppienLkm(int aNoppienLkm){
    mNoppienLkm = aNoppienLkm;
}