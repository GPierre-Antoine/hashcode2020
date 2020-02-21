//
// Created by pierreantoine on 21/02/2020.
//

#include <istream>
#include "parser.h"


problem_instance parser::parse(std::istream & istream)
{
    std::size_t book_count;
    std::size_t libraries;
    std::size_t duration;
    istream >> book_count >> libraries >> duration;

    problem_instance instance(book_count, libraries, duration);

    while (book_count--)
    {
        instance.books.add(istream.get());
    }

    return instance;
}
