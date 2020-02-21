//
// Created by pierreantoine on 21/02/2020.
//


#pragma once


#include <cstddef>
#include <numeric>
#include <iterator>
#include <cmath>


struct basic_info
{
    std::size_t size;
    std::size_t sum;
    double mean;
    double stddev;
};

template <typename iterator, typename lambda>
struct basic_info_calculator
{
    basic_info operator()(iterator begin, iterator end, lambda &&);
};

template <typename iterator, typename callable>
basic_info
basic_info_calculator<iterator, callable>::operator()(const iterator begin, const iterator end, callable && lambda)
{
    basic_info info{};
    info.size = std::distance(begin, end);
    info.sum = std::accumulate(begin, end, 0, lambda);
    info.mean = double(info.sum) / info.size;

    double accum = 0.0;
    std::for_each(
            begin, end, [&, info](const auto & value)
            {
                accum += std::pow(lambda(value) - info.mean, 2);
            }
    );

    info.stddev = std::sqrt(accum / double(info.size - 1));

    return info;
}
