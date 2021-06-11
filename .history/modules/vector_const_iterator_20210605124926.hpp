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
		    const ft::Vector<T, Alloc>*		_pvector;
	
		public:
			// Coplien
		    Const_Iterator() 							{}
		    Const_Iterator(const const_iterator &it)		{}
		    Const_Iterator(const ft::Vector<T, Alloc>* vector, size_type index) : _pvector(vector), _index(index)	{}
			const_iterator &operator=(const_iterator &it) 	{
													this->_pvector = it._pvector; 
													return (this);
												};
			~Const_Iterator()							{}
	
			// Operator overload
		    const_reference operator*() const	{ return (this->_pvector->at(this->_index)); }
		    const_iterator operator++()				{ ++this->_index; return (*this); }
		    const_iterator operator--()				{ --this->_index; return (*this); }
			const_iterator operator++(int)			{ const_iterator tmp(*this); ++this->_index; return(tmp); }
	    	const_iterator operator--(int)			{ const_iterator tmp(*this); --this->_index; return(tmp); }
			const_iterator operator+(size_type i)		{ const_iterator tmp(this->_pvector, this->_index + i); return(tmp); }
	    	const_iterator operator-(size_type i)		{ const_iterator tmp(this->_pvector, this->_index - i); return(tmp); }
	
			// Comparison operator overload
		    bool operator!=(const const_iterator &sec_it) const	{ return (_index != sec_it._index); }
		    bool operator==(const const_iterator &sec_it) const	{ return (_index == sec_it._index); }
		    bool operator>=(const const_iterator &sec_it) const	{ return (_index >= sec_it._index); }
		    bool operator>(const const_iterator &sec_it) const	{ return (_index > sec_it._index); }
		    bool operator<=(const const_iterator &sec_it) const	{ return (_index <= sec_it._index); }
		    bool operator<(const const_iterator &sec_it) const	{ return (_index < sec_it._index); }
	};
}

#endif