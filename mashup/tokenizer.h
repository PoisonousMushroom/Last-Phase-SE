/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <vector>
#include <sstream>
#include <iterator>

std::vector<std::string> tokens_in_vector(std::string args){
    std::stringstream ss(args);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end(ss);
    std::vector<std::string> vstrings(begin, end);
    return vstrings;
    }


#endif /* TOKENIZER_H */

