//
// Created by pierreantoine on 21/02/2020.
//

#include <istream>
#include <iostream>
#include "parser.h"


void flush(std::istream & istream)
{
    std::cerr << "\nExtra info :" << std::endl;
    std::string container;
    while (getline(istream, container))
    {
        std::cerr << container << "\n";
    }
}

problem_instance parser::parse(std::istream & istream)
{
    unsigned int book_count;
    library_id_t libraries_count;
    duration_t duration;
    istream >> book_count >> libraries_count >> duration;

    problem_instance instance(book_count, libraries_count, duration);

    parse_books(istream, book_count, instance);

    for (library_id_t library_id = 0; library_id < libraries_count; ++library_id)
    {
        unsigned int library_book_count;
        duration_t registration_duration;
        books_per_day_t books_per_day;
        istream >> library_book_count >> registration_duration >> books_per_day;
        instance.libraries.add(library_id, library_book_count, registration_duration, books_per_day);
        auto & library = instance.libraries[library_id];
        for (unsigned int item; item < library_book_count; ++item)
        {
            book_id_t book_id;
            istream >> book_id;
            library.add(&instance.books[book_id]);
        }
        library.compute_stats();
    }

    istream >> std::ws;

    auto next = istream.peek();
    if (next != EOF)
    {
        flush(istream);
        throw std::runtime_error("bad parsing");
    }

    return instance;
}
void parser::parse_books(std::istream & istream, unsigned int book_count, problem_instance & instance)
{
    while (book_count--)
    {
        score_t score;
        istream >> score;
        instance.books.add(score);
    }
}
