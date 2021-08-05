#ifndef VECTOR_REVERSE_ITERATOR_HPP
#define VECTOR_REVERSE_ITERATOR_HPP

#include <iostream>
#include <cstddef>

namespace ft
{
	template<class T>
	class VectorReverseIterator
	{
		public:
			typedef T										value_type;
    		typedef std::ptrdiff_t							difference_type;
    		typedef T*										pointer;
    		typedef T&										reference;
    		typedef std::random_access_iterator_tag			iterator_category;
			typedef ft::VectorReverseIterator<T>			reverse_iterator;

		private:
		    pointer		_pvector;

		public:
			// Coplien
		    VectorReverseIterator() 									{};
		    VectorReverseIterator(const reverse_iterator &it) : _pvector(it._pvector)		{};
		    VectorReverseIterator(pointer vector) : _pvector(vector)	{};
			reverse_iterator &operator=(reverse_iterator &it) 	{ _pvector = it._pvector; return (this); }
			~VectorReverseIterator()							{};

			// Operator overload
		    reference operator*() const					{ return (*_pvector); }
			reference operator[](int i)					{ return (*(_pvector + i)); }
		    reverse_iterator operator++()				{ --_pvector; return (*this); }
		    reverse_iterator operator--()				{ ++_pvector; return (*this); }
			reverse_iterator operator++(int)			{ reverse_iterator tmp(*this); --_pvector; return(tmp); }
	    	reverse_iterator operator--(int)			{ reverse_iterator tmp(*this); ++_pvector; return(tmp); }
			reverse_iterator operator+(size_t i)		{ reverse_iterator tmp(_pvector - i); return(tmp); }
	    	reverse_iterator operator-(size_t i)		{ reverse_iterator tmp(_pvector + i); return(tmp); }

			// Comparison operator overload
		    bool operator!=(const reverse_iterator &sec_it) const	{ return (_pvector != sec_it._pvector); }
		    bool operator==(const reverse_iterator &sec_it) const	{ return (_pvector == sec_it._pvector); }
		    bool operator>=(const reverse_iterator &sec_it) const	{ return (_pvector >= sec_it._pvector); }
		    bool operator>(const reverse_iterator &sec_it) const	{ return (_pvector > sec_it._pvector); }
		    bool operator<=(const reverse_iterator &sec_it) const	{ return (_pvector <= sec_it._pvector); }
		    bool operator<(const reverse_iterator &sec_it) const	{ return (_pvector < sec_it._pvector); }

			// Is input iterator
			static const bool input_iter = true;
	};
}

#endif
