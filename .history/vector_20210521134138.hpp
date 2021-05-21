#ifndef VECTOR_HPP 
#define VECTOR_HPP

#include <iostream>
#include <bits/stl_iterator_base_funcs.h>

namespace ft
{
	template<class T>
	class Vector
	{
		private:
			T 		*_ptr;
	   		size_t	_capacity;
			size_t	_size;

		public:
			class Iterator; // class implementation at EOF

			typedef	T 									value_type;
			typedef	T& 									reference;
			typedef	const T& 							const_reference;
			typedef	T* 									pointer;
			typedef	const T* 							const_pointer;
			typedef	size_t 								size_type;
			typedef	size_type 							difference_type;

			// Coplien
			Vector() : _capacity(0), _size(0), _ptr(0) {}
			Vector(size_t n_size) : _capacity(n_size), _size(n_size) { _ptr = new T[n_size]; }
			Vector(size_t n_size, const T&init);
			Vector(const Vector<T> &vector);
			Vector<T> &operator=(const Vector<T> &vector);
			~Vector() { delete[](this->_ptr); };

			// Iterator
			Iterator	begin() { return (Iterator(this, 0)); }
			Iterator	end() { return (Iterator(this, this->_size)); }

			// Getters
			size_t			size() const { return (this->_size); }
			size_t			capacity() const { return (this->_capacity); }
			pointer			data() { return (this->_ptr); };
			const_pointer	data() const { return (this->_ptr); };
			reference		at (size_type n) { return (this->_ptr[n]); };
			const_reference	at (size_type n) const { return (this->_ptr[n]); };
			reference		back() { return (this->_ptr[this->_size - 1]); }
			const_reference	back() const { return (this->_ptr[this->_size - 1]); }
			reference		front() { return (this->_ptr[0]); }
			const_reference	front() const { return (this->_ptr[0]); }
			// max_size

			// Setters
			void			push_back(const_reference value);
			void			pop_back() { this->_size--; }

			// Resizers
			void			reserve(size_type capacity);   
			void			resize(size_type size);

			// Empty and clear
			bool			empty() const { return (this->_size == 0); }
			void			clear() { this->_size = 0; }


			// assign
			// swap
			// shrink_to_fit
			// emplace
			// emplace_back
			// erase
			// insert

			// Operator overloads
			reference operator[](size_type n) { return (this->_ptr[n]); };
	};
}

// Coplien implementation

template<class T>
ft::Vector<T>::Vector(size_type n_size, const_reference init) : _capacity(n_size), _size(n_size)
{
	_ptr = new T[n_size];	
	for (size_t i = 0; i < n_size; i++)
		_ptr[i] = init;
}

template<class T>
ft::Vector<T>::Vector(const ft::Vector<T>&vector)
{
	this->_size = vector._size;
	this->_capacity = vector._capacity;
	this->_ptr = new T[vector._size];
	for (size_t i = 0; i < vector._size; i++)
		_ptr[i] = vector._ptr[i];
}

template<class T>
ft::Vector<T> &ft::Vector<T>::operator=(const Vector<T> &vector)
{
	this->_size = vector._size;
	this->_capacity = vector._capacity;
	this->_ptr = new T[vector._size];
	for (size_t i = 0; i < vector._size; i++)
		_ptr[i] = vector._ptr[i];
	return (this);
}

// Vector methods

template<class T>
void ft::Vector<T>::push_back(const_reference value)
{
	if (this->_size <= this->_capacity)
		this->reserve(this->_capacity + 3);
	this->_ptr[this->_size] = value;
	this->_capacity = this->_capacity + 3;
	this->_size = this->_size + 1;
}


template<class T>
void ft::Vector<T>::reserve(size_type capacity)
{
	if(this->_ptr == 0)
    {
        this->_size = 0;
        this->_capacity = 0;
    }
	T *n_ptr = new T[capacity];
	
	for (size_t i = 0; i < this->_size; i++)
    	n_ptr[i] = this->_ptr[i];
	if (this->_ptr)
    	delete[](this->_ptr);
    this->_ptr = n_ptr;

}

template<class T>
void ft::Vector<T>::resize(size_type size)
{
	reserve(size);
    this->_size = size;
}

// Iterator class

template<class T>
class ft::Vector<T>::Iterator
{
	private:
	    const Vector<T>*	_pvector;
	    size_type 			_index;

	public:
		// Coplien
	    Iterator() {}
	    Iterator(const Iterator &it) {}
	    Iterator(const Vector<T> *vector, size_type index) : _pvector(vector), _index(index) {}
		Iterator &operator=(Iterator &it) 	{
												this->_pvector = it._pvector; 
												this->_index = it._index;
												return (this);
											};
		~Iterator() {}

		// Operator overload
	    const_reference operator*() const { return (this->_pvector); }
	    Iterator &operator++() { ++this->_index; return (*this); }
	    Iterator &operator--() { --this->_index; return (*this); }
		Iterator &operator++(int){ tmp(*this); ++this->_index; return(tmp);}
    	Iterator &operator--(int){ tmp(*this); --this->_index; return(tmp);}

		// Comparison operator overload
	    bool operator!=(const Iterator &sec_it) const { return (_index != sec_it._index); }
	    bool operator==(const Iterator &sec_it) const { return (_index == sec_it._index); }
	    bool operator>=(const Iterator &sec_it) const { return (_index >= sec_it._index); }
	    bool operator>(const Iterator &sec_it) const { return (_index > sec_it._index); }
	    bool operator<=(const Iterator &sec_it) const { return (_index <= sec_it._index); }
	    bool operator<(const Iterator &sec_it) const { return (_index < sec_it._index); }
};

#endif // VECTOR_HPP