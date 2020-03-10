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

template <typename iterator, typename element>
struct basic_info_calculator
{
    static basic_info extract(iterator begin, iterator end, std::function<std::size_t(element)> lambda) noexcept;
};

template <typename iterator, typename element>
basic_info basic_info_calculator<iterator, element>::extract(
        iterator begin, iterator end, std::function<std::size_t(element)> lambda
) noexcept
{
    auto size = static_cast<std::size_t>(std::distance(begin, end));
    auto sum = static_cast<std::size_t>(std::accumulate(
            begin, end, 0, [lambda](std::size_t total, const element & value)
            {
                std::size_t increment = lambda(value);
                if (std::numeric_limits<std::size_t>::max() - increment < total)
                {
                    throw std::runtime_error("sum overflow");
                }
                return total + increment;

            }
    ));
    auto mean = double(sum) / size;

    auto accum = 0.0;
    std::for_each(
            begin, end, [&, mean](const auto & value)
            {
                accum += std::pow(lambda(value) - mean, 2);
            }
    );

    auto stddev = std::sqrt(accum / double(size - 1));

    return {size, sum, mean, stddev};
}
