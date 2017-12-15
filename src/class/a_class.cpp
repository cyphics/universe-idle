// -*- compile-command: "make -sk"; -*-
// libbignum.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include "../../include/class/a_class.h"

//////////////////////////////////////////////////////////////////////
// $Log:$
//

AnObject::AnObject(){
    _member = 0;
}

AnObject::AnObject(double num_value){
    _member = num_value;
}


AnObject::~AnObject(){}

void AnObject::print(){
    std::cout << "object of value " << _member << "\n";
}

int AnObject::get_value(){
    return _member;
}
