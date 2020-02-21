//
// Created by pierreantoine on 21/02/2020.
//

#include "library_set.h"


library_set::library_set(unsigned long expect)
{
    catalog.reserve(expect);
}
void library_set::add(
        library_id_t id, book_count_t book_count, duration_t registration_duration, books_per_day_t books_per_day
)
{
    catalog.emplace_back(library{id, book_count, registration_duration, books_per_day});
    catalog[catalog.size() - 1].book_references.reserve(book_count);
}
library & library_set::operator[](unsigned int index)
{
    return catalog[index];
}
