#if !defined(MAP_HPP)
#define MAP_HPP

#include <iostream>
#include <utility>
#include "pair.hpp"
#include "make_pair.hpp"
#include "value_compare.hpp"
#include "../tools/enable_if.hpp"
#include "binary_search_tree.hpp"
#include "bst_iterator.hpp"
#include "bst_const_iterator.hpp"
#include "bst_reverse_iterator.hpp"
#include "bst_const_reverse_iterator.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::Pair<Key, T> > >
	class Map
	{
		public :
			typedef Key													key_type;
			typedef T													mapped_type;
			typedef ft::Pair<Key, T>									value_type;
			typedef Compare												key_compare;
			typedef Alloc												allocator_type;
			typedef value_type&											reference;
			typedef const value_type&									const_reference;
			typedef value_type*											pointer;
			typedef const value_type*									const_pointer;
			typedef size_t												size_type;
			typedef typename std::ptrdiff_t								difference_type;
			typedef typename ft::BSTIterator<value_type>				iterator;
			typedef typename ft::BSTConstIterator<value_type>			const_iterator;
			typedef typename ft::BSTReverseIterator<value_type>			reverse_iterator;
			typedef typename ft::BSTConstReverseIterator<value_type>	const_reverse_iterator;

		private :
			key_compare							comp;
			BinarySearchTree<value_type>		bst;
			allocator_type						alloc;

		public :
			// Coplien
			explicit Map(const key_compare &n_comp = key_compare(), const allocator_type &n_alloc = allocator_type())
			: comp(n_comp), bst(), alloc(n_alloc) {}
			Map(const Map< Key, T, Compare, Alloc > &x);
			Map &operator=(const Map &x);
			template <class Inputiterator>
  			Map(typename ft::enable_if<Inputiterator::input_iter, Inputiterator>::type first, 
			Inputiterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			// ~Map() {}

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
			Pair<iterator,iterator>				equal_range(const key_type& k);
			Pair<const_iterator,const_iterator>	equal_range(const key_type& k) const;

			// Getters
			size_type								size() const;
			size_type								count(const key_type& k) const;
			bool									empty() const { return (bst.GetRoot() == NULL); }
			allocator_type							get_allocator() const { return (alloc); }
			size_type								max_size() const { return( alloc.max_size() ); }
			key_compare								key_comp() const { return (comp); }
			value_compare<Key, T, Compare, Alloc>	value_comp() const { return ( value_compare<Key,  T,  Compare,  Alloc> (Compare())); }
			mapped_type&					 		operator[](const key_type &k);

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

// Coplien

template <class Key, class T, class Compare, class Alloc>
template <class Inputiterator>
ft::Map<Key, T, Compare, Alloc>::Map(typename ft::enable_if<Inputiterator::input_iter, Inputiterator>::type first, 
Inputiterator last, const key_compare& n_comp, const allocator_type& n_alloc) : comp(n_comp), bst(NULL), alloc(n_alloc)
{
	while (first != last)
	{
		bst.Insert(bst.GetRoot(), *first);
		first++;
	}
}

template <class Key, class T, class Compare, class Alloc>
ft::Map<Key, T, Compare, Alloc>::Map(const Map< Key, T, Compare, Alloc > &x)
{
	comp = x.comp;
	alloc = x.alloc;

	bst();
	this->insert(x.begin(), x.end());
}

template <class Key, class T, class Compare, class Alloc>
ft::Map<Key, T, Compare, Alloc> &ft::Map<Key, T, Compare, Alloc>::operator=(const Map &x)
{
	comp = x.comp;
	alloc = x.alloc;

	bst();
	this->insert(x.begin(), x.end());
}

// Member functions 

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::iterator ft::Map<Key, T, Compare, Alloc>::end()
{
	ft::Map<Key, T, Compare, Alloc>::iterator it = this->begin();

	while (it.hasNext() == true)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::const_iterator ft::Map<Key, T, Compare, Alloc>::end() const
{
	ft::Map<Key, T, Compare, Alloc>::const_iterator it = this->begin();

	while (it.hasNext() == true)
		it++;

	return (const_iterator(this->end()));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::iterator ft::Map<Key, T, Compare, Alloc>::find(const ft::Map<Key, T, Compare, Alloc>::key_type& k)
{
	if (bst.GetRoot() == NULL)
		return (NULL);

	ft::Map<Key, T, Compare, Alloc>::iterator it = this->begin();

	while (it != NULL && it.curr()->data.first != k)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::const_iterator ft::Map<Key, T, Compare, Alloc>::find(const ft::Map<Key, T, Compare, Alloc>::key_type& k) const
{
	ft::Map<Key, T, Compare, Alloc>::const_iterator it = this->begin();

	while (it != this->end() && *it != k)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::iterator ft::Map<Key, T, Compare, Alloc>::upper_bound(const key_type& k)
{
	ft::Map<Key, T, Compare, Alloc>::iterator it = this->begin();
	ft::Map<Key, T, Compare, Alloc>::key_compare comp = this->key_comp();

	while (it != it.end() && comp(*it.first, k) != true)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::const_iterator ft::Map<Key, T, Compare, Alloc>::upper_bound(const key_type& k) const
{
	ft::Map<Key, T, Compare, Alloc>::iterator it = this->begin();
	ft::Map<Key, T, Compare, Alloc>::key_compare comp = this->key_comp();

	while (it != it.end() && comp(*it.first, k) != true)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::iterator ft::Map<Key, T, Compare, Alloc>::lower_bound(const key_type& k)
{
	ft::Map<Key, T, Compare, Alloc>::iterator it = this->begin();
	ft::Map<Key, T, Compare, Alloc>::key_compare comp = this->key_comp();

	while (it != it.end() && comp(*it.first, k) != false)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::const_iterator ft::Map<Key, T, Compare, Alloc>::lower_bound(const key_type& k) const
{
	ft::Map<Key, T, Compare, Alloc>::iterator it = this->begin();
	ft::Map<Key, T, Compare, Alloc>::key_compare comp = this->key_comp();

	while (it != it.end() && comp(*it.first, k) != false)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Pair<typename ft::Map<Key, T, Compare, Alloc>::iterator, typename ft::Map<Key, T, Compare, Alloc>::iterator> ft::Map<Key, T, Compare, Alloc>::equal_range(const key_type& k)
{
	return (ft::Pair<key_type, mapped_type>(this->lower_bound(k), this->upper_bound(k)));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Pair<typename ft::Map<Key, T, Compare, Alloc>::const_iterator, typename ft::Map<Key, T, Compare, Alloc>::const_iterator> ft::Map<Key, T, Compare, Alloc>::equal_range(const key_type& k) const
{
	return (ft::Pair<key_type, mapped_type>(this->lower_bound(k), this->upper_bound(k)));
}

// Member functions - getters

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::size_type ft::Map<Key, T, Compare, Alloc>::size() const
{
	return (bst.GetSize());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::mapped_type& ft::Map<Key, T, Compare, Alloc>::operator[](const key_type &k)
{
	ft::Pair<Key, T> *p = new ft::Pair<Key, T>;
	*p = *(find(k));

	return (p->second);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::size_type ft::Map<Key, T, Compare, Alloc>::count(const key_type& k) const
{
	if (this->find(k) != this->end())
		return (1);
	return (0);
}

// Member functions - Setters

template <class Key, class T, class Compare, class Alloc>
void	ft::Map<Key, T, Compare, Alloc>::erase(ft::Map<Key, T, Compare, Alloc>::iterator position)
{
	bst.Delete(bst.GetRoot(), *position);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::size_type	ft::Map<Key, T, Compare, Alloc>::erase(const ft::Map<Key, T, Compare, Alloc>::key_type &k)
{
	bst.Delete(bst.GetRoot(), *find(k));

	return (bst.GetSize());
}

template <class Key, class T, class Compare, class Alloc>
void	ft::Map<Key, T, Compare, Alloc>::erase(ft::Map<Key, T, Compare, Alloc>::iterator first, ft::Map<Key, T, Compare, Alloc>::iterator last)
{
	while (first != last)
	{
		this->erase(first);
		first++;
	}
}

template <class Key, class T, class Compare, class Alloc>
ft::Pair<typename ft::Map<Key, T, Compare, Alloc>::iterator, bool>	ft::Map<Key, T, Compare, Alloc>::insert(const value_type &val)
{
	if (find(val.first) == NULL)
		return (ft::Pair<typename ft::Map<Key, T, Compare, Alloc>::iterator, bool>(bst.Insert(bst.GetRoot(), val), true));

	if (find(val.first) == this->end())
		return (ft::Pair<typename ft::Map<Key, T, Compare, Alloc>::iterator, bool>(bst.Insert(bst.GetRoot(), val), true));

	return (ft::Pair<typename ft::Map<Key, T, Compare, Alloc>::iterator, bool>(find(val.first), false));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::iterator	ft::Map<Key, T, Compare, Alloc>::insert(ft::Map<Key, T, Compare, Alloc>::iterator position, const value_type &val)
{
	return (bst.Insert(position.curr(), val));
}

// Relational operators

template <class Key, class T, class Compare, class Alloc>
bool operator==(const ft::Map<Key, T, Compare, Alloc>& lhs, const ft::Map<Key, T, Compare, Alloc>& rhs)
{ 
	if (lhs._size != rhs._size)	
		return (false);

	typename ft::Map<Key, T, Compare, Alloc>::iterator lhs_it = lhs.begin(); 
	typename ft::Map<Key, T, Compare, Alloc>::iterator rhs_it = rhs.begin(); 

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
	typename ft::Map<Key, T, Compare, Alloc>::iterator lhs_it = lhs.begin(); 
	typename ft::Map<Key, T, Compare, Alloc>::iterator rhs_it = rhs.begin(); 

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
	typename ft::Map<Key, T, Compare, Alloc>::iterator lhs_it = lhs.begin(); 
	typename ft::Map<Key, T, Compare, Alloc>::iterator rhs_it = rhs.begin(); 

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
