#if !defined(MAP_HPP)
#define MAP_HPP

#include <iostream>
#include <utility>

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T>>> 
	class Map
	{
		public :
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef std::pair<const key_type, mapped_type>	value_type;
			typedef Compare									key_compare;
			// typedef 										value_compare;
			typedef Alloc									allocator_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef value_type*								pointer;
			typedef const value_type*						const_pointer;
			typedef 										iterator;
			typedef 										const_iterator;
			typedef ptrdiff_t								difference_type;
			typedef size_t									size_type;

		private :
			pointer	pdata;

		public :
			// Coplien
			explicit Map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
  			Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			Map(const map &x);
			~Map();

			// Iterator
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			iterator find (const key_type& k);
			const_iterator find (const key_type& k) const;
			
			// Getters
			mapped_type& at(const key_type& k);
			const mapped_type& at(const key_type& k) const;
			size_type count(const key_type& k) const;
			bool empty() const;
			pair<iterator,iterator>             equal_range (const key_type& k);
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const;

			// Setters
			void clear();
			void erase (iterator position);
			size_type erase (const key_type& k);
			void erase (iterator first, iterator last);

			// Member functions

	};
}

#endif // MAP_HPP
