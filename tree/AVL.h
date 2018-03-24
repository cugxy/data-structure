// Author：		xiongw
// Date：		2018-3-22
// filename:	AVL.h

#ifndef _AVL_H_
#define _AVL_H_

#include <iostream>
#include <stack>
#include "BST.h"

template<class E, class K>
struct AVLNode : public BSTNode<E, K>
{
	int nbf;		//平衡因子（balance factor）
	AVLNode() :pLeft(NULL), pRight(NULL), nbf(0) { }
	AVLNode(E d, AVLNode<E, K>* pL = NULL, AVLNode<E, K>* pR = NULL)
		: data(d), pLeft(pL), pRight(pR), nff(0) { }
};

template<class E, class K>
class AVLTree :public BST<E, K>
{
private:
	AVLNode<E, K> *m_pRoot;
	K m_RefValue;

public:
	AVLTree() : m_pRoot(NULL) {}

	AVLTree(K ref) : m_pRoot(NULL), m_RefValue(ref) {}

	bool					Insert(E& el);

	bool					Remove(K x, E& el);

	int						Height() const;

	friend std::istream&	operator >> (std::istream& in, AVLTree<E, K>& tree);

	friend std::ostream&	operator << (std::ostream& in, AVLTree<E, K>& tree);

protected:
	AVLNode<E, K>*			Search(K x, AVLNode<E, K>*& par) const;

	bool					Insert(AVLNode<E, K>*& ptr, E& el);

	bool					Remove(AVLNode<E, K>*& ptr, K x, E& el);

	void					RotateL(AVLNode<E, K>*& ptr);

	void					RotateR(AVLNode<E, K>*& ptr);

	void					RotateLR(AVLNode<E, K>*& ptr);

	void					RotateRL(AVLNode<E, K>*& ptr);
			
	int						Height(AVLNode<E, K>* ptr) const;
};


template<class E, class K>
bool AVLTree<E, K>::Insert(E & el)
{
	return false;
}

template<class E, class K>
bool AVLTree<E, K>::Remove(K x, E & el)
{
	return false;
}

template<class E, class K>
int AVLTree<E, K>::Height() const
{
	return 0;
}

template<class E, class K>
AVLNode<E, K>* AVLTree<E, K>::Search(K x, AVLNode<E, K>*& par) const
{
	return NULL;
}

template<class E, class K>
bool AVLTree<E, K>::Insert(AVLNode<E, K>*& ptr, E & el)
{
	return false;
}

template<class E, class K>
bool AVLTree<E, K>::Remove(AVLNode<E, K>*& ptr, K x, E & el)
{
	return false;
}

template<class E, class K>
void AVLTree<E, K>::RotateL(AVLNode<E, K>*& ptr)
{
}

template<class E, class K>
void AVLTree<E, K>::RotateR(AVLNode<E, K>*& ptr)
{
}

template<class E, class K>
void AVLTree<E, K>::RotateLR(AVLNode<E, K>*& ptr)
{
}

template<class E, class K>
void AVLTree<E, K>::RotateRL(AVLNode<E, K>*& ptr)
{
}

template<class E, class K>
int AVLTree<E, K>::Height(AVLNode<E, K>* ptr) const
{
	return 0;
}

template<class E, class K>
std::istream & operator >> (std::istream & in, AVLTree<E, K>& tree)
{
	// TODO: 在此处插入 return 语句
}

template<class E, class K>
std::ostream & operator<<(std::ostream & in, AVLTree<E, K>& tree)
{
	// TODO: 在此处插入 return 语句
}

#endif // !_AVL_H


