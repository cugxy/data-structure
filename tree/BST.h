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
template<class E, class K>
struct BSTNode
{
	E data;					/**< 数据 */
	BSTNode<E, K> *pLeft;	/**< 左子树 */
	BSTNode<E, K> *pRight;	/**< 右子树 */

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
	BSTNode(const E d, BSTNode<E, K> *pL = NULL, BSTNode<E, K> *pR = NULL)
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
template<class E, class K>
class BST
{
private:
	BSTNode<E, K> *m_pRoot;	/**< 根节点 */
	K m_RefValue;			/**< 结束标记 */

private:
	/**
	* \brief 搜索
	* \param[in] x 搜索元素
	* \param[in] ptr 搜索子树
	* \return BSTNode<E, K>* 
	*/
	BSTNode<E, K>* Search(const K x, BSTNode<E, K>* ptr);

	/**
	* \brief 拷贝子树
	* \param[in] ptr 子树
	* \return BSTNode<E, K>*
	*/
	BSTNode<E, K>* Copy(BSTNode<E, K>* ptr);

	/**
	* \brief 获取最小值节点
	* \param[in] ptr 子树
	* \return BSTNode<E, K>*
	*/
	BSTNode<E, K>* Min(BSTNode<E, K>* ptr) const;

	/**
	* \brief 获取最大值节点
	* \param[in] ptr 子树
	* \return BSTNode<E, K>*
	*/
	BSTNode<E, K>* Max(BSTNode<E, K>* ptr) const;

	/**
	* \brief 插入
	* \param[in] v 插入元素
	* \param[in] ptr 子树
	* \return bool
	*/
	bool Insert(const E& v, BSTNode<E, K>*& ptr);

	/**
	* \brief 删除
	* \param[in] x 删除元素
	* \param[in] ptr 子树
	* \return bool
	*/
	bool Remove(const K x, BSTNode<E, K>*& ptr);

	/**
	* \brief 析构
	* \param[in] ptr 子树
	* \return void
	*/
	void Destory(BSTNode<E, K>*& ptr);

	/**
	* \brief 置空
	* \param[in] ptr 子树
	* \return void
	*/
	void makeEmpty(BSTNode<E, K>*& ptr);

	/**
	* \brief 打印
	* \param[in] ptr 子树
	* \return void
	*/
	void PrintTree(BSTNode<E, K>*& ptr) const;

public:
	/**
	* \brief 默认构造函数
	*/
	BST();

	/**
	* \brief 构造函数
	* \param[in] value 结束标志
	*/
	explicit BST(K value);

	/**
	* \brief 重载 = 操作符
	* \param[in] tree 
	* \return BST<E, K>&
	*/
	BST<E, K>&	operator=(const BST<E, K> &tree);

	/**
	* \brief 析构函数
	*/
	~BST();

	/**
	* \brief 查找
	* \param[in] x 查找元素
	* \return BSTNode<E, K>*
	*/
	BSTNode<E, K>* Search(const K x)const;

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
	bool Remove(const K x);
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
	if (ptr == NULL) return NULL;
	BSTNode<E, K>* pTmp = new BSTNode<E, K>(ptr->data);
	pTmp->pLeft = Copy(ptr->pLeft);
	pTmp->pRight = Copy(ptr->pRight);
	return pTmp;
}

template<class E, class K>
BSTNode<E, K>* BST<E, K>::Min(BSTNode<E, K>* ptr) const
{
	if (ptr == NULL) return NULL;
	while (ptr->pLeft != NULL)
	{
		ptr = ptr->pLeft
	}
	return ptr;
}

template<class E, class K>
BSTNode<E, K>* BST<E, K>::Max(BSTNode<E, K>* ptr) const
{
	 if (ptr == NULL) return NULL;
	 while (ptr->pRight != NULL)
	 {
		 ptr = ptr->pRight
	 }
	 return ptr;
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

template<class E, class K>
void BST<E, K>::Destory(BSTNode<E, K>*& ptr)
{
	if (ptr == NULL)return;

	Destory(ptr->pLeft);
	Destory(ptr->pRight);
	delete ptr;
	ptr = nullptr;
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
