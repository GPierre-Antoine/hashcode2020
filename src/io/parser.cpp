//
// Created by pierreantoine on 21/02/2020.
//

#include <istream>
#include "parser.h"


problem_instance parser::parse(std::istream & istream)
{
    unsigned int book_count;
    unsigned int libraries_count;
    unsigned int duration;
    istream >> book_count >> libraries_count >> duration;

    problem_instance instance(book_count, libraries_count, duration);

    while (book_count--)
    {
        score_t score;
        istream >> score;
        instance.books.add(score);
    }

    while (libraries_count)
    {
        unsigned int library_book_count;
        unsigned int registration_date;
        unsigned int books_per_day;
        istream >> library_book_count >> registration_date >> books_per_day;
        instance.libraries.add(library_book_count, registration_date, books_per_day);
        auto & library = instance.libraries[libraries_count];
        while (library_book_count)
        {
            unsigned int book_id;
            istream >> book_id;
            auto book = &instance.books[book_id];
            library.add(book);
            library_book_count -= 1;
        }
        library.compute_stats();
        libraries_count -= 1;
    }

    return instance;
}
