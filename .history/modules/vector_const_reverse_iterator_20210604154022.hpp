#ifndef VECTOR_CONST_REVERSE_ITERATOR_HPP
#define VECTOR_CONST_REVERSE_ITERATOR_HPP

#include "vector.hpp"

template<class T, class Alloc>
class ft::Vector<T, Alloc>::Const_Reverse_Iterator
{
	private:
	    const ft::Vector<T>*	_pvector;
	    size_type 			_index;

	public:
		// Coplien
	    Const_Reverse_Iterator() 										{}
	    Const_Reverse_Iterator(const const_reverse_iterator &it)		{}
	    Const_Reverse_Iterator(const Vector<T>* vector, size_type index)
		: _pvector(vector), _index(index)								{}
		const_reverse_iterator &operator=(const_reverse_iterator &it) 	{
																			this->_pvector = it._pvector;
																			this->_index = it._index;
																			return (this);
																		}
		~Const_Reverse_Iterator()										{}

		// Operator overload
	    const_reference operator*() const				{ return (this->_pvector->at(this->_index)); }
	    const_reverse_iterator operator++()				{ --this->_index; return (*this); }
	    const_reverse_iterator operator--()				{ ++this->_index; return (*this); }
		const_reverse_iterator operator++(int)			{ const_reverse_iterator tmp(*this); --this->_index; return(tmp); }
    	const_reverse_iterator operator--(int)			{ const_reverse_iterator tmp(*this); ++this->_index; return(tmp); }
		const_reverse_iterator operator+(size_type i)	{ const_reverse_iterator tmp(this->_pvector, this->_index - i); return(tmp); }
    	const_reverse_iterator operator-(size_type i)	{ const_reverse_iterator tmp(this->_pvector, this->_index + i); return(tmp); }

		// Comparison operator overload
	    bool operator!=(const const_reverse_iterator &sec_it) const	{ return (_index != sec_it._index); }
	    bool operator==(const const_reverse_iterator &sec_it) const	{ return (_index == sec_it._index); }
	    bool operator>=(const const_reverse_iterator &sec_it) const	{ return (_index <= sec_it._index); }
	    bool operator>(const const_reverse_iterator &sec_it) const	{ return (_index < sec_it._index); }
	    bool operator<=(const const_reverse_iterator &sec_it) const	{ return (_index >= sec_it._index); }
	    bool operator<(const const_reverse_iterator &sec_it) const	{ return (_index > sec_it._index); }
};

#endif