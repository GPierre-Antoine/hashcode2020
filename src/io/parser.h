//
// Created by pierreantoine on 21/02/2020.
//


#pragma once


#include "lexer.h"
#include "../problem/problem_instance.h"


class parser
{
public:
    static problem_instance parse(std::istream& istream);
};

