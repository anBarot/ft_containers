#if !defined(MAP_HPP)
#define MAP_HPP

#include <iostream>
#include <utility>
#include "pair.hpp"
#include "value_compare.hpp"
#include "binary_search_tree.hpp"
#include "bst_iterator.hpp"
#include "bst_const_iterator.hpp"
#include "bst_reverse_iterator.hpp"
#include "bst_const_reverse_iterator.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::Pair<const Key, T>>>
	class Map
	{
		public :
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::Pair<const key_type, mapped_type>		value_type;
			typedef Compare										key_compare;
			typedef Alloc										allocator_type;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef value_type*									pointer;
			typedef const value_type*							const_pointer;
			typedef size_t										size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef typename ft::BSTIterator<T>					iterator;
			typedef typename ft::BSTConstIterator<T>			const_iterator;
			typedef typename ft::BSTReverseIterator<T>			reverse_iterator;
			typedef typename ft::BSTConstReverseIterator<T>		const_reverse_iterator;

		private :
			Compare								comp;
			BinarySearchTree<value_type>		bst;
			allocator_type						alloc;

		public :
			// Coplien
			explicit Map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
			template <class InputIterator>
  			Map(typename ft::enable_if<InputIterator::input_iter, InputIterator>::type first, 
			InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			Map(const Map &x);
			Map &operator=(const Map &x);
			~Map();

			// Iterator
			iterator 				begin() { return(iterator(bst)); }
			const_iterator 			begin() const { return(const_iterator(bst)); }
			reverse_iterator 		rbegin();
			const_reverse_iterator 	rbegin() const;
			iterator 				end();
			const_iterator 			end() const;
			reverse_iterator 		rend();
			const_reverse_iterator 	rend() const;
			iterator 				find(const key_type& k);
			const_iterator 			find(const key_type& k) const;
			iterator 				upper_bound(const key_type& k);
			const_iterator 			upper_bound(const key_type& k) const;
			iterator 				lower_bound(const key_type& k);
			const_iterator 			lower_bound(const key_type& k) const;

			// Getters
			size_type							size() const;
			size_type							count(const key_type& k) const;
			bool								empty() const;
			pair<iterator,iterator>				equal_range (const key_type& k);
			pair<const_iterator,const_iterator>	equal_range (const key_type& k) const;
			allocator_type						get_allocator() const;
			key_compare							key_comp()
			{



			}
			size_type							max_size() const { return( alloc.max_size() ); }
			mapped_type&						operator[](const key_type &k);
			value_compare						value_comp() const { return ( ft::Map::value_compare(); }

			// Setters
			void					clear();
			void					erase(iterator position);
			size_type				erase(const key_type &k);
			void					erase(iterator first, iterator last);
			pair<iterator, bool>	insert(const value_type &val);
			iterator				insert(iterator position, const value_type &val);
			template <class InputIterator>
			void					insert(typename ft::enable_if<InputIterator::input_iter, InputIterator>::type first,
											InputIterator last);

			// Other member functions
			void					swap(ft::Map &x) { Map tmp(x); x = *this; *this = tmp; };
	};
}

// Member functions - iterator

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::iterator ft::Map<Key, T, Compare, Alloc>::end()
{
	typename ft::Map::iterator it = this.begin();

	while (it != this.end())
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::const_iterator ft::Map<Key, T, Compare, Alloc>::end() const
{
	typename ft::Map::const_iterator it = this.begin();

	while (it != this.end())
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::iterator find(const typename ft::Map<Key, T, Compare, Alloc>::key_type& k)
{
	typename ft::Map::iterator it = this.begin();

	while (it != this.end() && *it != k)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map::const_iterator find(const typename ft::Map::key_type& k) const
{
	typename ft::Map::const_iterator it = this.begin();

	while (it != this.end() && *it != k)
		it++;

	return (it);
}

// Member functions - getters

template <class Key, class T, class Compare, class Alloc>
ft::Map::size_type ft::Map::size()
{
	size_type count = 0;

	for (typename ft::Map::iterator it = this.begin(); it != this.end(); ++it)
		count++;

	return (count);
}

template <class Key, class T, class Compare, class Alloc>
mapped_type& ft::Map::operator[](const key_type &k)
{
	return ((*((this->insert(make_pair(k,mapped_type()))).first)).second);
}

// Relational operators

template <class Key, class T, class Compare, class Alloc>
bool operator==(const ft::Map<Key, T, Compare, Alloc>& lhs, const ft::Map<Key, T, Compare, Alloc>& rhs)
{ 
	if (lhs._size != rhs._size)	
		return (false);

	ft::Map::iterator lhs_it = lhs.begin(); 
	ft::Map::iterator rhs_it = rhs.begin(); 

	while (lhs_it != lhs.end())
	{
		if (lhs_it.first != rhs_it.first)
			return (false);
		if (lhs_it.second != rhs_it.second)
			return (false);
		lhs_it++;
		rhs_it++;
	}

	return(true);
}

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const ft::Map<Key, T, Compare, Alloc>& lhs, const ft::Map<Key, T, Compare, Alloc>& rhs)
{ 
	if (lhs == rhs)
		return (false);	
	return(true);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<( const ft::Map<Key, T, Compare, Alloc>& lhs, const ft::Map<Key, T, Compare, Alloc>& rhs)
{ 
	ft::Map::iterator lhs_it = lhs.begin(); 
	ft::Map::iterator rhs_it = rhs.begin(); 

	while (lhs_it != lhs.end())
	{
		if (lhs_it.first >= rhs_it.first)
			return (false);
		if (lhs_it.second >= rhs_it.second)
			return (false);
		lhs_it++;
		rhs_it++;
	}

	if (lhs.size())

	return(true);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<=( const ft::Map<Key, T, Compare, Alloc>& lhs, const ft::Map<Key, T, Compare, Alloc>& rhs)
{ 
	ft::Map::iterator lhs_it = lhs.begin(); 
	ft::Map::iterator rhs_it = rhs.begin(); 

	while (lhs_it != lhs.end())
	{
		if (lhs_it.first > rhs_it.first)
			return (false);
		if (lhs_it.second > rhs_it.second)
			return (false);
		lhs_it++;
		rhs_it++;
	}

	return(true);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>( const ft::Map<Key, T, Compare, Alloc>& lhs, const ft::Map<Key, T, Compare, Alloc>& rhs)
{ 
	if (lhs <= rhs)
		return (false);	
	return (true);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>=( const ft::Map<Key, T, Compare, Alloc>& lhs, const ft::Map<Key, T, Compare, Alloc>& rhs)
{ 
	if (lhs < rhs)
		return (false);	
	return (true);
}

#endif
