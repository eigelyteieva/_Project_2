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

 void paskirstymas(vector<duomenys>&A,int p,vector<duomenys> &vargsiukai, vector<duomenys> &kietekai)
{
    int vargs=0;
    int kiete=0;
    for (int i=0; i<p; i++)
    {
        if(A[i].getGalutinis_egz() < 5.00)
        {
            vargsiukai.resize(vargs+1);
            vargsiukai[vargs] = A[i];
            vargs++;
        }
        else
        {
            kietekai.resize(kiete+1);
            kietekai[kiete] = A[i];
            kiete++;
        }
    }
}
void paskirstymo_isve(vector<duomenys> vargsiukai, vector<duomenys> kietekai, string pasirinkimas)
{
    std::ofstream duom_maz5("vargsiukai.txt");
    std::ofstream duom_daug5("kietekai.txt");

        duom_maz5<<setw(20)<<std::left<<"Vardas"<<setw(20)<<std::left<<"Pavarde";
        if (pasirinkimas == "G" || pasirinkimas == "g")
        {duom_maz5<<setw(20)<<std::left<<"Galutinis(egz.)\n";}
        else{duom_maz5<<setw(20)<<std::left<<"Mediana\n";}
        duom_maz5<<"-------------------------------------------------------\n";
        for (int i=0; i<vargsiukai.size(); i++)
    {
        duom_maz5<<setw(20)<<vargsiukai[i].getVardas()<<setw(20)<<vargsiukai[i].getPavarde();
        if (pasirinkimas == "G" || pasirinkimas == "g")
        {duom_maz5<<setw(20)<<std::setprecision(2)<<vargsiukai[i].getGalutinis_egz()<<endl;}
        else{duom_maz5<<setw(20)<<mediana1(vargsiukai[i].getPazymiai())<<endl;}
    }
        duom_maz5<<"\n\n";
        duom_maz5.close();


        duom_daug5<<setw(20)<<std::left<<"Vardas"<<setw(20)<<std::left<<"Pavarde";
        if (pasirinkimas == "G" || pasirinkimas == "g")
        {duom_daug5<<setw(20)<<std::left<<"Galutinis(egz.)\n";}
        else{duom_daug5<<setw(20)<<std::left<<"Mediana\n";}
        duom_daug5<<"-------------------------------------------------------\n";

        for (int i=0; i<kietekai.size(); i++)
    {
        duom_daug5<<setw(20)<<kietekai[i].getVardas()<<setw(20)<<kietekai[i].getPavarde();
        if (pasirinkimas == "G" || pasirinkimas == "g")
        {duom_daug5<<setw(20)<<std::setprecision(2)<<kietekai[i].getGalutinis_egz()<<endl;}
        else{duom_daug5<<setw(20)<<mediana1(kietekai[i].getPazymiai())<<endl;}
    }
        duom_daug5<<"\n\n";
        duom_daug5.close();


}
void duokiteRinktis(int &p, string &pasirinkimas, int &paz){
    int failo_pasirinkimas;
    cout<<"Pasirinkite, kurio dydzio faila noresite nuskaityti: 1 - 1000 duomenu, 2 - 10 000 duomenu, 3 - 100 000 duomenu, 4 - 1 000 000 duomenu, 5 - 10 000 000 duomenu"<<endl;
    cin>>failo_pasirinkimas;

    if (failo_pasirinkimas == 1) { p = 1000;}
    else if (failo_pasirinkimas == 2) {p = 10000;}
    else if (failo_pasirinkimas == 3) {p = 100000;}
    else if (failo_pasirinkimas == 4) {p = 1000000;}
    else if (failo_pasirinkimas == 5) {p = 10000000;}
    else {cout<<"Ivedete neteisinga simboli"<<endl;}

    cout<<"Jeigu norite matyti galutini egzamino pazymi spauskite G, jeigu mediana - M"<<endl;
    cin>>pasirinkimas;
    if ((pasirinkimas != "G") && (pasirinkimas != "g") && (pasirinkimas != "M") && (pasirinkimas != "m") )
    {
        cout<<"Ivedete netinkama simboli"<<endl;
        cout<<"Jeigu norite matyti galutini egzamino pazymi spauskite G, jeigu mediana - M";
        cin>>pasirinkimas;
    }
    cout<<"Iveskite kiek pazymiu yra faile"<<endl;
    cin>>paz;

}

int main()
{

    vector<duomenys> A;
    string duom_pasirinkimas,pasirinkimas;
    int p;
    int n;
    int paz;
    int B;
    int C;
    cout<<"Jeigu norite duomenis ivesti rankiniu butu spauskite R,jeigu norite, kad duomenys sugeneruotu atsitiktinai i faila spauskite F";
    cin>>duom_pasirinkimas;
    if ((duom_pasirinkimas != "R") && (duom_pasirinkimas != "r") && (duom_pasirinkimas != "F") && (duom_pasirinkimas != "f"))
    {
        cout<<"Ivedete netinkama simboli"<<endl;
        cout<<"Jeigu norite duomenis ivesti rankiniu butu spauskite R,jeigu norite, kad duomenys sugeneruotu atsitiktinai spauskite A";
        cin>>duom_pasirinkimas;
    }

    std::clock_t start, all;
    if (duom_pasirinkimas == "R" || duom_pasirinkimas == "r")
    {
        A=duom_rankinis(A,p,pasirinkimas);
        spausdinimas(A,pasirinkimas,p);

    start=std::clock();

    vector<duomenys> varg;
    vector<duomenys> kiete;


    paskirstymas(A,B,varg,kiete);
    double duration=(std::clock() - start) /(double)CLOCKS_PER_SEC;
    cout<<"Skirstymas uztruko"<<duration<<"s"<<endl;

    start=std::clock();
    paskirstymo_isve(varg,kiete);
    duration=(std::clock() - start) /(double)CLOCKS_PER_SEC;
    cout<<"Isvedimas uztruko"<<duration<<"s"<<endl;
    }
    else
    {

        duokiteRinktis(B,pasirinkimas,paz);

    start=std::clock();

    skaitymas(A,B,paz);

    double duration = (std::clock() - start)/(double)CLOCKS_PER_SEC;
    cout<<"SKAITYMAS UZTRUKO"<<duration<<"s"<<endl;

    start=std::clock();

    vector<duomenys> varg;
    vector<duomenys> kiete;

    paskirstymas(A,B,varg,kiete);

    duration=(std::clock() - start) /(double)CLOCKS_PER_SEC;
    cout<<"Skirstymas uztruko"<<duration<<"s"<<endl;

    paskirstymo_isve(varg,kiete);

    }

    cout<<":)"<<endl;

    return 0;

}
