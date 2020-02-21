//
// Created by pierreantoine on 21/02/2020.
//


#pragma once


#include <cstddef>
#include <numeric>
#include <iterator>
#include <cmath>
#include <vector>
#include <functional>


struct basic_info
{
    std::size_t size;
    std::size_t sum;
    double mean;
    double stddev;
};

template <typename iterator, typename closure>
struct basic_info_calculator
{
    basic_info operator()(iterator begin, iterator end, closure lambda);
};

template <typename iterator, typename closure>
basic_info basic_info_calculator<iterator, closure>::operator()(iterator begin, iterator end, closure lambda)
{
    basic_info info{};

    info.size = std::distance(begin, end);
    info.sum = std::accumulate(
            begin, end, 0, [lambda](std::size_t total, const auto & value)
            {
                std::size_t increment = lambda(value);
                if (std::numeric_limits<std::size_t>::max() - increment < total)
                {
                    throw std::runtime_error("sum overflow");
                }
                return total + increment;

            }
    );
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
