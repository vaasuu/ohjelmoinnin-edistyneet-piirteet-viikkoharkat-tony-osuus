#pragma once
#include <iostream>
#include <string>
using namespace std;

class Osoite
{
public:
    Osoite();
    Osoite(std::string aKatuosoite, std::string aPostinumero, std::string aKunta);
    ~Osoite();
    std::string getKatuosoite() const;
    std::string getPostinumero() const;
    std::string getKunta() const;
    void setKatuosoite(std::string aKatuosoite);
    void setPostinumero(std::string aPostinumero);
    void setKunta(std::string aKunta);
    void tulostaTiedot() const;
private:
    std::string mKatuosoite;
    std::string mPostinumero;
    std::string mKunta;
};