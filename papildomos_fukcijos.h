#ifndef PAPILDOMOS_FUKCIJOS_H_INCLUDED
#define PAPILDOMOS_FUKCIJOS_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <stdexcept>
#include <limits>
#include <fstream>
#include "papildomos_fukcijos.h"
#include "funkcijos.h"
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
#pragma once


float mediana(vector<int> pazymiai);

float mediana1(vector<float> pazymiai);

bool isNumber(const string& str);

int sveikoSkaiciausPatikrinimas();

int studentuskaiciaustikrinimas();

void spausdinimas (vector<duomenys> A,string pasirinkimas, int p);



#endif // PAPILDOMOS_FUKCIJOS_H_INCLUDED
