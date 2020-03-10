//
// Created by pierreantoine on 21/02/2020.
//


#pragma once


#include <vector>
#include "../entities/library.h"


class library_set
{
private:
    std::vector<library> catalog;
public:
    explicit library_set(unsigned long expect);
    void add(
            library_id_t id, book_count_t book_count, duration_t registration_duration, books_per_day_t books_per_day
    );
    library & operator[](unsigned int index);
    auto begin() -> decltype(catalog.begin());
    auto end() -> decltype(catalog.end());
    [[nodiscard]] auto cbegin() -> decltype(catalog.cbegin());
    [[nodiscard]] auto cend() -> decltype(catalog.cend());
};

