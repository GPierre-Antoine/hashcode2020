//
// Created by pierreantoine on 21/02/2020.
//


#pragma once


#include <cstddef>
#include "../collections/book_set.h"
#include "../collections/library_set.h"


struct problem_instance
{
    problem_instance(unsigned long book_count, library_id_t libraries_count, duration_t duration);
    book_set books;
    library_set libraries;
    duration_t duration;
};

