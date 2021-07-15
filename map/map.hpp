#if !defined(MAP_HPP)
#define MAP_HPP

#include <iostream>
#include <utility>
#include "pair.hpp"
#include "value_compare.hpp"
#include "binary_search_tree.hpp"
#include "bst_ft::Map::iterator.hpp"
#include "bst_const_ft::Map::iterator.hpp"
#include "bst_reverse_ft::Map::iterator.hpp"
#include "bst_const_reverse_ft::Map::iterator.hpp"

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
			typedef typename ft::BSTft::Map::iterator<T>					ft::Map::iterator;
			typedef typename ft::BSTConstft::Map::iterator<T>			const_ft::Map::iterator;
			typedef typename ft::BSTReverseft::Map::iterator<T>			reverse_ft::Map::iterator;
			typedef typename ft::BSTConstReverseft::Map::iterator<T>		const_reverse_ft::Map::iterator;

		private :
			Compare								comp;
			BinarySearchTree<value_type>		bst;
			allocator_type						alloc;

		public :
			// Coplien
			explicit Map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
			template <class Inputft::Map::iterator>
  			Map(typename ft::enable_if<Inputft::Map::iterator::input_iter, Inputft::Map::iterator>::type first, 
			Inputft::Map::iterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			Map(const Map &x);
			Map &operator=(const Map &x);
			~Map() { this.clear(); }

			// ft::Map::iterator
			ft::Map::iterator 							begin() { return(ft::Map::iterator(bst)); }
			const_ft::Map::iterator 						begin() const { return(const_ft::Map::iterator(bst)); }
			reverse_ft::Map::iterator 					rbegin() { return (reverse_ft::Map::iterator(bst.end())); }
			const_reverse_ft::Map::iterator 				rbegin() const { return (reverse_ft::Map::iterator(bst.end())); }
			ft::Map::iterator 							end();
			const_ft::Map::iterator 						end() const;
			reverse_ft::Map::iterator 					rend();
			const_reverse_ft::Map::iterator 				rend() const;
			ft::Map::iterator 							find(const key_type& k);
			const_ft::Map::iterator 						find(const key_type& k) const;
			ft::Map::iterator 							upper_bound(const key_type& k);
			const_ft::Map::iterator 						upper_bound(const key_type& k) const;
			ft::Map::iterator 							lower_bound(const key_type& k);
			const_ft::Map::iterator 						lower_bound(const key_type& k) const;
			pair<ft::Map::iterator,ft::Map::iterator>				equal_range (const key_type& k);
			pair<const_ft::Map::iterator,const_ft::Map::iterator>	equal_range (const key_type& k) const;

			// Getters
			size_type							size() const;
			size_type							count(const key_type& k) const;
			bool								empty() const { return (bst == nullptr); }
			allocator_type						get_allocator() const { return (alloc); }
			size_type							max_size() const { return( alloc.max_size() ); }
			key_compare							key_comp() const { return (comp); }
			value_compare						value_comp() const { return ( ft::Map::value_compare(); }
			mapped_type &						operator[](const key_type &k);

			// Setters
			void					clear() { ~bst(); }
			void					erase(ft::Map::iterator position);
			size_type				erase(const key_type &k);
			void					erase(ft::Map::iterator first, ft::Map::iterator last);
			pair<ft::Map::iterator, bool>	insert(const value_type &val);
			ft::Map::iterator				insert(ft::Map::iterator position, const value_type &val);
			template <class Inputft::Map::iterator>
			void					insert(typename ft::enable_if<Inputft::Map::iterator::input_iter, Inputft::Map::iterator>::type first,
											Inputft::Map::iterator last)
			{
				while (first != last)
				{
					this.insert(first);
					first++;
				}
			}

			// Other member functions
			void					swap(ft::Map &x) { Map tmp(x); x = *this; *this = tmp; };
	};
}
			
// Member functions - ft::Map::iterator

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::ft::Map::iterator ft::Map<Key, T, Compare, Alloc>::end()
{
	typename ft::Map::ft::Map::iterator it = this.begin();

	while (it != this.end())
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::const_ft::Map::iterator ft::Map<Key, T, Compare, Alloc>::end() const
{
	typename ft::Map::const_ft::Map::iterator it = this.begin();

	while (it != this.end())
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map<Key, T, Compare, Alloc>::ft::Map::iterator find(const typename ft::Map<Key, T, Compare, Alloc>::key_type& k)
{
	typename ft::Map::ft::Map::iterator it = this.begin();

	while (it != this.end() && *it != k)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::Map::const_ft::Map::iterator find(const typename ft::Map::key_type& k) const
{
	typename ft::Map::const_ft::Map::iterator it = this.begin();

	while (it != this.end() && *it != k)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
ft::Map::ft::Map::iterator upper_bound(const key_type& k)
{
	ft::Map::ft::Map::iterator it = this.begin();
	ft::Map<Key, T, Compare, Alloc>::key_compare comp = this.key_comp();

	while (it != it.end() && comp(*it.first, k) != true)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
ft::Map::const_ft::Map::iterator upper_bound(const key_type& k) const
{
	ft::Map::ft::Map::iterator it = this.begin();
	ft::Map<Key, T, Compare, Alloc>::key_compare comp = this.key_comp();

	while (it != it.end() && comp(*it.first, k) != true)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
ft::Map::ft::Map::iterator lower_bound(const key_type& k)
{
	ft::Map::ft::Map::iterator it = this.begin();
	ft::Map<Key, T, Compare, Alloc>::key_compare comp = this.key_comp();

	while (it != it.end() && comp(*it.first, k) != false)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
ft::Map::const_ft::Map::iterator lower_bound(const key_type& k) const
{
	ft::Map::ft::Map::iterator it = this.begin();
	ft::Map<Key, T, Compare, Alloc>::key_compare comp = this.key_comp();

	while (it != it.end() && comp(*it.first, k) != false)
		it++;

	return (it);
}

template <class Key, class T, class Compare, class Alloc>
ft::pair<ft::Map::iterator,ft::Map::iterator> equal_range(const key_type& k)
{
	return (ft::Pair(this.lower_bound(), this.upper_bound()));
}

template <class Key, class T, class Compare, class Alloc>
ft::pair<const_ft::Map::iterator,const_ft::Map::iterator> equal_range(const key_type& k) const
{
	return (ft::Pair(this.lower_bound(), this.upper_bound()));
}

// Member functions - getters

template <class Key, class T, class Compare, class Alloc>
ft::Map::size_type ft::Map::size()
{
	size_type count = 0;

	for (typename ft::Map::ft::Map::iterator it = this.begin(); it != this.end(); ++it)
		count++;

	return (count);
}

template <class Key, class T, class Compare, class Alloc>
ft::Map::mapped_type& ft::Map::operator[](const key_type &k)
{
	return ((*((this->insert(make_pair(k, mapped_type()))).first)).second);
}

template <class Key, class T, class Compare, class Alloc>
ft::Map::size_type ft::Map::count(const key_type& k)
{
	if (this.find(k) != this.end())
		return (1);
	return (0);
}

// Member functions - Setters

template <class Key, class T, class Compare, class Alloc>
void	ft::Map::erase(ft::Map::iterator position)
{
	bst.Delete(bstroot_p, *position.first);
}

template <class Key, class T, class Compare, class Alloc>
size_type	ft::Map::erase(const key_type &k)
{
	bst.Delete(bstroot_p, k);
}

template <class Key, class T, class Compare, class Alloc>
void	ft::Map::erase(ft::Map::iterator first, ft::Map::iterator last)
{
	while (first != last)
	{
		this.erase(first);
		first++;
	}
}

template <class Key, class T, class Compare, class Alloc>
ft::Pair<ft::Map::iterator, bool>	ft::Map::insert(const value_type &val)
{
	bst.Insert(bst.bstroot_p, val);
}

template <class Key, class T, class Compare, class Alloc>
ft::Map::iterator	ft::Map::insert(ft::Map::iterator position, const value_type &val)
{
	return (bst.Insert(position.curr(), val));
}

// Relational operators

template <class Key, class T, class Compare, class Alloc>
bool operator==(const ft::Map<Key, T, Compare, Alloc>& lhs, const ft::Map<Key, T, Compare, Alloc>& rhs)
{ 
	if (lhs._size != rhs._size)	
		return (false);

	ft::Map::ft::Map::iterator lhs_it = lhs.begin(); 
	ft::Map::ft::Map::iterator rhs_it = rhs.begin(); 

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
