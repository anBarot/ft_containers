#if !defined(STACK_HPP)
#define STACK_HPP

namespace ft
{
	template<class T, class C>
	class Stack
	{

		private:
			C		_container;

		public:
			typedef	C 						container_type;
			typedef	T 						value_type;
			typedef	typename C::size_type 	size_type;

			// Coplien
			explicit Stack(const container_type &ctnr = container_type()) : _container(ctnr) {}
			Stack(const Stack<T, C> &stack) : _container(stack._container) {}
			Stack<T, C> &operator=(const Stack<T, C> &stack) { _container = stack._container; return (*this); }
			~Stack() {};

			// Getters
			size_type	size() const { return (_container.size()); }

			// Member functions
			bool				empty() const					{ return (_container.empty()); }
			void				pop()							{ _container.pop_back(); }
			void				push (const value_type& val)	{ _container.push_back(val); }
			value_type&			top()							{ return (_container.back()); }
			const 	value_type& top() const						{ return (_container.back()); }
	};
}

// Non member function

template <class T, class C>
void	swap(ft::Stack<T, C> &x, ft::Stack<T, C> &y)
{
	ft::Stack<T, C> tmp = x;
	x = y;
	y = tmp;
}

// Relational operator overload

template <class T, class C>
bool operator==(const ft::Stack<T,C> &lhs, const ft::Stack<T,C> &rhs)
{ return (lhs._container == rhs._container); }
 	
template <class T, class C>
bool operator!=(const ft::Stack<T,C> &lhs, const ft::Stack<T,C> &rhs)
{ return (lhs._container != rhs._container); }
 	
template <class T, class C>
bool operator<(const ft::Stack<T,C> &lhs, const ft::Stack<T,C> &rhs)
{ return (lhs._container < rhs._container); }
 	
template <class T, class C>
bool operator<=(const ft::Stack<T,C> &lhs, const ft::Stack<T,C> &rhs)
{ return (lhs._container <= rhs._container); }
 	
template <class T, class C>
bool operator>(const ft::Stack<T,C> &lhs, const ft::Stack<T,C> &rhs)
{ return (lhs._container > rhs._container); }
 	
template <class T, class C>
bool operator>=(const ft::Stack<T,C> &lhs, const ft::Stack<T,C> &rhs)
{ return (lhs._container >= rhs._container); }

#endif // STACK_HPP
