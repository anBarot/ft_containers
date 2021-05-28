#ifndef QUEUE_HPP 
#define QUEUE_HPP

#include <iostream>

namespace ft
{
	template<class T, class C>
	class Queue
	{

		private:
			C		_container;
			size_t	_size;

		public:
			typedef	T 			value_type;
			typedef	T& 			reference;
			typedef C			container_type;
			typedef	const T& 	const_reference;
			typedef	T* 			pointer;
			typedef	const T* 	const_pointer;
			typedef	size_t 		size_type;
			typedef	size_type 	difference_type;

			// Coplien
			Queue() {};
			Queue(size_t size) : _size(size) {};
			Queue(const C& container) : _container(container), _size(_container.size()) {};
			Queue(const Queue<T, C> &queue);
			Queue<T, C> &operator=(const Queue<T, C> &queue);
			~Queue() {};

			// Getters
			size_t	size() { return (this->_size); }

			// Member functions
			bool	empty() const { return (this->_size == 0); };
			T&		front() { return (this->_container.front()); }
			T&		back() { return (this->_container.back()); }
			void	pop() { this->_container.pop_front(); };
			void	push(const T&value) { this->_container.push_back(value); };
			void	emplace() { this->_container.emplac_back(); };
			void	swap(Queue<T, C>& x);
	};
}

// Coplien implementation

template<class T, class C>
ft::Queue<T, C>::Queue(const ft::Queue<T, C>&queue)
{
	this->_size = queue.size();
	this->_container = queue._container;
}

template<class T, class C>
ft::Queue<T, C> &ft::Queue<T, C>::operator=(const ft::Queue<T, C>&queue)
{
	this->_size = queue._size;
	this->_capacity = queue._capacity;
	this->_container = queue._container;
	return (this);
}

// Member functions

template<class T, class C>
void ft::Queue<T, C>::swap(ft::Queue<T, C>& x)
{
	ft::Queue<T, C> &tmp = x;
	x = this;
	this = tmp;
}

// Non member function

template<class T, class C>
void	swap(ft::Queue<T, C> &queue1, ft::Queue<T, C> &queue2)
{
	ft::Queue<T, C> &tmp = queue1;
	queue1 = queue2;
	queue2 = tmp;
}

#endif // QUEUE_HPP