#ifndef CPP_3_05_HEADER_H_INCLUDED
#define CPP_3_05_HEADER_H_INCLUDED

#include <iostream>
#include <vector>
#include <string.h>
#include <numeric>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <chrono>

using namespace std;

struct results
{
    string surname;
    string name;
    vector <float> hwm;
    float examm;
    float average;
    float fpointsa;
    float fpointsm;
};

void random(struct results *resultss);
void mean(struct results *resultss);
void median(struct results *resultss);
bool sortname(const results &a, const results &b);
bool sortfm(const results &a, const results &b);
void filegen(string fname, vector <results> &students,struct results resultss,int number);
int firstntp(vector <results> &students);
void vsplitting(vector <results> &students,  struct results &resultss, string &fname1, string &fname2, string &fname3, int &number);

#endif // CPP_3_05_HEADER_H_INCLUDED
