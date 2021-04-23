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