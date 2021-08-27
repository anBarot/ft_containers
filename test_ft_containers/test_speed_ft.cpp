#include <iostream>
#include <iterator>
#include <time.h> 
#include "../map/map.hpp"
#include "../vector/vector.hpp"

void    test_vector_speed()
{
    ft::vector<int> ft_vec;

    for (size_t i = 0; i < 1000000000; i++)
        ft_vec.push_back(i);
}

void    test_map_speed()
{
    ft::map<int, int> ft_map;

    // for (size_t i = 1000; i < 100000; i++)
    //     ft_map.insert(ft::make_pair(i, rand()));
    for (size_t i = 0; i < 50; i++)
        ft_map.insert(ft::make_pair(i, rand()));
    for (size_t i = 50; i < 100; i++)
        ft_map.insert(ft::make_pair(i, rand()));
}

int main()
{
    srand (time(NULL));
    test_map_speed();
    test_vector_speed();

    return (0);
}
