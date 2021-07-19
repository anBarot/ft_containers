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

		private :
			Compare comp;

		public :
			value_compare(Compare c) : comp(c) {}
			result_type operator()(const value_type & x, const value_type & y) const
			{ return (comp(x.first, y.first)); }
	};
}

#endif // VALUE_COMPARE_HPP
