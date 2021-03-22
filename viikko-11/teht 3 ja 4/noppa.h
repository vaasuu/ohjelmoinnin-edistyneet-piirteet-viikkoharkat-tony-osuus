#pragma once
class noppa
{
public:
    noppa();
    noppa(int aNoppienLkm);

    int getViimeisinLukema();
    void heitaNoppaa();
    void kerroViimeisenHeitonLukeama();
    int getNoppienLkm();
    void setNoppienLkm(int aNoppienLkm);
    
private:
    int mNopanViimeisinLuku;
    int mNoppienLkm;
    int mNoppa1;
    int mNoppa2;
    int mNoppa3;
    int mNoppa4;
    int mNoppa5;
};