#include <iostream>
#include <string>
#include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
#include <map>
#include <stack>
#include <vector>
#include "../vector/vector.hpp"
#include "../stack/stack.hpp"
#include "../map/map.hpp"

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT  (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->_container = rhs._container;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->GetContainer().begin(); }
	iterator end() { return this->GetContainer().end(); }
};

int main(int argc, char** argv) {

	std::cout << "Enter main.cpp\n";

	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	std::cout << "argc == 2\n";

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<int> > stack_deq_buffer;
	ft::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	std::cout << "count value : " << COUNT << "\n";

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	
	std::cout << "exception thrown OK\n";

	for (int i = 0; i < 20; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	std::cout << "map insert OK \n";

	int sum = 0;
	for (int i = 0; i < 20; i++)
	{
		int access = rand();
		sum += map_int[access];
	}

	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}

	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}

	std::cout << std::endl;
	return (0);
}
