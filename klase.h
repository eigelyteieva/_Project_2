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

#include "papildomos_fukcijos.h"
#include "funkcijos.h"

#pragma once

class duomenys {
    private:
    string vardas, pavarde;
    vector<float> pazymiai;
    float egzamino_rez;
    float galutinis_egz;


    public:

    //konstruktoius
    duomenys(){};

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
    //destruktorius
    ~duomenys(){};

};


#endif // KLASE_H_INCLUDED
