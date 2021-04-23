# Ohjelmoinnin viikkoharjoitukset – 6. viikkoharjoitusten ratkaisut

#### (Valtteri Huuskonen 2021-04-24)

## Tehtävä 1

Jos yrittää muuttaa periytetyn luokan (Opettaja tai Opiskelija) sisällä olevassa koodissa suoraan nimeä tai ikää (ilman settereitä) se ei onnistu, koska `Henkilo::mNimi` on private. Se on kääntäjän mukaan inaccessible, eli siihen ei ole pääsyä. 

Jos muutetaan ne privatesta protected, niin sitten voidaan muokata aliluokissa; muualla se toimii kuin private.

### henkilo.h

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

    // Ulospäin private, mutta aliluokille näkyvä == protected
    protected:
        string mNimi;

    // Luokan tietojäsenet (yleensä private)
    // Näihin päästään käsiksi vain luokan metodeissa
    private:
        int mIka;
        Osoite osoite;
};
```

### opettaja.cpp lisäys

```cpp
void Opettaja::teeJotain() {
    mNimi = "Kalle";
```

### Opettaja.h lisäys

```cpp
    Public:
        void teeJotain();
```

## Tehtävä 2-4

### koulu.h

```cpp
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Opiskelija.h"
#include "Opettaja.h"
using namespace std;

class koulu
{
public:
    koulu();
    koulu(string aKoulunNimi);
    ~koulu();
    void lisaaOpiskelija(Opiskelija& aOpiskelija);
    void lisaaOpettaja(Opettaja& aOpettaja);
    void tulostaKaikkiTiedot() const;
    void tulostaOpettajat() const;
    void tulostaOpiskelijat() const;
    void setKoulunNimi(string& aKoulunNimi);
    string getKoulunNimi();
    void lisaaOpettajalleKurssi(string& aOpe, string& aKurssi);
    void lisaaOpiskelijalleKurssi(string& aOpiskelija, string& aKurssi);
private:
    vector <Opettaja*> opettajat_ptr;
    vector <Opiskelija*> opiskelijat_ptr;
    string koulunNimi;
};
```

### koulu.cpp

```cpp
#include <iostream>
#include "Opiskelija.h"
#include "Henkilo.h"
#include "Osoite.h"
#include "koulu.h"
#include <string>
#include <vector>
using namespace std;

koulu::koulu() {
    cout << "koulu parametriton rakentaja" << endl;
}

koulu::koulu(string aKoulunNimi) : koulunNimi(aKoulunNimi) {
    cout << "koulu 1 parametrinen rakentaja" << endl;
}

koulu::~koulu() {
    cout << "koulu purkaja" << endl;
}

void koulu::lisaaOpiskelija(Opiskelija& aOpiskelija) {
    opiskelijat_ptr.push_back(new Opiskelija(aOpiskelija));    
}

void koulu::lisaaOpettaja(Opettaja& aOpettaja) {
    opettajat_ptr.push_back(new Opettaja(aOpettaja));
}

void koulu::tulostaKaikkiTiedot() const {
    cout << "Koulun nimi: " << koulunNimi << endl;
    cout << "Opettajien lukumäärä: " << opettajat_ptr.size() << endl; 
    cout << "Opettajat:" << endl;
    tulostaOpettajat();
    cout << "Opiskelijoiden lukumäärä: " << opiskelijat_ptr.size() << endl;
    cout << "Opiskelijat:" << endl;
    tulostaOpiskelijat();
}

void koulu::tulostaOpettajat() const {
    for (auto &&i : opettajat_ptr)
    {
        cout << "\n" << endl;
        i->tulostaTiedot();
        cout << "\n" << endl;
    }
}

void koulu::tulostaOpiskelijat() const {

    for (auto &&i : opiskelijat_ptr)
    {
        cout << "\n" << endl;
        i->tulostaTiedot();
        cout << "\n" << endl;
    }
}

void koulu::setKoulunNimi(string& aKoulunNimi) {
    koulunNimi = aKoulunNimi;
}

string koulu::getKoulunNimi() {
    return koulunNimi;
}

void koulu::lisaaOpettajalleKurssi(string& aOpe, string& aKurssinNimi) {

    bool found_ope = false;

    for (auto &&ope : opettajat_ptr)
    {
        if (ope->getNimi() == aOpe)
        {
            ope->lisaaKurssi(aKurssinNimi);
            cout << aKurssinNimi << " on nyt lisätty!" << endl;
            found_ope = true;
        }
        
    }
    if (!found_ope)
    {
        cout << "Ei löydy opettajaa nimeltä \"" << aOpe << "\"" << endl;
    }
}

void koulu::lisaaOpiskelijalleKurssi(string& aOpiskelija, string& aKurssinNimi) {

    bool found_opiskelija = false;

    for (auto &&opiskelija : opiskelijat_ptr)
    {
        if (opiskelija->getNimi() == aOpiskelija)
        {
            opiskelija->lisaaKurssi(aKurssinNimi);
            cout << aKurssinNimi << " on nyt lisätty!" << endl;
            found_opiskelija = true;
        }
        
    }
    if (!found_opiskelija)
    {
        cout << "Ei löydy opiskelijaa nimeltä \"" << aOpiskelija << "\"" << endl;
    }
}
```

### main.cpp

```cpp
#include <iostream>
#include "Opiskelija.h"
#include "Opettaja.h"
#include "koulu.h"
#include <string>
using namespace std;

int main() {
    string aKoulunNimi;
    cout << "Koulun nimi: ";
    getline(cin, aKoulunNimi);
    koulu koulu(aKoulunNimi);
    
    char ans = '0';
    while (ans != '8')
    {
        cout << R"asdf(
1. Lisää opettaja
2. Lisää opettajalle kurssi
3. Lisää opiskelija
4. Lisää opiskelijalle kurssi
5. Tulosta opettajat
6. Tulosta opiskelijat
7. Tulosta koulun tiedot
q. Poistu ohjelmasta
)asdf";

        cin >> ans;

        switch (ans)
        {
        case '1':
            {
                Opettaja temp_ope;
                temp_ope.kysyTiedot();
                koulu.lisaaOpettaja(temp_ope);
                break;
            }
        case '2':
            {
                string aOpe;
                cout << "Opettajan nimi jolle kurssi lisätään: ";
                cin.ignore(1024, '\n');
                getline(cin, aOpe);
                string aKurssinNimi;
                cout << "kurssin nimi: ";
                getline(cin, aKurssinNimi);
                koulu.lisaaOpettajalleKurssi(aOpe, aKurssinNimi);
                break;
            }

        case '3':
            {
                Opiskelija temp_opiskelija;
                temp_opiskelija.kysyTiedot();
                koulu.lisaaOpiskelija(temp_opiskelija);
                break;
            }
        case '4':
            {
                string aOpiskelija;
                cout << "Opiskelijan nimi jolle kurssi lisätään: ";
                cin.ignore(1024, '\n');
                getline(cin, aOpiskelija);
                string aKurssinNimi;
                cout << "kurssin nimi: ";
                getline(cin, aKurssinNimi);
                koulu.lisaaOpiskelijalleKurssi(aOpiskelija, aKurssinNimi);
                break;
            }
        case '5':
            {
                koulu.tulostaOpettajat();
                break;
            }
        case '6':
            {
                koulu.tulostaOpiskelijat();
                break;
            }
        case '7':
            {
                koulu.tulostaKaikkiTiedot();
                break;
            }
        case 'q':
            {
                return 0;
                break;
            }
        default:
            {
                cout << "Väärä vastausvaihtoehto!" << endl;
                break;
            }
        }
    }
    
    return 0;
}
```

## Tehtävä 5

Ennen tulostaTiedot() const -metodin muuttamista virtuaaliseksi, kutsuttiin pelkästään Henkilö-luokan metodia. 

tulostaTiedot() const -metodin virtuaaliseksi muuttamisen jälkeen Henkilöllä kutsuttiin Henkilö-luokan metodia, Opettajalla Opettaja-luokan metodia ja Opiskelijalla Opiskelija-luokan metodia. Siis jokainen ns. omaa tulostaTiedot() metodiansa. Tämä tapahtuu siksi, koska `virtual` avainsana kertoo että käytetään ns. dynaamista sidontaa, jonka seurauksena kutsutaan (ajon aikana) aina ns. oikeaa metodia, vaikka niitä on useampi samanniminen. 

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
        virtual void tulostaTiedot() const;
        void kysyTiedot();

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

void Henkilo::tulostaTiedot() const {
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
    void tulostaTiedot() const;

private:
    string Koulutusala;
    vector <string> Vastuukurssit;
};
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

Opettaja::Opettaja(const string& aNimi, const int& aIka, 
const Osoite& aOsoite, const string& aKoulutusala) // 4 parametrinen oletusrakentaja
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

void Opettaja::tulostaTiedot() const {
    Henkilo::tulostaTiedot();
    cout << "Koulutusala: " << Koulutusala << endl;
    cout << "Vastuukurssit: " << endl;
    for (string kurssi : Vastuukurssit)
    {
        cout << " " << kurssi << endl;
    }
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
    Opiskelija(const string& aNimi, const int& aIka, const Osoite& aOsoite, 
    const string& aOpNro, const int& aOpintopisteet); // 4 parametrinen oletusrakentaja
    Opiskelija(const Opiskelija& aOpiskelija); // kopiorakentaja
    ~Opiskelija(); // purkaja
    
    void setOpNro(const string& aOpNro);
    string getOpNro() const;
    
    void setSuoritetutKurssit(const vector <string>& aSuoritetutKurssit);
    vector <string> getSuoritetutKurssit() const; 
    void lisaaKurssi(string aKurssi);
    
    void tulostaTiedot() const;
    
    void setOpintopisteet(const int& aOpintopisteet);
    int getOpintopisteet() const;
    void lisaaOpintopisteita(const int& aOpintopisteet);

private:
    string opNro;
    vector <string> suoritetutKurssit;
    int opintopisteet;
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

void Opiskelija::tulostaTiedot() const {
    Henkilo::tulostaTiedot();
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

### main.cpp

```cpp
#include <iostream>
#include "Opiskelija.h"
#include "Opettaja.h"
#include <string>
#include <vector>
using namespace std;

int main() {

    // teht 5

    vector <Henkilo*> henkilot;

    henkilot.push_back(new Henkilo);
    henkilot.push_back(new Opettaja);
    henkilot.push_back(new Opiskelija);

    for (Henkilo* x : henkilot)
    {
        x->tulostaTiedot();
    }
    
    return 0;
}
```
