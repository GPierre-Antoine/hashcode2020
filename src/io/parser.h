//
// Created by pierreantoine on 21/02/2020.
//


#pragma once


#include "../problem/problem_instance.h"


class parser
{
public:
    static problem_instance parse(std::istream & istream);
    static void parse_books(std::istream & istream, unsigned int book_count, problem_instance & instance);
};

