//
// Created by pierreantoine on 21/02/2020.
//

#include <iostream>
#include <exception>
#include "io/parser.h"


using std::cout;
using std::cerr;
using std::runtime_error;
using std::cin;
using std::endl;

int main()
{

    auto && problem = parser::parse(cin);

    return 0;
}