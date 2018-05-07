#include "tokenizer.h"
#include <vector>
#include <sstream>
#include <iterator>
#include <iostream>

std::vector<std::string> tokens_in_vector(std::string args){
    std::istringstream ss(args);
    std::string s;
    std::vector<std::string> vstrings;
    while (getline(ss, s, ' ')) {
        vstrings.push_back(s);
    }
    return vstrings;
}