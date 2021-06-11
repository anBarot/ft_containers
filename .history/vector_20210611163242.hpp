#ifndef VECTOR_HPP 
#define VECTOR_HPP

#include <iostream>
#include <limits>
#include "modules/vector_iterator.hpp"
#include "modules/vector_const_iterator.hpp"
#include "modules/vector_reverse_iterator.hpp"
#include "modules/vector_const_reverse_iterator.hpp"

template <class Tp>
struct has_iterator_category
{
private:
    struct two {char lx; char lxx;};
    template <class Up> static two test(...);
    template <class Up> static char test(typename Up::iterator_category* = 0);
public:
    static const bool value = sizeof(test<Tp>(0)) == 1;
};

template <class Tp, class Up,
          bool = has_iterator_category<iterator_traits<Tp> >::value>
struct has_iterator_category_convertible_to
    // either integral_constant<bool, false> or integral_constant<bool, true>
  : public integral_constant<
      bool, 
      is_convertible<typename iterator_traits<Tp>::iterator_category, Up>::value
    >
{};

// specialization for has_iterator_category<iterator_traits<Tp> >::value == false
template <class Tp, class Up>
struct has_iterator_category_convertible_to<Tp, Up, false> : public false_type {};

template <class Tp>
struct is_input_iterator 
  : public has_iterator_category_convertible_to<Tp, input_iterator_tag> {};

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class Vector
	{
		public:
			typedef	T 												value_type;
			typedef	T& 												reference;
			typedef	const T& 										const_reference;
			typedef	T* 												pointer;
			typedef	const T* 										const_pointer;
			typedef	size_t											size_type;
			typedef	long 											difference_type;
			typedef typename ft::VectorIterator<T>					iterator;
			typedef typename ft::VectorConst_Iterator<T>			const_iterator;
			typedef typename ft::VectorReverse_Iterator<T>			reverse_iterator;
			typedef typename ft::VectorConst_Reverse_Iterator<T>	const_reverse_iterator;
			typedef	Alloc											allocator_type;

		private:
			allocator_type		_alloc;
			pointer				_data;
	   		size_type			_capacity;
			size_type			_size;

		public:
			// Coplien
			explicit Vector(const allocator_type &alloc = allocator_type()) : _capacity(0), _size(0), _data(NULL), _alloc(alloc) {}
			explicit Vector(size_type n, const value_type &val = value_type(), const allocator_type& alloc = allocator_type());
			Vector(const Vector & x);
			Vector<T, Alloc> &operator=(const Vector<T, Alloc> &vector);
			template <class InputIterator>
        	Vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
			typename std::iterator_traits<InputIterator>::iterator_category())
			: _alloc(alloc),  _data(NULL),  _capacity(0), _size(0)
			{
				while (first != last)
					this->push_back(*first++);
			}
			~Vector();

			// Iterator
			iterator				begin()			{ return (iterator(_data)); }
			const_iterator			begin() const 	{ return (const_iterator(_data)); }
			iterator				end() 			{ return (iterator(_data + _size)); }
			const_iterator			end() const		{ return (const_iterator(_data + _size)); }
			reverse_iterator 		rbegin()		{ return (reverse_iterator(_data + _size - 1)); }
			const_reverse_iterator	rbegin() const	{ return (const_reverse_iterator(_data + _size - 1)); }
			reverse_iterator		rend()			{ return (reverse_iterator(_data - 1)); }
			const_reverse_iterator	rend() const	{ return (const_reverse_iterator(_data - 1)); }
			iterator				erase(iterator position);
			iterator				erase(iterator first, iterator last);
			iterator				insert(iterator position, const value_type& val);
    		void					insert(iterator position, size_type n, const value_type& val);

			// template<typename InputIterator, typename = std::_RequireInputIter<InputIterator>>
    		// void			insert(iterator position, InputIterator first, InputIterator last);

			// Getters
			size_type		size() const 			{ return (_size); }
			size_type		capacity() const 		{ return (_capacity); }
			allocator_type	get_allocator() const	{ return (_alloc); };
			reference		at(size_type n) 		{ return (_data[n]); }
			const_reference	at(size_type n) const 	{ return (_data[n]); }
			reference		back() 					{ return (_data[_size - 1]); }
			const_reference	back() const 			{ return (_data[_size - 1]); }
			reference		front() 				{ return (*(_data)); }
			const_reference	front() const 			{ return (*(_data)); }
			size_type		max_size() const 		{ return (_alloc.max_size()); } // std::numeric_limits<std::size_t>::max() / sizeof(T)


			// Setters
			void			push_back(const_reference value);
			void			pop_back();
			template <class InputIterator>
			void			assign(InputIterator first, InputIterator last);
			void			assign(size_type n, reference val);

			// Resizers
			void			reserve(size_type capacity);
			void			resize(size_type size, value_type val = value_type());
			void			shrink_to_fit();

			// Empty and clear
			bool			empty() const 	{ return (_size == 0); }
			void			clear();

			// Other methods
			void			swap(Vector &x) { Vector tmp(x); ~x; x = *this; *this = tmp; };

			// Operator overloads
			reference operator[](size_type n);
	};
}

// Coplien implementation

template<class T, class Alloc>
ft::Vector<T, Alloc>::Vector(size_type n, const value_type &val, const allocator_type &alloc)
: _alloc(alloc), _capacity(0), _size(0) 
{
	this->reserve(n);
	for (size_type i = 0; i < n; i++)
		_alloc.construct(_data + i, val);
	_size = n;
	_capacity = n;
}

template<class T, class Alloc>
ft::Vector<T, Alloc>::Vector(const ft::Vector<T, Alloc> &x)
{
	_alloc = x.get_allocator();
	*this = x;
}

template<class T, class Alloc>
ft::Vector<T, Alloc> &ft::Vector<T, Alloc>::operator=(const Vector<T, Alloc> &vector)
{
	_size = vector._size;
	_capacity = vector._capacity;
	_data = _alloc.allocate(_capacity);

	for (size_t i = 0; i < _size; i++)
		_alloc.construct(_data + i, vector._data[i]);

	return (*this);
}

template<class T, class Alloc>
ft::Vector<T, Alloc>::~Vector()
{
	this->clear();
	if (_capacity > 0)
		_alloc.deallocate(this->_data, this->_capacity);
}

// Vector methods

template<class T, class Alloc>
void ft::Vector<T, Alloc>::clear()
{
	if (_size)
	{
		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(_data + i);
		_size = 0;
	}
}

template<class T, class Alloc>
void ft::Vector<T, Alloc>::pop_back()
{
	if (this->empty() == false)
	{
		_alloc.destroy(_data + _size - 1);
		this->_size--;
	}
}

template<class T, class Alloc>
void ft::Vector<T, Alloc>::push_back(const_reference value)
{
	if (!_capacity)
	{
		_data = _alloc.allocate(1);
		_capacity++;
	}
	else if (_capacity == _size)
	{
		pointer n_data = _alloc.allocate(_capacity * 2);
		_capacity *= 2;
		
		for (size_type i = 0; i < _size; i++)
			_alloc.construct(n_data + i, _data[i]);
		_alloc.deallocate(_data, _capacity);
		_data = n_data;
	}

	_alloc.construct(_data + _size, value);
	_size++;
}

template<class T, class Alloc>
void ft::Vector<T, Alloc>::reserve(size_type capacity)
{
	if (capacity <= _capacity)
		return;

	_data = _alloc.allocate(capacity);
	_capacity = capacity;
	
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(_data + i, _data[i]);
}

template<class T, class Alloc>
typename ft::Vector<T, Alloc>::reference ft::Vector<T, Alloc>::operator[](size_type n)
{
	if (n >= _size)
		return ;
	return(_data[n]);
}

// Relational operator overload

template<class T, class Alloc>
bool operator==(const ft::Vector<T, Alloc> & lhs, const ft::Vector<T, Alloc> & rhs)
{
	if (lhs._size != rhs._size)
		return (false);

	typename ft::Vector<T, Alloc>::iterator i_lhs = lhs.begin();
	typename ft::Vector<T, Alloc>::iterator i_rhs = rhs.begin();

	for (i_lhs; i_lhs != lhs.end(); i_lhs++)
	{
		if (*i_lhs != *i_rhs)
			return (false);
		i_lhs++;
		i_rhs++;
	}

	return (true);
}

template<class T, class Alloc>
bool operator!=(const ft::Vector<T, Alloc> & lhs, const ft::Vector<T, Alloc> & rhs)
{	return (!(lhs == rhs)); }

template<class T, class Alloc>
bool operator<(const ft::Vector<T, Alloc> & lhs, const ft::Vector<T, Alloc> & rhs)
{
	typename ft::Vector<T, Alloc>::iterator i_lhs = lhs.begin();
	typename ft::Vector<T, Alloc>::iterator i_rhs = rhs.begin();

	for (i_lhs; i_lhs != lhs.end(); i_lhs++)
	{
		if (*i_lhs >= *i_rhs)
			return (false);
		i_lhs++;
		i_rhs++;
	}

	return (true);
}

template<class T, class Alloc>
bool operator<=(const ft::Vector<T, Alloc> & lhs, const ft::Vector<T, Alloc> & rhs)
{
	typename ft::Vector<T, Alloc>::iterator i_lhs = lhs.begin();
	typename ft::Vector<T, Alloc>::iterator i_rhs = rhs.begin();

	for (i_lhs; i_lhs != lhs.end(); i_lhs++)
	{
		if (*i_lhs > *i_rhs)
			return (false);
		i_lhs++;
		i_rhs++;
	}

	return (true);
}

template<class T, class Alloc>
bool operator>(const ft::Vector<T, Alloc> & lhs, const ft::Vector<T, Alloc> & rhs)
{	return (!(lhs <= rhs)); }

template<class T, class Alloc>
bool operator>=(const ft::Vector<T, Alloc> & lhs, const ft::Vector<T, Alloc> & rhs)
{	return (!(lhs < rhs)); }

// Vector methods : Iterator

template<class T, class Alloc>
typename ft::Vector<T, Alloc>::iterator ft::Vector<T, Alloc>::erase(iterator position)
{
	if (this->empty() == true || position._index > this->_size)
		return;

	if (position == this->end())
	{
		this->pop_back();
		return (position--);
	}

	Vector<T, Alloc> tmp(position++, position.end());

	for (size_type i = 0; i != tmp.size(); i++)
		this->pop_back();
	for (iterator it = tmp.begin(); it != tmp.end(); it++)
		this->push_back(*it);

	return (position);
}

// template<class T, class Alloc>
// typename ft::Vector<T, Alloc>::iterator	ft::Vector<T, Alloc>::erase(iterator first, iterator last)
// {
// 	if (this->empty() == true || (last._index - first._index) < 0 ||
// 		this->_data == NULL || last._index > this->_size)
// 		return ;

// 	if (last == this)
		
// }

// template <class T, class Alloc>
// typename ft::Vector<T, Alloc>::iterator	ft::Vector<T, Alloc>::insert(iterator position, const value_type &val)
// {
// 	if (this->_data == NULL )
// 		return ;
// }

// template <class T, class Alloc>
// void ft::Vector<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
// {

// }

#endif // VECTOR_HPP