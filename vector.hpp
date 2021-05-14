#ifndef VECTOR_HPP 
#define VECTOR_HPP

#include <iostream>
#include <iterator>
// #include "iterator.hpp"

namespace ft
{
	template<class T>
	class Vector
	{
		private:
			T 		*_ptr;
			size_t	_size;
	   		size_t	_capacity;

		public:
			// Coplien
			Vector() : _capacity(0), _size(0), _ptr(0) {}
			Vector(size_t n_size) : _capacity(n_size), _size(n_size) { _ptr = new T[n_size]; }
			Vector(size_t n_size, const T&init);
			Vector(const Vector<T> &vector);
			Vector<T> &operator=(const Vector<T> &vector);
			~Vector() { delete[](this->_ptr); };

			// Iterator member function
			// iterator<T> begin() { return (this->ptr); }
			// iterator<T> end() { return (this->ptr + this->size); }

			// Getters
			size_t	size() { return (this->_size); }
			size_t	capacity() { return (this->_capacity); }
			T		*data() { return (this->_ptr); };

			// Member functions one-liner
			bool	empty() const { return (this->_size == 0); };
			void	clear() { this->_size = 0; };
			T&		front() { return (this->_ptr[0]); }
			T&		back() { return (this->_ptr[this->_size - 1]); }
			void	pop_back() { this->_size--; };

			// Other member functions
			void	push_back(const T &value);
			void	reserve(size_t capacity);   
			void	resize(size_t size);
			// assign
			// at
			// swap
			// shrink_to_fit
			// emplace
			// emplace_back
			// erase
			// insert
			// max_size


			// Operator overloads
			T &operator[](unsigned int index) { return (this->_ptr[index]); };
	};
}

// Coplien implementation

template<class T>
ft::Vector<T>::Vector(size_t n_size, const T &init) : _capacity(n_size), _size(n_size)
{
	_ptr = new T[n_size];	
	for (int i = 0; i < n_size; i++)
		_ptr[i] = init;
}

template<class T>
ft::Vector<T>::Vector(const ft::Vector<T> &vector)
{
	this->_size = vector._size;
	this->_capacity = vector._capacity;
	this->_ptr = new T[vector._size];
	for (unsigned int i = 0; i < vector._size; i++)
		_ptr[i] = vector._ptr[i];
}

template<class T>
ft::Vector<T> &ft::Vector<T>::operator=(const Vector<T> &vector)
{
	this->_size = vector._size;
	this->_capacity = vector._capacity;
	this->_ptr = new T[vector._size];
	for (unsigned int i = 0; i < vector._size; i++)
		_ptr[i] = vector._ptr[i];
	return (this);
}

// Member functions

template<class T>
void ft::Vector<T>::push_back(const T&value)
{
	if (this->_size <= this->_capacity)
		this->reserve(this->_capacity + 3);
	this->_ptr[this->_size] = value;
	this->_capacity = this->_capacity + 3;
	this->_size = this->_size + 1;
}


template<class T>
void ft::Vector<T>::reserve(size_t capacity)
{
	if(this->_ptr == 0)
    {
        this->_size = 0;
        this->_capacity = 0;
    }
	T *n_ptr = new T[capacity];
	
	for (unsigned int i = 0; i < this->_size; i++)
    	n_ptr[i] = this->_ptr[i];
	if(this->_ptr)
    	delete[](this->_ptr);
    this->_ptr = n_ptr;

}

template<class T>
void ft::Vector<T>::resize(size_t size)
{
	reserve(size);
    this->_size = size;
}

#endif // VECTOR_HPP