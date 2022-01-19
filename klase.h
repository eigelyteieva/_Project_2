#ifndef KLASE_H_INCLUDED
#define KLASE_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <stdexcept>
#include <limits>
#include <fstream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::istream;
using std::sort;
using std::vector;
using std::to_string;

#include "papildomos_funkcijos.h"
#include "funkcijos.h"

#pragma once

///Čia yra abstrakti "zmogus" klasė
class zmogus{
public:
    virtual void setVardas(string vardass) = 0; ///Vardo setteris
    virtual string getVardas() = 0; ///Vardo getteris
    virtual float getEgzamino_rez() = 0; ///Egzamino rezultatų getteris
    virtual void setPavarde(string p) = 0; ///Pavardės setteris
    virtual string getPavarde() = 0; ///Pavardės getteris
    virtual void setPazymiai(float pa) = 0; ///Pažymių setteris
    virtual vector<float> getPazymiai() = 0;///Pažymių getteris
    virtual void setEgzamino_rez(float e) = 0; ///Egzamino rezultatų setteris
    virtual float getGalutinis_egz() = 0; ///Galutinio egzamino rezultatų getteris
    virtual void setGalutinis_egz(float g) =0;///Galutinio egzamino rezultatų setteris
};
///Cia yra klasė "duomenys" kuri yra paveldėtos abstrakčios klasės "zmogus" vaikinė klasė
class duomenys : public zmogus{
    private:
    string vardas, pavarde;
    vector<float> pazymiai;
    float egzamino_rez;
    float galutinis_egz;

    public:
    duomenys (string vardas, string pavarde, vector <float>pazymiai, float egzamino_rez, float galutinis_egz ){
    this->vardas = vardas;
    this->pavarde = pavarde;
    this->pazymiai = pazymiai;
    this->egzamino_rez = egzamino_rez;
    this->galutinis_egz = galutinis_egz;
    }

    //konstruktoius
    duomenys()
    {
        vardas = " ";
        pavarde = " ";
        egzamino_rez = 0;
        galutinis_egz = 0;
    };

    void setVardas(string v)
    {
        vardas = v;
    }
    string getVardas()
    {
        return vardas;
    }

    void setPavarde(string p)
    {
        pavarde = p;
    }
    string getPavarde()
    {
        return pavarde;
    }
    void setPazymiai(float pa)
    {
        pazymiai.push_back(pa);
    }
    vector<float> getPazymiai()
    {
        return pazymiai;
    }

    void setEgzamino_rez(float e)
    {
        egzamino_rez = e;
    }
    float getEgzamino_rez()
    {
        return egzamino_rez;
    }

    void setGalutinis_egz(float g)
    {
        galutinis_egz = g;
    }
    float getGalutinis_egz()
    {
        return galutinis_egz;
    }
    duomenys& operator= (const duomenys& duom)
    {

    vardas = duom.vardas;
    pavarde = duom.pavarde;
    pazymiai = duom.pazymiai;
    egzamino_rez = duom.egzamino_rez;
    galutinis_egz = duom.galutinis_egz;
    return *this;
    }
    //destruktorius
    ~duomenys(){};

};

#endif // KLASE_H_INCLUDED
