#if !defined(BST_CONST_ITERATOR_HPP)
#define BST_CONST_ITERATOR_HPP

#include "binary_search_tree.hpp"
#include "../stack/stack.hpp"
#include "../tools/iterator_traits.hpp"

namespace ft
{
	template <class T>
	class BSTConstIterator : public ft::iterator_traits<T*>
	{
		private :
			ft::Stack<s_BSTNode<T>*> st_node;

		public :
			// Coplien
			BSTConstIterator() : st_node(nullptr) {};
			BSTConstIterator(BinarySearchTree<T> &bst)
			{
        		s_BSTNode<T>* current = bst->bstroot_p;
        		while (current != nullptr)
            	{
					st_node.push(current);
					current = current->left;
				}
			}
			BSTConstIterator(s_BSTNode<T> *bst)
			{
        		s_BSTNode<T>* current = bst;
        		while (current != nullptr)
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

			// Operator overload
			T		operator*() { return (curr()->data); };

	};
}

template <class T>
bool ft::BSTConstIterator<T>::hasNext()
{
	if (st_node == nullptr)
		return (false);
	return (true);
}

template <class T>
void ft::BSTConstIterator<T>::next()
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
