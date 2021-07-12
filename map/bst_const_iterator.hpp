#if !defined(BST_ITERATOR_HPP)
#define BST_ITERATOR_HPP

#include "binary_search_tree.hpp"
#include "../stack/stack.hpp"

namespace ft
{
	template <class T>
	class BSTIterator
	{
		private :
			ft::Stack<s_BSTNode*> st_node;

		public :
			// Coplien
			BSTIterator() : st_node(nullptr);
			BSTIterator(BinarySearchTree<T> &bst)
			{
        		s_BSTNode* current = bst->bstroot_p;
        		while (current != nullptr)
            	{
					q.push(current);
					current = current->left;
				}
			}
			BSTIterator(s_BSTNode *bst)
			{
        		s_BSTNode* current = bst;
        		while (current != nullptr)
            	{
					q.push(current);
					current = current->left;
				}
			}
			~BSTIterator() {};

			// Getters
			s_BSTNode* curr(){ return st_node.top(); }

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
	s_BSTNode* curr = st_node.top()->right;

	st_node.pop();
    while (curr != nullptr)
	{
		st_node.push(curr);
		curr = curr->left;
	}
}

#endif
