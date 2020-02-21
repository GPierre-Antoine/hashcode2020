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
    explicit book_set(unsigned int expect);
    void add(score_t book_score);
    book & operator[](unsigned int index);
    std::size_t size() const;
};

