#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

namespace ft
{
	template <class T>
	class VectorIterator
	{
		public :
			typedef T	value_type;
			typedef T*	pointer;
			typedef T&	reference;

		private:
		    pointer			_pvector;

		public:
			// Coplien
		    Iterator() 							{}
		    Iterator(iterator &it)				{ _pvector = it._pvector }
		    Iterator(pointer vector) : _pvector(vector) {}
			iterator &operator=(iterator &it) 	{
													_pvector = it._pvector; 
													_index = it._index;
													return (this);
												}
			~Iterator()							{}

			// Operator overload
		    reference operator*()				{ return (_pvector->at(this->_index)); }
		    iterator operator++()				{ ++_pvector; return (*this); }
		    iterator operator--()				{ --_pvector; return (*this); }
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