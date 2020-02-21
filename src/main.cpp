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

int main(int argc, char **argv)
{
    std::vector<std::string> arguments(argv + 1, argv + argc);

    std::istream *ref = &cin;

    try
    {
        auto problem = parser::parse(*ref);
        std::cout << "there are " << problem.books.size() << " books\n";
    }
    catch (std::exception & e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}