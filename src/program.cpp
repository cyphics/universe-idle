// -*- compile-command: "./../compile.sh"; -*-

#include <libhello/french.h>
#include <libhello/english.h>
#include <class/a_class.h>

#include <iostream>
int main()
{
    std::cout << libhello::say_hello_in_french()  << "\n";
    std::cout << libhello::say_hello_in_english()  << "\n";

    AnObject a_num;
    a_num.print();

   return 0;
}
