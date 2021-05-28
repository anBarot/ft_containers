#if !defined(MAP_HPP)
#define MAP_HPP

#include <iostream>

namespace ft 
{
	template < class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key, T>>> 
	class map
	{
		public :
			typedef Key	key_type;
			typedef T	mapped_type;
			typedef 	value_type;
			typedef 	key_compare;
			typedef 	value_compare;
			typedef 	allocator_type;
			typedef 	reference;
			typedef 	const_reference;
			typedef 	pointer;
			typedef 	const_pointer;
			typedef 	iterator;
			typedef 	const_iterator;
			typedef 	reverse_iterator;
			typedef 	const_reverse_iterator;
			typedef 	difference_type;
			typedef 	size_type;

		private :


		public :
		// Coplien


		// Member functions


	}
}

#endif // MAP_HPP
