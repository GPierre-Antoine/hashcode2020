//
// Created by pierreantoine on 21/02/2020.
//


#pragma once


#include <cstddef>
#include "def.h"


struct book
{
    const book_id_t id{};
    const score_t score{};
    unsigned references{};
    unsigned read_on_day{};
};

