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
		public:
			class Iterator;

			typedef	T 						value_type;
			typedef	T& 						reference;
			typedef	const T& 				const_reference;
			typedef	T* 						pointer;
			typedef	const T* 				const_pointer;
			typedef	size_t					size_type;
			typedef	long 					difference_type;
			typedef Iterator				iterator;
			typedef const Iterator			const_iterator;
			typedef	Alloc					allocator_type;

		private:
			allocator_type		_alloc;
			pointer				_data;
	   		size_type			_capacity;
			size_type			_size;

		public:
			// Coplien
			explicit Vector(const allocator_type &alloc = allocator_type()) : _capacity(NULL), _size(NULL), _data(NULL), _alloc(alloc)	{}

			explicit Vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _size(n), _capacity(n), _alloc(alloc)
			{
				this->reserve(n);
				for (size_type i = 0; i < n; i++)
			_		_alloc.construct(_data + i, val);
				_size = n;
				_capacity = n;
			}

			Vector(const Vector& x);
			Vector<T, Alloc> &operator=(const Vector<T, Alloc> &vector);

			template <class InputIterator>
        	Vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());

			~Vector()	{
							this->clear();
							if (this->_capacity > 0)
								this->_alloc.deallocate(this->_data, this->_capacity);
						}

			// Iterator
			iterator		begin() { return (iterator(this, 0)); }
			const_iterator	begin() const { return (iterator(this, 0)); }
			iterator		end() 	{ return (iterator(this, this->_size)); }
			iterator		erase(iterator position);
			iterator		erase(iterator first, iterator last);
			iterator		insert(iterator position, const value_type& val);
    		void			insert(iterator position, size_type n, const value_type& val);

			template<typename InputIterator, typename = std::_RequireInputIter<InputIterator>>
    		void			insert(iterator position, InputIterator first, InputIterator last);

			// Getters
			size_type		size() const 			{ return (this->_size); }
			size_type		capacity() const 		{ return (this->_capacity); }
			reference		at (size_type n) 		{ return (this->_data[n]); }
			const_reference	at (size_type n) const 	{ return (this->_data[n]); }
			reference		back() 					{ return (this->_data[this->_size - 1]); }
			const_reference	back() const 			{ return (this->_data[this->_size - 1]); }
			reference		front() 				{ return (this->_data[0]); }
			const_reference	front() const 			{ return (this->_data[0]); }
			size_type		max_size() const 		{ return (_alloc.max_size()); } // std::numeric_limits<std::size_t>::max() / sizeof(T)


			// Setters
			void			push_back(const_reference value);
			void			pop_back();
			template <class InputIterator>
			void			assign(InputIterator first, InputIterator last);
			void			assign(size_type n, const value_type& val);

			// Resizers
			void			reserve(size_type capacity);
			void			resize(size_type size) 	{ reserve(size); this->_size = size; }
			void			shrink_to_fit()			{ this->_capacity = this->_size; }

			// Empty and clear
			bool			empty() const 	{ return (this->begin() == this->end()); }
			void			clear();

			// Other methods
			void swap (Vector &x) { Vector tmp(x); ~x; x = *this; *this = tmp; };

			// Operator overloads
			reference operator[](size_type n) { return (this->_data[n]); };
	};
}

// Coplien implementation

template<class T, class Alloc>
ft::Vector<T, Alloc>::Vector(const ft::Vector<T, Alloc>&vector)
{
	this->_size = vector._size;
	this->_capacity = vector._capacity;
	this->_data = new T[vector._size];
	for (size_t i = 0; i < vector._size; i++)
		_data[i] = vector._data[i];
}

template<class T, class Alloc>
ft::Vector<T, Alloc> &ft::Vector<T, Alloc>::operator=(const Vector<T, Alloc> &vector)
{
	this->_size = vector._size;
	this->_capacity = vector._capacity;
	this->_data = new T[vector._size];
	for (size_t i = 0; i < vector._size; i++)
		_data[i] = vector._data[i];
	return (this);
}

// Vector methods

template<class T, class Alloc>
void ft::Vector<T, Alloc>::pop_back()
{
	if (this->empty() == false)
	{
		this->_size--;
		_alloc.destroy(this->back());
	}
}

template<class T, class Alloc>
void ft::Vector<T, Alloc>::push_back(const_reference value)
{
		if (_size_alloc == 0)
		{
			_ptr = _alloc.allocate(1);
			_size_alloc++;
		}
		if (_size_filled == _size_alloc)
			_extend();
	if (!_capacity)
	{
		_data = _alloc.allocate(1);
		_capacity++;
	}
	if (_capacity == _size)
	{
		pointer n_data = _alloc.allocate(_capacity * 2);
		
		for (size_type i = 0; i < _size; i++)
			_alloc.construct(n_data + i, _data[i]);
		_alloc.deallocate(_data, _capacity);
		_ptr = new_arr;
		_size_alloc *= 2;
	}

	_alloc.construct(_data + _size, value);
	_size++;
}

template<class T, class Alloc>
void ft::Vector<T, Alloc>::reserve(size_type capacity)
{
	if (capacity <= this->_capacity || this->_data == NULL)
		return;

	pointer n_data = _alloc.allocate(capacity);
	
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(n_data + i, _data[i]);

    _data = n_data;
	_capacity = capacity;
}

// Relational operator overload

template<class T, class Alloc>
bool operator!=(const Vector<T, Alloc> &sec_it) const { return (_index != sec_it._index); }

// Vector methods : Iterator

template<class T, class Alloc>
ft::Vector<T, Alloc>::iterator ft::Vector<T, Alloc>::erase(iterator position)
{
	if (this->empty() == true || this->_data == NULL || position._index > this->_size)
		return ;

	this->_size = this->_size - 1;
	T *n_data = new T[this->_size];

	size_t	i = 0;

	for (i; i < position._index; i++)
    	n_data[i] = this->_data[i];
	i++;
	for (i; i <= this->_size; i++)
    	n_data[i - 1] = this->_data[i];

	delete[](this->_data);
	this->_data = n_data;

	return (position);
}

template<class T, class Alloc>
ft::Vector<T, Alloc>::iterator	ft::Vector<T, Alloc>::erase(iterator first, iterator last)
{
	if (this->empty() == true || (last._index - first._index) < 0 ||
		this->_data == NULL || last._index > this->_size)
		return ;

	this->_size = this->_size - (last._index - first._index);
	T *n_data = new T[this->_size];

	size_t	i = 0;

	for (i; i < first._index; i++)
    	n_data[i] = this->_data[i];
	last._index = i;
	for (i; i <= this->_size; i++)
    	n_data[i - 1] = this->_data[i];
	
	delete[](this->_data);
	this->_data = n_data;

	return (last);
}

template <class T, class Alloc>
ft::Vector<T, Alloc>::iterator	ft::Vector<T, Alloc>::insert(iterator position, const value_type &val)
{
	if (this->_data == NULL ||)
		return ;


}

template <class T, class Alloc>
void ft::Vector<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
{

}

#endif // VECTOR_HPP