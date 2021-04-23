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

### filename.ext

```cpp

```
