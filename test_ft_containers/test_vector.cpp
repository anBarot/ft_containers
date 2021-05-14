#include <iostream>
#include <vector>
#include "vector.hpp"
// #include "iterator.hpp"
#include <iterator>

template<class V>
void	display_vector(V &vec) 
{
	for (int i = 0; i + 1 < vec.size(); i++)
		std::cout << vec[i] << ", ";
	if (vec.size())
		std::cout << vec[vec.size() - 1] << std::endl;
	std::cout << "Size : " << vec.size() << std::endl;
	std::cout << "Capacity : " << vec.capacity() << std::endl;
	std::cout << "Empty ? " << " : " << vec.empty() << std::endl;
}

template<class V>
void	test_front_back(V &vec, std::string str)
{
	std::cout << "\nTesting front " << " - " << str << " :" << std::endl;
	std::cout << vec.front();
	std::cout << "\nTesting back " << " - " << str << " :" << std::endl;
	std::cout << vec.back();
}

template<class T, class V>
void	test_push_and_pop(V &vec, T value, std::string str)
{
	std::cout << "\nTesting push_back " << value << " - " << str << " :" << std::endl;
	vec.push_back(value);
	display_vector(vec);
	test_front_back(vec, "std_vec");
	std::cout << "\nTesting pop_back " << value << " - " << str << " :" << std::endl;
	vec.pop_back();
	display_vector(vec);
	test_front_back(vec, "std_vec");
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
	std::cout << "\nVector content std_vec :" << std::endl;
	display_vector(std_vec);
	std::cout << "\nVector content my_vec :" << std::endl;
	display_vector(my_vec);

	test_push_and_pop(std_vec, value, "std_vec");
	test_push_and_pop(my_vec, value, "my_vec");
	test_clear_empty(std_vec, "std_vec");
	test_clear_empty(my_vec, "my_vec");
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

int main()
{
	std::cout << "+++++++++++++++++ Test vector <string> +++++++++++++++++" << std::endl;
	test_vector_str();
	std::cout << "\n\n+++++++++++++++++ Test vector <int> +++++++++++++++++" << std::endl;
	test_vector_int();
	std::cout << "\n\n+++++++++++++++++ Test vector <float> +++++++++++++++++" << std::endl;
	test_vector_float();
}
