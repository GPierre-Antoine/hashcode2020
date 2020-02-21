//
// Created by pierreantoine on 21/02/2020.
//

#include "book_set.h"


book_set::book_set(unsigned long expect)
{
    catalog.reserve(expect);
}
void book_set::add(std::size_t book_score)
{
    catalog.emplace_back(book{catalog.size(), book_score, 0, 0});
}

