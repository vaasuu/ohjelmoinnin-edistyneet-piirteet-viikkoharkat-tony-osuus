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