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
            book{static_cast<score_t>(catalog.size()), book_score, 0, 0}
    );
}
book & book_set::operator[](unsigned int index)
{
    return catalog[index];
}

