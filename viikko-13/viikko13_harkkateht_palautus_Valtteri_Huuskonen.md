# Ohjelmoinnin viikkoharjoitukset – 4. viikkoharjoitusten ratkaisut 

#### (Valtteri Huuskonen 2021-03-31)

## Tehtävä 1

### main.cpp

```cpp
#include <iostream>
#include "Paivays.h"
#include "Kalenterimerkinta.h"
using namespace std;

int main(){
    Kalenterimerkinta muista;
    muista.tulostaMerkinta();

    Kalenterimerkinta x(muista);

    x.tulostaMerkinta();

    muista.tulostaMerkinta();
    
    return 0;
}
```

### Kalenterimerkinta.h (muutokset)

```cpp
    Kalenterimerkinta(const Kalenterimerkinta& aKalenterimerkinta); // kopiorakentaja
```

### Kalenterimerkinta.cpp (muutokset)

```cpp
Kalenterimerkinta::Kalenterimerkinta(const Kalenterimerkinta& aKalenterimerkinta)
    : mAsia(aKalenterimerkinta.mAsia), mMuistutus(aKalenterimerkinta.mMuistutus)
{
    cout << "Kalenterimerkinta-luokan Kopiorakentaja kysyy päivää" << endl;
    mPaivays.kysyPaivamaara();
    cout << "Kalenterimerkinta-luokan Kopiorakentaja" << endl;
}
```

## Tehtävä 2 

### main.cpp

```cpp
#include <iostream>
#include "Paivays.h"
#include "Kalenterimerkinta.h"
using namespace std;

void doSomethingArvoparametri(Kalenterimerkinta aKalenterimerkinta){
    cout << "inside doSomethingArvoparametri-function" << endl;
    aKalenterimerkinta.setAsia("Joku asia");
    aKalenterimerkinta.tulostaMerkinta();
}

void doSomethingViittausparametri(Kalenterimerkinta& aKalenterimerkinta){
    cout << "inside doSomethingViittausparametri-function" << endl;
    aKalenterimerkinta.setAsia("Joku asia");
    aKalenterimerkinta.tulostaMerkinta();
}

void doSomethingViittausparametriConst(const Kalenterimerkinta& aKalenterimerkinta){
    cout << "inside doSomethingViittausparametriConst-function" << endl;
    aKalenterimerkinta.getAsia(); // Nyt pystyy kutsumaan vain niitä metodeja jotka ovat const tyyppiä. 
    // Ei voi kutsua esim setter-metodeja koska const tyyppi estää tiedon muuttamisen.
    // Const-sana tulee laittaa parametriviitteen yhteyteen, jos ei ole tarvetta muuttaa alkuperäistä oliota
}

int main(){
    Kalenterimerkinta muista;
    muista.tulostaMerkinta();

    doSomethingArvoparametri(muista); // kopiorakentajaa kutsutaan
    cout << "outside doSomethingArvoparametri" << endl;
    muista.tulostaMerkinta();

    doSomethingViittausparametri(muista); // kopiorakentajaa ei kutsuta
    cout << "outside doSomethingViittausparametri" << endl;
    muista.tulostaMerkinta();

    /*  
        Olioparametrin välitystä arvoparametrina ei tulisi käyttää, koska siinä kopioidaan tietoa "turhaan" 
        ja se on raskaampaa kuin viittausparametrit
     */

    doSomethingViittausparametriConst(muista);

return 0;
}
```

### Kalenterimerkinta.h

```cpp
#include "Paivays.h"
#include <string>
using std::string;

class Kalenterimerkinta
{
public:
    Kalenterimerkinta();
    Kalenterimerkinta(const Paivays& aPaivays, const string& aAsia, const bool& aMuistutus);
    Kalenterimerkinta(const Kalenterimerkinta& aKalenterimerkinta); // kopiorakentaja
    ~Kalenterimerkinta();
    Paivays getPaivays() const;
    string getAsia() const;
    bool getMuistutus() const;
    void setPaivays(const Paivays& aPaivays);
    void setAsia(const string& aAsia);
    void setMuistutus(const bool& aMuistutus);
    void tulostaMerkinta() const;
    void kysyTiedot();
private:
    Paivays mPaivays;
    string mAsia;
    bool mMuistutus;
};
```

### Kalenterimerkinta.cpp

```cpp
#include <iostream>
#include "Kalenterimerkinta.h"
using namespace std;

Kalenterimerkinta::Kalenterimerkinta() : mPaivays(1,1,1970), mAsia("N/A"), mMuistutus(false)
{
    cout << "Kalenterimerkintä-luokan parametriton rakentaja" << endl;
};

Kalenterimerkinta::Kalenterimerkinta(const Paivays& aPaivays, const string& aAsia, const bool& aMuistutus) 
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

Paivays Kalenterimerkinta::getPaivays() const {
    return mPaivays;
};

string Kalenterimerkinta::getAsia() const {
    return mAsia;
};

bool Kalenterimerkinta::getMuistutus() const {
    return mMuistutus;
};

void Kalenterimerkinta::setPaivays(const Paivays& aPaivays) {
    mPaivays = aPaivays;
};

void Kalenterimerkinta::setAsia(const string& aAsia) {
    mAsia = aAsia;
};

void Kalenterimerkinta::setMuistutus(const bool& aMuistutus) {
    mMuistutus = aMuistutus;
};

void Kalenterimerkinta::tulostaMerkinta() const {
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
```

### 

```cpp

```

### 

```cpp

```

## Tehtävä 3

### 

```cpp

```

### 

```cpp

```

### 

```cpp

```

### 
```cpp

```