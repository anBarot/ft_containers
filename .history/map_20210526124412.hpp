#if !defined(MAP_HPP)
#define MAP_HPP

#include <iostream>
#include <utility>

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T>>> 
	class map
	{
		public :
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef std::pair<const key_type, mapped_type>	value_type;
			typedef Compare									key_compare;
			// typedef 										value_compare;
			typedef Alloc									allocator_type;
			typedef allocator_type::reference				reference;
			typedef allocator_type::const_reference			const_reference;
			typedef allocator_type::pointer					pointer;
			typedef allocator_type::const_pointer			const_pointer;
			typedef 										iterator;
			typedef 										const_iterator;
			typedef 										reverse_iterator;
			typedef 										const_reverse_iterator;
			typedef ptrdiff_t								difference_type;
			typedef size_t									size_type;

		private :


		public :
		// Coplien


		// Member functions


	}
}

#endif // MAP_HPP