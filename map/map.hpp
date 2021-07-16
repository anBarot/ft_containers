#if !defined(MAP_HPP)
#define MAP_HPP

#include <iostream>
#include <utility>
#include "pair.hpp"
#include "value_compare.hpp"
#include "../tools/enable_if.hpp"
#include "binary_search_tree.hpp"
#include "bst_iterator.hpp"
#include "bst_const_iterator.hpp"
#include "bst_reverse_iterator.hpp"
#include "bst_const_reverse_iterator.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::Pair<const Key, T> > >
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
			template <class Inputiterator>
  			Map(typename ft::enable_if<Inputiterator::input_iter, Inputiterator>::type first, 
			Inputiterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			Map(const Map &x);
			Map &operator=(const Map &x);
			~Map() { this->clear(); }

			// iterator
			iterator 							begin() { return(iterator(bst)); }
			const_iterator 						begin() const { return(const_iterator(bst)); }
			reverse_iterator 					rbegin() { return (reverse_iterator(bst.end())); }
			const_reverse_iterator 				rbegin() const { return (reverse_iterator(bst.end())); }
			iterator 							end();
			const_iterator 						end() const;
			reverse_iterator 					rend();
			const_reverse_iterator 				rend() const;
			iterator 							find(const key_type& k);
			const_iterator 						find(const key_type& k) const;
			iterator 							upper_bound(const key_type& k);
			const_iterator 						upper_bound(const key_type& k) const;
			iterator 							lower_bound(const key_type& k);
			const_iterator 						lower_bound(const key_type& k) const;
			Pair<iterator,iterator>				equal_range (const key_type& k);
			Pair<const_iterator,const_iterator>	equal_range (const key_type& k) const;

			// Getters
			size_type							size() const;
			size_type							count(const key_type& k) const;
			bool								empty() const { return (bst == nullptr); }
			allocator_type						get_allocator() const { return (alloc); }
			size_type							max_size() const { return( alloc.max_size() ); }
			key_compare							key_comp() const { return (comp); }
			value_compare						value_comp() const { return ( value_compare(); }
			mapped_type&						operator[](const key_type &k);

			// Setters
			void					clear() { ~bst(); }
			void					erase(iterator position);
			size_type				erase(const key_type &k);
			void					erase(iterator first, iterator last);
			Pair<iterator, bool>	insert(const value_type &val);
			iterator				insert(iterator position, const value_type &val);
			template <class Inputiterator>
			void					insert(typename ft::enable_if<Inputiterator::input_iter, Inputiterator>::type first,
											Inputiterator last)
			{
				while (first != last)
				{
					insert(first);
					first++;
				}
			}

			// Other member functions
			void					swap(Map &x) { Map tmp(x); x = *this; *this = tmp; };
	};
}
			
// Member functions - ft::Map::iterator

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::iterator ft::Map<Key, T, Compare, Alloc>::end()
{
	typename ft::Map::iterator it = this->begin();

	while (it != this->end())
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::const_iterator ft::Map<Key, T, Compare, Alloc>::end() const
{
	typename ft::Map::const_iterator it = this->begin();

	while (it != this->end())
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::iterator ft::Map<Key, T, Compare, Alloc>::find(const typename ft::Map<Key, T, Compare, Alloc>::key_type& k)
{
	typename ft::Map::iterator it = this->begin();

	while (it != this->end() && *it != k)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::const_iterator ft::Map<Key, T, Compare, Alloc>::find(const typename ft::Map::key_type& k) const
{
	typename ft::Map<Key, T, Compare, Alloc>::const_iterator it = this->begin();

	while (it != this->end() && *it != k)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::iterator ft::Map<Key, T, Compare, Alloc>::upper_bound(const key_type& k)
{
	typename ft::Map<Key, T, Compare, Alloc>::iterator it = this->begin();
	typename ft::Map<Key, T, Compare, Alloc>::key_compare comp = this->key_comp();

	while (it != it.end() && comp(*it.first, k) != true)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::const_iterator ft::Map<Key, T, Compare, Alloc>::upper_bound(const key_type& k) const
{
	typename ft::Map<Key, T, Compare, Alloc>::iterator it = this->begin();
	typename ft::Map<Key, T, Compare, Alloc>::key_compare comp = this->key_comp();

	while (it != it.end() && comp(*it.first, k) != true)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::iterator ft::Map<Key, T, Compare, Alloc>::lower_bound(const key_type& k)
{
	typename ft::Map<Key, T, Compare, Alloc>::iterator it = this->begin();
	typename ft::Map<Key, T, Compare, Alloc>::key_compare comp = this->key_comp();

	while (it != it.end() && comp(*it.first, k) != false)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::const_iterator ft::Map<Key, T, Compare, Alloc>::lower_bound(const key_type& k) const
{
	typename ft::Map<Key, T, Compare, Alloc>::iterator it = this->begin();
	typename ft::Map<Key, T, Compare, Alloc>::key_compare comp = this->key_comp();

	while (it != it.end() && comp(*it.first, k) != false)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Pair<ft::Map::iterator, ft::Map::iterator> ft::Map<Key, T, Compare, Alloc>::equal_range(const key_type& k)
{
	return (ft::Pair(this->lower_bound(), this->upper_bound()));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Pair<ft::Map::const_iterator, ft::Map::const_iterator> ft::Map<Key, T, Compare, Alloc>::equal_range(const key_type& k) const
{
	return (ft::Pair(this->lower_bound(), this->upper_bound()));
}

// Member functions - getters

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::size_type ft::Map<Key, T, Compare, Alloc>::size() const
{
	size_type count = 0;

	for (typename ft::Map::ft::Map::iterator it = this->begin(); it != this->end(); ++it)
		count++;

	return (count);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::mapped_type& ft::Map<Key, T, Compare, Alloc>::operator[](const key_type &k)
{
	return ((*((this->insert(make_pair(k, mapped_type()))).first)).second);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::size_type ft::Map<Key, T, Compare, Alloc>::count(const key_type& k)
{
	if (this->find(k) != this->end())
		return (1);
	return (0);
}

// Member functions - Setters

template <class Key, class T, class Compare, class Alloc>
void	ft::Map<Key, T, Compare, Alloc>::erase(ft::Map::iterator position)
{
	bst.Delete(bstroot_p, *position.first);
}

template <class Key, class T, class Compare, class Alloc>
size_type	ft::Map<Key, T, Compare, Alloc>::erase(const key_type &k)
{
	bst.Delete(bstroot_p, k);
}

template <class Key, class T, class Compare, class Alloc>
void	ft::Map<Key, T, Compare, Alloc>::erase(ft::Map::iterator first, ft::Map::iterator last)
{
	while (first != last)
	{
		this->erase(first);
		first++;
	}
}

template <class Key, class T, class Compare, class Alloc>
ft::Pair<ft::Map::iterator, bool>	ft::Map::insert(const value_type &val)
{
	bst.Insert(bst.bstroot_p, val);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::iterator	ft::Map::insert(ft::Map::iterator position, const value_type &val)
{
	return (bst.Insert(position.curr(), val));
}

// Relational operators

template <class Key, class T, class Compare, class Alloc>
bool operator==(const ft::Map<Key, T, Compare, Alloc>& lhs, const ft::Map<Key, T, Compare, Alloc>& rhs)
{ 
	if (lhs._size != rhs._size)	
		return (false);

	typename ft::Map::iterator lhs_it = lhs.begin(); 
	typename ft::Map::iterator rhs_it = rhs.begin(); 

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
	ft::Map::ft::Map::iterator lhs_it = lhs.begin(); 
	ft::Map::ft::Map::iterator rhs_it = rhs.begin(); 

	while (lhs_it != lhs.end())
	{
		if (lhs_it.first >= rhs_it.first)
			return (false);
		if (lhs_it.second >= rhs_it.second)
			return (false);
		lhs_it++;
		rhs_it++;
	}

	return(true);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<=( const ft::Map<Key, T, Compare, Alloc>& lhs, const ft::Map<Key, T, Compare, Alloc>& rhs)
{ 
	ft::Map::ft::Map::iterator lhs_it = lhs.begin(); 
	ft::Map::ft::Map::iterator rhs_it = rhs.begin(); 

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
