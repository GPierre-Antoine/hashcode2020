//
// Created by pierreantoine on 21/02/2020.
//


#pragma once


#include <vector>
#include "../entities/def.h"
#include "../entities/book.h"


typedef std::vector<book> book_collection;

class bookset
{
    book_collection catalog;
public:
    typedef typename book_collection::const_iterator const_iterator;
    typedef typename book_collection::iterator iterator;

    explicit bookset(unsigned int expect);
    void add(score_t book_score);
    book & operator[](unsigned int index);

    [[nodiscard]] std::size_t size() const;

    [[nodiscard]] const_iterator cbegin() const noexcept;
    [[nodiscard]] const_iterator cend() const noexcept;

    [[nodiscard]] iterator begin() noexcept;
    [[nodiscard]] iterator end() noexcept;
};

