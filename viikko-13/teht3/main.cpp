#include <iostream>
#include <string>
#include <vector>
#include "Henkilo.h"
using namespace std;

int main(){
    vector <Henkilo> henkilot;
    
    bool run = true;
    while (run)
    {
        cout << "1. Lisää uusi henkilö\n2. Tulosta henkilöt\n3. Lopeta\n4. Poista henkilö" << endl;
        cout << "Valitse: ";
        char input=0;
        cin >> input;
        switch (input) {
            case '1': 
                {
                    Henkilo x;
                    x.kysyTiedot();
                    henkilot.push_back(x);
                    break;
                }
                
            case '2':
                {
                    for (size_t i = 0; i < henkilot.size(); i++)
                    {
                        cout << "--------------------------" << endl;
                        henkilot[i].tulostaHenkilonTiedot();
                        cout << "--------------------------" << endl;
                    }
                    break;
                }

            case '3':
                { 
                    run = false;
                    break;
                }

            case '4':
                {
                    bool deleted = false;
                    string nameToDelete;
                    cout << "Anna poistettavan henkilön nimi: ";
                    cin.ignore(256, '\n');
                    getline(cin,nameToDelete);

                    for (size_t i = 0; i < henkilot.size(); i++)
                    {
                        if (henkilot[i].getNimi() == nameToDelete)
                        {
                            henkilot.erase(henkilot.begin()+i);
                            cout << nameToDelete << " on nyt poistettu!" << endl;
                            deleted = true;
                        }
                        
                    }
                    if (!deleted)
                    {
                        cout << "Ei löydy henkilöä nimeltä \"" << nameToDelete << "\"" << endl;
                    }
                    
                    break;
                }

            default:
                {
                    cout << "Väärä valinta!" << endl;
                    break;
                }
        }
    }
    
    return 0;
}