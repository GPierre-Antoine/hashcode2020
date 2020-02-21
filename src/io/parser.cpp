//
// Created by pierreantoine on 21/02/2020.
//

#include "parser.h"


problem_instance parser::parse(std::istream & istream)
{
    const auto book_count = lexer::read_word(istream).second;
    istream >> std::ws;
    const auto libraries = lexer::read_word(istream).second;
    istream >> std::ws;
    const auto duration = lexer::read_word(istream).second;

    return problem_instance(book_count, libraries, duration);
}
