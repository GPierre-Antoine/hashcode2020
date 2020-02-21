//
// Created by pierreantoine on 21/02/2020.
//


#pragma once


#include "lexer.h"


class parser
{
    lexer scanner;
public:

    explicit parser(lexer && scanner);
};

