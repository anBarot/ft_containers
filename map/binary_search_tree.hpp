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

		public:
		// Coplien
			BinarySearchTree() : bstroot_p(NULL) { std::cout << "bst constructor called \n";}
			BinarySearchTree(s_BSTNode<T> *n_node) : bstroot_p(n_node) { std::cout << "bst constructor called \n"; }
			BinarySearchTree(T &data) : bstroot_p(GetNewNode(data)) { std::cout << "bst constructor called \n"; }
			// ~BinarySearchTree();

		// Getters
			struct s_BSTNode<T>	*GetRoot() const { return (bstroot_p); }

		// Member function
			s_BSTNode<T>	*GetNewNode(const T &data);
			s_BSTNode<T>	*Insert(s_BSTNode<T> *root, const T &data);
			s_BSTNode<T>	*Delete(s_BSTNode<T> *root, T &data);
			bool			Search(s_BSTNode<T> *root, T &data);
			s_BSTNode<T>	*FindMin(s_BSTNode<T> *root);
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
	n_node->right = n_node->left = NULL;

	return (n_node);
}

template <class T>
ft::s_BSTNode<T>	*ft::BinarySearchTree<T>::Insert(ft::s_BSTNode<T> *root, const T &data)
{
	if (bstroot_p == NULL)
		return (bstroot_p = GetNewNode(data));
	else
	{
		if (root == NULL)
			return (root = GetNewNode(data));
		else if (data <= root->data)
			return (root->left = Insert(root->left, data));
		else
			return (root->right = Insert(root->right, data));
	}
	return (NULL);
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
			root = NULL;
		}
		else if (root->left == NULL)
		{
			ft::s_BSTNode<T> *tmp = root;
			root = root->right;
			delete tmp;
		}
		else if (root->right == NULL)
		{
			ft::s_BSTNode<T> *tmp = root;
			root = root->left;
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

#endif
