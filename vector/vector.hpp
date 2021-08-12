#ifndef VECTOR_HPP 
#define VECTOR_HPP

#include <iostream>
#include <limits>
#include "vector_iterator.hpp"
#include "vector_const_iterator.hpp"
#include "vector_reverse_iterator.hpp"
#include "vector_const_reverse_iterator.hpp"
#include "../tools/enable_if.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef	T													value_type;
			typedef	T&													reference;
			typedef	const T& 											const_reference;
			typedef	T*													pointer;
			typedef	const T* 											const_pointer;
			typedef	size_t												size_type;
			typedef	long 												difference_type;
			typedef typename ft::VectorIterator<T>						iterator;
			typedef typename ft::VectorConstIterator<const T>			const_iterator;
			typedef typename ft::VectorReverseIterator<T>				reverse_iterator;
			typedef typename ft::VectorConstReverseIterator<const T>	const_reverse_iterator;
			typedef	Alloc												allocator_type;

		private:
			allocator_type		_alloc;
			pointer				_data;
	   		size_type			_capacity;
			size_type			_size;

		public:
			// Coplien
			explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _data(NULL), _capacity(0), _size(0) {}
			explicit vector(size_type n, const value_type &val = value_type(), const allocator_type& alloc = allocator_type());
			vector<T, Alloc> &operator=(const vector &vector);
			vector(vector &x);
			template <typename InputIterator>
			vector(typename ft::enable_if<InputIterator::input_iter, InputIterator>::type first,
			InputIterator last, const allocator_type &alloc = allocator_type())
			: _alloc(alloc),  _data(NULL),  _capacity(0), _size(0)
			{
				while (first != last)
					this->push_back(*first++);
			}
			virtual ~vector();

			// Iterator
			iterator				begin()			{ return (iterator(_data)); }
			const_iterator			begin() const 	{ return (const_iterator(_data)); }
			iterator				end() 			{ return (iterator(_data + _size)); }
			const_iterator			end() const		{ return (const_iterator(_data + _size)); }
			reverse_iterator 		rbegin()		{ return (reverse_iterator(_data + _size - 1)); }
			const_reverse_iterator	rbegin() const	{ return (const_reverse_iterator(_data + _size - 1)); }
			reverse_iterator		rend()			{ return (reverse_iterator(_data - 1)); }
			const_reverse_iterator	rend() const	{ return (const_reverse_iterator(_data - 1)); }

			// Getters
			size_type		size() const 			{ return (_size); }
			size_type		capacity() const 		{ return (_capacity); }
			allocator_type	get_allocator() const	{ return (_alloc); }
			reference		at(size_type n); 	
			const_reference	at(size_type n) const;
			reference		back() 					{ return (_data[_size - 1]); }
			const_reference	back() const 			{ return (_data[_size - 1]); }
			reference		front() 				{ return (*(_data)); }
			const_reference	front() const 			{ return (*(_data)); }
			size_type		max_size() const 		{ return (_alloc.max_size()); }

			// Setters
			void					push_back(const_reference value);
			void					pop_back();
			iterator				erase(iterator position);
			iterator				erase(iterator first, iterator last);
			iterator				insert(iterator position, const value_type& val);
    		void					insert(iterator position, size_type n, const value_type& val);
			template<typename InputIterator>
			void					insert(iterator position,
									typename ft::enable_if<InputIterator::input_iter, InputIterator>::type first,
									InputIterator last);
			void					assign(size_type n, const_reference val);
			template <typename InputIterator>
			void					assign(typename ft::enable_if<InputIterator::input_iter, InputIterator>::type first, 
									InputIterator last);

			// Resizers
			void			reserve(size_type capacity);
			void			resize(size_type size, value_type val = value_type());

			// Empty and clear
			bool			empty() const 	{ return (_size == 0); }
			void			clear();

			// Other methods
			void			swap(vector &x) { vector tmp(x); x = *this; *this = tmp; };

			// Operator overloads
			reference operator[](size_type n);

			// Exception
			class OutOfRange_exception: public std::exception
			{
				public :
			  		virtual const char* what() const throw()
			  		{ return ("Exception thrown : This pointer is out of range\n");}
			};
	};
}

// Coplien implementation

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(size_type n, const value_type &val, const allocator_type &alloc)
: _alloc(alloc), _capacity(0), _size(0) 
{
	this->reserve(n);
	for (size_type i = 0; i < n; i++)
		_alloc.construct(_data + i, val);
	_size = n;
	_capacity = n;
}

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(ft::vector<T, Alloc> &x) : 
_alloc(allocator_type()), _capacity(0), _size(0)
{ *this = x; }

template<class T, class Alloc>
ft::vector<T, Alloc> &ft::vector<T, Alloc>::operator=(const vector &vector)
{
	_size = vector._size;
	_capacity = vector._capacity;
	_data = _alloc.allocate(_capacity);

	for (size_t i = 0; i < _size; i++)
		_alloc.construct(_data + i, vector._data[i]);

	return (*this);
}

template<class T, class Alloc>
ft::vector<T, Alloc>::~vector()
{
	this->clear();
	if (_capacity > 0)
		_alloc.deallocate(this->_data, this->_capacity);
}

// vector methods

template<class T, class Alloc>
void ft::vector<T, Alloc>::clear()
{
	if (_size)
	{
		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(_data + i);
		_size = 0;
	}
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::pop_back()
{
	if (this->empty() == false)
	{
		_alloc.destroy(_data + _size - 1);
		this->_size--;
	}
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::push_back(const_reference value)
{
	if (!_capacity)
	{
		_data = _alloc.allocate(1);
		_capacity++;
	}
	else if (_capacity == _size)
	{
		pointer n_data = _alloc.allocate(_capacity * 2);
		
		for (size_type i = 0; i < _size; i++)
		{
			_alloc.construct(n_data + i, _data[i]);
			_alloc.destroy(_data + i);
		}
		_alloc.deallocate(_data, _capacity);
		_capacity *= 2;
		_data = n_data;
	}

	_alloc.construct(_data + _size, value);
	_size++;
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::reserve(size_type capacity)
{
	if (capacity <= _capacity)
		return;

	_data = _alloc.allocate(capacity);
	_capacity = capacity;
	
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(_data + i, _data[i]);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::reference	ft::vector<T, Alloc>::at(size_type n) 		
{
	if (n >= _size)
		throw(ft::vector<T, Alloc>::OutOfRange_exception());
	return (_data[n]); 
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::const_reference	ft::vector<T, Alloc>::at(size_type n) const 	
{ 
	if (n >= _size)
		throw(ft::vector<T, Alloc>::OutOfRange_exception());
	return (_data[n]); 
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::operator[](size_type n)
{
	return(_data[n]);
}

// vector methods : Iterator

template<class T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::erase(iterator position)
{
	if (this->empty() == true || position > this->end())
		return (NULL);

	if (position == this->end())
	{
		this->pop_back();
		return (position--);
	}

	vector<T, Alloc> tmp(position + 1, this->end());

	for (size_type i = 0; i <= tmp.size(); i++)
		this->pop_back();
	for (iterator it = tmp.begin(); it != tmp.end(); it++)
		this->push_back(*it);

	return (position);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::erase(iterator first, iterator last)
{
	if (this->empty() == true || last > this->end() || first > this->end())
		return (NULL);

	iterator tmp = first;

	for (tmp; tmp != last; tmp++)
		erase(tmp);

	return (first);
}

template<class T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::insert(iterator position, const value_type& val)
{
	if (_size == _capacity)
	{
		pointer n_data = _alloc.allocate(_capacity * 2);

		for (size_type i = 0; i < _size; i++)
		{
			_alloc.construct(n_data + i, _data[i]);
			_alloc.destroy(_data + i);
		}
		_alloc.deallocate(_data, _capacity);
		_data = n_data;
		_capacity *= 2;
	}

	vector tmp(position, this->end());

	for (size_t i = 0; i < tmp.size(); i++)
		this->pop_back();
	this->push_back(val);
	for (iterator it = tmp.begin(); it != tmp.end(); it++)
		this->push_back(*it);

	return (position);
}

template<class T, class Alloc>
void ft::vector<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
{
	if (_size - n < _capacity)
	{
		pointer n_data = _alloc.allocate(_capacity * 2);

		for (size_type i = 0; i < _size; i++)
		{
			_alloc.construct(n_data + i, _data[i]);
			_alloc.destroy(_data + i);
		}
		_alloc.deallocate(_data, _capacity);
		_data = n_data;
		_capacity *= 2;
	}

	vector tmp(position, this->end());

	for (size_t i = 0; i < tmp.size(); i++)
		this->pop_back();

	while (n)
	{
		this->push_back(val);
		n--;
	}

	for (iterator it = tmp.begin(); it != tmp.end(); it++)
		this->push_back(*it);
}

template <class T, class Alloc>
template<typename InputIterator>
void	ft::vector<T, Alloc>::insert(iterator position,
		typename ft::enable_if<InputIterator::input_iter, InputIterator>::type first,
		InputIterator last)
{
	if (last - first < _capacity)
	{
		pointer n_data = _alloc.allocate(_capacity * 2);

		for (size_type i = 0; i < _size; i++)
		{
			_alloc.construct(n_data + i, _data[i]);
			_alloc.destroy(_data + i);
		}

		_alloc.deallocate(_data, _capacity);
		_data = n_data;
		_capacity *= 2;
	}

	for (first; first <= last; first++)
	{
		insert(position, *first);
		position++;
	}
}

template <class T, class Alloc>
void ft::vector<T, Alloc>::assign(size_type n, const_reference val)
{
	this->clear();

	for (size_type i = 0; i < n; i++)
		this->push_back(val);
}

template <class T, class Alloc>
template <typename InputIterator>
void ft::vector<T, Alloc>::assign(typename ft::enable_if<InputIterator::input_iter, InputIterator>::type first, 
						InputIterator last)
{
	this->clear();

	size_t count = 0;
	iterator tmp_first = first;
	iterator tmp_last = last;
	while (tmp_first != tmp_last)
	{
		tmp_first++;
		count++;
	}
	if (_capacity < count)
		this->reserve(count);
	while (first < last)
	{
		this->push_back(*first);
		first++;
	}
}

// Relational operator overload

template<class T, class Alloc>
bool operator==(const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs)
{
	if (lhs.size() != rhs.size())
		return (false);

	typename ft::vector<T, Alloc>::const_iterator i_lhs = lhs.begin();
	typename ft::vector<T, Alloc>::const_iterator i_rhs = rhs.begin();

	while (i_lhs != lhs.end())
	{
		if (*i_lhs != *i_rhs)
			return (false);
		i_lhs++;
		i_rhs++;
	}

	return (true);
}

template<class T, class Alloc>
bool operator!=(const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs)
{	return (!(lhs == rhs)); }

template<class T, class Alloc>
bool operator<(const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs)
{
	typename ft::vector<T, Alloc>::const_iterator i_lhs = lhs.begin();
	typename ft::vector<T, Alloc>::const_iterator i_rhs = rhs.begin();

	while (i_lhs != lhs.end())
	{
		if (*i_lhs >= *i_rhs)
			return (false);
		i_lhs++;
		i_rhs++;
	}

	return (true);
}

template<class T, class Alloc>
bool operator<=(const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs)
{
	typename ft::vector<T, Alloc>::const_iterator i_lhs = lhs.begin();
	typename ft::vector<T, Alloc>::const_iterator i_rhs = rhs.begin();

	while (i_lhs != lhs.end())
	{
		if (*i_lhs > *i_rhs)
			return (false);
		i_lhs++;
		i_rhs++;
	}

	return (true);
}

template<class T, class Alloc>
bool operator>(const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs)
{	return (!(lhs <= rhs)); }

template<class T, class Alloc>
bool operator>=(const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs)
{	return (!(lhs < rhs)); }

#endif
