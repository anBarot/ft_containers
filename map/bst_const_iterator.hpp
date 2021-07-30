#if !defined(BST_CONST_ITERATOR_HPP)
#define BST_CONST_ITERATOR_HPP

#include "binary_search_tree.hpp"
#include "../stack/stack.hpp"
// #include "../tools/iterator_traits.hpp"

namespace ft
{
	template <class T>
	class BSTConstIterator //: public ft::iterator_traits<T*>
	{
		public :
			typedef T								value_type;
    		typedef std::ptrdiff_t					difference_type;
    		typedef T*								pointer;
    		typedef T&								reference;
    		typedef std::bidirectional_iterator_tag	iterator_category;
			typedef BSTConstIterator<T>				const_iterator;
		
		private :
			ft::Stack<s_BSTNode<T>*> st_node;

		public :
			// Coplien
			BSTConstIterator() : st_node(NULL) {};
			BSTConstIterator(const BinarySearchTree<T> &bst)
			{
        		s_BSTNode<T>* current = bst.GetRoot();
        		while (current != NULL)
            	{
					st_node.push(current);
					current = current->left;
				}
			}
			BSTConstIterator(s_BSTNode<T> *bst)
			{
        		s_BSTNode<T>* current = bst;
        		while (current != NULL)
            	{
					st_node.push(current);
					current = current->left;
				}
			}
			~BSTConstIterator() {};

			// Getters
			s_BSTNode<T>* curr(){ return st_node.top(); }

			// Member function
    		bool	hasNext();
			void	next();
			void	prev();

			// Operator overload
			T					operator*() 			{ return (curr()->data); };
			const_iterator 		operator++()			{ this->next(); return (*this); }
			const_iterator 		operator--()			{ this->prev(); return (*this); }
			const_iterator 		operator++(int)			{ const_iterator tmp(*this); this->next(); return(tmp); }
	    	const_iterator 		operator--(int)			{ const_iterator tmp(*this); this->prev(); return(tmp); }
			T 					operator->()			{ return (curr()->data); }

			// Comparison operator overload
		    bool operator!=(const const_iterator &sec_it) const	{ return (st_node != sec_it.st_node); }
		    bool operator==(const const_iterator &sec_it) const	{ return (st_node == sec_it.st_node); }
		    bool operator>=(const const_iterator &sec_it) const	{ return (st_node >= sec_it.st_node); }
		    bool operator>(const const_iterator &sec_it) const	{ return (st_node > sec_it.st_node); }
		    bool operator<=(const const_iterator &sec_it) const	{ return (st_node <= sec_it.st_node); }
		    bool operator<(const const_iterator &sec_it) const	{ return (st_node < sec_it.st_node); }

			// Is input iterator
			static const bool input_iter = true;
	};
}

template <class T>
bool ft::BSTConstIterator<T>::hasNext()
{
	if (st_node.top() == NULL)
		return (false);
	return (true);
}

template <class T>
void ft::BSTConstIterator<T>::next()
{
	s_BSTNode<T>* curr = st_node.top()->right;

	st_node.pop();
    while (curr != NULL)
	{
		st_node.push(curr);
		curr = curr->left;
	}
}

#endif
