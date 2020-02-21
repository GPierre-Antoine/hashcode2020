//
// Created by pierreantoine on 21/02/2020.
//


#pragma once


#include <algorithm>
#include <istream>
#include "word.h"


class lexer
{
public:
    static token read_word(std::istream & input);
};

