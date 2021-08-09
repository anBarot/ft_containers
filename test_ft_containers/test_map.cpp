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
	std::cout << "Display map :\n";

	for (typename M::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << it->first << " : " << it->second << "\n";

	std::cout << "Size : " << map.size() << std::endl;
	std::cout << "Max size : " << map.max_size() << std::endl;
	std::cout << "Empty ? : " << map.empty() << "\n\n";
}

void	test_insertmap_std_intint(std::map<int, int> &map)
{
	map.insert(std::make_pair(3, 4));
	map.insert(std::make_pair(1, 2));
	map.insert(std::make_pair(5, 6));
	map.insert(std::make_pair(7, 8));
}

void	test_insertmap_ft_intint(ft::map<int, int> &map)
{
	map.insert(ft::make_pair(3, 4));
	map.insert(ft::make_pair(1, 2));
	map.insert(ft::make_pair(5, 6));
	map.insert(ft::make_pair(7, 8));
}

void	test_insertmap_std_intstr(std::map<int, std::string> &map)
{
	map.insert(std::make_pair(3, "three"));
	map.insert(std::make_pair(1, "one"));
	map.insert(std::make_pair(5, "five"));
	map.insert(std::make_pair(7, "seven"));
}

void	test_insertmap_ft_intstr(ft::map<int, std::string> &map)
{
	map.insert(ft::make_pair<int, std::string>(3, "three"));
	map.insert(ft::make_pair<int, std::string>(1, "one"));
	map.insert(ft::make_pair<int, std::string>(5, "five"));
	map.insert(ft::make_pair<int, std::string>(7, "seven"));
}

template <class M>
void	test_find(M &map)
{
	std::cout << "\nfind 5 : " << (map.find(5))->second << "\n"; 
	std::cout << "find 6 : ";
	if (map.find(6) == map.end())
		std::cout << "Cannot find key 6\n"; 
	std::cout << "map count(5) : " << map.count(5) << "\n"; 
	std::cout << "map count(6) : " << map.count(6) << "\n"; 
	std::cout << "map[5] : " << map[5] << "\n"; 
	std::cout << "map[6] : " << map[6] << "\n"; 
	std::cout << "map count(5) : " << map.count(5) << "\n"; 
	std::cout << "map count(6) : " << map.count(6) << "\n"; 
}

template <class M>
void	test_erase_map(M &map)
{
	std::cout << "Test erase map 5 \n";
	map.erase(5);
	display_map(map);
}

void	test_map_int_int()
{
	std::map<int, int> std_map;
	ft::map<int, int> ft_map;

	COLOR(BOLDYELLOW) test_insertmap_std_intint(std_map);
	display_map(std_map);

	COLOR(BOLDGREEN) test_insertmap_ft_intint(ft_map);
	display_map(ft_map);

	COLOR(BOLDYELLOW) test_find(std_map);
	COLOR(BOLDGREEN) test_find(ft_map);

	COLOR(BOLDYELLOW) test_erase_map(std_map);
	COLOR(BOLDGREEN) test_erase_map(ft_map);
}

void	test_map_int_string()
{
	std::map<int, std::string> std_map;
	ft::map<int, std::string> ft_map;

	COLOR(BOLDYELLOW) test_insertmap_std_intstr(std_map);
	display_map(std_map);

	COLOR(BOLDGREEN) test_insertmap_ft_intstr(ft_map);
	display_map(ft_map);

	COLOR(BOLDYELLOW) test_erase_map(std_map);
	COLOR(BOLDGREEN) test_erase_map(ft_map);
}

template <class M>
void	test_plus_less(M &map)
{

	std::cout << "it begin++ loop :\n";

	for (typename M::iterator it_beg = map.begin(); it_beg != map.end(); it_beg++)
		std::cout << it_beg->first << " : " << it_beg->second << "\n";


	std::cout << "it end-- loop :\n";

	typename M::iterator it = map.end();
	
	it--;

	while (it-- != map.begin())
	{
		std::cout << it->first << " : " << it->second << "\n";
	}
}

template <class M>
void	test_plus_less_rev(M &map)
{

	std::cout << "\nit rbegin++ loop :\n";

	for (typename M::reverse_iterator it_beg = map.rbegin(); it_beg != map.rend(); it_beg++)
		std::cout << it_beg->first << " : " << it_beg->second << "\n";


	std::cout << "\nit rend-- loop :\n";

	typename M::reverse_iterator it = map.rend();

	while (--it != map.rbegin())
	{
		std::cout << it->first << " : " << it->second << "\n";
	}
	std::cout << it->first << " : " << it->second << "\n";
}

void	test_iterator()
{
	std::map<int, std::string> std_map;
	ft::map<int, std::string> ft_map;
	
	test_insertmap_std_intstr(std_map);
	test_insertmap_ft_intstr(ft_map);

	COLOR(BOLDYELLOW) test_plus_less(std_map);
	COLOR(BOLDGREEN) test_plus_less(ft_map);
}

void	test_reverse_iterator()
{
	std::map<int, std::string> std_map;
	ft::map<int, std::string> ft_map;
	
	test_insertmap_std_intstr(std_map);
	test_insertmap_ft_intstr(ft_map);

	COLOR(BOLDYELLOW) test_plus_less_rev(std_map);
	COLOR(BOLDGREEN) test_plus_less_rev(ft_map);
}

int main()
{
	COLOR(BLUE) std::cout << "Test map <int, int>\n";
	test_map_int_int();

	COLOR(BLUE) std::cout << "\nTest map <int, string>\n";
	test_map_int_string();

	COLOR(BLUE) std::cout << "\nTest iterator functions\n";
	test_iterator();

	COLOR(BLUE) std::cout << "\nTest reverse iterator functions\n";
	test_reverse_iterator();


	COLOR(RESET)
}
