#ifndef VECTOR_CONST_ITERATOR_HPP
#define VECTOR_CONST_ITERATOR_HPP

namespace ft
{
	template <class T>
	class VectorConst_Iterator
	{
		public:
			typedef T						value_type;
			typedef T*						pointer;
			typedef T&						reference;
			typedef VectorConst_Iterator	const_iterator;

		private:
		    const pointer	_pvector;

		public:
			// Coplien
		    VectorConst_Iterator() 							{}
		    VectorConst_Iterator(const const_iterator &it) : _pvector(it._pvector)	{}
		    VectorConst_Iterator(const pointer vector) : _pvector(vector._pvector)	{}
			const_iterator &operator=(const_iterator &it) 	{ _pvector = it._pvector; return (this); }
			~VectorConst_Iterator()							{}

			// Operator overload
		    reference operator*() const				{ return (*_pvector); }
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
	};
}

#endif