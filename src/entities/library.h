//
// Created by pierreantoine on 21/02/2020.
//


#pragma once


#include <cstddef>
#include <vector>
#include "book.h"


typedef unsigned short library_id_t;
typedef unsigned short book_count_t;
typedef unsigned short duration_t;
typedef unsigned short books_per_day_t;

struct library
{
    const library_id_t id;
    const book_count_t book_count;
    const duration_t registration_duration;
    const books_per_day_t books_per_day;
    std::vector<book *> book_references{};
    std::size_t sum{0};
    double mean{0};

    void compute_stats();
    void add(book *book_ptr);
};

