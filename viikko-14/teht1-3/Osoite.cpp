#include "Osoite.h"
#include <iostream>
#include <string>
using namespace std;

Osoite::Osoite() : mKatuosoite("N/A"), mPostinumero("N/A"), mKunta("N/A")
{
    cout << "Osoite -luokan oletusrakentaja (parametriton rakentaja)" << endl;
}

Osoite::Osoite(string aKatuosoite, string aPostinumero, string aKunta)
    : mKatuosoite(aKatuosoite), mPostinumero(aPostinumero), mKunta(aKunta)
{
    cout << "Osoite -luokan 3 parametrinen rakentaja" << endl;
}

Osoite::~Osoite()
{
    cout << "Osoite -luokan purkaja" << endl;
}

std::string Osoite::getKatuosoite() const {
    return mKatuosoite;
}
std::string Osoite::getPostinumero() const {
    return mPostinumero;
}
std::string Osoite::getKunta() const {
    return mKunta;
}
void Osoite::setKatuosoite(std::string aKatuosoite) {
    mKatuosoite = aKatuosoite;
}
void Osoite::setPostinumero(std::string aPostinumero) {
    mPostinumero = aPostinumero;
}
void Osoite::setKunta(std::string aKunta) {
    mKunta = aKunta;
}
void Osoite::tulostaTiedot() const {
    cout << " Katuosoite: " << mKatuosoite << endl;
    cout << " Postinumero: " << mPostinumero << endl;
    cout << " Kunta: " << mKunta << endl;
}