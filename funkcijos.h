#ifndef FUNKCIJOS_H_INCLUDED
#define FUNKCIJOS_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <stdexcept>
#include <limits>
#include <fstream>
#include <fstream>
#include <vector>
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
#pragma once


#include "papildomos_funkcijos.h"
#include "klase.h"


vector<duomenys> duom_rankinis (vector<duomenys> A,int &p, string &pasirinkimas);

void skaitymas(vector<duomenys>& A,int p, int paz);


#endif // FUNKCIJOS_H_INCLUDED

