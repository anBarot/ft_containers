#ifndef VECTOR_CONST_ITERATOR_HPP
#define VECTOR_CONST_ITERATOR_HPP

#include <iostream>
#include <cstddef>

namespace ft
{
	template <class T>
	class VectorConstIterator
	{
		public:
			typedef const T								value_type;
    		typedef std::ptrdiff_t						difference_type;
    		typedef const T*							pointer;
    		typedef T&									reference;
    		typedef std::random_access_iterator_tag		iterator_category;
			typedef ft::VectorConstIterator<const T>	const_iterator;

		private:
		    pointer	_pvector;

		public:
			// Coplien
		    VectorConstIterator() 							{}
		    VectorConstIterator(const const_iterator &it) : _pvector(it._pvector)	{}
		    VectorConstIterator(const pointer vector) : _pvector(vector)	{}
			const_iterator &operator=(const_iterator &it) 	{ _pvector = it._pvector; return (this); }
			~VectorConstIterator()							{}

			// Operator overload
		    reference operator*() const				{ return (*_pvector); }
			reference operator[](int i)				{ return (*(_pvector + i)); }
		    const_iterator operator++()				{ ++_pvector; return (*this); }
		    const_iterator operator--()				{ --_pvector; return (*this); }
			const_iterator operator++(int)			{ const_iterator tmp(*this); ++_pvector; return(tmp); }
	    	const_iterator operator--(int)			{ const_iterator tmp(*this); --_pvector; return(tmp); }
			const_iterator operator+(size_t i)		{ const_iterator tmp(_pvector + i); return(tmp); }
	    	const_iterator operator-(size_t i)		{ const_iterator tmp(_pvector - i); return(tmp); }

			// Comparison operator overload
		    bool operator!=(const const_iterator &sec_it) const	{ return (_pvector != sec_it._pvector); }
		    bool operator==(const const_iterator &sec_it) const	{ return (_pvector == sec_it._pvector); }
		    bool operator>=(const const_iterator &sec_it) const	{ return (_pvector >= sec_it._pvector); }
		    bool operator>(const const_iterator &sec_it) const	{ return (_pvector > sec_it._pvector); }
		    bool operator<=(const const_iterator &sec_it) const	{ return (_pvector <= sec_it._pvector); }
		    bool operator<(const const_iterator &sec_it) const	{ return (_pvector < sec_it._pvector); }

			// Is input iterator
			static const bool input_iter = true;
	};
}

#endif
