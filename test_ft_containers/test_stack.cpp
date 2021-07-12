#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include "stack/stack.hpp"
#include "vector/vector.hpp"

# define RESET			"\033[0m"
# define RED     		"\033[31m"
# define GREEN   		"\033[32m"
# define YELLOW  		"\033[33m"
# define BLUE    		"\033[34m"
# define BOLDRED     	"\033[1m\033[31m"
# define BOLDGREEN   	"\033[1m\033[32m"
# define BOLDYELLOW  	"\033[1m\033[33m"
# define BOLDBLUE		"\033[1m\033[34m"
# define COLOR(COL_VAL)	std::cout << COL_VAL;

template<class S>
void	display_stack(S &stack)
{
	std::cout << stack.top() << "\n";
	std::cout << "Size : " << stack.size() << std::endl;
	std::cout << "Empty ? " << " : " << stack.empty() << "\n\n";
}

template<class S>
void	test_top(S &stack, std::string str)
{
	std::cout << "Testing top " << " - " << str << " :" << std::endl;
	std::cout << stack.top() << "\n";
}

template<class T, class S>
void	test_push_and_pop(S &stack, T value, std::string str)
{
	std::cout << "Testing push " << value << " - " << str << " :" << std::endl;
	stack.push(value);
	test_top(stack, str);
	std::cout << "Testing pop " << value << " - " << str << " :" << std::endl;
	stack.pop();
	test_top(stack, str);
}

template<class T, class V_1, class V_2>
void	test_stack(V_1 &std_stack, V_2 &my_stack , T value )
{
	COLOR(BOLDYELLOW) std::cout << "stack top content std_stack :" << std::endl;
	display_stack(std_stack);
	COLOR(BOLDGREEN) std::cout << "\nstack top content my_stack :" << std::endl;
	display_stack(my_stack);

	COLOR(BOLDYELLOW) test_push_and_pop(std_stack, value, "std_stack");
	COLOR(BOLDGREEN) test_push_and_pop(my_stack, value, "my_stack");

	COLOR(RESET);
}

void	test_stack_vector()
{
	std::vector<int> vec(5, 12);

	std::stack<int, std::vector<int> > std_stack(vec);
	ft::Stack<int, std::vector<int> > my_stack(vec);

	test_stack(std_stack, my_stack, 24);
}

int main()
{
	std::cout << "+++++++++++++++++ Test stack <vector> +++++++++++++++++" << std::endl;
	test_stack_vector();
	COLOR(RESET)
}
