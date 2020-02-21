//
// Created by pierreantoine on 21/02/2020.
//


#pragma once


#include <cstddef>
#include "basic_info.h"
#include "../collections/bookset.h"


struct bookset_statistics
{
    explicit bookset_statistics(const bookset & b);
    basic_info score;
    basic_info references;
};

