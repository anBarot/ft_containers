#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

namespace ft
{
	template <class T>
	class VectorIterator
	{
		public:
			typedef T						value_type;
			typedef T*						pointer;
			typedef T&						reference;
			typedef ft::VectorIterator<T>	iterator;

		private:
		    pointer			_pvector;

		public:
			// Coplien
		    VectorIterator() {}
		    VectorIterator(const iterator &it) { *this = it; }
		    VectorIterator(pointer vector) : _pvector(vector) {}
			iterator &operator=(const iterator &it) { _pvector = it._pvector; return (*this); }
			~VectorIterator()					{}

			// Operator overload
			reference operator*()				{ return (*_pvector); }
			iterator operator++()				{ ++_pvector; return (*this); }
			iterator operator--()				{ --_pvector; return (*this); }
			iterator operator++(int)			{ iterator tmp(*this); ++_pvector; return(tmp); }
	    	iterator operator--(int)			{ iterator tmp(*this); --_pvector; return(tmp); }
			iterator operator+(size_t i)		{ return (iterator(_pvector + i)); }
	    	iterator operator-(size_t i)		{ return (iterator(_pvector - i)); }

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