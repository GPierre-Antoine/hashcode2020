//
// Created by pierreantoine on 21/02/2020.
//

#include <iterator>
#include "bookset_statistics.h"
#include "../entities/book.h"
#include "basic_info.h"


bookset_statistics::bookset_statistics(const bookset & b)
{
    score = basic_info_calculator<decltype(b.cbegin()), book>::extract(
            b.cbegin(), b.cend(), [&](const book & book)
            {
                return book.score;
            }
    );
    this->references = basic_info_calculator<decltype(b.cbegin()), book>::extract(
            b.cbegin(), b.cend(), [&](const book & book)
            {
                return book.references;
            }
    );
}
