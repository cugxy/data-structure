// Author£º		xiongw
// Date£º		2018-3-17
// filename:	BST.h

#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include <stdlib.h>

template<class E, class K>
struct BSTNode
{
	E data;
	BSTNode<E, K> *pLeft;
	BSTNode<E, K> *pRight;

	BSTNode() :pLeft(NULL), pRight(NULL) {}
	BSTNode(const E d, BSTNode<E, K> *pL = NULL, BSTNode<E, K> *pR = NULL)
		:data(d), pLeft(pL), pRight(pR) {}

	~BSTNode() { }
};

template<class E, class K>
class BST
{
private:
	BSTNode<E, K> *m_pRoot;
	K m_RefValue;

private:
	BSTNode<E, K>*	Search(const K x, BSTNode<E, K>* ptr);
	BSTNode<E, K>*	Copy(BSTNode<E, K>* ptr);
	BSTNode<E, K>*	Min(BSTNode<E, K>* ptr) const;
	BSTNode<E, K>*	Max(BSTNode<E, K>* ptr) const;

	bool			Insert(const E& v, BSTNode<E, K>*& ptr);
	bool			Remove(const K x, BSTNode<E, K>*& ptr);

	void			makeEmpty(BSTNode<E, K>*& ptr);
	void			PrintTree(BSTNode<E, K>*& ptr) const;

public:
	BST();
	explicit BST(K value);
	BST<E, K>&	operator=(const BST<E, K> &tree);
	~BST();

	bool	Search(const K x)const;
	void	MakeEmpty();
	void	PrintTree() const;
	E		Min();
	E		Max();
	bool	Insert(const E& v);
	bool	Remove(const K x);
};





#endif // !_BST_H_
