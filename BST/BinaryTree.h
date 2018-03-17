// Author£º		xiongw
// Date£º		2018-3-17
// filename:	BST.h

#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <iostream>
#include <istream>

template<class T>
struct BinTreeNode
{
	T					data;
	BinTreeNode<T>	   *pLeftChild;
	BinTreeNode<T>	   *pRightChild;

	BinTreeNode()
		: pLeftChild(NULL)
		, pRightChild(NULL)
	{

	}

	BinTreeNode(T d, BinTreeNode<T> *pL = NULL, BinTreeNode<T> *pR = NULL)
		: data(d)
		, pLeftChild(pL)
		, pRightChild(pR)
	{

	}
};


template<class T>
class BinaryTree
{
protected:
	BinTreeNode<T>*		m_pRoot;
	T					m_RefValue;

protected:
	void				CreateBinTree(std::istream& in, BinTreeNode<T>*& pSubTree);

	bool				Insert(BinTreeNode<T>*& pSubTree, const T& d);

	void				Destory(BinTreeNode<T>*& pSubTree);

	BinTreeNode<T>*		Copy(BinTreeNode<T>* pOriTree);
	
	int					Height(BinTreeNode<T>* pSubTree);
	
	int					Size(BinTreeNode<T>* pSubTree);

	BinTreeNode<T>*		Parent(BinTreeNode<T>* pSubTree, BinTreeNode<T>* pCurrent);

	bool				Find(BinTreeNode<T>* pSubTree, const T& x) const;

	BinTreeNode<T>*		Find(BinTreeNode<T>* pSubTree, const T& x) const;

	void				Traverse(BinTreeNode<T>* pSubTree, std::ostream& out);


	void				PreOrder(BinTreeNode<T>& subTree, void(*fun)(BinTreeNode<T>* p));

	void				InOrder(BinTreeNode<T>& subTree, void(*fun)(BinTreeNode<T>* p));

	void				PostOrder(BinTreeNode<T>& subTree, void(*fun)(BinTreeNode<T>* p));


	friend std::istream&	operator >> (std::istream& in, BinaryTree<T> tree);

	friend std::ostream&	operator << (std::ostream& out, BinaryTree<T> tree);

public:
	BinaryTree();
	explicit BinaryTree(T value);
	BinaryTree(BinaryTree<T>& tree);
	virtual ~BinaryTree();

	bool				IsEmpty();

	BinTreeNode<T>*		Parent(BinTreeNode<T>*& pCurrent);
	
	BinTreeNode<T>*		LeftChild(BinTreeNode<T>* pCurrent);

	BinTreeNode<T>*		RightChild(BinTreeNode<T>* pCurrent);

	int					Height();

	int					Size();

	BinTreeNode<T>*		GetRoot() const;

	BinTreeNode<T>*		Find(T& v) const;

	int					Insert(const T& v);


	void				PreOrder(void(*fun)(BinTreeNode<T>* p));

	void				InOrder(void(*fun)(BinTreeNode<T>* p));

	void				PostOrder(void(*fun)(BinTreeNode<T>* p));
};

template<class T>
void BinaryTree<T>::CreateBinTree(std::istream & in, BinTreeNode<T>*& pSubTree)
{
}

template<class T>
bool BinaryTree<T>::Insert(BinTreeNode<T>*& pSubTree, const T & d)
{
	return false;
}

template<class T>
void BinaryTree<T>::Destory(BinTreeNode<T>*& pSubTree)
{
	if (pSubTree != NULL)
	{
		Destory(pSubTree->pLeftChild);
		Destory(pSubTree->pRightChild);
		delete pSubTree;
		pSubTree = NULL;
	}
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::Copy(BinTreeNode<T>* pOriTree)
{
	return false;
}

template<class T>
int BinaryTree<T>::Height(BinTreeNode<T>* pOriTree)
{
	return 0;
}

template<class T>
int BinaryTree<T>::Size(BinTreeNode<T>* pOriTree)
{
	return 0;
}

template<class T>
BinTreeNode<T>*	BinaryTree<T>::Parent(BinTreeNode<T>* pSubTree, BinTreeNode<T>* pCurrent)
{
	return NULL;
}

template<class T>
bool BinaryTree<T>::Find(BinTreeNode<T>* pSubTree, const T& x) const
{
	return false;
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::Find(BinTreeNode<T>* pSubTree, const T& x) const
{
	return NULL;
}

template<class T>
void BinaryTree<T>::Traverse(BinTreeNode<T>* pSubTree, std::ostream& out)
{

}


template<class T>
void BinaryTree<T>::PreOrder(BinTreeNode<T>& subTree, void(*fun)(BinTreeNode<T>* p))
{
}

template<class T>
void BinaryTree<T>::InOrder(BinTreeNode<T>& subTree, void(*fun)(BinTreeNode<T>* p))
{

}

template<class T>
void BinaryTree<T>::PostOrder(BinTreeNode<T>& subTree, void(*fun)(BinTreeNode<T>* p))
{

}



template<class T>
BinaryTree<T>::BinaryTree()
{

}

template<class T>
BinaryTree<T>::BinaryTree(T value)
{

}

template<class T>
BinaryTree<T>::BinaryTree(BinaryTree<T>& tree)
{

}

template<class T>
BinaryTree<T>::~BinaryTree()
{

}

template<class T>
inline BinTreeNode<T>* BinaryTree<T>::Parent(BinTreeNode<T>*& pCurrent)
{
	return NULL;
}

template<class T>
inline BinTreeNode<T>* BinaryTree<T>::LeftChild(BinTreeNode<T>* pCurrent)
{
	return NULL;
}

template<class T>
inline BinTreeNode<T>* BinaryTree<T>::RightChild(BinTreeNode<T>* pCurrent)
{
	return NULL;
}

template<class T>
inline int BinaryTree<T>::Height()
{
	return 0;
}

template<class T>
inline int BinaryTree<T>::Size()
{
	return 0;
}

template<class T>
inline BinTreeNode<T>* BinaryTree<T>::GetRoot() const
{
	return NULL;
}

template<class T>
inline BinTreeNode<T>* BinaryTree<T>::Find(T & v) const
{
	return NULL;
}

template<class T>
inline int BinaryTree<T>::Insert(const T & v)
{
	return 0;
}

template<class T>
inline void BinaryTree<T>::PreOrder(void(*fun)(BinTreeNode<T>*p))
{
}

template<class T>
inline void BinaryTree<T>::InOrder(void(*fun)(BinTreeNode<T>*p))
{
}

template<class T>
inline void BinaryTree<T>::PostOrder(void(*fun)(BinTreeNode<T>*p))
{
}

template<class T>
std::istream&	operator >> (std::istream& out, BinaryTree<T> tree)
{

}

template<class T>
std::ostream&	operator << (std::ostream& out, BinaryTree<T> tree)
{

}

#endif // !_BINARYTREE_H_
