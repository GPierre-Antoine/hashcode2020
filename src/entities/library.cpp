//
// Created by pierreantoine on 21/02/2020.
//

#include <numeric>
#include <iostream>
#include "library.h"


void library::add(book *book_ptr)
{
    book_references.emplace_back(book_ptr);
    book_ptr->references += 1;
}
void library::compute_stats()
{
    sum = std::accumulate(
            book_references.begin(), book_references.end(), 0, [](std::size_t total, book *book)
            {
                if (std::numeric_limits<std::size_t>::max() - book->score < total)
                {
                    throw std::runtime_error("sum overflow");
                }
                return total + book->score;
            }
    );
    mean = double(sum) / book_references.size();
}
