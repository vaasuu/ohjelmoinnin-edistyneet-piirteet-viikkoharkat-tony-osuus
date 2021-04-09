# Ohjelmoinnin viikkoharjoitukset – 5. viikkoharjoitusten ratkaisut 

#### (Valtteri Huuskonen 2021-04-09)

## Tehtävä 1

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

Henkilo::Henkilo(const string& aNimi, const int& aIka) : mNimi(aNimi), mIka(aIka)
{
    cout << "Henkilö " << aNimi << " luotu. (2 parametrinen rakentaja)" << endl;
}

Henkilo::Henkilo(const string& aNimi, const int& aIka, const Osoite& aOsoite)
    : mNimi(aNimi), mIka(aIka), osoite(aOsoite)
{
    cout << "Luotu henkilö, jolla nimi, ikä ja osoite" << endl;
}

Henkilo::Henkilo(const Henkilo& aHenkilo) // kopiorakentaja
    : mNimi(aHenkilo.mNimi), mIka(aHenkilo.mIka), osoite(aHenkilo.osoite)
{
    cout << "Henkilo –luokan kopiorakentaja" << endl;
}

Henkilo::~Henkilo(){
    cout << "Henkilö -luokan purkaja" << endl;
}

void Henkilo::setNimi(string aNimi){
    // asetetaan henkilölle uusi nimi
    mNimi = aNimi; 
}

void Henkilo::setIka(const int& aIka){
    mIka = aIka;
}

string Henkilo::getNimi() const {
    return mNimi;
}

int Henkilo::getIka() const {
    return mIka;
}

void Henkilo::setOsoite(const Osoite& aOsoite) {
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

### Henkilo.h

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
        Henkilo(const string& aNimi, const int& aIka);
        Henkilo(const string& aNimi, const int& aIka, const Osoite& aOsoite);
        Henkilo(const Henkilo& aHenkilo); // kopiorakentaja
        ~Henkilo();

        void setNimi(string aNimi);
        void setIka(const int& aIka);
        string getNimi() const;
        int getIka() const;
        void setOsoite(const Osoite& aOsoite);
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

### main.cpp

```cpp
#include <iostream>
#include "Opiskelija.h"
#include "Opettaja.h"
#include <string>
using namespace std;

int main() {
    Opiskelija tyyppi("Kalle", 25, Osoite("Aleksanterinkatu 1", "3345", "Tampere") ,"12345", 3);
    tyyppi.tulostaTiedot();
    tyyppi.lisaaKurssi("Integrointi");
    tyyppi.lisaaOpintopisteita(3);
    cout << "--------------------------" << endl;
    tyyppi.tulostaTiedot();


    cout << "-------------------" << endl;
    Opettaja ope("Tony", 25, Osoite("Aleksanterinkatu 1", "3345", "Tampere"), "Tietotekniikka");
    ope.lisaaKurssi("IoT ja web dev");
    ope.lisaaKurssi("Integrointi");
    ope.tulostaTiedot();
    ope.poistaKurssi("Derivointi");
    ope.poistaKurssi("Integrointi");
    return 0;
}
```

### Opettaja.cpp

```cpp
#include <iostream>
#include "Opettaja.h"
#include "Henkilo.h"
#include "Osoite.h"
#include <string>
#include <vector>
using namespace std;

Opettaja::Opettaja() // parametriton rakentaja 
{
    cout << "Opettaja parametriton rakentaja" << endl;
} 

Opettaja::Opettaja(const string& aNimi, const int& aIka, const Osoite& aOsoite, 
const string& aKoulutusala) // 4 parametrinen oletusrakentaja
: Henkilo(aNimi, aIka, aOsoite), Koulutusala(aKoulutusala) 
{
    cout << "Opettaja 4 parametrinen oletusrakentaja" << endl;
} 

Opettaja::Opettaja(const Opettaja& aOpettaja) // kopiorakentaja
    : Henkilo(aOpettaja.getNimi(), aOpettaja.getIka(), Osoite(aOpettaja.getOsoite())), 
    Koulutusala(aOpettaja.Koulutusala), Vastuukurssit(aOpettaja.Vastuukurssit)
{
    cout << "Opettaja kopiorakentaja" << endl;
}

Opettaja::~Opettaja() { // purkaja
    cout << "Opettaja purkaja" << endl;
} 

void Opettaja::setKoulutusala(const string& aKoulutusala) {
    Koulutusala = aKoulutusala;
}
string Opettaja::getKoulutusala() const {
    return Koulutusala;
}

void Opettaja::setVastuukurssit(const vector <string>& aVastuukurssit) {
    Vastuukurssit = aVastuukurssit;
}

vector <string> Opettaja::getVastuukurssit() const {
    return Vastuukurssit;
} 

void Opettaja::lisaaKurssi(string aKurssi) {
    Vastuukurssit.push_back(aKurssi);
}

void Opettaja::poistaKurssi(string aKurssi) {
    bool deleted = false;
    for (size_t i = 0; i < Vastuukurssit.size(); i++)
    {
        if (Vastuukurssit[i] == aKurssi)
        {
            Vastuukurssit.erase(Vastuukurssit.begin()+i);
            cout << aKurssi << " on nyt poistettu!" << endl;
            deleted = true;
        }
        
    }
    if (!deleted)
    {
        cout << "Ei löydy kurssia nimeltä \"" << aKurssi << "\"" << endl;
    }
}

void Opettaja::tulostaTiedot() {
    tulostaHenkilonTiedot();
    cout << "Koulutusala: " << Koulutusala << endl;
    cout << "Vastuukurssit: " << endl;
    for (string kurssi : Vastuukurssit)
    {
        cout << " " << kurssi << endl;
    }
}
```

### Opettaja.h

```cpp
#pragma once
#include <string>
#include <vector>
#include "Henkilo.h"
using namespace std;

class Opettaja : public Henkilo
{
public:
    Opettaja(); // parametriton oletusrakentaja
    Opettaja(const string& aNimi, const int& aIka, const Osoite& aOsoite, 
    const string& aKoulutusala); // 4 parametrinen oletusrakentaja
    Opettaja(const Opettaja& aOpettaja); // kopiorakentaja
    ~Opettaja(); // purkaja
    
    void setKoulutusala(const string& aKoulutusala);
    string getKoulutusala() const;
    
    void setVastuukurssit(const vector <string>& aVastuukurssit);
    vector <string> getVastuukurssit() const; 
    void lisaaKurssi(string aKurssi);
    void poistaKurssi(string aKurssi);
    void tulostaTiedot();

private:
    string Koulutusala;
    vector <string> Vastuukurssit;
};
```

### Opiskelija.cpp

```cpp
#include <iostream>
#include "Opiskelija.h"
#include "Henkilo.h"
#include "Osoite.h"
#include <string>
#include <vector>
using namespace std;

Opiskelija::Opiskelija() // parametriton rakentaja 
{
    cout << "Opiskelija parametriton rakentaja" << endl;
} 

Opiskelija::Opiskelija(const string& aNimi, const int& aIka, const Osoite& aOsoite, 
const string& aOpNro, const int& aOpintopisteet) // 5 parametrinen oletusrakentaja
: Henkilo(aNimi, aIka, aOsoite), opNro(aOpNro), opintopisteet(aOpintopisteet) 
{
    cout << "Opiskelija 5 parametrinen oletusrakentaja" << endl;
} 

Opiskelija::Opiskelija(const Opiskelija& aOpiskelija) // kopiorakentaja
    : Henkilo(aOpiskelija.getNimi(), aOpiskelija.getIka(), Osoite(aOpiskelija.getOsoite())), 
    opNro(aOpiskelija.opNro), suoritetutKurssit(aOpiskelija.suoritetutKurssit), 
    opintopisteet(aOpiskelija.opintopisteet)
{
    cout << "Opiskelija kopiorakentaja" << endl;
}

Opiskelija::~Opiskelija() { // purkaja
    cout << "Opiskelija purkaja" << endl;
} 

void Opiskelija::setOpNro(const string& aOpNro) {
    opNro = aOpNro;
}
string Opiskelija::getOpNro() const {
    return opNro;
}

void Opiskelija::setSuoritetutKurssit(const vector <string>& aSuoritetutKurssit) {
    suoritetutKurssit = aSuoritetutKurssit;
}

vector <string> Opiskelija::getSuoritetutKurssit() const {
    return suoritetutKurssit;
} 

void Opiskelija::lisaaKurssi(string aKurssi) {
    suoritetutKurssit.push_back(aKurssi);
}

void Opiskelija::tulostaTiedot() {
    tulostaHenkilonTiedot();
    cout << "Opiskelijanumero: " << opNro << endl;
    cout << "Opintopisteet: " << opintopisteet << endl;
    cout << "Suoritetut kurssit: " << endl;
    for (string kurssi : suoritetutKurssit)
    {
        cout << " " << kurssi << endl;
    }
}

void Opiskelija::setOpintopisteet(const int& aOpintopisteet) {
    opintopisteet = aOpintopisteet;
}

int Opiskelija::getOpintopisteet() const {
    return opintopisteet;
}

void Opiskelija::lisaaOpintopisteita(const int& aOpintopisteet) {
    opintopisteet += aOpintopisteet;
}
```

### Opiskelija.h

```cpp
#pragma once
#include <string>
#include <vector>
#include "Henkilo.h"
using namespace std;

class Opiskelija : public Henkilo
{
public:
    Opiskelija(); // parametriton oletusrakentaja
    Opiskelija(const string& aNimi, const int& aIka, const Osoite& aOsoite, const string& aOpNro, 
    const int& aOpintopisteet); // 4 parametrinen oletusrakentaja
    Opiskelija(const Opiskelija& aOpiskelija); // kopiorakentaja
    ~Opiskelija(); // purkaja
    
    void setOpNro(const string& aOpNro);
    string getOpNro() const;
    
    void setSuoritetutKurssit(const vector <string>& aSuoritetutKurssit);
    vector <string> getSuoritetutKurssit() const; 
    void lisaaKurssi(string aKurssi);
    
    void tulostaTiedot();
    
    void setOpintopisteet(const int& aOpintopisteet);
    int getOpintopisteet() const;
    void lisaaOpintopisteita(const int& aOpintopisteet);

private:
    string opNro;
    vector <string> suoritetutKurssit;
    int opintopisteet;
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
    cout << " Katuosoite: " << mKatuosoite << endl;
    cout << " Postinumero: " << mPostinumero << endl;
    cout << " Kunta: " << mKunta << endl;
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

## Tehtävä 4 ja 5

### main.cpp

```cpp
#include <iostream>
#include "Opiskelija.h"
#include "Opettaja.h"
#include <string>
using namespace std;

int main() {

    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
    
    Henkilo a;
    Opettaja b;
    Opiskelija c;

    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;

    Henkilo d("Dee", 23);
    Opettaja e("Eee", 40, Osoite("Katu", "67123", "Tampere"), "Tietotekniikka");
    Opiskelija f("Äff", 24, Osoite("Kuja", "4321", "Tampere"), "1234", 53);

    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;

    Henkilo g(d);
    Opettaja h(e);
    Opiskelija i(f); 
    
    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;

    return 0;
}
```
