//
// Created by pierreantoine on 21/02/2020.
//


#pragma once


#include <vector>
#include "../entities/book.h"


class bookset
{
    std::vector<book> catalog;
public:
    explicit bookset(unsigned int expect);
    void add(score_t book_score);
    book & operator[](unsigned int index);
    std::size_t size() const;
};

