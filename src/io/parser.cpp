//
// Created by pierreantoine on 21/02/2020.
//

#include <istream>
#include "parser.h"


problem_instance parser::parse(std::istream & istream)
{
    auto book_count = istream.get();
    const auto libraries = istream.get();
    const auto duration = istream.get();

    problem_instance instance(book_count, libraries, duration);

    while (book_count--)
    {
        instance.books.add(istream.get());
    }

    return instance;
}
