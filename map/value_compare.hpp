#ifndef VALUE_COMPARE_HPP
#define  VALUE_COMPARE_HPP

#include "map.hpp"

namespace ft
{
	template <class Key, class T, class Compare, class Alloc> 
	class value_compare
	{
		public :
			typedef bool 	result_type;
			typedef T		value_type;	

		protected:
			Compare comp;
			value_compare(Compare c) : comp(c) {}

		public:
			bool operator()(const value_type & x, const value_type & y) const
			{ return (comp(x.first, y.first)); }
	};
}

#endif // VALUE_COMPARE_HPP
