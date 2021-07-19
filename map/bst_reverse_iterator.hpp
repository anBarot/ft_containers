#if !defined(BST_REVERSE_ITERATOR_HPP)
#define BST_REVERSE_ITERATOR_HPP

#include <iterator>
#include <stack>
#include "binary_search_tree.hpp"
#include "../stack/stack.hpp"
// #include "../tools/iterator_traits.hpp"

namespace ft
{
	template <class T>
	class BSTReverseIterator //: public ft::iterator_traits<T*>
	{
		public :
			typedef T								value_type;
    		typedef std::ptrdiff_t					difference_type;
    		typedef T*								pointer;
    		typedef T&								reference;
    		typedef std::bidirectional_iterator_tag	iterator_category;
			typedef ft::BSTReverseIterator<T>		reverse_iterator;

		private :
			ft::Stack<T, s_BSTNode<T>*> st_node;

		public :
			// Coplien
			BSTReverseIterator() : st_node(nullptr) {}
			BSTReverseIterator(BinarySearchTree<T> &bst)
			{
        		s_BSTNode<T>* current = bst->bstroot_p;
        		while (current != nullptr)
            	{
					st_node.push(current);
					current = current->left;
				}
			}
			BSTReverseIterator(s_BSTNode<T> *bst)
			{
        		s_BSTNode<T>* current = bst;

        		while (current != nullptr)
            	{
					st_node.push(current);
					current = current->left;
				}
			}
			~BSTReverseIterator() {};

			// Getters
			s_BSTNode<T>* curr(){ return st_node.top(); }

			// Member function
    		bool	hasNext();
			void	next();
			void	prev();

			// Operator overload
			T					operator*() 			{ return (curr()->data); };
			reverse_iterator 	operator++()			{ this->prev(); return (*this); }
			reverse_iterator 	operator--()			{ this->next(); return (*this); }
			reverse_iterator 	operator++(int)			{ reverse_iterator tmp(*this); this->prev(); return(tmp); }
	    	reverse_iterator 	operator--(int)			{ reverse_iterator tmp(*this); this->next(); return(tmp); }

			// Comparison operator overload
		    bool operator!=(const reverse_iterator &sec_it) const	{ return (st_node != sec_it.st_node); }
		    bool operator==(const reverse_iterator &sec_it) const	{ return (st_node == sec_it.st_node); }
		    bool operator>=(const reverse_iterator &sec_it) const	{ return (st_node >= sec_it.st_node); }
		    bool operator>(const reverse_iterator &sec_it) const	{ return (st_node > sec_it.st_node); }
		    bool operator<=(const reverse_iterator &sec_it) const	{ return (st_node <= sec_it.st_node); }
		    bool operator<(const reverse_iterator &sec_it) const	{ return (st_node < sec_it.st_node); }

			// Is input iterator
			static const bool input_iter = true;
	};
}

template <class T>
bool ft::BSTReverseIterator<T>::hasNext()
{
	if (st_node == nullptr)
		return (false);
	return (true);
}

template <class T>
void ft::BSTReverseIterator<T>::next()
{
	s_BSTNode<T>* curr = st_node.top()->right;

	st_node.pop();
    while (curr != nullptr)
	{
		st_node.push(curr);
		curr = curr->left;
	}
}

template <class T>
void ft::BSTReverseIterator<T>::prev()
{
	s_BSTNode<T>* curr = st_node.top()->left;

	st_node.pop();
    while (curr != nullptr)
	{
		st_node.push(curr);
		curr = curr->right;
	}
}

#endif
