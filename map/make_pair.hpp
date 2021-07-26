#if !defined(MAKE_PAIR_HPP)
#define MAKE_PAIR_HPP

#include "pair.hpp"

namespace ft
{
    template <class T1, class T2>
    ft::Pair<T1, T2> make_pair(const T1 &x, const T2 &y)
    {
        std::cout << "make pair function \n";
        return( ft::Pair<T1, T2>(x, y));
    }
}

#endif
