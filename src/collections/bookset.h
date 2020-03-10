//
// Created by pierreantoine on 21/02/2020.
//


#pragma once


#include <vector>
#include "../entities/def.h"
#include "../entities/book.h"


class bookset
{
    std::vector<book> catalog;
public:
    explicit bookset(unsigned int expect);
    void add(score_t book_score);
    book & operator[](unsigned int index);

    [[nodiscard]] std::size_t size() const;

    [[nodiscard]] auto cbegin() const noexcept -> decltype(catalog.cbegin());
    [[nodiscard]] auto cend() const noexcept -> decltype(catalog.cend());
    auto begin() noexcept -> decltype(catalog.begin());
    auto end() noexcept -> decltype(catalog.end());
};

