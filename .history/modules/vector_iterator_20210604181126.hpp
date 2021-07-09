#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

namespace ft
{
	template <class T>
	class VectorIterator
	{
		public:
			typedef T	value_type;
			typedef T*	pointer;
			typedef T&	reference;

		private:
		    pointer			_pvector;

		public:
			// Coplien
		    Iterator() 							{}
		    Iterator(iterator &it) : _pvector(it.p_vector) {}
		    Iterator(pointer vector) : _pvector(vector.p_vector) {}
			iterator &operator=(iterator &it) 	{ _pvector = it._pvector; return (this); }
			~Iterator()							{}

			// Operator overload
		    reference operator*()				{ return (_pvector); }
		    iterator operator++()				{ ++_pvector; return (*this); }
		    iterator operator--()				{ --_pvector; return (*this); }
			iterator operator++(int)			{ iterator tmp(*this); ++_pvector; return(tmp); }
	    	iterator operator--(int)			{ iterator tmp(*this); --_pvector; return(tmp); }
			iterator operator+(size_t i)		{ iterator tmp(_pvector + (i * sizeof(T))); return(tmp); }
	    	iterator operator-(size_t i)		{ iterator tmp(_pvector - (i * sizeof(T))); return(tmp); }

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