#if !defined(BST_ITERATOR_HPP)
#define BST_ITERATOR_HPP

#include <iterator>
#include "binary_search_tree.hpp"
#include "../stack/stack.hpp"
// #include "../tools/iterator_traits.hpp"

namespace ft
{
	template <class T>
	class BSTIterator //: public ft::iterator_traits<T*>
	{
		public :
			typedef T								value_type;
    		typedef std::ptrdiff_t					difference_type;
    		typedef T*								pointer;
    		typedef T&								reference;
    		typedef std::bidirectional_iterator_tag	iterator_category;
			typedef BSTIterator<T>					iterator;

		private :
			ft::Stack<s_BSTNode<T>*> 	st_node;
			ft::Stack<s_BSTNode<T>*> 	save_stack;

		public :
			// Coplien
			BSTIterator() : st_node(ft::Stack<s_BSTNode<T>*>()) {}
			BSTIterator(BinarySearchTree<T> &bst)
			{
        		s_BSTNode<T>* current = bst.GetRoot();

        		while (current != NULL)
            	{
					st_node.push(current);
					current = current->left;
				}
			}
			BSTIterator(s_BSTNode<T> *bst_node)
			{
        		s_BSTNode<T>* current = bst_node;

        		while (current != NULL)
            	{
					st_node.push(current);
					current = current->left;
				}
			}
			iterator operator=(const iterator &n_it)
			{
				st_node = n_it.st_node;

				return (*this);
			}
			~BSTIterator() {}

			// Getters
			s_BSTNode<T>* curr(){ return (st_node.top()); }
			s_BSTNode<T>* prev_curr(){ return (save_stack.top()); }

			// Member function
    		bool	hasNext();
			void	next();
			void	prev();
			bool	IsEmpty() { return (st_node.empty()); };

			// Operator overload
			T				operator*() 			{ return (curr()->data); };
			T				*operator->() 			{ return (&(curr()->data)); };
			iterator 		operator++()			{ this->next(); return (*this); }
			iterator 		operator--()			{ this->prev(); return (*this); }
			iterator 		operator++(int)			{ iterator tmp(*this); this->next(); return(tmp); }
	    	iterator 		operator--(int)			{ iterator tmp(*this); this->prev(); return(tmp); }

			// Comparison operator overload
		    bool operator!=(const iterator &sec_it) const	{ return (st_node != sec_it.st_node); }
		    bool operator==(const iterator &sec_it) const	{ return (st_node == sec_it.st_node); }
		    bool operator>=(const iterator &sec_it) const	{ return (st_node >= sec_it.st_node); }
		    bool operator>(const iterator &sec_it) const	{ return (st_node > sec_it.st_node); }
		    bool operator<=(const iterator &sec_it) const	{ return (st_node <= sec_it.st_node); }
		    bool operator<(const iterator &sec_it) const	{ return (st_node < sec_it.st_node); }

			// Is input iterator
			static const bool input_iter = true;
	};
}

template <class T>
bool ft::BSTIterator<T>::hasNext()
{
	if (this->IsEmpty())
		return (false);

	return (true);
}

template <class T>
void ft::BSTIterator<T>::next()
{
	if (this->hasNext())
	{
		s_BSTNode<T>* curr = this->curr()->right;

		st_node.pop();

    	while (curr != NULL)
		{
			st_node.push(curr);
			save_stack.push(curr);
			curr = curr->left;
		}
	}
}

template <class T>
void ft::BSTIterator<T>::prev()
{
	s_BSTNode<T>* curr = this->prev_curr()->left;

	save_stack.pop();

	if (curr == NULL)
		st_node.push(save_stack.top());

    while (curr != NULL)
	{
		st_node.push(curr);
		curr = curr->right;
	}
}

#endif
