//
// Created by pierreantoine on 21/02/2020.
//

#include "problem_instance.h"


problem_instance::problem_instance(
        const unsigned long book_count, const library_id_t libraries_count, const duration_t duration
)
        : books(book_count), libraries(libraries_count), duration(duration)
{

}
