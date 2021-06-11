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
	    Vector<T, Alloc>*	_pvector;
	    size_type 			_index;

	public:
		// Coplien
	    Reverse_Iterator() 									{};
	    Reverse_Iterator(const reverse_iterator &it)		{};
	    Reverse_Iterator(Vector<T>* vector, size_type index) : _pvector(vector), _index(index)	{};
		reverse_iterator &operator=(reverse_iterator &it) 	{
																this->_pvector = it._pvector; 
																this->_index = it._index;
																return (this);
															}
		~Reverse_Iterator()									{};

		// Operator overload
	    reference operator*() const					{ return (*_pvector); }
	    reverse_iterator operator++()				{ --this->_index; return (*this); }
	    reverse_iterator operator--()				{ ++this->_index; return (*this); }
		reverse_iterator operator++(int)			{ reverse_iterator tmp(*this); --this->_index; return(tmp); }
    	reverse_iterator operator--(int)			{ reverse_iterator tmp(*this); ++this->_index; return(tmp); }
		reverse_iterator operator+(size_type i)		{ reverse_iterator tmp(this->_pvector, this->_index - i); return(tmp); }
    	reverse_iterator operator-(size_type i)		{ reverse_iterator tmp(this->_pvector, this->_index + i); return(tmp); }

		// Comparison operator overload
	    bool operator!=(const iterator &sec_it) const	{ return (_index != sec_it._index); }
	    bool operator==(const iterator &sec_it) const	{ return (_index == sec_it._index); }
	    bool operator>=(const iterator &sec_it) const	{ return (_index >= sec_it._index); }
	    bool operator>(const iterator &sec_it) const	{ return (_index > sec_it._index); }
	    bool operator<=(const iterator &sec_it) const	{ return (_index <= sec_it._index); }
	    bool operator<(const iterator &sec_it) const	{ return (_index < sec_it._index); }
};

#endif