#ifndef VECTOR_REVERSE_ITERATOR_HPP
#define VECTOR_REVERSE_ITERATOR_HPP

#include "vector.hpp"

template<class T, class Alloc>
class VectorReverse_Iterator
{
	public:
			typedef T						value_type;
			typedef T*						pointer;
			typedef T&						reference;
			typedef VectorReverse_Iterator	reverse_iterator;

	private:
	    pointer		_pvector;

	public:
		// Coplien
	    VectorReverse_Iterator() 									{};
	    VectorReverse_Iterator(const reverse_iterator &it)			{};
	    VectorReverse_Iterator(pointer vector) : _pvector(vector._pvector)	{};
		reverse_iterator &operator=(reverse_iterator &it) 	{ _pvector = it._pvector; return (this); }
		~VectorReverse_Iterator()							{};

		// Operator overload
	    reference operator*() const					{ return (*_pvector); }
	    reverse_iterator operator++()				{ --_pvector; return (*this); }
	    reverse_iterator operator--()				{ ++_pvector; return (*this); }
		reverse_iterator operator++(int)			{ reverse_iterator tmp(*this); --_pvector; return(tmp); }
    	reverse_iterator operator--(int)			{ reverse_iterator tmp(*this); ++_pvector; return(tmp); }
		reverse_iterator operator+(size_type i)		{ reverse_iterator tmp(_pvector - i); return(tmp); }
    	reverse_iterator operator-(size_type i)		{ reverse_iterator tmp(_pvector + i); return(tmp); }

		// Comparison operator overload
	    bool operator!=(const iterator &sec_it) const	{ return (_pvector != sec_it._pvector); }
	    bool operator==(const iterator &sec_it) const	{ return (_pvector == sec_it._pvector); }
	    bool operator>=(const iterator &sec_it) const	{ return (_pvector >= sec_it._pvector); }
	    bool operator>(const iterator &sec_it) const	{ return (_pvector > sec_it._pvector); }
	    bool operator<=(const iterator &sec_it) const	{ return (_pvector <= sec_it._pvector); }
	    bool operator<(const iterator &sec_it) const	{ return (_pvector < sec_it._pvector); }
};

#endif