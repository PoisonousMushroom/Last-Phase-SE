#include "tokenizer.h"
#include <vector>
#include <sstream>
#include <iterator>
#include <iostream>

std::vector<std::string> tokens_in_vector(std::string args){
    std::cout<<"tokens in vectors\n";
    std::istringstream ss(args);
    std::string s;
    std::vector<std::string> vstrings;
    while (getline(ss, s, ' ')) {
        std::cout << s << std::endl;
        vstrings.push_back(s);
    }
    return vstrings;
    }