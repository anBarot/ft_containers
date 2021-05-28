#if !defined(STACK_HPP)
#define STACK_HPP

namespace ft
{
	template<class T, class C>
	class Stack
	{

		private:
			C		_container;
			size_t	_size;

		public:
			typedef	T 			value_type;
			typedef	C 			container_type;
			typedef	size_t 		size_type;

			// Coplien
			explicit stack (const container_type &ctnr = container_type());
			Stack(size_t size) : _size(size) {};
			Stack(const C& container) : _container(container), _size(_container.size()) {};
			Stack(const Stack<T, C> &stack);
			Stack<T, C> &operator=(const Stack<T, C> &stack);
			~Stack() {};

			// Getters
			size_t	size() const { return (_container.size()); }

			// Member functions
			bool	empty() const { return (_container.size() == 0); };
			T&		top() { return ((_container.back()); };
			const 	T& top() const { return ((_container.back()); };
			void	pop() { this->_container.pop_back(); };
			void	push(const T &value) { this->_container.push_back(value); };
			void	emplace() { this->_container.emplac_back(); };
			void	swap(Stack<T, C> &x);
	};
}

// Member functions

template <class T, class C>
void ft::Stack<T, C>::swap(ft::Stack<T, C> &x)
{
	ft::Stack<T, C> &tmp = x;
	x = this;
	this = tmp;
}

// Non member function

template <class T, class C>
void	swap(ft::Queue<T, C> &queue1, ft::Queue<T, C> &queue2)
{
	ft::Queue<T, C> &tmp = queue1;
	queue1 = queue2;
	queue2 = tmp;
}

// Relational operator overload

template <class T, class C>
bool operator==(const ft::Stack<T,C> &lhs, const ft::Stack<T,C> &rhs)
{ return (); }
 	
template <class T, class C>
bool operator!=(const ft::Stack<T,C> &lhs, const ft::Stack<T,C> &rhs)
{ return (); }
 	
template <class T, class C>
bool operator<(const ft::Stack<T,C> &lhs, const ft::Stack<T,C> &rhs)
{ return (); }
 	
template <class T, class C>
bool operator<=(const ft::Stack<T,C> &lhs, const ft::Stack<T,C> &rhs)
{ return (); }
 	
template <class T, class C>
bool operator>(const ft::Stack<T,C> &lhs, const ft::Stack<T,C> &rhs)
{ return (); }
 	
template <class T, class C>
bool operator>=(const ft::Stack<T,C> &lhs, const ft::Stack<T,C> &rhs)
{ return (); }

#endif // STACK_HPP