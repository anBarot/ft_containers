#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <time.h> 

void    test_vector_speed()
{
    std::vector<int> std_vec;

    for (size_t i = 0; i < 1000000000; i++)
        std_vec.push_back(i);
}

void    test_map_speed()
{
    std::map<int, int> std_map;

    for (size_t i = 0; i < 1000; i++)
        std_map.insert(std::make_pair(i, rand()));
}

int main()
{
    srand (time(NULL));
    test_map_speed();
    test_vector_speed();

    return (0);
}
