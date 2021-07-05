#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

namespace ft
{
	template <class T>
	class MapIterator
	{
		public:
			typedef T						value_type;
			typedef T*						pointer;
			typedef T&						reference;
			typedef ft::MapIterator<T>		iterator;

		private:
			// to add : node, 

		public:
			// Coplien
		    MapIterator() {}
			MapIterator(const iterator &it) { *this = it; }
		    MapIterator(pointer vector) : /* private member */ {}
			iterator &operator=(const iterator &it) { /* private member */ = it./* private member */; return (*this); }
			~MapIterator() {}

			// Operator overload
			reference operator*()				{ return (/* private member */); }
			iterator operator++()				{ ++/* private member */; return (*this); }
			iterator operator--()				{ --/* private member */; return (*this); }
			iterator operator++(int)			{ iterator tmp(*this); ++/* private member */; return(tmp); }
	    	iterator operator--(int)			{ iterator tmp(*this); --/* private member */; return(tmp); }
			iterator operator+(size_t i)		{ return (iterator(/* private member */ + i)); }
	    	iterator operator-(size_t i)		{ return (iterator(/* private member */ - i)); }

			// Comparison operator overload
		    bool operator!=(const iterator &sec_it) const	{ return (/* private member */ != sec_it./* private member */); }
		    bool operator==(const iterator &sec_it) const	{ return (/* private member */ == sec_it./* private member */); }
		    bool operator>=(const iterator &sec_it) const	{ return (/* private member */ >= sec_it./* private member */); }
		    bool operator>(const iterator &sec_it) const	{ return (/* private member */ > sec_it./* private member */); }
		    bool operator<=(const iterator &sec_it) const	{ return (/* private member */ <= sec_it./* private member */); }
		    bool operator<(const iterator &sec_it) const	{ return (/* private member */ < sec_it./* private member */); }

			// Is input iterator
			static const bool input_iter = true;
	};
}

#endif
