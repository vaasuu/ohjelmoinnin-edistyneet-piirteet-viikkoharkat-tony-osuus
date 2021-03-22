#pragma once
class noppa
{
public:
    noppa();
    noppa(int aNoppienLkm, const int aMaxNoppienLkm = 5);

    int getViimeisinLukema();
    void heitaNoppaa();
    void kerroViimeisenHeitonLukema();
    int getNoppienLkm();
    void setNoppienLkm(int aNoppienLkm);

private:
    int mNopanViimeisinLuku;
    int mNoppienLkm;
    int mMaxNoppienLkm;
    int nopat[];
};