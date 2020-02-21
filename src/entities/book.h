//
// Created by pierreantoine on 21/02/2020.
//


#pragma once


#include <cstddef>


typedef unsigned short book_id_t;
typedef unsigned short score_t;

struct book
{
    const book_id_t id;
    const score_t score;
    unsigned references{};
    unsigned read_on_day{};
};

