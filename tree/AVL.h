// Author：		xiongw
// Date：		2018-3-22
// filename:	AVL.h

#ifndef _AVL_H_
#define _AVL_H_

#include <iostream>
#include <stack>
#include "BST.h"

/**
* \brief	平衡二叉树搜索树节点
* \author	xy
*/
template<class E, class K>
struct AVLNode : public BSTNode<E>
{
	int nbf;		/**< 平衡因子（balance factor） */

	/**
	* \brief 默认构造函数
	*/
	AVLNode() :pLeft(NULL), pRight(NULL), nbf(0) { }

	/**
	* \brief 构造函数
	* \param[in] d 数据
	* \param[in] pL 左子树
	* \param[in] pR 右子树
	*/
	AVLNode(E d, AVLNode<E, K>* pL = NULL, AVLNode<E, K>* pR = NULL)
		: data(d), pLeft(pL), pRight(pR), nff(0) { }
};

/**
* \brief 二叉树 左右子树与根节点存在一定大小关系且左右子树平衡
* \author	xy
*/
template<class E, class K>
class AVLTree :public BST<E>
{
private:
	AVLNode<E, K> *m_pRoot;	/**< 根节点 */
	K m_RefValue;			/**< 结束标记 */

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
	AVLNode<E, K> *pSubL= ptr;		// 指针 pSubL 指向 之前根节点，
	ptr = pSubL->pRight;			// ptr 指向 之前根节点的右子树，成为新的根节点
	pSubL->pRight = ptr->pLeft;		// 将之前根节点（即新的左子树根节点)的右节点赋值为新的根节点的左节点）
	ptr->pLeft = pSubL;				// 新的根节点左节点赋值为pSubL(之前根节点) 右节点不变
	ptr-nbf = 0;
	pSubL->nbf = 0;
}

template<class E, class K>
void AVLTree<E, K>::RotateR(AVLNode<E, K>*& ptr)
{
	AVLNode<E, K> *pSubR = ptr;
	ptr = pSubR->pLeft;
	pSubR->pLeft = ptr->pRight;
	ptr->pRight = pSubR;
	ptr - nbf = 0;
	pSubR->nbf = 0;
}

template<class E, class K>
void AVLTree<E, K>::RotateLR(AVLNode<E, K>*& ptr)
{
	AVLNode<K, E>* pSubR = ptr;
	AVLNode<K, E>* pSubL = ptr->pLeft;
	ptr = pSubL->pRight;

	pSubL->pRight = ptr->pLeft;
	ptr->pLeft = pSubL;

	pSubR->pLeft = ptr->pRight;
	ptr->pRight = pSubR;

	if (ptr->nbf <= 0) ///?????????
		pSubL->nbf = 0;
	else
		pSubL->nbf = 0;

	if (ptr->nbf == -1)
		pSubR->nbf = 1;
	else
		pSubR->nbf = 0;
	ptr->nbf = 0;
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


