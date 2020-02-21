//
// Created by pierreantoine on 21/02/2020.
//

#include <iostream>
#include "lexer.h"


token lexer::read_word(std::istream & input)
{
    auto peek = input.peek();
    if (peek == EOF)
    {
        throw std::runtime_error("Unexpected EOF");
    }
    if (peek == 10)
    {
        input.get();
        return {token_type::newline, 0};
    }
    if (peek == 32)
    {
        input.get();
        return {token_type::space, 0};
    }
    std::size_t result;
    input >> result;
    return {token_type::number, result};
}