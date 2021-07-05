#if !defined(PAIR_HPP)
#define PAIR_HPP

namespace ft
{
	template <class T1, class T2> 
	class Pair
	{
		public :
			typedef T1 first_type;
	    	typedef T2 second_type;

		private :
	    	T1 first;
	    	T2 second;

		public :
			// Coplien
			Pair() {};
			Pair(const first_type& a, const second_type& b) :
			first(a), second(b) {}
			template<class U, class V>
			Pair(const Pair<U,V>& pr)
			{
				first = pr.first;
				second = pr.second;
			}
			Pair& operator=(const Pair& pr)
			{
				first = pr.first;
				second = pr.second;

				return (*this);
			}

			// Member function
			Pair<T1,T2> make_pair(T1 x, T2 y)
			{ return (Pair(x, y)); }
	};
}

template <class T1, class T2>
bool operator==(const ft::Pair<T1,T2>& lhs, const ft::Pair<T1,T2>& rhs)
{ return (lhs.first == rhs.first && lhs.second == lhs.second); }

template <class T1, class T2>
bool operator!=(const ft::Pair<T1,T2>& lhs, const ft::Pair<T1,T2>& rhs)
{ return (!(lhs == rhs)); }

template <class T1, class T2>
bool operator<(const ft::Pair<T1,T2>& lhs, const ft::Pair<T1,T2>& rhs)
{
	if (lhs.first == rhs.first)
		return (lhs.second < rhs.second);
	return (lhs.first < rhs.first);
}

template <class T1, class T2>
bool operator<=(const ft::Pair<T1,T2>& lhs, const ft::Pair<T1,T2>& rhs)
{
	if (lhs.first == rhs.first)
		return (lhs.second <= rhs.second);
	return (lhs.first <= rhs.first);
}

template <class T1, class T2>
bool operator>(const ft::Pair<T1,T2>& lhs, const ft::Pair<T1,T2>& rhs)
{ return (!(lhs <= rhs)); }

template <class T1, class T2>
bool operator>=(const ft::Pair<T1,T2>& lhs, const ft::Pair<T1,T2>& rhs)
{ return (!(lhs < rhs)); }

#endif
