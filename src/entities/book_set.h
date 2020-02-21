//
// Created by pierreantoine on 21/02/2020.
//


#pragma once


#include <vector>
#include "book.h"


class book_set
{
    std::vector<book> catalog;
public:
    explicit book_set(unsigned long expect);
    void add(std::size_t book_score);
};

