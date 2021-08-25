#if !defined(BSTNODE_HPP)
#define BSTNODE_HPP

#include <iostream>

namespace ft
{
	template <class T>
	class	BSTNode
	{
		public :
			T				data;
			BSTNode		*left;
			BSTNode		*right;
	};
}

#endif
