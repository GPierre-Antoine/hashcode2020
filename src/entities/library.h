//
// Created by pierreantoine on 21/02/2020.
//


#pragma once


#include <cstddef>
#include <vector>
#include "book.h"


struct library
{
    const unsigned int book_count;
    const unsigned int registration_duration;
    const unsigned int books_per_day;
    std::vector<book *> book_references;
    std::size_t sum;
    double mean;

    void compute_stats();
    void add(book *book_ptr);
};

