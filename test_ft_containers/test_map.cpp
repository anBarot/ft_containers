#include <iostream>
#include <map>
#include <iterator>
#include "../map/map.hpp"

# define RESET   		"\033[0m"
# define RED     		"\033[31m"
# define GREEN   		"\033[32m"
# define YELLOW  		"\033[33m"
# define BLUE    		"\033[34m"
# define BOLDRED     	"\033[1m\033[31m"
# define BOLDGREEN   	"\033[1m\033[32m"
# define BOLDYELLOW  	"\033[1m\033[33m"
# define BOLDBLUE    	"\033[1m\033[34m"
# define COLOR(COL_VAL)	std::cout << COL_VAL;

template<class M>
void	display_map(M &map)
{
	typename M::iterator it_beg = map.begin();
	typename M::iterator it_end = --map.end();

	std::cout << it_beg->first << " , ";
	std::cout << it_beg->second << "\n";
	std::cout << it_end->first << " , ";
	std::cout << it_end->second << "\n";
	// for (typename M::iterator it = map.begin(); it != map.end(); ++it)
	// 	std::cout << it->first << " : " << it->second << "\n";
	// std::cout << "Size : " << map.size() << std::endl;
	// std::cout << "Max size : " << map.max_size() << std::endl;
	// std::cout << "Empty ? : " << map.empty() << "\n\n";
}

// void	test_insertmap_std(std::map<std::string, int> &map)
// {
// 	map.insert(std::make_pair("a", 1));
// 	map.insert(std::make_pair("b", 2));
// 	map.insert(std::make_pair("c", 3));
// }

// void	test_insertmap_ft(ft::Map<std::string, int> &map)
// {
// 	map.insert(ft::make_pair<std::string, int>("a", 1));
// 	map.insert(ft::make_pair<std::string, int>("b", 2));
// 	map.insert(ft::make_pair<std::string, int>("c", 3));
// }

void	test_insertmap_std_intint(std::map<int, int> &map)
{
	map.insert(std::make_pair(1, 2));
	map.insert(std::make_pair(3, 4));
	map.insert(std::make_pair(5, 6));
}

void	test_insertmap_ft_intint(ft::Map<int, int> &map)
{
	map.insert(ft::make_pair<int, int>(1, 2));
	std::cout << "insert 1 : " << map[1] << "\n";

	map.insert(ft::make_pair<int, int>(3, 4));
	std::cout << "insert 3 : " << map[3] << "\n";

	map.insert(ft::make_pair<int, int>(5, 6));
	std::cout << "insert 5 : " << map[5] << "\n";
}

// void	test_mapint()
// {
// 	std::map<std::string, int> std_map;
// 	ft::Map<std::string, int> ft_map;

// 	test_insertmap_std(std_map);
// 	COLOR(BOLDYELLOW) display_map(std_map);
// 	test_insertmap_ft(ft_map);
// 	COLOR(BOLDGREEN) display_map(ft_map);
// }

void	test_map_int_int()
{
	std::map<int, int> std_map;
	ft::Map<int, int> ft_map;

	test_insertmap_std_intint(std_map);
	COLOR(BOLDYELLOW) display_map(std_map);
	std::cout << "insert ft \n";
	test_insertmap_ft_intint(ft_map);
	// COLOR(BOLDGREEN) display_map(ft_map);
}

int main()
{
	std::cout << "Test map <string, int>\n";
	test_map_int_int();
	COLOR(RESET)
}
