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
	class map
	{
		public :
			typedef Key														key_type;
			typedef T														mapped_type;
			typedef ft::Pair<Key, T>										value_type;
			typedef Compare													key_compare;
			typedef ft::value_compare<Key, T, Compare, Alloc>				value_compare;
			typedef Alloc													allocator_type;
			typedef value_type&												reference;
			typedef const value_type&										const_reference;
			typedef value_type*												pointer;
			typedef const value_type*										const_pointer;
			typedef size_t													size_type;
			typedef typename ft::BSTIterator<value_type>					iterator;
			typedef typename ft::BSTConstIterator<value_type>				const_iterator;
			typedef typename ft::BSTReverseIterator<value_type>				reverse_iterator;
			typedef typename ft::BSTConstReverseIterator<value_type>		const_reverse_iterator;

		private :
			key_compare							comp;
			BinarySearchTree<value_type>		bst;
			allocator_type						alloc;

		public :
			// Coplien
			explicit map(const key_compare &n_comp = key_compare(), const allocator_type &n_alloc = allocator_type())
			: comp(n_comp), bst(), alloc(n_alloc) {}
			map(const map< Key, T, Compare, Alloc > &x);
			map &operator=(const map &x);
			template <class InputIterator>
  			map(typename ft::enable_if<std::is_base_of<typename InputIterator::iterator_category, std::__1::bidirectional_iterator_tag>::value, InputIterator>::type first,
			InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			virtual ~map();

			// iterator
			iterator 							begin() { return(iterator(bst)); }
			const_iterator 						begin() const { return(const_iterator(bst)); }
			reverse_iterator 					rbegin() { return (reverse_iterator(bst)); }
			const_reverse_iterator 				rbegin() const { return (reverse_iterator(bst)); }
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
			size_type				size() const;
			size_type				count(const key_type& k) const;
			bool					empty() const { return (bst.GetSize() == 0); }
			allocator_type			get_allocator() const { return (alloc); }
			size_type				max_size() const { return( alloc.max_size() ); }
			key_compare				key_comp() const { return (comp); }
			value_compare			value_comp() const { return ( value_compare(Compare())); }
			mapped_type&			operator[](const key_type &k);

			// Setters
			void					clear() { bst.~BinarySearchTree(); }
			void					erase(iterator position);
			size_type				erase(const key_type &k);
			void					erase(iterator first, iterator last);
			Pair<iterator, bool>	insert(const value_type &val);
			iterator				insert(iterator position, const value_type &val);
			template <class InputIterator>
			void					insert(typename ft::enable_if<std::is_base_of<typename InputIterator::iterator_category, std::__1::bidirectional_iterator_tag>::value, InputIterator>::type first,
											InputIterator last);

			// Other member functions
			void					swap(map &x) { map tmp(x); x = *this; *this = tmp; };
	};
}

// Coplien

template <class Key, class T, class Compare, class Alloc>
template <class InputIterator>
ft::map<Key, T, Compare, Alloc>::map(typename ft::enable_if<std::is_base_of<typename InputIterator::iterator_category, std::__1::bidirectional_iterator_tag>::value, InputIterator>::type first, 
InputIterator last, const key_compare& n_comp, const allocator_type& n_alloc) : comp(n_comp), bst(NULL), alloc(n_alloc)
{
	while (first != last)
	{
		bst.Insert(bst.GetRoot(), *first);
		first++;
	}
}

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map(const map< Key, T, Compare, Alloc > &x) : bst()
{
	comp = x.comp;
	alloc = x.alloc;
	ft::map<Key, T, Compare, Alloc>::const_iterator beg = x.begin();
	ft::map<Key, T, Compare, Alloc>::const_iterator end = x.end();

	while (beg != end)
	{
		bst.Insert(bst.GetRoot(), *beg);
		beg++;
	}
}

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::~map()
{
	clear();
}

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc> &ft::map<Key, T, Compare, Alloc>::operator=(const map &x)
{
	clear();
	comp = x.comp;
	alloc = x.alloc;
	ft::map<Key, T, Compare, Alloc>::const_iterator beg = x.begin();
	ft::map<Key, T, Compare, Alloc>::const_iterator end = x.end();

	while (beg != end)
	{
		bst.Insert(bst.GetRoot(), *beg);
		beg++;
	}
	return (*this);
}

// Member functions 

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::end()
{
	ft::map<Key, T, Compare, Alloc>::iterator it = this->begin();

	while (it.hasNext() == true)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator ft::map<Key, T, Compare, Alloc>::end() const
{
	ft::map<Key, T, Compare, Alloc>::const_iterator it = this->begin();

	while (it.hasNext() == true)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::reverse_iterator ft::map<Key, T, Compare, Alloc>::rend()
{
	ft::map<Key, T, Compare, Alloc>::reverse_iterator it = this->rbegin();

	while (it.hasNext() == true)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_reverse_iterator ft::map<Key, T, Compare, Alloc>::rend() const
{
	ft::map<Key, T, Compare, Alloc>::const_reverse_iterator it = this->rbegin();

	while (it.hasNext() == true)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::find(const ft::map<Key, T, Compare, Alloc>::key_type& k)
{
	if (bst.GetRoot() == NULL)
		return (this->end());

	ft::map<Key, T, Compare, Alloc>::iterator it = this->begin();
	ft::map<Key, T, Compare, Alloc>::iterator end = this->end();
	ft::map<Key, T, Compare, Alloc>::key_compare comp = this->key_comp();

	while (it != this->end() && comp(it->first, k) == true)
		it++;
	
	if (it == end || comp(k, it->first) == true)
		return (end);

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator ft::map<Key, T, Compare, Alloc>::find(const ft::map<Key, T, Compare, Alloc>::key_type& k) const
{
	if (bst.GetRoot() == NULL)
		return (this->end());

	ft::map<Key, T, Compare, Alloc>::const_iterator it = this->begin();
	ft::map<Key, T, Compare, Alloc>::iterator end = this->end();
	ft::map<Key, T, Compare, Alloc>::key_compare comp = this->key_comp();

	while (it != this->end() && comp(it->first, k) == true)
		it++;

	if (it == end || comp(k, it->first) == true)
		return (end);
		
	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::upper_bound(const key_type& k)
{
	ft::map<Key, T, Compare, Alloc>::iterator it = this->begin();
	ft::map<Key, T, Compare, Alloc>::key_compare comp = this->key_comp();

	while (it != this->end() && comp(k, it->first) != true)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator ft::map<Key, T, Compare, Alloc>::upper_bound(const key_type& k) const
{
	ft::map<Key, T, Compare, Alloc>::iterator it = this->begin();
	ft::map<Key, T, Compare, Alloc>::key_compare comp = this->key_comp();

	while (it != this->end() && comp(k, it->first) != true)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::lower_bound(const key_type& k)
{
	ft::map<Key, T, Compare, Alloc>::iterator it = this->begin();
	ft::map<Key, T, Compare, Alloc>::key_compare comp = this->key_comp();

	while (it != this->end() && comp(it->first, k) != false)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator ft::map<Key, T, Compare, Alloc>::lower_bound(const key_type& k) const
{
	ft::map<Key, T, Compare, Alloc>::const_iterator it = this->begin();
	ft::map<Key, T, Compare, Alloc>::key_compare comp = this->key_comp();

	while (it != this->end() && comp(it->first, k) != false)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Pair<typename ft::map<Key, T, Compare, Alloc>::iterator, typename ft::map<Key, T, Compare, Alloc>::iterator> ft::map<Key, T, Compare, Alloc>::equal_range(const key_type& k)
{
	return (ft::Pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Pair<typename ft::map<Key, T, Compare, Alloc>::const_iterator, typename ft::map<Key, T, Compare, Alloc>::const_iterator> ft::map<Key, T, Compare, Alloc>::equal_range(const key_type& k) const
{
	return (ft::Pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
}

// Member functions - getters

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type ft::map<Key, T, Compare, Alloc>::size() const
{
	return (bst.GetSize());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::mapped_type& ft::map<Key, T, Compare, Alloc>::operator[](const key_type &k)
{
	ft::map<Key, T, Compare, Alloc>::iterator it = find(k);

	if (it == this->end())
	{
		ft::BSTNode<value_type>* node = bst.Insert(bst.GetRoot(), Pair<Key, T>(k, 0));
		return (node->data.second);
	}
	else
		return (it->second);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type ft::map<Key, T, Compare, Alloc>::count(const key_type& k) const
{
	ft::map<Key, T, Compare, Alloc>::const_iterator it = this->begin();

	while (it != this->end())
	{
		if (it->first == k)
			return (1);
		it++;
	}
	return (0);
}

// Member functions - Setters

template <class Key, class T, class Compare, class Alloc>
void	ft::map<Key, T, Compare, Alloc>::erase(ft::map<Key, T, Compare, Alloc>::iterator position)
{
	if (position != this->end())
		bst.Delete(bst.GetRoot(), *position);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type	ft::map<Key, T, Compare, Alloc>::erase(const ft::map<Key, T, Compare, Alloc>::key_type &k)
{
	if (find(k) != this->end())
		bst.Delete(bst.GetRoot(), *find(k));

	return (bst.GetSize());
}

template <class Key, class T, class Compare, class Alloc>
void	ft::map<Key, T, Compare, Alloc>::erase(ft::map<Key, T, Compare, Alloc>::iterator first, ft::map<Key, T, Compare, Alloc>::iterator last)
{
	while (last-- != first)
		this->erase(last);
}

template <class Key, class T, class Compare, class Alloc>
ft::Pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool>	ft::map<Key, T, Compare, Alloc>::insert(const value_type &val)
{
	if (find(val.first) == this->end())
		return (ft::Pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool>(bst.Insert(bst.GetRoot(), val), true));

	return (ft::Pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool>(find(val.first), false));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator	ft::map<Key, T, Compare, Alloc>::insert(ft::map<Key, T, Compare, Alloc>::iterator position, const value_type &val)
{
	return (bst.Insert(position.curr(), val));
}

template <class Key, class T, class Compare, class Alloc>
template <class InputIterator>
void ft::map<Key, T, Compare, Alloc>::insert(typename ft::enable_if<std::is_base_of<typename InputIterator::iterator_category, std::__1::bidirectional_iterator_tag>::value, InputIterator>::type first, InputIterator last)
{
	while (first != last)
	{
		insert(*first);
		first++;
	}
}

// Relational operators

template <class Key, class T, class Compare, class Alloc>
bool operator==(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{ 
	if (lhs.size() != rhs.size())	
		return (false);

	typename ft::map<Key, T, Compare, Alloc>::const_iterator lhs_it = lhs.begin(); 
	typename ft::map<Key, T, Compare, Alloc>::const_iterator rhs_it = rhs.begin(); 

	while (lhs_it != lhs.end())
	{
		if (lhs_it->first != rhs_it->first)
			return (false);
		if (lhs_it->second != rhs_it->second)
			return (false);
		lhs_it++;
		rhs_it++;
	}

	return(true);
}

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{ 
	return(!(lhs == rhs));
}

template <class Key, class T, class Compare, class Alloc>
bool operator<( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{ 
	typename ft::map<Key, T, Compare, Alloc>::const_iterator lhs_it = lhs.begin(); 
	typename ft::map<Key, T, Compare, Alloc>::const_iterator rhs_it = rhs.begin(); 

	while (lhs_it != lhs.end())
	{
		if (lhs_it->first >= rhs_it->first)
			return (false);
		if (lhs_it->second >= rhs_it->second)
			return (false);
		lhs_it++;
		rhs_it++;
	}

	return(true);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{ 
	typename ft::map<Key, T, Compare, Alloc>::const_iterator lhs_it = lhs.begin(); 
	typename ft::map<Key, T, Compare, Alloc>::const_iterator rhs_it = rhs.begin(); 

	while (lhs_it != lhs.end())
	{
		if (lhs_it->first > rhs_it->first)
			return (false);
		if (lhs_it->second > rhs_it->second)
			return (false);
		lhs_it++;
		rhs_it++;
	}

	return(true);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{ 
	return (!(lhs <= rhs));
}

template <class Key, class T, class Compare, class Alloc>
bool operator>=( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{ 
	return (!(lhs < rhs));
}

// Other function

template <class Key, class T, class Compare, class Alloc>
void swap(ft::map<Key,T,Compare,Alloc>& x, ft::map<Key,T,Compare,Alloc>& y)
{
	x.swap(y);
}

#endif
