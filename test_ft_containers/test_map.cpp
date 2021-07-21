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
	for (typename M::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << it->first << " : " << it->second << "\n";
	std::cout << "Size : " << map.size() << std::endl;
	std::cout << "Max size : " << map.max_size() << std::endl;
	std::cout << "Empty ? : " << map.empty() << "\n\n";
}

void	test_insertmap_std(std::map<std::string, int> &map)
{
	map.insert(std::make_pair("a", 1));
	map.insert(std::make_pair("b", 2));
	map.insert(std::make_pair("c", 3));
}

void	test_insertmap_ft(ft::Map<std::string, int> &map)
{
	map.insert(ft::make_pair("a", 1));
	map.insert(ft::make_pair("b", 2));
	map.insert(ft::make_pair("c", 3));
}

void	test_mapint()
{
	std::map<std::string, int> std_map;
	ft::Map<std::string, int> ft_map;

	test_insertmap_std(std_map);
	COLOR(BOLDYELLOW) display_map(std_map);
	test_insertmap_ft(ft_map);
	COLOR(BOLDGREEN) display_map(ft_map);
}

int main()
{
	std::cout << "Test map <string, int>\n";
	test_mapint();
	COLOR(RESET)
}
