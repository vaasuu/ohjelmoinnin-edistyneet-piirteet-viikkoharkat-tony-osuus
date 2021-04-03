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
        cout << "1. Lisää uusi henkilö\n2. Tulosta henkilöt\n3. Lopeta" << endl;
        char input=0;
        cin >> input;
        switch (input) {
        case '1': 
            {
                Henkilo x;
                x.kysyTiedot();
                henkilot.push_back(x);
                // henkilot.push_back(Henkilo("Kalle", 20));
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
        default:
            {
                cout << "Väärä valinta!" << endl;
                break;
            }
        }
    }
    
    return 0;
}