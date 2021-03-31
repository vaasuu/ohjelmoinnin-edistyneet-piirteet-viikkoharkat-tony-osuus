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