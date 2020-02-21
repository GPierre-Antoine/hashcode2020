//
// Created by pierreantoine on 21/02/2020.
//


#pragma once


#include <cstddef>


typedef unsigned short book_id;
typedef unsigned short score_t;

struct book
{
    const book_id id;
    const score_t score;
    unsigned int references;
    unsigned int read_on_day;
};

