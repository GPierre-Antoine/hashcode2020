//
// Created by pierreantoine on 21/02/2020.
//

#include "bookset.h"
#include "../entities/book.h"


bookset::bookset(unsigned int expect)
{
    catalog.reserve(expect);
}
void bookset::add(score_t book_score)
{
    catalog.emplace_back(
            book{static_cast<book_id_t>(catalog.size()), book_score}
    );
}
book & bookset::operator[](unsigned int index)
{
    return catalog[index];
}
std::size_t bookset::size() const
{
    return catalog.size();
}

auto bookset::cbegin() const noexcept -> decltype(catalog.cbegin())
{
    return catalog.cbegin();
}

auto bookset::cend() const noexcept -> decltype(catalog.cend())
{
    return catalog.cend();
}

auto bookset::begin() noexcept -> decltype(catalog.begin())
{
    return catalog.begin();
}

auto bookset::end() noexcept -> decltype(catalog.end())
{
    return catalog.end();
}

