// Author：		xiongw
// Date：		2018-3-17
// filename:	BST.h
// 二叉搜索树

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

	void			Destory(BSTNode<E, K>*& ptr);

	void			makeEmpty(BSTNode<E, K>*& ptr);

	void			PrintTree(BSTNode<E, K>*& ptr) const;

public:
	BST();

	explicit BST(K value);

	BST<E, K>&	operator=(const BST<E, K> &tree);

	~BST();

	BSTNode<E, K>*	Search(const K x)const;

	void			MakeEmpty();

	void			PrintTree() const;
		
	E				Min();

	E				Max();

	bool			Insert(const E& v);

	bool			Remove(const K x);
};

template<class E, class K>
BSTNode<E, K>* BST<E, K>::Search(const K x, BSTNode<E, K>* ptr)
{
	if (ptr == NULL)
		return NULL;
	else if (x < ptr->data)
		return Search(x, ptr->pLeft);
	else if (x > ptr->data)
		return Search(x, ptr->pRight);
	else
		return ptr;
}

template<class E, class K>
BSTNode<E, K>* BST<E, K>::Copy(BSTNode<E, K>* ptr)
{
	if (ptr == NULL)
		return NULL;
	else
	{
		BSTNode<E, K>* pTmp = new BSTNode<E, K>(ptr->data);
		pTmp->pLeft = Copy(ptr->pLeft);
		pTmp->pRight = Copy(ptr->pRight);
		return pTmp;
	}
}

template<class E, class K>
BSTNode<E, K>* BST<E, K>::Min(BSTNode<E, K>* ptr) const
{
	if (ptr == NULL)
		return NULL;
	else
	{
		while (ptr->pLeft != NULL)
		{
			ptr = ptr->pLeft
		}
		return ptr;
	}
}

template<class E, class K>
BSTNode<E, K>* BST<E, K>::Max(BSTNode<E, K>* ptr) const
{
	 if (ptr == NULL)
		 return NULL;
	 else
	 {
		 while (ptr->pRight != NULL)
		 {
			 ptr = ptr->pRight
		 }
		 return ptr;
	 }
}

template<class E, class K>
bool BST<E, K>::Insert(const E & v, BSTNode<E, K>*& ptr)
{
	if (ptr == NULL)
	{
		ptr = new BSTNode<E, K>(v);
		return true;
	}
	else if (v < ptr->data)
		Insert(v, ptr->pLeft);
	else if (v > ptr->data)
		Insert(v, ptr->pRight);
	else
		return false;
}

template<class E, class K>
bool BST<E, K>::Remove(const K x, BSTNode<E, K>*& ptr)
{
	BSTNode<E, K> *pTmp = NULL;
	if (ptr != NULL)
	{
		if (x < ptr->data)
			Remove(x, ptr->pLeft);
		else if (x > ptr->data)
			Remove(x, ptr->pRight);
		else if (ptr->pLeft != NULL && ptr->pRight != NULL) // 如果左右均不为空 则将比其大的第一个值放到该位置 并转化成在右子树中删除该值
		{
			pTmp = ptr->pRight;
			while (pTmp->pLeft != NULL)
			{
				pTmp = pTmp->pLeft;
			}
			ptr->data = pTmp->data;
			Remove(ptr->data, ptr->pRight);
		}
		else
		{
			pTmp = ptr;
			if (ptr->pLeft == NULL)// 左子树为空 
				ptr = ptr->pRight;
			else                   // 右子树为空 
				ptr = ptr->pLeft;
			delete pTmp;
			return true;
		}
	}
	return false;
}

template<class E, class K>
void BST<E, K>::Destory(BSTNode<E, K>*& ptr)
{
	if (ptr == NULL)
		return;
	else
	{
		Destory(ptr->pLeft);
		Destory(ptr->pRight);
		delete ptr;
		ptr = nullptr;
	}
}

template<class E, class K>
void BST<E, K>::makeEmpty(BSTNode<E, K>*& ptr)
{
	Destory(ptr);
}

template<class E, class K>
void BST<E, K>::PrintTree(BSTNode<E, K>*& ptr) const
{
	if (ptr != NULL)
	{
		PrintTree(ptr->pLeft);
		std::cout << ptr->data;
		PrintTree(ptr->pRight);
	}
}

template<class E, class K>
BST<E, K>::BST()
	: m_pRoot(NULL)
{
}

template<class E, class K>
BST<E, K>::BST(K value)
	: m_pRoot = NULL
	, m_RefValue(value)
{
}

template<class E, class K>
BST<E, K>& BST<E, K>::operator=(const BST<E, K>& tree)
{
	// TODO: 在此处插入 return 语句
	return Copy(tree);
}

template<class E, class K>
BST<E, K>::~BST()
{
	Destory(m_pRoot);
}

template<class E, class K>
BSTNode<E, K>* BST<E, K>::Search(const K x) const
{
	return Search(x, m_pRoot);
}

template<class E, class K>
void BST<E, K>::MakeEmpty()
{
	makeEmpty(m_pRoot);
}

template<class E, class K>
void BST<E, K>::PrintTree() const
{
	PrintTree(m_pRoot);
}

template<class E, class K>
 E BST<E, K>::Min()
{
	return Min(m_pRoot);
}

template<class E, class K>
 E BST<E, K>::Max()
{
	return Max(m_pRoot);
}

template<class E, class K>
 bool BST<E, K>::Insert(const E & v)
{
	return Insert(v, m_pRoot);
}

template<class E, class K>
bool BST<E, K>::Remove(const K x)
{
	return Remove(x, m_pRoot);
}

#endif // !_BST_H_
