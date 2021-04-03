# Ohjelmoinnin viikkoharjoitukset – 4. viikkoharjoitusten ratkaisut 

#### (Valtteri Huuskonen 2021-04-03)

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

## Tehtävä 3

### Henkilö.h

```cpp
#pragma once
#include <iostream>
#include <string>
#include "Osoite.h"
using namespace std;

// Henkilö-luokan esittely (kirjoitetaan omaan .h tiedostoon)
// Esittely == declaration, API
class Henkilo {
    // Luokan julkinen rajapinta (API), toiminnot, metodit
    public:
        Henkilo();
        Henkilo(string aNimi, int aIka);
        Henkilo(string aNimi, int aIka, Osoite aOsoite);
        ~Henkilo();

        void setNimi(string aNimi);
        void setIka(int aIka);
        string getNimi() const;
        int getIka() const;
        void setOsoite(Osoite aOsoite);
        Osoite getOsoite() const;
        void tulostaHenkilonTiedot() const;
        void kysyTiedot();

    // Luokan tietojäsenet (yleensä private)
    // Näihin päästään käsiksi vain luokan metodeissa
    private:
        string mNimi;
        int mIka;
        Osoite osoite;
};
```

### Henkilo.cpp

```cpp
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

    cin.ignore(256,'\n');
    cout << "Nimi: ";
    getline(cin,name);
    mNimi = name;


    cout << "Ikä: ";
    cin >> age;
    mIka = age;
    cin.ignore(256,'\n');

    cout << "Katu: ";
    getline(cin,address);
    osoite.setKatuosoite(address);
}
```

### main.cpp

```cpp
#include <iostream>
#include <string>
#include <vector>
#include "Henkilo.h"
using namespace std;

int main(){
    vector <Henkilo> henkilot;
    
    bool run = true;
    while (run)
    {
        cout << "1. Lisää uusi henkilö\n2. Tulosta henkilöt\n3. Lopeta" << endl;
        cout << "Valitse: ";
        char input=0;
        cin >> input;
        switch (input) {
        case '1': 
            {
                Henkilo x;
                x.kysyTiedot();
                henkilot.push_back(x);
                break;
            }
        case '2':
            {
                for (size_t i = 0; i < henkilot.size(); i++)
                {
                    cout << "--------------------------" << endl;
                    henkilot[i].tulostaHenkilonTiedot();
                    cout << "--------------------------" << endl;
                }
                break;
            }
        case '3':
            { 
                run = false;
                break;
            }
        default:
            {
                cout << "Väärä valinta!" << endl;
                break;
            }
        }
    }
    
    return 0;
}
```

### Osoite.h
```cpp
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Osoite
{
public:
    Osoite();
    Osoite(std::string aKatuosoite, std::string aPostinumero, std::string aKunta);
    ~Osoite();
    std::string getKatuosoite() const;
    std::string getPostinumero() const;
    std::string getKunta() const;
    void setKatuosoite(std::string aKatuosoite);
    void setPostinumero(std::string aPostinumero);
    void setKunta(std::string aKunta);
    void tulostaTiedot() const;
private:
    std::string mKatuosoite;
    std::string mPostinumero;
    std::string mKunta;
};
```

### Osoite.cpp
```cpp
#include "Osoite.h"
#include <iostream>
#include <string>
using namespace std;

Osoite::Osoite() : mKatuosoite("N/A"), mPostinumero("N/A"), mKunta("N/A")
{
    cout << "Osoite -luokan oletusrakentaja (parametriton rakentaja)" << endl;
}

Osoite::Osoite(string aKatuosoite, string aPostinumero, string aKunta)
    : mKatuosoite(aKatuosoite), mPostinumero(aPostinumero), mKunta(aKunta)
{
    cout << "Osoite -luokan 3 parametrinen rakentaja" << endl;
}

Osoite::~Osoite()
{
    cout << "Osoite -luokan purkaja" << endl;
}

std::string Osoite::getKatuosoite() const {
    return mKatuosoite;
}
std::string Osoite::getPostinumero() const {
    return mPostinumero;
}
std::string Osoite::getKunta() const {
    return mKunta;
}
void Osoite::setKatuosoite(std::string aKatuosoite) {
    mKatuosoite = aKatuosoite;
}
void Osoite::setPostinumero(std::string aPostinumero) {
    mPostinumero = aPostinumero;
}
void Osoite::setKunta(std::string aKunta) {
    mKunta = aKunta;
}
void Osoite::tulostaTiedot() const {
    cout << "Katuosoite: " << mKatuosoite << endl;
    cout << "Postinumero: " << mPostinumero << endl;
    cout << "Kunta: " << mKunta << endl;
}
```

## Tehtävä 4

### Henkilo.h (lisäys)
```cpp
        Henkilo(const Henkilo& aHenkilo); // kopiorakentaja
```

### Henkilo.cpp (lisäys)
```cpp
Henkilo::Henkilo(const Henkilo& aHenkilo) // kopiorakentaja
    : mNimi(aHenkilo.mNimi), mIka(aHenkilo.mIka), osoite(aHenkilo.osoite)
{
    cout << "Henkilo –luokan kopiorakentaja" << endl;
}
```

### main.cpp 
```cpp
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
```