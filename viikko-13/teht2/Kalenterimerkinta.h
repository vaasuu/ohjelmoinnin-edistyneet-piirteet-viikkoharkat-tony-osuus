#include "Paivays.h"
#include <string>
using std::string;

class Kalenterimerkinta
{
public:
    Kalenterimerkinta();
    Kalenterimerkinta(Paivays aPaivays, string aAsia, bool aMuistutus);
    Kalenterimerkinta(const Kalenterimerkinta& aKalenterimerkinta); // kopiorakentaja
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