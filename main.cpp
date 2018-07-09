#include <bits/stdc++.h>
#include <boost/static_assert.hpp>

// Реализовать constexpr функцию bin_id - определения ближайшей большей степени двойки
namespace {
    constexpr auto bin_id_c14(size_t x) noexcept { //C++14

        size_t exponent = 0;

        if (not(x && !(x & (x - 1))) and x != 0) exponent++;

        while (x = (x >> 1)) {
            ++exponent;
        }

        return exponent;
    }

    constexpr size_t if_is_degree_of_two(size_t x) noexcept {

        return ((x && !(x & (x - 1))) or x == 0) ? true : false;
    }


    constexpr size_t sum_of_exponent(size_t x, size_t exponent = 0) noexcept {

        return (x = (x >> 1)) ? sum_of_exponent(x, ++exponent) : exponent;
    }


    constexpr auto bin_id(size_t x) noexcept { //C++11


        return if_is_degree_of_two(x) ? sum_of_exponent(x, 0) : sum_of_exponent(x, 1);

    }


    BOOST_STATIC_ASSERT(bin_id(0) == 0);
    BOOST_STATIC_ASSERT(bin_id(1) == 0);
    BOOST_STATIC_ASSERT(bin_id(2) == 1);
    BOOST_STATIC_ASSERT(bin_id(4) == 2);
    BOOST_STATIC_ASSERT(bin_id(7) == 3);
    BOOST_STATIC_ASSERT(bin_id(8) == 3);
    BOOST_STATIC_ASSERT(bin_id(9) == 4);
    BOOST_STATIC_ASSERT(bin_id(1023) == 10);
    BOOST_STATIC_ASSERT(bin_id(1024) == 10);
    BOOST_STATIC_ASSERT(bin_id(1025) == 11);
    BOOST_STATIC_ASSERT(bin_id(1024 * 1024 - 33) == 20);
    BOOST_STATIC_ASSERT(bin_id(1024 * 1024) == 20);
    BOOST_STATIC_ASSERT(bin_id(1024 * 1024 + 33) == 21);
    BOOST_STATIC_ASSERT(bin_id(1024 * 1024 * 1024 - 127) == 30);
    BOOST_STATIC_ASSERT(bin_id(1024 * 1024 * 1024) == 30);
    BOOST_STATIC_ASSERT(bin_id(1024 * 1024 * 1024 + 127) == 31);

}

int main() {
    size_t n;

    while (std::cin >> n)
        std::cout << bin_id(n) << std::endl;

    return 0;
}