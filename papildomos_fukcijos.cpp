#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <stdexcept>
#include <limits>
#include <fstream>
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
using std::list;
using std::to_string;

#include "papildomos_fukcijos.h"
#include "klase.h"

#pragma once
float mediana(vector<int> pazymiai)
{
    sort (pazymiai.begin(), pazymiai.end());
    if (pazymiai.size() % 2 != 0)
    {return pazymiai[pazymiai.size()/2];}
    else
    {return (double)(pazymiai[(pazymiai.size() - 1)/2]+pazymiai[pazymiai.size()/2])/2.0;}
}
float mediana1(vector<float> pazymiai)
{
    sort (pazymiai.begin(), pazymiai.end());
    if (pazymiai.size() % 2 != 0)
    {return pazymiai[pazymiai.size()/2];}
    else
    {return (double)(pazymiai[(pazymiai.size() - 1)/2]+pazymiai[pazymiai.size()/2])/2.0;}
}
bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}
int sveikoSkaiciausPatikrinimas()
{
    string laikinas;
    int temp;
    while(1){
        cin>>laikinas;
        if(isNumber(laikinas) == true){
            temp = stoi(laikinas);
            if(((temp >= 0) && (temp <= 10)))
            break;
            else cout<<"Ivedete neteisinga simboli"<<endl<<"Pabandykite dar karta: ";
        }
        else cout<<"Ivedete neteisinga simboli"<<endl<<"Pabandykite dar karta: ";
    }
    return temp;
}
int studentuskaiciaustikrinimas()
{
    string laikinas;
    int temp;
    while(1){
        cin>>laikinas;
        if(isNumber(laikinas) == true){
            temp = stoi(laikinas);
            if(((temp >= 0) && (temp <= 100)))
            break;
            else cout<<"Ivedete neteisinga simboli"<<endl<<"Pabandykite dar karta: ";
        }
        else cout<<"Ivedete neteisinga simboli"<<endl<<"Pabandykite dar karta: ";
    }
    return temp;
}
void spausdinimas (vector<duomenys> A,string pasirinkimas, int p)
{

    string pavadinimas = to_string(p) + ".txt";
    std::ofstream isve;
    isve.open(pavadinimas);
    isve<<setw(20)<<std::left<<"Vardas"<<setw(20)<<std::left<<"Pavarde";
    if (pasirinkimas == "G" || pasirinkimas == "g")
    {isve<<setw(20)<<std::left<<"Galutinis(egz.)\n";}
    else{isve<<setw(20)<<std::left<<"Mediana\n";}
    isve<<"-------------------------------------------------------\n";
    for (int i=0; i<A.size(); i++)
    {
        isve<<setw(20)<<A[i].getVardas()<<setw(20)<<A[i].getPavarde();
        if (pasirinkimas == "G" || pasirinkimas == "g")
        {isve<<setw(20)<<std::setprecision(2)<<A[i].getGalutinis_egz()<<endl;}
        else{isve<<setw(20)<<mediana1(A[i].getPazymiai())<<endl;}
    }
    isve<<"\n\n";
}
