#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

namespace ft
{
	template <class T>
	class VectorIterator
	{
		public:
			typedef T				value_type;
			typedef T*				pointer;
			typedef T&				reference;
			typedef VectorIterator	iterator;

		private:
		    pointer			_pvector;

		public:
			// Coplien
		    VectorIterator() {}
		    VectorIterator(iterator &it) : _pvector(it._pvector) {}
		    VectorIterator(pointer vector) : _pvector(vector) {}
			iterator &operator=(iterator &it) 	{ _pvector = it._pvector; return (this); }
			~VectorIterator()					{}

			// Operator overload
			reference operator*()				{ return (*_pvector); }
			iterator operator++()				{ ++_pvector; return (*this); }
			iterator operator--()				{ --_pvector; return (*this); }
			iterator operator++(int)			{ iterator tmp(*this); ++_pvector; return(tmp); }
	    	iterator operator--(int)			{ iterator tmp(*this); --_pvector; return(tmp); }
			iterator operator+(size_t i)		{ iterator tmp(_pvector + i); return(tmp); }
	    	iterator operator-(size_t i)		{ iterator tmp(_pvector - i); return(tmp); }

			// Comparison operator overload
		    bool operator!=(const iterator &sec_it) const	{ return (_pvector != sec_it._pvector); }
		    bool operator==(const iterator &sec_it) const	{ return (_pvector == sec_it._pvector); }
		    bool operator>=(const iterator &sec_it) const	{ return (_pvector >= sec_it._pvector); }
		    bool operator>(const iterator &sec_it) const	{ return (_pvector > sec_it._pvector); }
		    bool operator<=(const iterator &sec_it) const	{ return (_pvector <= sec_it._pvector); }
		    bool operator<(const iterator &sec_it) const	{ return (_pvector < sec_it._pvector); }
	};
}

#endif