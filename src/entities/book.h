//
// Created by pierreantoine on 21/02/2020.
//


#pragma once


#include <cstddef>


struct book
{
    const std::size_t id;
    const std::size_t score;
    std::size_t references;
    std::size_t read_on_day;
};

