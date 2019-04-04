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
template<class E>
struct AVLNode : public BSTNode<E>
{
	int nbf;		/**< 平衡因子（balance factor）左子树高度减去右子树高度 */

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
	AVLNode(E d, AVLNode<E>* pL = NULL, AVLNode<E>* pR = NULL)
		: data(d), pLeft(pL), pRight(pR), nff(0) { }
};

/**
* \brief 二叉树 左右子树与根节点存在一定大小关系且左右子树平衡
* \author	xy
*/
template<class E>
class AVLTree :public BST<E>
{
private:
	AVLNode<E> *m_pRoot;	/**< 根节点 */

protected:

	/**
	* \brief 搜索
	* \param[in] x 搜索元素
	* \param[in] par 搜索子树
	* \return AVLNode<E>*
	*/
	AVLNode<E>* Search(E x, AVLNode<E>*& par) const;

	/**
	* \brief 插入
	* \param[in] ptr 子树
	* \param[in] el 插入元素
	* \return bool
	*/
	bool Insert(AVLNode<E>*& ptr, E& el);

	/**
	* \brief 移除
	* \param[in] ptr 子树
	* \param[in] x 移除元素
	* \param[in] el 移除元素
	* \return bool
	*/
	bool Remove(AVLNode<E>*& ptr, E& el);

	/**
	* \brief 左单旋转
	* \param[in] ptr 子树
	* \return void
	*/
	void RotateL(AVLNode<E>*& ptr);

	/**
	* \brief 右单旋转
	* \param[in] ptr 子树
	* \return void
	*/
	void RotateR(AVLNode<E>*& ptr);

	/**
	* \brief 左右旋转
	* \param[in] ptr 子树
	* \return void
	*/
	void RotateLR(AVLNode<E>*& ptr);

	/**
	* \brief 右左旋转
	* \param[in] ptr 子树
	* \return void
	*/
	void RotateRL(AVLNode<E>*& ptr);
		
	/**
	* \brief 子树高
	* \param[in] ptr 子树
	* \return int
	*/
	int	Height(AVLNode<E>* ptr) const;

public:

	/**
	* \brief 默认构造函数
	*/
	AVLTree() : m_pRoot(NULL) {}

	/**
	* \brief 插入
	* \param[in] el 插入元素
	* \return bool
	*/
	bool Insert(E& el);

	/**
	* \brief 搜索
	* \param[in] x 搜索元素
	* \return AVLNode<E>*
	*/
	AVLNode<E>* Search(E & el) const;

	/**
	* \brief 移除
	* \param[in] el 移除元素
	* \return bool
	*/
	bool Remove(E& el);

	/**
	* \brief 树高
	* \return int
	*/
	int Height() const;

	friend std::istream& operator >> (std::istream& in, AVLTree<E>& tree);

	friend std::ostream& operator << (std::ostream& in, AVLTree<E>& tree);
};


template<class E>
bool AVLTree<E>::Insert(E & el)
{
	return false;
}

template<class E>
AVLNode<E>* AVLTree<E>::Search(E & el) const
{
	return false;
}

template<class E>
bool AVLTree<E>::Remove(E & el)
{
	return false;
}

template<class E>
int AVLTree<E>::Height() const
{
	return 0;
}

template<class E>
AVLNode<E>* AVLTree<E>::Search(E x, AVLNode<E>*& par) const
{
	return NULL;
}

template<class E>
bool AVLTree<E>::Insert(AVLNode<E>*& ptr, E & el)
{
	return false;
}

template<class E>
bool AVLTree<E>::Remove(AVLNode<E>*& ptr, E & el)
{
	return false;
}

template<class E>
void AVLTree<E>::RotateL(AVLNode<E>*& ptr)
{
	AVLNode<E> *pSubL= ptr;			// 指针 pSubL 指向 之前根节点，
	ptr = pSubL->pRight;			// ptr 指向 之前根节点的右子树，成为新的根节点
	pSubL->pRight = ptr->pLeft;		// 将之前根节点（即新的左子树根节点)的右节点赋值为新的根节点的左节点）
	ptr->pLeft = pSubL;				// 新的根节点左节点赋值为pSubL(之前根节点) 右节点不变
	ptr->nbf = 0;					// 重置平衡因子
	pSubL->nbf = 0;
}

template<class E>
void AVLTree<E>::RotateR(AVLNode<E>*& ptr)
{
	AVLNode<E> *pSubR = ptr;
	ptr = pSubR->pLeft;
	pSubR->pLeft = ptr->pRight;
	ptr->pRight = pSubR;
	ptr->nbf = 0;
	pSubR->nbf = 0;
}

template<class E>
void AVLTree<E>::RotateLR(AVLNode<E>*& ptr)
{
	// 先左单旋
	AVLNode<K>* pSubR = ptr;
	AVLNode<K>* pSubL = ptr->pLeft;
	ptr = pSubL->pRight;
	pSubL->pRight = ptr->pLeft;
	ptr->pLeft = pSubL;

	if (ptr->nbf <= 0)
		pSubL->nbf = 0;
	else
		pSubL->nbf = -1;
	// 右单旋
	pSubR->pLeft = ptr->pRight;
	ptr->pRight = pSubR;

	if (ptr->nbf == -1)
		pSubR->nbf = 1;
	else
		pSubR->nbf = 0;
	ptr->nbf = 0;
}

template<class E>
void AVLTree<E>::RotateRL(AVLNode<E>*& ptr)
{
	AVLNode<K>* pSubL = ptr;
	AVLNode<K>* pSubR = ptr->pRight;
	ptr = pSubL->pLeft;
	pSubR->pLeft = ptr->pRight;
	ptr->pRight = pSubR;
	
	if (ptr->nbf >= 0)
		pSubR->nbf = 0;
	else
		pSubR->nbf = 1;

	pSubL->pRight = ptr->pLeft;
	ptr->pLeft = pSubL;
	
	if (ptr->nbf == 1)
		pSubL->nbf = -1;
	else
		pSubL->nbf = 0;
	ptr->nbf = 0;
}

template<class E>
int AVLTree<E>::Height(AVLNode<E>* ptr) const
{
	return 0;
}

template<class E>
std::istream & operator >> (std::istream & in, AVLTree<E>& tree)
{
	// TODO: 在此处插入 return 语句
}

template<class E>
std::ostream & operator<<(std::ostream & in, AVLTree<E>& tree)
{
	// TODO: 在此处插入 return 语句
}

#endif // !_AVL_H


