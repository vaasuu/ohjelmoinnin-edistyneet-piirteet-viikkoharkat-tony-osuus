# Ohjelmoinnin viikkoharjoitukset – 6. viikkoharjoitusten ratkaisut

#### (Valtteri Huuskonen 2021-04-23)

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

## Tehtävä 2

### filename.ext

```cpp

```

## Tehtävä 3

### filename.ext

```cpp

```

### filename.ext

## Tehtävä 4

```cpp

```
