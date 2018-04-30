/* 
 * File:   WorldException.h
 */

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>

class Exception: public std::exception{
protected:
    std::string errorMessage;
public:
    explicit Exception(const char* errMsg):errorMessage(errMsg){};
    explicit Exception(const std::string errMsg):errorMessage(errMsg){};
    virtual ~Exception() throw(){};
    virtual const char* what() const throw (){
       return errorMessage.c_str();
    }
};

#endif /* EXCEPTION_H */

