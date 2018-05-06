/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "exception.h"
#include "bug.h"

Exception::Exception(const char* msg){
    reason = msg;
}
const char* Exception::what() const throw(){
    return reason;
}