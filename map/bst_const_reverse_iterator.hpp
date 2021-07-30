#if !defined(BST_CONST_REVERSE_ITERATOR_HPP)
#define BST_CONST_REVERSE_ITERATOR_HPP

#include "binary_search_tree.hpp"
#include "../stack/stack.hpp"
// #include "../tools/iterator_traits.hpp"

namespace ft
{
	template <class T>
	class BSTConstReverseIterator //: public ft::iterator_traits<T*>
	{
		private :
			const ft::Stack<s_BSTNode<T>*> st_node;

		public :
			// Coplien
			BSTConstReverseIterator() : st_node(NULL) {};
			BSTConstReverseIterator(const BinarySearchTree<T> &bst)
			{
        		s_BSTNode<T>* current = bst->bstroot_p;
        		while (current != NULL)
            	{
					st_node.push(current);
					current = current->left;
				}
			}
			BSTConstReverseIterator(s_BSTNode<T> *bst)
			{
        		s_BSTNode<T>* current = bst;
        		while (current != NULL)
            	{
					st_node.push(current);
					current = current->left;
				}
			}
			~BSTConstReverseIterator() {};

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
bool ft::BSTConstReverseIterator<T>::hasNext()
{
	if (st_node == NULL)
		return (false);
	return (true);
}

template <class T>
void ft::BSTConstReverseIterator<T>::next()
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
