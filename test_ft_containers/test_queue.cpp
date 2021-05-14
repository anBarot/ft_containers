#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include "vector.hpp"
#include "queue.hpp"
// #include "iterator.hpp"
#include <iterator>

template<class V>
void	display_queue(V &queue) 
{
	int size = queue.size();

	while (!queue.empty())
	{
		std::cout << queue.front() << ' ';
        queue.pop();
	}
	std::cout << "\nSize : " << queue.size() << std::endl;
	std::cout << "Empty ? " << " : " << queue.empty() << std::endl;
}

template<class V>
void	test_front_back(V &queue, std::string str)
{
	std::cout << "\nTesting front " << " - " << str << " :" << std::endl;
	std::cout << queue.front() << std::endl;
	std::cout << "Testing back " << " - " << str << " :" << std::endl;
	std::cout << queue.back() << std::endl;
}

template<class V>
void	test_push_and_pop(V &queue, std::string str)
{
	std::cout << "\nTesting push_back " << " - " << str << " :" << std::endl;
	queue.push(0);
	queue.push(13);
	queue.push(45);
	test_front_back(queue, str);
	display_queue(queue);
}

template<class V_1, class V_2>
void	test_queue(V_1 &std_queue, V_2 &my_queue)
{
	std::cout << "\nQueue content std_queue :" << std::endl;
	display_queue(std_queue);
	std::cout << "\nQueue content my_queue :" << std::endl;
	display_queue(my_queue);

	test_push_and_pop(std_queue, "std_queue");
	// test_push_and_pop(my_queue, value, "my_queue");
}

void	test_queue_list()
{
	std::list<int> std_list(5, 12);

	std::queue<int, std::list<int>> std_queue(std_list);
	// std::queue<int, std::list<int>> my_queue(std_list);
	ft::Queue<int, std::list<int>> my_queue(std_list);

	test_queue(std_queue, my_queue);
}

// void	test_queue_float()
// {
// 	std::queue<float> std_queue(3, 45.7897);
// 	Queue<float> my_queue(3, 45.7897);

// 	test_queue(std_queue, my_queue, 1.23456);
// }

int main()
{
	std::cout << "\n\n+++++++++++++++++ Test queue <list<string>> +++++++++++++++++" << std::endl;
	test_queue_list();
	// std::cout << "\n\n+++++++++++++++++ Test queuetor <float> +++++++++++++++++" << std::endl;
	// test_queue_deque();
}
