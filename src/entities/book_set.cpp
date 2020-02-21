//
// Created by pierreantoine on 21/02/2020.
//

#include "book_set.h"


book_set::book_set(unsigned int expect)
{
    catalog.reserve(expect);
}
void book_set::add(score_t book_score)
{
    catalog.emplace_back(
            book{static_cast<book_id_t>(catalog.size()), book_score}
    );
}
book & book_set::operator[](unsigned int index)
{
    return catalog[index];
}
std::size_t book_set::size() const
{
    return catalog.size();
}

