#if !defined(BST_ITERATOR_HPP)
#define BST_ITERATOR_HPP

#include <iterator>
#include "binary_search_tree.hpp"
#include "../stack/stack.hpp"
#include "../tools/iterator_traits.hpp"

namespace ft
{
	template <class T>
	class BSTIterator : public ft::iterator_traits<T*>
	{
		public :
			// Iteratpr traits definition
			typedef T								value_type;
    		typedef std::ptrdiff_t					difference_type;
    		typedef T*								pointer;
    		typedef T&								reference;
    		typedef std::bidirectional_iterator_tag	iterator_category; 

		private :
			ft::Stack<s_BSTNode<T> *> st_node;

		public :
			// Coplien
			BSTIterator() : st_node(nullptr) {}
			BSTIterator(BinarySearchTree<T> &bst)
			{
        		s_BSTNode<T>* current = bst->bstroot_p;
        		while (current != nullptr)
            	{
					st_node.push(current);
					current = current->left;
				}
			}
			BSTIterator(s_BSTNode<T> *bst)
			{
        		s_BSTNode<T>* current = bst;

        		while (current != nullptr)
            	{
					st_node.push(current);
					current = current->left;
				}
			}
			~BSTIterator() {};

			// Getters
			s_BSTNode<T>* curr(){ return st_node.top(); }

			// Member function
    		bool	hasNext();
			void	next();

			// Operator overload
			T		operator*() { return (curr()->data); };

	};
}

template <class T>
bool ft::BSTIterator<T>::hasNext()
{
	if (st_node == nullptr)
		return (false);
	return (true);
}

template <class T>
void ft::BSTIterator<T>::next()
{
	s_BSTNode<T>* curr = st_node.top()->right;

	st_node.pop();
    while (curr != nullptr)
	{
		st_node.push(curr);
		curr = curr->left;
	}
}

#endif
