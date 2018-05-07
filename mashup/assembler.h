#ifndef ASSEMBLER_H
#define ASSEMBLER_H
#include <string>

#include <vector>
#include "exception.h"
#include <numeric>
#include <valarray> //accumulate()

using namespace std;

void printvv(vector< vector<string> > v);

vector<std::string> split(string s, char delim);

string convert( char const* s, int i);
#endif