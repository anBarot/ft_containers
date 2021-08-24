#if !defined(BST_CONST_REVERSE_ITERATOR_HPP)
#define BST_CONST_REVERSE_ITERATOR_HPP

#include <iterator>
#include "binary_search_tree.hpp"
#include "../stack/stack.hpp"
#include "../tools/iterator_traits.hpp"

namespace ft
{
	template <class T>
	class BSTConstReverseIterator : public ft::iterator_traits<std::__1::bidirectional_iterator_tag, T>
	{
		public :
			typedef const T								value_type;
    		typedef const T*							pointer;
			typedef typename ft::iterator_traits<std::__1::bidirectional_iterator_tag, T>::iterator_category iterator_category;
			typedef BSTConstReverseIterator<const T>	iterator;

		private :
			ft::stack<s_BSTNode<T>*> 	st_node;
			ft::stack<s_BSTNode<T>*> 	save_stack;

		public :
			// Coplien
			BSTConstReverseIterator() : st_node(ft::stack<s_BSTNode<T>*>()), save_stack(ft::stack<s_BSTNode<T>*>()) {}
			BSTConstReverseIterator(const BinarySearchTree<T> &bst)
			{
        		s_BSTNode<T>* current = bst.GetRoot();

        		while (current != NULL)
            	{
					st_node.push(current);
					current = current->right;
				}
			}
			BSTConstReverseIterator(s_BSTNode<T> *bst_node)
			{
        		s_BSTNode<T>* current = bst_node;

        		while (current != NULL)
            	{
					st_node.push(current);
					current = current->right;
				}
			}
			iterator operator=(const iterator &n_it)
			{
				st_node = n_it.st_node;

				return (*this);
			}
			~BSTConstReverseIterator() {}

			// Getters
			s_BSTNode<T>* curr() const		{ return (st_node.top()); }
			s_BSTNode<T>* prev_curr()const	{ return (save_stack.top()); }

			// Member function
    		bool	hasNext();
			void	next();
			void	prev();

			// Operator overload
			T				operator*() 			{ return (curr()->data); };
			T				*operator->() 			{ return (&(curr()->data)); };
			iterator 		operator++()			{ this->next(); return (*this); }
			iterator 		operator--()			{ this->prev(); return (*this); }
			iterator 		operator++(int)			{ iterator tmp(*this); this->next(); return(tmp); }
	    	iterator 		operator--(int)			{ iterator tmp(*this); this->prev(); return(tmp); }

			// Comparison operator overload
		    bool operator!=(const iterator &sec_it) const	{ 
																if (st_node.empty() == false && sec_it.st_node.empty() == false)
																	return (curr()->data.first != sec_it.curr()->data.first); 
																else if (st_node.empty() == true && sec_it.st_node.empty() == true)
																	return (false);
																return (true);
															}
		    bool operator==(const iterator &sec_it) const	{ return !(st_node != sec_it.st_node); }
		    bool operator>(const iterator &sec_it) const	{ 
																if (st_node.empty() == false && sec_it.st_node.empty() == false)
																	return (curr()->data.first > sec_it.curr()->data.first); 
																else if ((st_node.empty() == true && sec_it.st_node.empty() == true) || st_node.empty() == true)
																	return (false);
																return (true);
															}
		    bool operator<=(const iterator &sec_it) const	{ return !(st_node > sec_it.st_node); }
		    bool operator<(const iterator &sec_it) const	{ 
																if (st_node.empty() == false && sec_it.st_node.empty() == false)
																	return (curr()->data.first < sec_it.curr()->data.first); 
																else if ((st_node.empty() == true && sec_it.st_node.empty() == true) || st_node.empty() == true)
																	return (false);
																return (true);
															}
		    bool operator>=(const iterator &sec_it) const	{ return !(st_node < sec_it.st_node); }
	};
}

template <class T>
bool ft::BSTConstReverseIterator<T>::hasNext()
{
	if (st_node.empty() == true)
		return (false);

	return (true);
}

template <class T>
void ft::BSTConstReverseIterator<T>::next()
{
	if (this->hasNext())
	{
		save_stack.push(this->curr());

		s_BSTNode<T>* curr = this->curr()->left;

		st_node.pop();

    	while (curr != NULL)
		{
			st_node.push(curr);
			curr = curr->right;
		}
	}
}

template <class T>
void ft::BSTConstReverseIterator<T>::prev()
{
	if (save_stack.empty() == false)
	{
		if (st_node.empty() == false)
			st_node.pop();
		st_node.push(save_stack.top());
		save_stack.pop();
	}
}

#endif
