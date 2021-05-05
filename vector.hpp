#include <iostream>
#include "ft.hpp"
#include "iterator.hpp"
#include <list>

template<class T>
class vector
{
	private:
		typedef T*	pointer;
		pointer 	_ptr;
		size_t		_size;
   		size_t		_capacity;

	public:
		// Coplien
		vector() : _capacity(0), _size(0), _ptr(0) {}
		vector(size_t n_size) : _capacity(n_size), _size(n_size) { _ptr = new T[n_size]; }
		vector(size_t n_size, const T&init);
		vector(const vector<T> &vector);
		~vector() { delete(this->_ptr); };

		// Getters
		size_t capacity() const { return (this->_capacity); }
		size_t size() const { return (this->_size); }

		// Other member functions
		bool empty() const;
		T& front();
		T& back();
		void push_back(const T &value); 
		void pop_back();
		void reserve(size_t capacity);   
		void resize(size_t size);

		iterator begin() { return (this->ptr); }
		iterator end() { return (this->ptr + this->size); }

		// Operator overloads
		T & operator[](unsigned int index);  
		Vector<T> & operator=(const Vector<T> &);
};

// Coplien implementation

template<class T>
vector<T>::vector(size_t n_size, const T &init) : _capacity(n_size), _size(n_size)
{
	_ptr = new T[n_size];	
	for (int i = 0; i < n_size; i++)
	{
		_ptr[i] = init;
		T();
	}
}

template<class T>
vector<T>::vector(const vector<T> &vector)
{
	this->_size = vector._size;
	this->_capacity = vector._capacity;
	_ptr = new T[n_size];
	for (int i = 0; i < n_size; i++)
		_ptr[i] = vector._ptr[i];
}

// Member functions

template<class T>
bool empty() const

template<class T>
T & front()

template<class T>
T & back()

template<class T>
void push_back(const T & value)

template<class T>
void pop_back()

template<class T>
void reserve(unsigned int capacity)

template<class T>
void resize(unsigned int size)


// Operator overloads

T & operator[](unsigned int index);  
Vector<T> & operator=(const Vector<T> &);