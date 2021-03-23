# Ohjelmoinnin viikkoharjoitukset – 2 viikkoharjoitusten ratkaisut

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


## Tehtävä 2

```

```


## Tehtävä 3


```

```


## Tehtävä 4

```

```
