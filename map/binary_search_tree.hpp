#if !defined(BINARY_SEARCH_TREE_HPP)
#define BINARY_SEARCH_TREE_HPP

#include <iostream>

namespace ft
{
	template <class T>
	struct	s_BSTNode
	{
		T				data;
		s_BSTNode		*left;
		s_BSTNode		*right;
	};

	template <class T>
	class BinarySearchTree
	{
		private:
			struct s_BSTNode<T>	*bstroot_p;
			int					size;

		public:
		// Coplien
			BinarySearchTree() : bstroot_p(NULL) {}
			BinarySearchTree(s_BSTNode<T> *n_node) : bstroot_p(n_node) {}
			BinarySearchTree(T &data) : bstroot_p(GetNewNode(data)) {}
			// ~BinarySearchTree();

		// Getters
			struct s_BSTNode<T>	*GetRoot() const { return (bstroot_p); }

		// Member function
			s_BSTNode<T>	*GetNewNode(const T &data);
			s_BSTNode<T>	*Insert(s_BSTNode<T> *root, const T &data);
			s_BSTNode<T>	*Delete(s_BSTNode<T> *root, T &data);
			bool			Search(s_BSTNode<T> *root, T &data);
			s_BSTNode<T>	*FindMin(s_BSTNode<T> *root);
			s_BSTNode<T>	*FindMax(s_BSTNode<T> *root);
	};
}

// template <class T>
// ft::BinarySearchTree<T>::~BinarySearchTree()
// {
// 	while (bstroot_p != NULL)
// 		Delete(bstroot_p, bstroot_p->data);
// }

template <class T>
ft::s_BSTNode<T>	*ft::BinarySearchTree<T>::GetNewNode(const T &n_data)
{
	ft::s_BSTNode<T> *n_node = new ft::s_BSTNode<T>;

	n_node->data = n_data;
	n_node->right = NULL;
	n_node->left = NULL;

	return (n_node);
}

template <class T>
ft::s_BSTNode<T>	*ft::BinarySearchTree<T>::Insert(ft::s_BSTNode<T> *root, const T &data)
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
			Insert(root->left, data);
		}
		else
		{
			if (root->right == NULL)
			{
				size++;
				return (root->right = GetNewNode(data));
			}
			Insert(root->right, data);
		}
	}
	return (root);
}

template <class T>
ft::s_BSTNode<T>	*ft::BinarySearchTree<T>::Delete(ft::s_BSTNode<T> *root, T &data)
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
			delete root;
			size--;
			root = NULL;
		}
		else if (root->left == NULL)
		{
			ft::s_BSTNode<T> *tmp = root;
			root = root->right;
			size--;
			delete tmp;
		}
		else if (root->right == NULL)
		{
			ft::s_BSTNode<T> *tmp = root;
			root = root->left;
			size--;
			delete tmp;
		}
		else
		{
			ft::s_BSTNode<T> *tmp = FindMin(root->right);
			root->data = tmp->data;
			root->right = Delete(root->right, tmp->data);
		}
	}
	return (root);
}

template <class T>
bool	ft::BinarySearchTree<T>::Search(ft::s_BSTNode<T> *root, T &data)
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

template <class T>
ft::s_BSTNode<T>	*ft::BinarySearchTree<T>::FindMin(ft::s_BSTNode<T> *root)
{
	if (bstroot_p == NULL || root == NULL)
		return (NULL);
	if (root->left == NULL)
		return (root);
	else
		return (FindMin(root->left));
}

template <class T>
ft::s_BSTNode<T>	*ft::BinarySearchTree<T>::FindMax(ft::s_BSTNode<T> *root)
{
	if (bstroot_p == NULL || root == NULL)
		return (NULL);
	if (root->right == NULL)
		return (root);
	else
		return (FindMax(root->right));
}

#endif
