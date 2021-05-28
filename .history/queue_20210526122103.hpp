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
			explicit Queue(const container_type& ctnr = container_type()) {}
			Queue(const Queue<T, C> &queue) { this->_container = queue._container; }
			Queue<T, C> &operator=(const Queue<T, C> &queue) { this->_container = queue._container; }
			~Queue() { ~_container; }

			// Getters
			size_t				size() { return (this->conatiner.size()); }

			// Member functions
			bool				empty() const { return (this->_container.empty()); }
			value_type &		front() { return (this->_container.front()); }
			const value_type &	front() const { return (this->_container.front()); }
			value_type &		back() { return (this->_container.back()); }
			const value_type &	back() const  { return (this->_container.back()); }
			void				pop() { this->_container.pop_front(); }
			void				push(const value_type & value) { this->_container.push_back(value); }
			template <class... Args>
			void				emplace (Args&&... args)  { this->_container.emplac_back(args); }
			void				swap(Queue<T, C>& x) { Queue<T, C> &tmp = x; x = this; this = tmp; }
	};
}

// Non member function

template<class T, class C>
void	swap(ft::Queue<T, C> &x, ft::Queue<T, C> &y)
{
	ft::Queue<T, C> &tmp = x;
	x = y;
	y = tmp;
}

// Relational operator

template <class T, class C>
bool operator==(const ft::Queue<T, C>& lhs, const ft::Queue<T, C>& rhs)
{ return (lhs._container == rhs._container); }

template <class T, class C>
bool operator!=(const ft::Queue<T, C>& lhs, const ft::Queue<T, C>& rhs)
{ return (lhs._container != rhs._container); }

template <class T, class C>
bool operator<(const ft::Queue<T, C>& lhs, const ft::Queue<T, C>& rhs)
{ return (lhs._container < rhs._container); }

template <class T, class C>
bool operator<=(const ft::Queue<T, C>& lhs, const ft::Queue<T, C>& rhs)
{ return (lhs._container <= rhs._container); }

template <class T, class C>
bool operator>(const ft::Queue<T, C>& lhs, const ft::Queue<T, C>& rhs)
{ return (lhs._container > rhs._container); }

template <class T, class C>
bool operator>=(const ft::Queue<T, C>& lhs, const ft::Queue<T, C>& rhs)
{ return (lhs._container >= rhs._container); }

#endif // QUEUE_HPP