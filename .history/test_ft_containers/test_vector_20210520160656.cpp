#include <iostream>
#include <vector>
#include <queue>
#include "vector.hpp"
// #include "iterator.hpp"
#include <iterator>

# define RESET   		"\033[0m"
# define RED     		"\033[31m"
# define GREEN   		"\033[32m"
# define YELLOW  		"\033[33m"
# define BLUE    		"\033[34m"
# define BOLDRED     	"\033[1m\033[31m"
# define BOLDGREEN   	"\033[1m\033[32m"
# define BOLDYELLOW  	"\033[1m\033[33m"
# define BOLDBLUE    	"\033[1m\033[34m"
# define out(val)		std::cout << val

template<class V>
void	display_vector(V &vec) 
{
	for (ft::Vector::Iterator &it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " - ";
	std::cout << "Size : " << vec.size() << std::endl;
	std::cout << "Capacity : " << vec.capacity() << std::endl;
	std::cout << "Empty ? " << " : " << vec.empty() << "\n\n";
}

template<class V>
void	test_front_back(V &vec, std::string str)
{
	std::cout << "Testing front " << " - " << str << " :" << std::endl;
	std::cout << vec.front() << "\n";
	std::cout << "Testing back " << " - " << str << " :" << std::endl;
	std::cout << vec.back() << "\n\n";
}

template<class T, class V>
void	test_push_and_pop(V &vec, T value, std::string str)
{
	std::cout << "Testing push_back " << value << " - " << str << " :" << std::endl;
	vec.push_back(value);
	display_vector(vec);
	test_front_back(vec, str);
	std::cout << "Testing pop_back " << value << " - " << str << " :" << std::endl;
	vec.pop_back();
	display_vector(vec);
	test_front_back(vec, str);
}

template<class V>
void	test_clear_empty(V &vec, std::string str)
{
	std::cout << "\nTesting clear " << " - " << str << " :" << std::endl;
	vec.clear();
	display_vector(vec);
}

template<class T, class V_1, class V_2>
void	test_vector(V_1 &std_vec, V_2 &my_vec, T value)
{
	std::cout << BOLDYELLOW;
	std::cout << "Vector content std_vec :" << std::endl;
	display_vector(std_vec);
	
	std::cout << BOLDGREEN;
	std::cout << "\nVector content my_vec :" << std::endl;
	display_vector(my_vec);

	out(BOLDYELLOW);
	test_push_and_pop(std_vec, value, "std_vec");
	std::cout << BOLDGREEN;
	test_push_and_pop(my_vec, value, "my_vec");
	std::cout << BOLDYELLOW;
	test_clear_empty(std_vec, "std_vec");
	std::cout << BOLDGREEN;
	test_clear_empty(my_vec, "my_vec");

	std::cout << RESET;
}

void	test_vector_str()
{
	std::vector<std::string> std_vec(3, "Hello");
	ft::Vector<std::string> my_vec(3, "Hello");

	test_vector(std_vec, my_vec, "Goodbuy");
}

void	test_vector_int()
{
	std::vector<int> std_vec(3, 5);
	ft::Vector<int> my_vec(3, 5);

	test_vector(std_vec, my_vec, 6);
}

void	test_vector_float()
{
	std::vector<float> std_vec(3, 45.7897);
	ft::Vector<float> my_vec(3, 45.7897);

	test_vector(std_vec, my_vec, 1.23456);
}

void	test_vector_queue()
{
	std::vector<int> std_vec(2, 12);
	ft::Vector<int> my_vec(2, 12);

	std::queue<int, std::vector<int>> std_queue(std_vec);
	std::queue<int, ft::Vector<int>> my_queue(my_vec);

	std::cout << BOLDYELLOW << "display content std vec:\n";
	display_vector(std_vec);
	std::cout << BOLDGREEN << "display content my vec :\n";
	display_vector(my_vec);

	std::cout << BOLDBLUE << "\nqueue push(5)\n\n";
	std_queue.push(5);
	my_queue.push(5);
	
	std::cout << BOLDYELLOW << "display content std vec:\n";
	display_vector(std_vec);
	std::cout << BOLDGREEN << "display content my vec :\n";
	display_vector(my_vec);

	std::cout << BOLDYELLOW << "Test std queue front back:\n";
	std::cout << std_queue.front() << "\n";
	std::cout << std_queue.back() << "\n";
	std::cout << BOLDGREEN << "Test my queue front back :\n";
	std::cout << my_queue.front() << "\n";
	std::cout << my_queue.back() << "\n";
}

int main()
{
	std::cout << "+++++++++++++++++ Test vector <string> +++++++++++++++++" << std::endl;
	test_vector_str();
	std::cout << "\n\n+++++++++++++++++ Test vector <int> +++++++++++++++++" << std::endl;
	test_vector_int();
	std::cout << "\n\n+++++++++++++++++ Test vector <float> +++++++++++++++++" << std::endl;
	test_vector_float();
	std::cout << "\n\n+++++++++++++++++ Test std::queue(vector) +++++++++++++++++" << std::endl;
	test_vector_queue();
}