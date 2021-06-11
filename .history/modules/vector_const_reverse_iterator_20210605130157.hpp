#ifndef VECTOR_CONST_REVERSE_ITERATOR_HPP
#define VECTOR_CONST_REVERSE_ITERATOR_HPP

namespace ft
{
	template <class T>
	class VectorConst_Reverse_Iterator
	{
		public:
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef VectorConst_Reverse_Iterator	const_reverse_iterator;

		private:
		    const pointer		_pvector;

		public:
			// Coplien
		    VectorConst_Reverse_Iterator() 										{}
		    VectorConst_Reverse_Iterator(const const_reverse_iterator &it)
			: _pvector(it._pvector)			{}
		    VectorConst_Reverse_Iterator(const pointer vector)
			: _pvector(vector)										{}
			const_reverse_iterator &operator=(const_reverse_iterator &it) 	{ _pvector = it._pvector; return (this); }
			~VectorConst_Reverse_Iterator()										{}

			// Operator overload
		    reference operator*() const						{ return (*_pvector); }
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