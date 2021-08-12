#include <iostream>
#include <vector>
#include <iterator>
#include "../vector/vector.hpp"

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

template<class V>
void	display_vector(V &vec)
{
	for (typename V::iterator it = vec.begin(); it + 1 < vec.end(); ++it)
		std::cout << *it << " - ";
	if (vec.size() > 0)
	{
		typename V::iterator it = vec.end() - 1;
		std::cout << *it << std::endl;
	}
	std::cout << "Size : " << vec.size() << std::endl;
	std::cout << "Max size : " << vec.max_size() << std::endl;
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
	test_front_back(vec, str);
	std::cout << "Testing pop_back " << value << " - " << str << " :" << std::endl;
	vec.pop_back();
	test_front_back(vec, str);
}

template<class T, class V>
void	test_assign(V &vec, T value, std::string str)
{
	std::cout << "Testing assign (3, " << value << ") - " << str << " :" << std::endl;
	vec.assign(3, value);
	display_vector(vec);

	std::cout << "Testing assign iterator(7, " << value << ") - " << str << " :" << std::endl;
	V vec_test(7, value);
	vec.assign(vec_test.begin(), vec_test.end());
	display_vector(vec);
}

template<class V>
void	test_clear_empty(V &vec, std::string str)
{
	std::cout << "\nTesting clear " << " - " << str << " :" << std::endl;
	vec.clear();
	display_vector(vec);
}

template<class T, class V>
void	test_insert_erase(V &vec, T value, std::string str)
{
	std::cout << "\nTesting insert (begin)" << " - " << str << std::endl;
	std::cout << *(vec.insert(vec.begin(), value)) << "\n";
	test_front_back(vec, str);
	std::cout << "\nTesting erase (begin)" << " - " << str << std::endl;
	std::cout << *(vec.erase(vec.begin())) << "\n";
	test_front_back(vec, str);
}

template<class V, class T>
void	test_riterator(V &vec, std::string str, T value)
{
	std::cout << "Testing reverse iterator" << " - " << str << std::endl;

	vec[1] = value;
	// vec.insert(vec.begin(), value);
	for (typename V::reverse_iterator it = vec.rbegin(); it + 1 != vec.rend(); ++it)
		std::cout << *it << " - ";
	if (vec.size() > 0)
	{
		typename V::reverse_iterator it = vec.rend() - 1;
		std::cout << *it << std::endl;
	}
}

template<class T, class V_1, class V_2>
void	test_vector(V_1 &std_vec, V_2 &my_vec , T value, T value_two)
{
	COLOR(BOLDYELLOW) std::cout << "Vector content std_vec :" << std::endl;
	display_vector(std_vec);
	COLOR(BOLDGREEN) std::cout << "\nVector content my_vec :" << std::endl;
	display_vector(my_vec);

	COLOR(BOLDYELLOW) test_push_and_pop(std_vec, value, "std_vec");
	COLOR(BOLDGREEN) test_push_and_pop(my_vec, value, "my_vec");
	
	COLOR(BOLDYELLOW) std::cout << "Vector content std_vec :" << std::endl;
	display_vector(std_vec);
	COLOR(BOLDGREEN) std::cout << "\nVector content my_vec :" << std::endl;
	display_vector(my_vec);

	COLOR(BOLDYELLOW) test_insert_erase(std_vec, value, "std_vec");
	COLOR(BOLDGREEN) test_insert_erase(my_vec, value, "my_vec");

	COLOR(BOLDYELLOW) test_clear_empty(std_vec, "std_vec");
	COLOR(BOLDGREEN) test_clear_empty(my_vec, "my_vec");

	COLOR(BOLDYELLOW) test_assign(std_vec, value, "std_vec");
	COLOR(BOLDGREEN) test_assign(my_vec, value, "my_vec");

	COLOR(BOLDYELLOW) test_riterator(std_vec, "std_vec", value_two);
	COLOR(BOLDGREEN) test_riterator(my_vec, "my_vec", value_two);

	std::cout << RESET;
}

void	test_vector_str()
{
	std::vector<std::string> std_vec(3, "Hello");
	ft::vector<std::string> my_vec(3, "Hello");

	test_vector(std_vec, my_vec, "Goodbuy", "Hello");
}

void	test_vector_int()
{
	std::vector<int> std_vec(3, 12);
	ft::vector<int> my_vec(3, 12);

	test_vector(std_vec, my_vec, 6, 42);
}

void	test_vector_float()
{
	std::vector<float> std_vec(3, 45.7897);
	ft::vector<float> my_vec(3, 45.7897);

	test_vector(std_vec, my_vec, 1.23456, 42.4242);
}

void	test_swap()
{
	std::vector<int> std_vec_one(3, 12);
	ft::vector<int> ft_vec_one(3, 12);
	std::vector<int> std_vec_two(3, 50);
	ft::vector<int> ft_vec_two(3, 50);

	COLOR(BOLDYELLOW) std::cout << "Std vec content :\n";
	display_vector(std_vec_one);
	COLOR(BOLDGREEN) std::cout << "My vec content :\n";
	display_vector(ft_vec_one);

	std_vec_one.swap(std_vec_two);
	ft_vec_one.swap(ft_vec_two);

	COLOR(BOLDYELLOW) std::cout << "Std vec content after swap:\n";
	display_vector(std_vec_one);
	COLOR(BOLDGREEN) std::cout << "My vec content after swap:\n";
	display_vector(ft_vec_one);

	std_vec_one[0] = std_vec_two[0];
	std_vec_one[1] = 0;
	ft_vec_one[0] = ft_vec_two[0];
	ft_vec_one[1] = 0;
	display_vector(ft_vec_one);
	display_vector(ft_vec_two);

	COLOR(BLUE)	std::cout << "Test comparison operator \n";

	COLOR(BOLDYELLOW)	std::cout << "Operator == std : " << (std_vec_one == std_vec_two) << "\n";
	COLOR(BOLDGREEN)	std::cout << "Operator == ft : " << (ft_vec_one == ft_vec_two) << "\n";
	COLOR(BOLDYELLOW)	std::cout << "Operator != std : " << (std_vec_one != std_vec_two) << "\n";
	COLOR(BOLDGREEN)	std::cout << "Operator != ft : " << (ft_vec_one != ft_vec_two) << "\n";
	COLOR(BOLDYELLOW)	std::cout << "Operator < std : " << (std_vec_one < std_vec_two) << "\n";
	COLOR(BOLDGREEN)	std::cout << "Operator < ft : " << (ft_vec_one < ft_vec_two) << "\n";
	COLOR(BOLDYELLOW)	std::cout << "Operator > std : " << (std_vec_one > std_vec_two) << "\n";
	COLOR(BOLDGREEN)	std::cout << "Operator > ft : " << (ft_vec_one > ft_vec_two) << "\n";
	COLOR(BOLDYELLOW)	std::cout << "Operator >= std : " << (std_vec_one >= std_vec_two) << "\n";
	COLOR(BOLDGREEN)	std::cout << "Operator >= ft : " << (ft_vec_one >= ft_vec_two) << "\n";
	COLOR(BOLDYELLOW)	std::cout << "Operator <= std : " << (std_vec_one <= std_vec_two) << "\n";
	COLOR(BOLDGREEN)	std::cout << "Operator <= ft : " << (ft_vec_one <= ft_vec_two) << "\n";
}

int main()
{
	std::cout << "+++++++++++++++++ Test vector <string> +++++++++++++++++" << std::endl;
	test_vector_str();
	std::cout << "\n\n+++++++++++++++++ Test vector <int> +++++++++++++++++" << std::endl;
	test_vector_int();
	std::cout << "\n\n+++++++++++++++++ Test vector <float> +++++++++++++++++" << std::endl;
	test_vector_float();
	std::cout << "\n\n+++++++++++++++++ Test swap +++++++++++++++++" << std::endl;
	test_swap();

	COLOR(RESET)
}
