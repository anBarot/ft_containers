#if !defined(BINARY_SEARCH_TREE_HPP)
#define BINARY_SEARCH_TREE_HPP

#include <iostream>

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
		struct s_BSTNode	*bstroot_p;

	public:
	// Coplien
		BinarySearchTree() : bstroot_p(nullptr) {}
		BinarySearchTree(s_BSTNode *n_node) : bstroot_p(n_node) {}
		BinarySearchTree(T &data) : bstroot_p(GetNewNode(data)) {}

	//Member function
		s_BSTNode	*GetNewNode(T &data);
		s_BSTNode	*Insert(s_BSTNode *root, T &data);
		s_BSTNode	*Delete(s_BSTNode *root, T &data);
		bool		Search(s_BSTNode *root, T &data);
		s_BSTNode	*FindMin(s_BSTNode *root);
};

template <class T>
s_BSTNode	*BinarySearchTree<T>::GetNewNode(T &data)
{
	s_BSTNode *n_node = new s_BSTNode;
	n_node->data = data;
	n_node->right = n_node->left = nullptr;
	return (n_node);
}

template <class T>
s_BSTNode	*BinarySearchTree<T>::Insert(s_BSTNode *root, T &data)
{
	if (bstroot_p == nullptr)
		return (bstroot_p = GetNewNode(data));
	else
	{
		if (root == nullptr)
			root = GetNewNode(data);
		else if (data <= root->data)
			root->left = Insert(root->left, data);
		else
			root->right = Insert(root->right, data);
	}
}

template <class T>
s_BSTNode	*BinarySearchTree<T>::Delete(s_BSTNode *root, T &data)
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
			s_BSTNode *tmp = root;
			root = root->right;
			delete tmp;
		}
		else if (root->right == nullptr)
		{
			s_BSTNode *tmp = root;
			root = root->left;
			delete tmp;
		}
		else
		{
			s_BSTNode *tmp = FindMin(root->right);
			root->data = tmp->data;
			root->right = Delete(root->right, tmp->data);
		}
	}
	return (root);
}

template <class T>
bool	BinarySearchTree<T>::Search(s_BSTNode *root, T &data)
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
s_BSTNode	*BinarySearchTree<T>::FindMin(s_BSTNode *root)
{
	if (bstroot_p == nullptr || root == nullptr)
		return (nullptr);
	if (root->left == nullptr)
		return (root);
	else
		return (FindMin(root->left));
}

#endif