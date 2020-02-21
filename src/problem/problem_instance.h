//
// Created by pierreantoine on 21/02/2020.
//


#pragma once


#include <cstddef>
#include "../entities/book_set.h"
#include "../entities/library_set.h"


struct problem_instance
{
    problem_instance(unsigned long book_count, unsigned long libraries_count, unsigned long duration);
    book_set books;
    library_set libraries;
    unsigned int duration;
};

