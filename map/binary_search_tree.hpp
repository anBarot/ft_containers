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
			BinarySearchTree() : bstroot_p(nullptr) {}
			BinarySearchTree(s_BSTNode<T> *n_node) : bstroot_p(n_node) {}
			BinarySearchTree(T &data) : bstroot_p(GetNewNode(data)) {}
			~BinarySearchTree();

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

template <class T>
ft::BinarySearchTree<T>::~BinarySearchTree()
{
	while (bstroot_p != nullptr)
		Delete(bstroot_p, bstroot_p->data);
}

template <class T>
ft::s_BSTNode<T>	*ft::BinarySearchTree<T>::GetNewNode(const T &n_data)
{
	ft::s_BSTNode<T> *n_node = new ft::s_BSTNode<T>;
	n_node->data = n_data;
	n_node->right = n_node->left = nullptr;
	return (n_node);
}

template <class T>
ft::s_BSTNode<T>	*ft::BinarySearchTree<T>::Insert(ft::s_BSTNode<T> *root, const T &data)
{
	if (bstroot_p == nullptr)
		return (bstroot_p = GetNewNode(data));
	else
	{
		if (root == nullptr)
			return (root = GetNewNode(data));
		else if (data <= root->data)
			root->left = Insert(root->left, data);
		else
			root->right = Insert(root->right, data);
	}
	return (nullptr);
}

template <class T>
ft::s_BSTNode<T>	*ft::BinarySearchTree<T>::Delete(ft::s_BSTNode<T> *root, T &data)
{
	if (root == nullptr || bstroot_p == nullptr)
		return (nullptr);
	else if (data < root->data)
		root->left = Delete(root->left, data);
	else if (data > root->data)
		root->right = Delete(root->right, data);
	else
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			root = nullptr;
		}
		else if (root->left == nullptr)
		{
			ft::s_BSTNode<T> *tmp = root;
			root = root->right;
			delete tmp;
		}
		else if (root->right == nullptr)
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
	if (bstroot_p == nullptr || root == nullptr)
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
	if (bstroot_p == nullptr || root == nullptr)
		return (nullptr);
	if (root->left == nullptr)
		return (root);
	else
		return (FindMin(root->left));
}

#endif
