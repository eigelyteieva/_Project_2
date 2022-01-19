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
#include "klase.h"

using namespace std;

#pragma once

vector<duomenys> duom_rankinis (vector<duomenys> A,int &p, string &pasirinkimas)
{
    cout<<"Iveskite studentu skaiciu: "<<endl;
    p = studentuskaiciaustikrinimas();
    duomenys s;
    for(int i=0; i<p; i++)
    {   string laikinas1, laikinas2;
        cout<<"Iveskite "<<i+1<<"-o varda ir pavarde: ";
        cin>>laikinas1>>laikinas2;
        s.setVardas(laikinas1);
        s.setPavarde(laikinas2);
        float suma=0;
        int pazymiu_skaicius = 0;
        cout<<"Iveskite "<<i+1<<"studento pazymius, kai baigsite vesti - iveskite 0"<<endl;
        float temp;
        cout<<"1 pazymis: ";
        while ((temp = sveikoSkaiciausPatikrinimas()) && (temp!=0))
        {
            cout<< pazymiu_skaicius + 2 <<" pazymis: ";
            s.setPazymiai(temp);
            suma+=temp;
            pazymiu_skaicius++;
        }
        cout<<"Iveskite "<<i+1<<" studento egzamino rezultata: ";
        s.setEgzamino_rez(sveikoSkaiciausPatikrinimas());
        s.setGalutinis_egz(0.4*(suma/(s.getPazymiai().size()))+0.6*s.getEgzamino_rez());
        A.push_back(s);
    }
    cout<<"Jeigu norite matyti galutini egzamino pazymi spauskite G, jeigu mediana - M"<<endl;
    cin>>pasirinkimas;
     if ((pasirinkimas != "G") && (pasirinkimas != "g") && (pasirinkimas != "M") && (pasirinkimas != "m") )
    {
        cout<<"Ivedete netinkama simboli"<<endl;
        cout<<"Jeigu norite matyti galutini egzamino pazymi spauskite G, jeigu mediana - M";
        cin>>pasirinkimas;
    }
    return A;
}

void skaitymas(vector<duomenys>& A,int p, int paz)
{
    int studentu_sk =0 ;
    std::ifstream duom;
    string k;
    string temp;
    float temp2;
    string pavadinimas = to_string(p)+".txt";

    duom.open(pavadinimas);
    if(duom.is_open())
    {
        getline(duom>>std::ws, k);

        while(studentu_sk < p)
        {
            float suma=0;
            A.resize(A.size()+1);
            duom>>temp;
            A.at(studentu_sk).setVardas(temp);
            duom>>temp;
            A.at(studentu_sk).setPavarde(temp);

            for(int i=0; i<paz; i++){

               int temp3;
               duom>>temp3;
               A.at(studentu_sk).setPazymiai(temp3);
                suma+=temp3;

            }
            duom>>temp2;
            A.at(studentu_sk).setEgzamino_rez(temp2);
            A.at(studentu_sk).setGalutinis_egz(0.4*(suma/paz)+0.6* temp2);
            studentu_sk++;
        }
    }
}
