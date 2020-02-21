//
// Created by pierreantoine on 21/02/2020.
//

#include <istream>
#include "parser.h"


problem_instance parser::parse(std::istream & istream)
{
    const auto book_count = istream.get();
    const auto libraries = istream.get();
    const auto duration = istream.get();

    return problem_instance(book_count, libraries, duration);
}
