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

class duomenys {
    private:
    string vardas, pavarde;
    vector<float> pazymiai;
    float egzamino_rez;
    float galutinis_egz;

    //copy konstruktorius

    public: duomenys(const duomenys & p1)
    {
        vardas = p1.vardas;
        pavarde = p1.pavarde;
        pazymiai = p1.pazymiai;
        egzamino_rez = p1.egzamino_rez;
        galutinis_egz = p1.galutinis_egz;
    }

    // konstruktoius
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
