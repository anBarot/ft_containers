#if !defined(BSTNODE_HPP)
#define BSTNODE_HPP

#include <iostream>

namespace ft
{
	template <class T>
	struct	BSTNode
	{
		T			data;
		BSTNode		*left;
		BSTNode		*right;
		BSTNode(const T &n_data) : data(n_data) {}
		~BSTNode() {}
	};
}

#endif
