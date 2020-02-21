//
// Created by pierreantoine on 21/02/2020.
//


#pragma once


#include <utility>


enum token_type
{
    number = 1, newline = 2, space = 3
};

typedef std::pair<token_type, std::size_t> token;