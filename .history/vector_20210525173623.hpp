#ifndef VECTOR_HPP 
#define VECTOR_HPP

#include <iostream>
#include <initializer_list>
#include <limits>
#include <iterator>

namespace ft
{
	template<class T, class Alloc = std::allocator<T>>
	class Vector
	{
		private:
			T 		*_ptr;
	   		size_t	_capacity;
			size_t	_size;
			Alloc	_alloc;

		public:
			class Iterator; // class implementation at EOF

			typedef	T 						value_type;
			typedef	T& 						reference;
			typedef	const T& 				const_reference;
			typedef	T* 						pointer;
			typedef	const T* 				const_pointer;
			typedef	size_t					size_type;
			typedef	size_type 				difference_type;
			typedef Iterator				iterator;
			typedef const Iterator			const_iterator;
			typedef	Alloc					allocator_type;

			// Coplien
			explicit Vector(const allocator_type &alloc = allocator_type()) : _capacity(), _size(0), _ptr(0), _alloc(alloc)	{}
			Vector(size_type n_size) : _capacity(n_size), _size(n_size) { _ptr = new T[n_size]; }
			Vector(std::initializer_list<T> l);
			Vector(size_type n_size, const T&init);
			Vector(const Vector<T> &vector);
			Vector<T> &operator=(const Vector<T> &vector);
			template <class InputIterator>
        	vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());
			~Vector() 													{ delete[](this->_ptr); };

			// Iterator
			iterator		begin() { return (iterator(this, 0)); }
			iterator		end() 	{ return (iterator(this, this->_size)); }
			iterator		erase(iterator position);
			iterator		erase(iterator first, iterator last);
			iterator		insert(iterator position, const value_type& val);
    		void			insert(iterator position, size_type n, const value_type& val);

			template<typename InputIterator, typename = std::_RequireInputIter<InputIterator>>
    		void			insert(iterator position, InputIterator first, InputIterator last)
			{




			}

			// Getters
			size_t			size() const 			{ return (this->_size); }
			size_t			capacity() const 		{ return (this->_capacity); }
			pointer			data() 					{ return (this->_ptr); };
			const_pointer	data() const 			{ return (this->_ptr); };
			reference		at (size_type n) 		{ return (this->_ptr[n]); };
			const_reference	at (size_type n) const 	{ return (this->_ptr[n]); };
			reference		back() 					{ return (this->_ptr[this->_size - 1]); }
			const_reference	back() const 			{ return (this->_ptr[this->_size - 1]); }
			reference		front() 				{ return (this->_ptr[0]); }
			const_reference	front() const 			{ return (this->_ptr[0]); }
			unsigned long	max_size() 				{ return (std::numeric_limits<size_type>::max() / sizeof(T) / 2); }

			// Setters
			void			push_back(const_reference value);
			void			pop_back();

			// Resizers
			void			reserve(size_type capacity) ;   
			void			resize(size_type size) 	{ reserve(size); this->_size = size; };
			void			shrink_to_fit()			{ this->_capacity = this->_size; };

			// Empty and clear
			bool			empty() const 	{ return (this->_size == 0); }
			void			clear()			{ this->_size = 0; }

			// Other methods
			void swap (Vector &x) { Vector tmp(x); ~x; x = *this; *this = tmp; };


			// assign
			// emplace
			// emplace_back

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
ft::Vector<T>::Vector(std::initializer_list<T> l) : _size(l.size()), _capacity(l.size())
{
	_ptr = new T[_size];
	int i = 0;

	for (std::initializer_list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		_ptr[i] = *it;
		i++;
	}
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
void ft::Vector<T>::pop_back()
{
	if (this->empty() == false)
		this->_size--;
}

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
        this->_size = 0;

	T *n_ptr = new T[capacity];
	
	for (size_t i = 0; i < this->_size; i++)
    	n_ptr[i] = this->_ptr[i];
	if (this->_ptr)
    	delete[](this->_ptr);
    this->_ptr = n_ptr;
}

// Relational operator overload

template<class T>
bool operator!=(const Vector &sec_it) const	{ return (_index != sec_it._index); }

// Vector methods : Iterator

template<class T>
ft::Vector<T>::iterator ft::Vector<T>::erase(iterator position)
{
	if (this->empty() == true || this->_ptr == NULL || position._index > this->_size)
		return ;

	this->_size = this->_size - 1;
	T *n_ptr = new T[this->_size];

	size_t	i = 0;

	for (i; i < position._index; i++)
    	n_ptr[i] = this->_ptr[i];
	i++;
	for (i; i <= this->_size; i++)
    	n_ptr[i - 1] = this->_ptr[i];

	delete[](this->_ptr);
	this->_ptr = n_ptr;

	return (position);
}

template<class T>
ft::Vector<T>::iterator	ft::Vector<T>::erase(iterator first, iterator last)
{
	if (this->empty() == true || (last._index - first._index) < 0 ||
		this->_ptr == NULL || last._index > this->_size)
		return ;

	this->_size = this->_size - (last._index - first._index);
	T *n_ptr = new T[this->_size];

	size_t	i = 0;

	for (i; i < first._index; i++)
    	n_ptr[i] = this->_ptr[i];
	last._index = i;
	for (i; i <= this->_size; i++)
    	n_ptr[i - 1] = this->_ptr[i];
	
	delete[](this->_ptr);
	this->_ptr = n_ptr;

	return (last);
}

template <class T>
ft::Vector<T>::iterator	ft::Vector<T>::insert(iterator position, const value_type &val)
{
	if (this->_ptr == NULL ||)
		return ;


}

template <class T>
void ft::Vector<T>::insert(iterator position, size_type n, const value_type& val)
{

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

#endif // VECTOR_HPP