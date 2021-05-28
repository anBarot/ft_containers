#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

template<class T>
class ft::Vector<T>::Iterator
{
	private:
	    const Vector<T>*	_pvector;
	    size_type 			_index;

	public:
		// Coplien
	    Iterator() 							{}
	    Iterator(const iterator &it)		{}
	    Iterator(const Vector<T> *vector, size_type index) : _pvector(vector), _index(index)	{}
		iterator &operator=(iterator &it) 	{
												this->_pvector = it._pvector; 
												this->_index = it._index;
												return (this);
											};
		~Iterator()							{}

		// Operator overload
	    const_reference operator*() const	{ return (this->_pvector->at(this->_index)); }
	    iterator operator++()				{ ++this->_index; return (*this); }
	    iterator operator--()				{ --this->_index; return (*this); }
		iterator operator++(int)			{ iterator tmp(*this); ++this->_index; return(tmp); }
    	iterator operator--(int)			{ iterator tmp(*this); --this->_index; return(tmp); }
		iterator operator+(size_type i)		{ iterator tmp(this->_pvector, this->_index + i); return(tmp); }
    	iterator operator-(size_type i)		{ iterator tmp(this->_pvector, this->_index - i); return(tmp); }

		// Comparison operator overload
	    bool operator!=(const iterator &sec_it) const	{ return (_index != sec_it._index); }
	    bool operator==(const iterator &sec_it) const	{ return (_index == sec_it._index); }
	    bool operator>=(const iterator &sec_it) const	{ return (_index >= sec_it._index); }
	    bool operator>(const iterator &sec_it) const	{ return (_index > sec_it._index); }
	    bool operator<=(const iterator &sec_it) const	{ return (_index <= sec_it._index); }
	    bool operator<(const iterator &sec_it) const	{ return (_index < sec_it._index); }
};

#endif // VECTOR_ITERATOR_HPP