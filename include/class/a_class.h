// -*- compile-command: "make -sk"; -*-
// libbignum.h
//
// last-edit-by: <cyphix>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef A_CLASS_H
#define A_CLASS_H 1
class AnObject
{
private:
    int _member;


 public:
    AnObject();
    AnObject(double num);
    ~AnObject();
    void print();
    int get_value();
};


#endif // A_CLASS_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
