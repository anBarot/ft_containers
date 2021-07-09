#include <iostream>
#include <stack>
#include <iterator>
#include "stack.hpp"

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

template<class S>
void	display_stack(S &stack)
{
	for (typename S::iterator it = stack.begin(); it + 1 < stack.end(); ++it)
		std::cout << *it << " - ";
	if (stack.size() > 0)
	{
		typename S::iterator it = stack.end() - 1;
		std::cout << *it << std::endl;
	}
	std::cout << "Size : " << stack.size() << std::endl;
	std::cout << "Max size : " << stack.max_size() << std::endl;
	std::cout << "Capacity : " << stack.capacity() << std::endl;
	std::cout << "Empty ? " << " : " << stack.empty() << "\n\n";
}

template<class S>
void	test_front_back(S &stack, std::string str)
{
	std::cout << "Testing front " << " - " << str << " :" << std::endl;
	std::cout << stack.front() << "\n";
	std::cout << "Testing back " << " - " << str << " :" << std::endl;
	std::cout << stack.back() << "\n\n";
}

template<class T, class S>
void	test_push_and_pop(S &stack, T value, std::string str)
{
	std::cout << "Testing push_back " << value << " - " << str << " :" << std::endl;
	stack.push_back(value);
	test_front_back(stack, str);
	std::cout << "Testing pop_back " << value << " - " << str << " :" << std::endl;
	stack.pop_back();
	test_front_back(stack, str);
}

template<class S>
void	test_clear_empty(S &stack, std::string str)
{
	std::cout << "\nTesting clear " << " - " << str << " :" << std::endl;
	stack.clear();
	display_stack(stack);
}

template<class T, class S>
void	test_insert_erase(S &stack, T value, std::string str)
{
	std::cout << "\nTesting insert (begin)" << " - " << str << std::endl;
	std::cout << *(stack.insert(stack.begin(), value)) << "\n";
	test_front_back(stack, str);
	std::cout << "\nTesting erase (begin)" << " - " << str << std::endl;
	std::cout << *(stack.erase(stack.begin())) << "\n";
	test_front_back(stack, str);
}

template<class T, class V_1, class V_2>
void	test_stack(V_1 &std_stack, V_2 &my_stack , T value )
{
	COLOR(BOLDYELLOW) std::cout << "stack content std_stack :" << std::endl;
	display_stack(std_stack);
	COLOR(BOLDGREEN) std::cout << "\nstack content my_stack :" << std::endl;
	display_stack(my_stack);

	COLOR(BOLDYELLOW) test_push_and_pop(std_stack, value, "std_stack");
	COLOR(BOLDGREEN) test_push_and_pop(my_stack, value, "my_stack");
	
	COLOR(BOLDYELLOW) std::cout << "stack content std_stack :" << std::endl;
	display_stack(std_stack);
	COLOR(BOLDGREEN) std::cout << "\nstack content my_stack :" << std::endl;
	display_stack(my_stack);

	COLOR(BOLDYELLOW) test_insert_erase(std_stack, value, "std_stack");
	COLOR(BOLDGREEN) test_insert_erase(my_stack, value, "my_stack");

	COLOR(BOLDYELLOW) test_clear_empty(std_stack, "std_stack");
	COLOR(BOLDGREEN) test_clear_empty(my_stack, "my_stack");

	std::cout << RESET;
}

void	test_stack_str()
{
	std::stack<std::string> std_stack();
	ft::stack<std::string> my_stack();

	test_stack(std_stack, my_stack, "Goodbuy");
}

void	test_stack_int()
{
	std::stack<int> std_stack(3, 12);
	ft::stack<int> my_stack(3, 12);

	test_stack(std_stack, my_stack, 6);
}

void	test_stack_float()
{
	std::stack<float> std_stack(3, 45.7897);
	ft::stack<float> my_stack(3, 45.7897);

	test_stack(std_stack, my_stack, 1.23456);
}

int main()
{
	std::cout << "+++++++++++++++++ Test stack <string> +++++++++++++++++" << std::endl;
	test_stack_str();
	std::cout << "\n\n+++++++++++++++++ Test stack <int> +++++++++++++++++" << std::endl;
	test_stack_int();
	std::cout << "\n\n+++++++++++++++++ Test stack <float> +++++++++++++++++" << std::endl;
	test_stack_float();
	COLOR(RESET)
}
