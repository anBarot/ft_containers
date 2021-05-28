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

		public:
			typedef	T 			value_type;
			typedef C			container_type;
			typedef	size_t 		size_type;

			// Coplien
			Queue() {};
			Queue(size_t size) : _size(size) {};
			Queue(const C& container) : _container(container), _size(_container.size()) {};
			Queue(const Queue<T, C> &queue);
			Queue<T, C> &operator=(const Queue<T, C> &queue);
			~Queue() {};

			// Getters
			size_t	size() { return (this->conatiner.size()); }

			// Member functions
			bool				empty() const { return (this->_container.empty()); };
			value_type &		front() { return (this->_container.front()); }
			const value_type &	front() const { return (this->_container.front()); }
			value_type &		back() { return (this->_container.back()); }
			const value_type &	back() const  { return (this->_container.back()); }
			void				pop() { this->_container.pop_front(); }
			void				push(const value_type & value) { this->_container.push_back(value); }
			void				swap(Queue<T, C>& x);
			template <class... Args>
			void				emplace (Args&&... args)  { this->_container.emplac_back(args); }
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
void ft::Queue<T, C>::swap(ft::Queue<T, C> &x)
{
	ft::Queue<T, C> &tmp = x;
	x = this;
	this = tmp;
}

// Non member function

template<class T, class C>
void	swap(ft::Queue<T, C> &x, ft::Queue<T, C> &y)
{
	ft::Queue<T, C> &tmp = x;
	x = y;
	y = tmp;
}

#endif // QUEUE_HPP