//
// Created by pierreantoine on 21/02/2020.
//

#include <istream>
#include <iostream>
#include <tuple>
#include "parser.h"


template <typename T>
auto read_type(std::istream & is)
{
    T t;
    is >> t;
    return t;
}

void flush(std::istream & istream)
{
    std::cerr << "\nExtra info :" << std::endl;
    std::string container;
    while (getline(istream, container))
    {
        std::cerr << container << "\n";
    }
}

std::tuple<unsigned, library_id_t, duration_t> read_first_line(std::istream & is)
{
    auto book_count = read_type<unsigned>(is);
    auto libraries_count = read_type<library_id_t>(is);
    auto duration = read_type<duration_t>(is);
    return {book_count, libraries_count, duration};
}

void parse_library(problem_instance & instance, std::istream & istream, library_id_t library_id)
{
    auto library_book_count = read_type<unsigned>(istream);
    auto registration_duration = read_type<duration_t>(istream);
    auto books_per_day = read_type<books_per_day_t>(istream);
    instance.libraries.add(library_id, library_book_count, registration_duration, books_per_day);
    auto & library = instance.libraries[library_id];
    for (unsigned int item{}; item < library_book_count; ++item)
    {
        auto book_id = read_type<book_id_t>(istream);
        library.add(&instance.books[book_id]);
    }
}

problem_instance parser::parse(std::istream & istream)
{
    auto[book_count, libraries_count, duration] = read_first_line(istream);

    problem_instance instance(book_count, libraries_count, duration);

    parse_books(istream, book_count, instance);

    for (library_id_t library_id{}; library_id < libraries_count; ++library_id)
    {
        parse_library(instance, istream, library_id);
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
        instance.books.add(read_type<score_t>(istream));
    }
}
