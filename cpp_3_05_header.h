#ifndef CPP_3_05_HEADER_H_INCLUDED
#define CPP_3_05_HEADER_H_INCLUDED

#include <iostream>
#include <deque>
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
    deque <float> hwm;
    string surname;
    string name;
    float examm;
    float average;
    float fpointsa;
    float fpointsm;
};

void mean(struct results *resultss);
void median(struct results *resultss);
void output1(deque <results> students);
bool sortfm(const results &a, const results &b);
void filegen(string fname,deque <results> &students,struct results resultss,int linenumber);
int firstntp(deque <results> &students);
void vsplitting(deque <results> &students,struct results &resultss,string &fname1,string &fname2,string &fname3,int linenumber);

#endif // CPP_3_05_HEADER_H_INCLUDED
