#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include "../stack/stack.hpp"
#include "../vector/vector.hpp"

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
	std::cout << stack.top() << "\n\n";
}

template<class T, class S>
void	test_push_and_pop(S &stack, T value, std::string str)
{
	std::cout << "Testing push " << value << " - " << str << " :" << std::endl;
	stack.push(value);
	test_top(stack, str);
	std::cout << "Testing pop " <<  " - " << str << " :" << std::endl;
	stack.pop();
	test_top(stack, str);
}

template <class S>
void	push_things(S &st, int val)
{
	st.push(10 + val);
	st.push(20 + val);
	st.push(30 + val);
	st.push(40 + val);
} 

void 	test_comp_operator()
{
	std::vector<int> vec(5,5);

	std::stack<int, std::vector<int> > std_stack_one(vec);
	ft::stack<int, std::vector<int> > ft_stack_one(vec);
	std::stack<int, std::vector<int> > std_stack_two(vec);
	ft::stack<int, std::vector<int> > ft_stack_two(vec);

	push_things(std_stack_one, 0);
	push_things(ft_stack_one, 0);
	push_things(std_stack_two, 5);
	push_things(ft_stack_two, 5);

	COLOR(BOLDYELLOW)	std::cout << "Stack top std (one and two) : " << std_stack_one.top() << " - " << std_stack_two.top() << "\n";
	COLOR(BOLDGREEN)	std::cout << "Stack top ft (one and two) : " << ft_stack_one.top() << " - " << ft_stack_two.top() << "\n";

	COLOR(RED) std::cout << "\nswapping\n\n";

	swap(std_stack_one, std_stack_two);
	swap(ft_stack_one, ft_stack_two);
	
	COLOR(BOLDYELLOW)	std::cout << "Stack top std (one and two) : " << std_stack_one.top() << " - " << std_stack_two.top() << "\n";
	COLOR(BOLDGREEN)	std::cout << "Stack top ft (one and two) : " << ft_stack_one.top() << " - " << ft_stack_two.top() << "\n";

	COLOR(BLUE) std::cout << "\nComparison operator test :\n";
	COLOR(BOLDYELLOW)	std::cout << "Operator == std : " << (std_stack_one == std_stack_two) << "\n";
	COLOR(BOLDGREEN)	std::cout << "Operator == ft : " << (ft_stack_one == ft_stack_two) << "\n";
	COLOR(BOLDYELLOW)	std::cout << "Operator != std : " << (std_stack_one != std_stack_two) << "\n";
	COLOR(BOLDGREEN)	std::cout << "Operator != ft : " << (ft_stack_one != ft_stack_two) << "\n";
	COLOR(BOLDYELLOW)	std::cout << "Operator < std : " << (std_stack_one < std_stack_two) << "\n";
	COLOR(BOLDGREEN)	std::cout << "Operator < ft : " << (ft_stack_one < ft_stack_two) << "\n";
	COLOR(BOLDYELLOW)	std::cout << "Operator > std : " << (std_stack_one > std_stack_two) << "\n";
	COLOR(BOLDGREEN)	std::cout << "Operator > ft : " << (ft_stack_one > ft_stack_two) << "\n";
	COLOR(BOLDYELLOW)	std::cout << "Operator >= std : " << (std_stack_one >= std_stack_two) << "\n";
	COLOR(BOLDGREEN)	std::cout << "Operator >= ft : " << (ft_stack_one >= ft_stack_two) << "\n";
	COLOR(BOLDYELLOW)	std::cout << "Operator <= std : " << (std_stack_one <= std_stack_two) << "\n";
	COLOR(BOLDGREEN)	std::cout << "Operator <= ft : " << (ft_stack_one <= ft_stack_two) << "\n";
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
	ft::stack<int, std::vector<int> > my_stack(vec);

	std::cout << "Stack <int, vector<int>> created, vec(5, 12)\n";

	test_stack(std_stack, my_stack, 24);

}

int main()
{
	COLOR(BLUE) std::cout << "+++++++++++++++++ Test stack <vector> +++++++++++++++++" << std::endl;
	test_stack_vector();
	COLOR(BLUE) std::cout << "\nTest comparison op and swap :" << std::endl;
	test_comp_operator();
	COLOR(RESET)
}
