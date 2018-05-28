// Author：		xiongw
// Date：		2018-3-17
// filename:	BST.h
// 二叉搜索树

#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include <stdlib.h>

/**
* \brief	二叉树搜索树节点
* \author	xy
*/
template<class E>
struct BSTNode
{
	E data;					/**< 数据 */
	BSTNode<E> *pLeft;	/**< 左子树 */
	BSTNode<E> *pRight;	/**< 右子树 */

	/**
	* \brief 默认构造函数
	*/
	BSTNode() :pLeft(NULL), pRight(NULL) {}

	/**
	* \brief 构造函数
	* \param[in] d 数据
	* \param[in] pL 左子树
	* \param[in] pR 右子树
	*/
	BSTNode(const E d, BSTNode<E> *pL = NULL, BSTNode<E> *pR = NULL)
		:data(d), pLeft(pL), pRight(pR) {}

	/**
	* \brief 析构函数
	*/
	~BSTNode() { }
};

/**
* \brief 二叉树 左右子树与根节点存在一定大小关系
* \author	xy
*/
template<class E>
class BST
{
private:
	BSTNode<E> *m_pRoot;	/**< 根节点 */

private:
	/**
	* \brief 搜索
	* \param[in] x 搜索元素
	* \param[in] ptr 搜索子树
	* \return BSTNode<E>* 
	*/
	BSTNode<E>* Search(const E x, BSTNode<E>* ptr);

	/**
	* \brief 拷贝子树
	* \param[in] ptr 子树
	* \return BSTNode<E>*
	*/
	BSTNode<E>* Copy(BSTNode<E>* ptr);

	/**
	* \brief 获取最小值节点
	* \param[in] ptr 子树
	* \return BSTNode<E>*
	*/
	BSTNode<E>* Min(BSTNode<E>* ptr) const;

	/**
	* \brief 获取最大值节点
	* \param[in] ptr 子树
	* \return BSTNode<E>*
	*/
	BSTNode<E>* Max(BSTNode<E>* ptr) const;

	/**
	* \brief 插入
	* \param[in] v 插入元素
	* \param[in] ptr 子树
	* \return bool
	*/
	bool Insert(const E& v, BSTNode<E>*& ptr);

	/**
	* \brief 删除
	* \param[in] x 删除元素
	* \param[in] ptr 子树
	* \return bool
	*/
	bool Remove(const E x, BSTNode<E>*& ptr);

	/**
	* \brief 析构
	* \param[in] ptr 子树
	* \return void
	*/
	void Destory(BSTNode<E>*& ptr);

	/**
	* \brief 置空
	* \param[in] ptr 子树
	* \return void
	*/
	void makeEmpty(BSTNode<E>*& ptr);

	/**
	* \brief 打印
	* \param[in] ptr 子树
	* \return void
	*/
	void PrintTree(BSTNode<E>*& ptr) const;

public:
	/**
	* \brief 默认构造函数
	*/
	BST();

	/**
	* \brief 重载 = 操作符
	* \param[in] tree 
	* \return BST<E>&
	*/
	BST<E>&	operator=(const BST<E> &tree);

	/**
	* \brief 析构函数
	*/
	~BST();

	/**
	* \brief 查找
	* \param[in] x 查找元素
	* \return BSTNode<E>*
	*/
	BSTNode<E>* Search(const E x)const;

	/**
	* \brief 置空
	* \return void
	*/
	void MakeEmpty();

	/**
	* \brief 打印
	* \return void
	*/
	void PrintTree() const;
		
	/**
	* \brief 最小值
	* \return E
	*/
	E Min();

	/**
	* \brief 最大值
	* \return E
	*/
	E Max();

	/**
	* \brief 插入
	* \param[in] v 插入元素
	* \return bool
	*/
	bool Insert(const E& v);

	/**
	* \brief 删除
	* \param[in] x 删除元素
	* \return bool
	*/
	bool Remove(const E x);
};

template<class E>
BSTNode<E>* BST<E>::Search(const E x, BSTNode<E>* ptr)
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

template<class E>
BSTNode<E>* BST<E>::Copy(BSTNode<E>* ptr)
{
	if (ptr == NULL) return NULL;
	BSTNode<E>* pTmp = new BSTNode<E>(ptr->data);
	pTmp->pLeft = Copy(ptr->pLeft);
	pTmp->pRight = Copy(ptr->pRight);
	return pTmp;
}

template<class E>
BSTNode<E>* BST<E>::Min(BSTNode<E>* ptr) const
{
	if (ptr == NULL) return NULL;
	while (ptr->pLeft != NULL)
	{
		ptr = ptr->pLeft
	}
	return ptr;
}

template<class E>
BSTNode<E>* BST<E>::Max(BSTNode<E>* ptr) const
{
	 if (ptr == NULL) return NULL;
	 while (ptr->pRight != NULL)
	 {
		 ptr = ptr->pRight
	 }
	 return ptr;
}

template<class E>
bool BST<E>::Insert(const E & v, BSTNode<E>*& ptr)
{
	if (ptr == NULL)
	{
		ptr = new BSTNode<E>(v);
		return true;
	}
	else if (v < ptr->data)
		Insert(v, ptr->pLeft);
	else if (v > ptr->data)
		Insert(v, ptr->pRight);
	else
		return false;
}

template<class E>
bool BST<E>::Remove(const E x, BSTNode<E>*& ptr)
{
	BSTNode<E> *pTmp = NULL;
	if (ptr == NULL) return false;
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
		else                   // 左子树不为空
			ptr = ptr->pLeft;
		delete pTmp;
		return true;
	}
}

template<class E>
void BST<E>::Destory(BSTNode<E>*& ptr)
{
	if (ptr == NULL)return;

	Destory(ptr->pLeft);
	Destory(ptr->pRight);
	delete ptr;
	ptr = nullptr;
}

template<class E>
void BST<E>::makeEmpty(BSTNode<E>*& ptr)
{
	Destory(ptr);
}

template<class E>
void BST<E>::PrintTree(BSTNode<E>*& ptr) const
{
	if (ptr == NULL)return;
	PrintTree(ptr->pLeft);
	std::cout << ptr->data;
	PrintTree(ptr->pRight);
}

template<class E>
BST<E>::BST()
	: m_pRoot(NULL)
{
}

template<class E>
BST<E>& BST<E>::operator=(const BST<E>& tree)
{
	return Copy(tree);
}

template<class E>
BST<E>::~BST()
{
	Destory(m_pRoot);
}

template<class E>
BSTNode<E>* BST<E>::Search(const E x) const
{
	return Search(x, m_pRoot);
}

template<class E>
void BST<E>::MakeEmpty()
{
	makeEmpty(m_pRoot);
}

template<class E>
void BST<E>::PrintTree() const
{
	PrintTree(m_pRoot);
}

template<class E>
 E BST<E>::Min()
{
	return Min(m_pRoot);
}

template<class E>
 E BST<E>::Max()
{
	return Max(m_pRoot);
}

template<class E>
 bool BST<E>::Insert(const E & v)
{
	return Insert(v, m_pRoot);
}

template<class E>
bool BST<E>::Remove(const E x)
{
	return Remove(x, m_pRoot);
}

#endif // !_BST_H_
