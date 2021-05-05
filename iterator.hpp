#include <iostream>

template <typename T>
class iterator
{
	private:
        typedef iterator self_type;
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;
        typedef std::forward_iterator_tag iterator_category;
        typedef int difference_type;
		pointer	ptr;

    public:
		//Coplien
        iterator(pointer n_ptr) : ptr(n_ptr) {}
		
		//Operator overload
        self_type operator++() { self_type i = *this; ptr++; return i; }
        self_type operator++(int junk) { ptr++; return *this; }
        reference operator*() { return (*ptr); }
        pointer operator->() { return (ptr); }
        bool operator==(const self_type& rhs) { return ptr == rhs.ptr; }
        bool operator!=(const self_type& rhs) { return ptr != rhs.ptr; }
    
};

template <typename T>
class const_iterator
{
	private:
        typedef const_iterator self_type;
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;
        typedef int difference_type;
        typedef std::forward_iterator_tag iterator_category;
        pointer	ptr;

    public:
		//Coplien
        const_iterator(pointer n_ptr) : ptr(n_ptr) {}
		
		//Operator overload
        self_type operator++() { self_type i = *this; ptr++; return i; }
        self_type operator++(int junk) { ptr++; return *this; }
        const reference operator*() { return *ptr; }
        const pointer operator->() { return ptr; }
        bool operator==(const self_type& rhs) { return ptr == rhs.ptr; }
        bool operator!=(const self_type& rhs) { return ptr != rhs.ptr; }  
};