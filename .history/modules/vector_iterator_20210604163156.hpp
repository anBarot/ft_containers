#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "vector.hpp"


namespace ft
{

class Vector<T, Alloc>;

template<class T, class Alloc>
class Iterator
{
	public:
		typedef	Vector<T, Alloc>::Iterator	iterator;
		typedef	Vector<T, Alloc>::size_type	size_type;

	private:
	    Vector<T, Alloc>*	_pvector;
	    size_type 			_index;

	public:
		// Coplien
	    Iterator() 							{}
	    Iterator(iterator &it)				{}
	    Iterator(Vector<T>* vector, size_type index) : _pvector(vector), _index(index)	{}
		iterator &operator=(iterator &it) 	{
												_pvector = it._pvector; 
												_index = it._index;
												return (this);
											}
		~Iterator()							{}

		// Operator overload
	    reference operator*()				{ return (_pvector->at(this->_index)); }
	    iterator operator++()				{ ++_index; return (*this); }
	    iterator operator--()				{ --_index; return (*this); }
		iterator operator++(int)			{ iterator tmp(*this); ++_index; return(tmp); }
    	iterator operator--(int)			{ iterator tmp(*this); --_index; return(tmp); }
		iterator operator+(size_type i)		{ iterator tmp(_pvector, _index + i); return(tmp); }
    	iterator operator-(size_type i)		{ iterator tmp(_pvector, _index - i); return(tmp); }

		// Comparison operator overload
	    bool operator!=(const iterator &sec_it) const	{ return (_index != sec_it._index); }
	    bool operator==(const iterator &sec_it) const	{ return (_index == sec_it._index); }
	    bool operator>=(const iterator &sec_it) const	{ return (_index >= sec_it._index); }
	    bool operator>(const iterator &sec_it) const	{ return (_index > sec_it._index); }
	    bool operator<=(const iterator &sec_it) const	{ return (_index <= sec_it._index); }
	    bool operator<(const iterator &sec_it) const	{ return (_index < sec_it._index); }
};
}

#endif