#if !defined(BINARY_SEARCH_TREE_HPP)
#define BINARY_SEARCH_TREE_HPP

#include <iostream>
#include "BSTnode.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class BinarySearchTree
	{
		private:
			BSTNode<T>			*bstroot_p;
			size_t				size;
			typedef typename 	Alloc::template rebind<BSTNode<T> >::other t_node_alloc;
			t_node_alloc		alloc;

		public:
		// Coplien
			BinarySearchTree() : bstroot_p(NULL), size(0) {}
			BinarySearchTree(BSTNode<T> *n_node) : bstroot_p(NULL), size(0)
			{
				if (n_node != NULL)
				{
					bstroot_p = n_node;
					size = 1;
				}
			}
			BinarySearchTree(T &data) : bstroot_p(GetNewNode(data)), size(1) {}
			virtual ~BinarySearchTree();

		// Getters
			BSTNode<T>	*GetRoot() const 	{ return (bstroot_p); }
			size_t	GetSize() const					{ return (size); }

		// Member function
			BSTNode<T>	*GetNewNode(const T &data);
			BSTNode<T>	*Insert(BSTNode<T> *root, const T &data);
			BSTNode<T>	*Delete(BSTNode<T> *root, const T &data);
			bool		Search(BSTNode<T> *root, const T &data);
			BSTNode<T>	*FindMin(BSTNode<T> *root);
			BSTNode<T>	*FindMax(BSTNode<T> *root);
	};
}

template <class T, class Alloc>
ft::BinarySearchTree<T, Alloc>::~BinarySearchTree()
{
	while (bstroot_p != NULL)
	{
		Delete(bstroot_p, bstroot_p->data);
	}
}

template <class T, class Alloc>
ft::BSTNode<T>	*ft::BinarySearchTree<T, Alloc>::GetNewNode(const T &n_data)
{
	ft::BSTNode<T> *n_node =  alloc.allocate(1);

	alloc.construct(n_node, n_data);
	n_node->right = NULL;
	n_node->left = NULL;

	return (n_node);
}

template <class T, class Alloc>
ft::BSTNode<T>	*ft::BinarySearchTree<T, Alloc>::Insert(ft::BSTNode<T> *root, const T &data)
{
	if (bstroot_p == NULL)
	{
		size++;
		return (bstroot_p = GetNewNode(data));
	}
	else
	{
		if (data <= root->data)
		{
			if (root->left == NULL)
			{
				size++;
				return (root->left = GetNewNode(data));
			}
			return (Insert(root->left, data));
		}
		else
		{
			if (root->right == NULL)
			{
				size++;
				return (root->right = GetNewNode(data));
			}
			return (Insert(root->right, data));
		}
	}
}

template <class T, class Alloc>
ft::BSTNode<T>	*ft::BinarySearchTree<T, Alloc>::Delete(ft::BSTNode<T> *root, const T &data)
{
	if (root == NULL || bstroot_p == NULL)
		return (NULL);
	else if (data < root->data)
		root->left = Delete(root->left, data);
	else if (data > root->data)
		root->right = Delete(root->right, data);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			if (root == bstroot_p)
				bstroot_p = NULL;
			size--;
			alloc.destroy(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			if (root == bstroot_p)
				bstroot_p = root->right;
			ft::BSTNode<T> *tmp = root->right;
			alloc.destroy(root);
			size--;
			return (tmp);
		}
		else if (root->right == NULL)
		{
			if (root == bstroot_p)
				bstroot_p = root->left;
			ft::BSTNode<T> *tmp = root->left;
			alloc.destroy(root);
			size--;
			return (tmp);
		}
		else
		{
			ft::BSTNode<T> *tmp = FindMin(root->right);
			root->data = tmp->data;
			root->right = Delete(root->right, tmp->data);
		}
	}
	return (root);
}

template <class T, class Alloc>
bool	ft::BinarySearchTree<T, Alloc>::Search(ft::BSTNode<T> *root, const T &data)
{
	if (bstroot_p == NULL || root == NULL)
		return (false);
	if (data == root->data)
		return (true);
	else if (data < root->data)
		return (Search(root->left, data));
	else
		return (Search(root->right, data));
}

template <class T, class Alloc>
ft::BSTNode<T>	*ft::BinarySearchTree<T, Alloc>::FindMin(ft::BSTNode<T> *root)
{
	if (bstroot_p == NULL || root == NULL)
		return (NULL);
	if (root->left == NULL)

		return (root);
	else
		return (FindMin(root->left));
}

template <class T, class Alloc>
ft::BSTNode<T>	*ft::BinarySearchTree<T, Alloc>::FindMax(ft::BSTNode<T> *root)
{
	if (bstroot_p == NULL || root == NULL)
		return (NULL);
	if (root->right == NULL)
		return (root);
	else
		return (FindMax(root->right));
}

#endif
