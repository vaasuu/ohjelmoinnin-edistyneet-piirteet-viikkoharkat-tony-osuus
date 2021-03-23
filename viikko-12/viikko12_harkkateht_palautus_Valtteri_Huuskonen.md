# Ohjelmoinnin viikkoharjoitukset – 3. viikkoharjoitusten ratkaisut 

#### (Valtteri Huuskonen 2021-03-23)

## Tehtävä 1

### Henkilo.h

```cpp
#pragma once
#include <iostream>
#include <string>
using namespace std;

// Henkilö-luokan esittely (kirjoitetaan omaan .h tiedostoon)
// Esittely == declaration, API
class Henkilo {
    // Luokan julkinen rajapinta (API), toiminnot, metodit
    public:

        Henkilo();
        Henkilo(string aNimi, int aIka);
        ~Henkilo();

        void setNimi(string aNimi);
        void setIka(int aIka);
        string getNimi() const;
        int getIka() const;
        void tulostaHenkilonTiedot() const;

    // Luokan tietojäsenet (yleensä private)
    // Näihin päästään käsiksi vain luokan metodeissa
    private:
        string mNimi;
        int mIka;
};
```

### Henkilo.cpp

```cpp
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
```

## Tehtävä 2 muutetut tiedostot

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

    // Luokan tietojäsenet (yleensä private)
    // Näihin päästään käsiksi vain luokan metodeissa
    private:
        string mNimi;
        int mIka;
        Osoite osoite;
};
```

### Henkilö.cpp

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
```

### main.cpp

```cpp
#include <iostream>
#include <string>
#include "Henkilo.h"
using namespace std;

int main(){
    Osoite kallenOsoite("Jokukatu", "12345", "JokuKunta");
    kallenOsoite.tulostaTiedot();

    Henkilo kalle("Kalle", 30, kallenOsoite);
    kalle.tulostaHenkilonTiedot();

    Henkilo ville("Ville", 20, Osoite("Nokiakatu 1", "54321", "Nokia"));
    ville.tulostaHenkilonTiedot();
    
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

## Tehtävä 3

### Paivays.cpp

```cpp
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
    Kalenterimerkinta(Paivays aPaivays, string aAsia, bool aMuistutus);
    ~Kalenterimerkinta();
    Paivays getPaivays();
    string getAsia();
    bool getMuistutus();
    void setPaivays(Paivays aPaivays);
    void setAsia(string aAsia);
    void setMuistutus(bool aMuistutus);
    void tulostaMerkinta();
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

Kalenterimerkinta::Kalenterimerkinta(Paivays aPaivays, string aAsia, bool aMuistutus) 
    : mPaivays(aPaivays), mAsia(aAsia), mMuistutus(aMuistutus)
{
    cout << "Kalenterimerkintä-luokan parametrillinen rakentaja" << endl;
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
```

### main.cpp

```cpp
#include <iostream>
#include "Paivays.h"
#include "Kalenterimerkinta.h"
using namespace std;

int main(){
    Kalenterimerkinta muista;
    muista.kysyTiedot();
    muista.tulostaMerkinta();

    Paivays huominenPaiva(24,3,2021);
    Kalenterimerkinta huomenna(huominenPaiva, "Käy kaupassa", true);
    huomenna.tulostaMerkinta();

    return 0;
}
```