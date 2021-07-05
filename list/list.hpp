#include <iostream>
#include <list>

// list_node implementation

template<class T>
struct list_node
{
	private :
		list_node *next, *prev;
		_T data;

	public :
		list_node() : next(this), prev(this) , data(NULL) {}
		~list_node() { unlink(); }

		void unlink()	{
							list_node tmp_prev = this->prev;
							list_node tmp_next = this->next;
							tmp_prev.next = this->next;
							tmp_next.prev = this->prev;
							this->next = this;
							this->prev = this;
						}
};

// list_const_iterator implementation

template<typename T>
struct list_const_iterator
{
	protected :
		list_node<T> *node;
  		list_const_iterator(list_node *n_node) : list_node(n_node) {}

	public :
  		T& operator*() const { return *(this->node); }
  		T* operator->() const { return this->node; }
  		list_const_iterator<T>& operator++()	{
													this->node = this->node->next;
													return *this;
  												}
		list_const_iterator<T> operator++(int)	{
													list_const_iterator<T> tmp = *this;
													this->node = this->node->next;
													return tmp;
												}
		list_const_iterator<T>& operator--()	{
													this->node = this->node->prev;
													return *this;
												}
		list_const_iterator<T> operator--(int) {
													list_const_iterator<T> tmp = *this;
													this->node = this->node->prev;
													return tmp;
												}
		bool operator==(const list_const_iterator<T>& other) const { return (this->node == other.node); }
		bool operator!=(const list_const_iterator<T>& other) const { return (this->node != other.node); }
};

// list_iterator implementation

template < typename T >
struct list_iterator : public list_const_iterator
{
	protected :
		list_iterator(list_node *n_node) : node(n_node) {}

	public :
		list_iterator<T>& operator++() 	{
												this->node = this->node->next;
												return *this;
											}
		list_iterator<T> operator++(int) 	{
												list_iterator<T> tmp = *this;
												this->node = this->node->next;
												return tmp;
											}
  		list_iterator<T>& operator--()		{
												this->node = this->node->prev;
												return *this;
  											}
  		list_iterator<T> operator--(int)	{
			  									list_iterator<T> tmp = *this;
												this->node = this->node->prev;
												return tmp;
											}
};

// list implementation

template < typename T >
class list
{
	typedef list_iterator<T> iterator;
    typedef list_const_iterator<T const> const_iterator;
	typedef T	valueType;

	private :
		list_node<T> *head;
		list_node<T> *tail;
		sizeT l_size;

	public :
	// Coplien
		list() { };
		list(list_node *n_node) : head(n_node), tail(n_node), l_size(1) {};
		~list() { clear(); };
		list &operator=(const list &n_list) {
												this->head = n_list.head;
												this->tail = n_list.tail;
												this->l_size = n_list.l_size;
												return (this);
											}

	// iterator
		iterator begin() { return (iterator(this->head)); }
		iterator end() { return (iterator(this->tail)); }
		// rbegin();
		// rend();
		// cbegin();
		// cend();
		// crbegin();
		// crend();

	// Capacity
		bool empty() 		{ return (this.size() == 0); };
		sizeT size()		{ return this.l_size; };

	// Element access
		T &front()			{ return this->head->data; }
		T &back()			{ return this->tail->data; }

	// Modifiers
		// assign();
		// emplace_front();
		// push_front();
		// pop_front();
		// emplace_back();
		// push_back();
		// pop_back();
		// emplace ();
		// insert();
		// erase();
		// swap();
		// resize();
		// clear();
	
	// Operation
		// splice();
		// remove();
		// remove_if();
		// unique();
		// merge();
		// sort();
		// reverse();
};
