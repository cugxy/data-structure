// Author：		xiongw
// Date：		2018-3-17
// filename:	BinaryTree.h

#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <iostream>
#include <istream>
#include <stack>
#include <queue>

/**
* \brief 二叉树节点
* \author	xy
*/
template<class T>
struct BinTreeNode
{
	T					data;			/**< 数据 */
	BinTreeNode<T>	   *pLeftChild;		/**< 左子树 */
	BinTreeNode<T>	   *pRightChild;	/**< 右子树 */

	/**
	* \brief 默认构造函数
	*/
	BinTreeNode()
		: pLeftChild(NULL)
		, pRightChild(NULL)
	{
	}

	/**
	* \brief 构造函数
	* \param[in] d 数据
	* \param[in] pL 左子树
	* \param[in] pR 右子树
	*/
	BinTreeNode(T d, BinTreeNode<T> *pL = NULL, BinTreeNode<T> *pR = NULL)
		: data(d)
		, pLeftChild(pL)
		, pRightChild(pR)
	{
	}
};

/**
* \brief 二叉树
* \author	xy
*/
template<class T>
class BinaryTree
{
protected:
	BinTreeNode<T>*		m_pRoot;	/**< 根节点 */
	T					m_RefValue;	/**< 结束标识 */

protected:
	/**
	* \brief 创建二叉树
	* \param[in|out] in 数据流
	* \param[in|out] pSubTree 子树
	* \return void
	*/
	void CreateBinTree(std::istream& in, BinTreeNode<T>*& pSubTree);

	/**
	* \brief 插入节点 插入规则为 左 > 根 > 右
	* \param[in] d 插入元素
	* \param[in|out] pSubTree 子树
	* \return bool
	*/
	bool Insert(BinTreeNode<T>*& pSubTree, const T& d);

	/**
	* \brief 递归 delete
	* \param[in|out] pSubTree 子树
	* \return void
	*/
	void Destory(BinTreeNode<T>*& pSubTree);

	/**
	* \brief 递归 copy
	* \param[in] pOriTree 子树
	* \return BinTreeNode<T>*
	*/
	BinTreeNode<T>*	Copy(BinTreeNode<T>* pOriTree);
	
	/**
	* \brief 获取子树高度
	* \param[in] pSubTree 子树
	* \return int
	*/
	int	Height(BinTreeNode<T>* pSubTree);
	
	/**
	* \brief 获取子树节点数量
	* \param[in] pSubTree 子树
	* \return int
	*/
	int	Size(BinTreeNode<T>* pSubTree);

	/**
	* \brief 递归查找父节点
	* \param[in] pSubTree 子树
	* \param[in] pCurrent 当前节点
	* \return BinTreeNode<T>* 当前节点父节点
	*/
	BinTreeNode<T>*	Parent(BinTreeNode<T>* pSubTree, BinTreeNode<T>* pCurrent);

	/**
	* \brief 判断元素 x 是否存在
	* \param[in] pSubTree 子树
	* \return bool
	*/
	bool IsExist(BinTreeNode<T>* pSubTree, const T& x);

	/**
	* \brief 查找元素 x 对应节点（节点中包含了左右子树信息）
	* \param[in] pSubTree 子树
	* \return BinTreeNode<T>*
	*/
	BinTreeNode<T>*	Find(BinTreeNode<T>* pSubTree, const T& x);

	/**
	* \brief 输出元素数据
	* \param[in] pSubTree 子树
	* \param[out] 输出流
	* \return void
	*/
	void Traverse(BinTreeNode<T>* pSubTree, std::ostream& out);

	/**
	* \brief 递归 前序遍历
	* \param[in] pSubTree 子树
	* \param[out] 函数指针（返回值为void，参数为BinTreeNode<T>*）
	* \return void
	*/
	void PreOrder(BinTreeNode<T>* pSubTree, void( * fun)(BinTreeNode<T>* p));

	/**
	* \brief 递归 中序遍历
	* \param[in] pSubTree 子树
	* \param[out] 函数指针（返回值为void，参数为BinTreeNode<T>*）
	* \return void
	*/
	void InOrder(BinTreeNode<T>* pSubTree, void( * fun)(BinTreeNode<T>* p));

	/**
	* \brief 递归 后序遍历
	* \param[in] pSubTree 子树
	* \param[out] 函数指针（返回值为void，参数为BinTreeNode<T>*）
	* \return void
	*/
	void PostOrder(BinTreeNode<T>* pSubTree, void( * fun)(BinTreeNode<T>* p));

	// 重载 输入
	friend std::istream& operator >> (std::istream& in, BinaryTree<T> tree);

	// 重载 输出
	friend std::ostream& operator << (std::ostream& out, BinaryTree<T> tree);

public:
	/**
	* \brief 默认构造函数
	*/
	BinaryTree();

	/**
	* \brief 构造函数
	* \param v 结束标识
	*/
	explicit BinaryTree(T v);

	/**
	* \brief 拷贝构造函数
	* \param tree 
	*/
	BinaryTree(BinaryTree<T>& tree);

	/**
	* \brief 析构函数
	*/
	virtual ~BinaryTree();

	/**
	* \brief 是否为空
	* \return bool
	*/
	bool IsEmpty();

	/**
	* \brief 获取父节点
	* \param pCurrent 当前节点
	* \return BinTreeNode<T>*
	*/
	BinTreeNode<T>*	Parent(BinTreeNode<T>*& pCurrent);
	
	/**
	* \brief 获取左子树
	* \param pCurrent 当前节点
	* \return BinTreeNode<T>*
	*/
	BinTreeNode<T>* LeftChild(BinTreeNode<T>* pCurrent);

	/**
	* \brief 获取右子树
	* \param pCurrent 当前节点
	* \return BinTreeNode<T>*
	*/
	BinTreeNode<T>*	RightChild(BinTreeNode<T>* pCurrent);

	/**
	* \brief 获取树高
	* \return int
	*/
	int Height();

	/**
	* \brief 获取元素个数
	* \return int
	*/
	int	Size();

	/**
	* \brief 获取根节点
	* \return BinTreeNode<T>*
	*/
	BinTreeNode<T>* GetRoot() const;

	/**
	* \brief 判断元素是否存在
	* \param v 元素
	* \return bool
	*/
	bool IsExist(T& v);

	/**
	* \brief 查找元素节点
	* \param v 元素
	* \return bool
	*/
	BinTreeNode<T>* Find(T& v);

	/**
	* \brief 插入元素
	* \param v 元素
	* \return bool
	*/
	int Insert(const T& v);

	/**
	* \brief 前序变量
	* \param[out] 函数指针（返回值为void，参数为BinTreeNode<T>*）
	* \return void
	*/
	void PreOrder(void( * fun)(BinTreeNode<T>* p));

	/**
	* \brief 前序变量
	* \param[out] 函数指针（返回值为void，参数为BinTreeNode<T>*）
	* \return void
	*/
	void InOrder(void( * fun)(BinTreeNode<T>* p));

	/**
	* \brief 中序变量
	* \param[out] 函数指针（返回值为void，参数为BinTreeNode<T>*）
	* \return void
	*/
	void PostOrder(void( * fun)(BinTreeNode<T>* p));

	/**
	* \brief 后序变量
	* \param[out] 函数指针（返回值为void，参数为BinTreeNode<T>*）
	* \return void
	*/
	void LevelOrder(void( * fun)(BinTreeNode<T>* p));
};

// 从输入流中读取数据并依次插入树节点中 中 >> 左 >> 右
template<class T>
void BinaryTree<T>::CreateBinTree(std::istream & in, BinTreeNode<T>*& pSubTree)
{
	T data;
	if (!in.eof())
	{
		in >> data;
		if (data != m_RefValue)
		{
			pSubTree = new BinTreeNode<T>(data);
			if (pSubTree == NULL)
			{
				std::cerr << "new error " << endl;
				throw std::exception("new error ");
			}
			CreateBinTree(in, pSubTree->pLeftChild);
			CreateBinTree(in, pSubTree->pRightChild);
		}
		else
			pSubTree = NULL;
	}

}

// 插入数据 d 如果子树根节点为空，构建子树，否则当 d > pSubTree 插入左边
template<class T>
bool BinaryTree<T>::Insert(BinTreeNode<T>*& pSubTree, const T & d)
{
	if (pSubTree == NULL)
	{
		BinTreeNode<T>* pNode = new BinTreeNode<T>(d);
		pSubTree = pNode;
		return true;
	}
	else if (pSubTree->data == d)
		return false;
	else if (d > pSubTree->data)
	{
		return Insert(pSubTree->pLeftChild, d);
	}
	else
	{
		return Insert(pSubTree->pRightChild, d);
	}
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
	if (pOriTree == NULL)
		return NULL;
	BinTreeNode<T>* pTmp = new BinTreeNode<T>();
	pTmp->data = pOriTree->data;
	pTmp->pLeftChild = Copy(pOriTree->pLeftChild);
	pTmp->pRightChild = Copy(pOriTree->pRightChild);
	return pTmp;
}

template<class T>
int BinaryTree<T>::Height(BinTreeNode<T>* pSubTree)
{
	if (pSubTree == NULL)
		return 0;
	else
	{
		int i = Height(pSubTree->pLeftChild);
		int j = Height(pSubTree->pRightChild);
		return (i < j) ? j + 1 : i + 1;
	}
}

template<class T>
int BinaryTree<T>::Size(BinTreeNode<T>* pSubTree)
{
	if (pSubTree == NULL)
		return 0;
	else
		return 1 + Size(pSubTree->pLeftChild) + Size(pSubTree->pRightChild);
}

template<class T>
BinTreeNode<T>*	BinaryTree<T>::Parent(BinTreeNode<T>* pSubTree, BinTreeNode<T>* pCurrent)
{
	if(pSubTree == NULL)
		return NULL;
	if (pSubTree->pLeftChild == pCurrent || pSubTree->pRightChild == pCurrent)
		return pSubTree;
	BinTreeNode<T>* pNode = NULL;
	if ((pNode = Parent(pSubTree->pLeftChild, pCurrent)) != NULL)
		return pNode;
	else
		return Parent(pSubTree->pRightChild, pCurrent);
}

template<class T>
bool BinaryTree<T>::IsExist(BinTreeNode<T>* pSubTree, const T& x)
{
	if(pSubTree == NULL)
		return false;
	if (pSubTree->data == x)
		return true;
	else
	{
		bool bl = IsExist(pSubTree->pLeftChild, x);
		bool br = IsExist(pSubTree->pRightChild, x);
		return bl || br;
	}
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::Find(BinTreeNode<T>* pSubTree, const T& x)
{
	if (pSubTree == NULL)
		return NULL;
	if (pSubTree->data == x)
		return pSubTree;
	else
	{
		BinTreeNode<T>* pL = Find(pSubTree->pLeftChild, x);
		BinTreeNode<T>* pR = Find(pSubTree->pRightChild, x);
		if (pL != NULL)
			return pL;
		else
			return pR;
	}
}

template<class T>
void BinaryTree<T>::Traverse(BinTreeNode<T>* pSubTree, std::ostream& out)
{
	if (pSubTree != NUll)
	{
		out << pSubTree->data << ' ';
		Traverse(pSubTree->pLeftChild, out);
		Traverse(pSubTree->pRightChild, out);
	}
}


template<class T>
void BinaryTree<T>::PreOrder(BinTreeNode<T>* pSubTree, void( * fun)(BinTreeNode<T>* p))
{
	if (pSubTree != NULL)
	{
		fun(pSubTree);
		PreOrder(pSubTree->pLeftChild, fun);
		PreOrder(pSubTree->pRightChild， fun);
	}
}

template<class T>
void BinaryTree<T>::InOrder(BinTreeNode<T>* pSubTree, void( * fun)(BinTreeNode<T>* p))
{
	if (pSubTree != NULL)
	{
		InOrder(pSubTree->pLeftChild, fun);
		fun(pSubTree);
		InOrder(pSubTree->pRightChild， fun);
	}
}

template<class T>
void BinaryTree<T>::PostOrder(BinTreeNode<T>* pSubTree, void(*fun)(BinTreeNode<T>* p))
{
	if (pSubTree != NULL)
	{
		PostOrder(pSubTree->pLeftChild, fun);
		PostOrder(pSubTree->pRightChild， fun);
		fun(pSubTree);
	}
}


template<class T>
BinaryTree<T>::BinaryTree()
	: m_pRoot(NULL)
{
}

template<class T>
BinaryTree<T>::BinaryTree(T v)
	: m_pRoot(NULL)
	, m_RefValue(v)
{
}

template<class T>
BinaryTree<T>::BinaryTree(BinaryTree<T>& tree)
{
	m_pRoot = Copy(tree.m_pRoot);
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
	Destory(m_pRoot);
}

template<class T>
bool BinaryTree<T>::IsEmpty()
{
	return (m_pRoot == NULL) ? true : false;
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::Parent(BinTreeNode<T>*& pCurrent)
{
	return (m_pRoot == NULL || pCurrent == NULL) ? NULL : Parent(m_pRoot, pCurrent);
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::LeftChild(BinTreeNode<T>* pCurrent)
{
	return (pCurrent == NULL) ? NULL : pCurrent->pLeftChild;
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::RightChild(BinTreeNode<T>* pCurrent)
{
	return (pCurrent == NULL) ? NULL : pCurrent->pRightChild;
}

template<class T>
int BinaryTree<T>::Height()
{
	return Height(m_pRoot);
}

template<class T>
int BinaryTree<T>::Size()
{
	return Size(m_pRoot);
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::GetRoot() const
{
	return m_pRoot;
}

template<class T>
bool BinaryTree<T>::IsExist(T & v)
{
	return IsExist(m_pRoot, v); 
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::Find(T & v)
{
	return Find(m_pRoot, v);
}

template<class T>
int BinaryTree<T>::Insert(const T & v)
{
	return Insert(m_pRoot, v);
}

template<class T>
void BinaryTree<T>::PreOrder(void(*fun)(BinTreeNode<T>*p))
{
	std::stack<BinTreeNode<T>* > st;
	BinTreeNode<T>* pNode = m_pRoot;
	st.push(NULL);
	while (pNode != NULL)
	{
		fun(pNode);
		if (pNode->pRightChild != NULL)
			st.push(pNode->pRightChild);
		if (pNode->pLeftChild != NULL)
			pNode = pNode->pLeftChild;
		else
			st.pop(pNode);
	}
}

template<class T>
void BinaryTree<T>::InOrder(void(*fun)(BinTreeNode<T>*p))
{
}

template<class T>
void BinaryTree<T>::PostOrder(void(*fun)(BinTreeNode<T>*p))
{
}

template<class T>
void BinaryTree<T>::LevelOrder(void(*fun)(BinTreeNode<T>*p))
{
	std::queue<BinTreeNode<T>* > q;
	BinTreeNode<T>* pNode = m_pRoot;
	q.push(pNode);
	while (!q.empty())
	{
		pNode = q.front();
		fun(pNode);
		q.pop();
		if (pNode->pLeftChild != NULL)
			q.push(pNode->pLeftChild);
		if (pNode->pRightChild != NULL)
			q.push(pNode->pRightChild);
	}
}

template<class T>
std::istream&	operator >> (std::istream& in, BinaryTree<T> tree)
{
	CreateBinTree(in, tree.m_pRoot);
	return in;
}

template<class T>
std::ostream&	operator << (std::ostream& out, BinaryTree<T> tree)
{
	out << "binary tree order:\n";
	tree.Traverse(tree.m_pRoot, out);
	out << std::endl;
	return out;
}

#endif // !_BINARYTREE_H_
