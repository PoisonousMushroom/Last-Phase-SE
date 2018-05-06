/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <exception>

using namespace std;
class Exception : public exception{
public:
    Exception(const char* msg);
    const char* what() const throw();
private:
    const char* reason;

};

#endif /* EXCEPTION_H */