#if !defined(BST_ITERATOR_HPP)
#define BST_ITERATOR_HPP

#include "binary_search_tree.hpp"

namespace ft
{
	template <class T>
	class BSTIterator
	{
		private :
			s_BSTNode	*bstroot;
			s_BSTNode	*top;

		public :
			// Coplien
			BSTIterator() : bstroot(nullptr);
			BSTIterator(BinarySearchTree<T> &bst) : bstroot(bst->bstroot_p), top(nullptr);
			BSTIterator(s_BSTNode *bst) : bstroot(bst), top(nullptr);
			~BSTIterator() {};

			// Member function
    		bool	hasNext();
			void	next();

			// Operator overload
			T		operator*() { return (bstroot->data); };

	};
}

template <class T>
bool ft::BSTIterator<T>::hasNext()
{
	if (bstroot->right != nullptr || (top != nullptr && top->right != nullptr))
		return (true);
	return (false);
}

template <class T>
void ft::BSTIterator<T>::next()
{
	if (hasNext() == false)
		return ;

	if (bstroot->right != nullptr)
	{
		top = bstroot;
		bstroot = bstroot->right;
	}
	else if (top->right != nullptr)
	{



	}
}

#endif
