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
    token token;
    token = lexer::read_word(cin);
    while (token.first != token_type::eof)
    {
        switch (token.first)
        {
            case token_type::eof:
                break;
            case token_type::newline:
                std::cout << "newline" << endl;
                break;
            case token_type::space:
                std::cout << "space" << endl;
                break;
            case token_type::number:
                std::cout << "number<" << token.second << '>' << endl;
                break;
        }
        token = lexer::read_word(cin);
    }

    return 0;
}