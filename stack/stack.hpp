#if !defined(STACK_HPP)
#define STACK_HPP

#include <deque>

namespace ft
{
	template<class T, class C = std::deque<T> >
	class stack
	{
		private:
			C		_container;

		public:
			typedef	C 		container_type;
			typedef	T 		value_type;
			typedef	size_t 	size_type;

			// Coplien
			explicit stack(const container_type &ctnr = container_type()) : _container(ctnr) {}
			stack(const stack<T, C> &stack) : _container(stack._container) {}
			stack<T, C> &operator=(const stack<T, C> &stack) { _container = stack._container; return (*this); }
			virtual ~stack() {};

			// Getters
			container_type		GetContainer() const { return (_container); };
			size_type			size() const { return (_container.size()); }

			// Member functions
			bool				empty() const					{ return (_container.empty()); }
			void				pop()							{ _container.pop_back(); }
			void				push(const value_type& val)		{ _container.push_back(val); }
			value_type&			top()							{ return (_container.back()); }
			const 	value_type& top() const						{ return (_container.back()); }
	};
}

// Non member function

template <class T, class C>
void	swap(ft::stack<T, C> &x, ft::stack<T, C> &y)
{
	ft::stack<T, C> tmp = x;
	x = y;
	y = tmp;
}

// Relational operator overload

template <class T, class C>
bool operator==(const ft::stack<T,C> &lhs, const ft::stack<T,C> &rhs)
{ return (lhs.GetContainer() == rhs.GetContainer()); }
 	
template <class T, class C>
bool operator!=(const ft::stack<T,C> &lhs, const ft::stack<T,C> &rhs)
{ return (lhs.GetContainer() != rhs.GetContainer()); }
 	
template <class T, class C>
bool operator<(const ft::stack<T,C> &lhs, const ft::stack<T,C> &rhs)
{ return (lhs.GetContainer() < rhs.GetContainer()); }
 	
template <class T, class C>
bool operator<=(const ft::stack<T,C> &lhs, const ft::stack<T,C> &rhs)
{ return (lhs.GetContainer() <= rhs.GetContainer()); }
 	
template <class T, class C>
bool operator>(const ft::stack<T,C> &lhs, const ft::stack<T,C> &rhs)
{ return (lhs.GetContainer() > rhs.GetContainer()); }
 	
template <class T, class C>
bool operator>=(const ft::stack<T,C> &lhs, const ft::stack<T,C> &rhs)
{ return (lhs.GetContainer() >= rhs.GetContainer()); }

#endif // STACK_HPP
