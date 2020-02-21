//
// Created by pierreantoine on 21/02/2020.
//

#include "bookset_statistics.h"
#include "../entities/book.h"


bookset_statistics::bookset_statistics(const bookset & b)
{
    score = basic_info_calculator<bookset::const_iterator, decltype([](book &)
    {
    };)>(b.catalog, [](const book & book)
    {
        return book.score;
    });
}
