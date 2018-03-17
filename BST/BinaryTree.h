// Author：		xiongw
// Date：		2018-3-17
// filename:	BST.h

#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <iostream>
#include <istream>
#include <stack>
#include <queue>

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
	// 从 in 流中递归构建树
	void				CreateBinTree(std::istream& in, BinTreeNode<T>*& pSubTree);

	// 插入节点？？？
	bool				Insert(BinTreeNode<T>*& pSubTree, const T& d);

	// 递归 delete
	void				Destory(BinTreeNode<T>*& pSubTree);

	// 递归 copy
	BinTreeNode<T>*		Copy(BinTreeNode<T>* pOriTree);
	
	// 获取子树高度
	int					Height(BinTreeNode<T>* pSubTree);
	
	// 获取子树大小
	int					Size(BinTreeNode<T>* pSubTree);

	// 递归查找父节点
	BinTreeNode<T>*		Parent(BinTreeNode<T>* pSubTree, BinTreeNode<T>* pCurrent);

	bool				IsExist(BinTreeNode<T>* pSubTree, const T& x);

	BinTreeNode<T>*		Find(BinTreeNode<T>* pSubTree, const T& x);

	// 递归输出 data
	void				Traverse(BinTreeNode<T>* pSubTree, std::ostream& out);

	// 递归 前序遍历
	void				PreOrder(BinTreeNode<T>* pSubTree, void( * fun)(BinTreeNode<T>* p));

	// 递归 中序遍历
	void				InOrder(BinTreeNode<T>* pSubTree, void( * fun)(BinTreeNode<T>* p));

	// 递归 后序遍历
	void				PostOrder(BinTreeNode<T>* pSubTree, void( * fun)(BinTreeNode<T>* p));

	// 重载 输入
	friend std::istream&	operator >> (std::istream& in, BinaryTree<T> tree);

	// 重载 输出
	friend std::ostream&	operator << (std::ostream& out, BinaryTree<T> tree);

public:

	BinaryTree();
	explicit BinaryTree(T v);
	BinaryTree(BinaryTree<T>& tree);
	virtual ~BinaryTree();

	bool				IsEmpty();

	BinTreeNode<T>*		Parent(BinTreeNode<T>*& pCurrent);
	
	BinTreeNode<T>*		LeftChild(BinTreeNode<T>* pCurrent);

	BinTreeNode<T>*		RightChild(BinTreeNode<T>* pCurrent);

	int					Height();

	int					Size();

	BinTreeNode<T>*		GetRoot() const;

	bool				IsExist(T& v);

	BinTreeNode<T>*		Find(T& v);

	int					Insert(const T& v);

	void				PreOrder(void( * fun)(BinTreeNode<T>* p));

	void				InOrder(void( * fun)(BinTreeNode<T>* p));

	void				PostOrder(void( * fun)(BinTreeNode<T>* p));

	void				LevelOrder(void( * fun)(BinTreeNode<T>* p));
};

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

template<class T>
bool BinaryTree<T>::Insert(BinTreeNode<T>*& pSubTree, const T & d)
{
	if (pSubTree == NULL)
		return false;
	if (pSubTree->data == d)
		return false;
	if (d > pSubTree->data)
	{
		if (pSubTree->pLeftChild == NULL)
		{
			BinTreeNode<T>* pNode = new BinTreeNode<T>(d);
			pSubTree->pLeftChild = pNode;
			return true;
		}
		else
		{
			return Insert(pSubTree->pLeftChild, d);
		}
	}
	else
	{
		if (pSubTree->pRightChild == NULL)
		{
			BinTreeNode<T>* pNode = new BinTreeNode<T>(d);
			pSubTree->pRightChild = pNode;
			return true;
		}
		else
		{
			return Insert(pSubTree->pRightChild, d);
		}
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
