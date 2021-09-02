#ifndef VECTOR_CONST_REVERSE_ITERATOR_HPP
#define VECTOR_CONST_REVERSE_ITERATOR_HPP

#include <iostream>
#include <cstddef>
#include "../tools/iterator_traits.hpp"

namespace ft
{
	template <class T>
	class VectorConstReverseIterator : public ft::iterator_traits<std::random_access_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator_traits<std::random_access_iterator_tag, T>::iterator_category iterator_category;
			typedef const T										value_type;
    		typedef const T*									pointer;
			typedef T&    						          		reference;
			typedef ft::VectorConstReverseIterator<const T>		const_reverse_iterator;

		private:
		    const pointer		_pvector;

		public:
			// Coplien
		    VectorConstReverseIterator() 										{}
		    VectorConstReverseIterator(const const_reverse_iterator &it)
			: _pvector(it._pvector)			{}
		    VectorConstReverseIterator(const pointer vector)
			: _pvector(vector)										{}
			const_reverse_iterator &operator=(const_reverse_iterator &it) 	{ _pvector = it._pvector; return (this); }
			~VectorConstReverseIterator()										{}

			// Getter
			pointer		GetPointer() { return(_pvector); }

			// Operator overload
		    reference operator*() const						{ return (*_pvector); }
			reference operator[](int i)						{ return (*(_pvector + i)); }
		    const_reverse_iterator operator++()				{ --_pvector; return (*this); }
		    const_reverse_iterator operator--()				{ ++_pvector; return (*this); }
			const_reverse_iterator operator++(int)			{ const_reverse_iterator tmp(*this); --_pvector; return(tmp); }
	    	const_reverse_iterator operator--(int)			{ const_reverse_iterator tmp(*this); ++_pvector; return(tmp); }
			const_reverse_iterator operator+(size_t i)		{ const_reverse_iterator tmp(_pvector - i); return(tmp); }
	    	const_reverse_iterator operator-(size_t i)		{ const_reverse_iterator tmp(_pvector + i); return(tmp); }

			// Comparison operator overload
		    bool operator!=(const const_reverse_iterator &sec_it) const	{ return (_pvector != sec_it._pvector); }
		    bool operator==(const const_reverse_iterator &sec_it) const	{ return (_pvector == sec_it._pvector); }
		    bool operator>=(const const_reverse_iterator &sec_it) const	{ return (_pvector <= sec_it._pvector); }
		    bool operator>(const const_reverse_iterator &sec_it) const	{ return (_pvector < sec_it._pvector); }
		    bool operator<=(const const_reverse_iterator &sec_it) const	{ return (_pvector >= sec_it._pvector); }
		    bool operator<(const const_reverse_iterator &sec_it) const	{ return (_pvector > sec_it._pvector); }
	};
}

#endif
