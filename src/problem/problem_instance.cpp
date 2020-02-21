//
// Created by pierreantoine on 21/02/2020.
//

#include "problem_instance.h"


problem_instance::problem_instance(
        const unsigned long book_count, const unsigned long libraries_count, const unsigned long duration
)
        : books(book_count), libraries(libraries_count), duration(duration)
{

}
