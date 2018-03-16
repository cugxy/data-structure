// Author：xiongy
// Date：2018/02/08
// filename:BinaryTree.h
#ifndef _BINARYTREE_
#define _BINARYTREE_
#include "ExportBinaryTree.h"
#include <ostream>
#include <iostream>
#include <string>
#include "BTreeNode.h"

using namespace std;

template<class T> 
class BINARYTREE_LIBRARY_EXPORT BinaryTree
{
public:
	BinaryTree() : m_pRoot(nullptr) {}
	~BinaryTree() {}

	void insert(T);
	void remove(T);
	BTreeNode<T>* search(T);
	void destory();

	void preOrder();
	void inOrder();
	void postOrder();
	void print();

	BTreeNode<T>* minimumNode();//查找最小的节点
	BTreeNode<T>* maximumNode();//查找最大的节点

	T minimumKey();//查找最小的键值
	T maximumKey();//查找最小的键值

	BTreeNode<T>* predecessor(BTreeNode<T>*);
	BTreeNode<T>* sucessor(BTreeNode<T>*);
private:
	BTreeNode<T>* m_pRoot;     //树的根指针  
private:
	void insert(BTreeNode<T>* &, BTreeNode<T>* );
	BTreeNode<T>* search(BTreeNode<T>* &, T);

	void preOrder(BTreeNode<T>* &);
	void inOrder(BTreeNode<T>* &);
	void postOrder(BTreeNode<T>* &);

	BTreeNode<T>* minimumNode(BTreeNode<T> *&);
	BTreeNode<T>* maximumNode(BTreeNode<T> *&);

	void print(BTreeNode<T>* &);
	BTreeNode<T>* remove(BTreeNode<T>* &, BTreeNode<T>*);
	void destory(BTreeNode<T>* &);
};

/*
*插入操作
*非递归实现
*内部使用函数
*/
template<typename T>
void BinaryTree<T>::insert(BTreeNode<T>* &pTree, BTreeNode<T>* pNode)
{
	BTreeNode<T>* pParent = nullptr;
	BTreeNode<T>* pTemp = pTree;
	//寻找插入点
	while (pTemp != nullptr)
	{
		pParent = pTemp;
		if (pNode->getData() > pTemp->getData())
			pTemp = pTemp->getRChild();
		else
			pTemp = pTemp->getLChild();
	}
	pNode->getParent() = pParent;
	if (pParent == nullptr) //如果树本来就是空树，则直接把z节点插入根节点
		pTree = pNode;
	else if (pNode->getData() > pParent->getData()) //如果z的值大于其双亲，则z为其双亲的右孩
		pParent->getRChild() = pNode;
	else
		pParent->getLChild() = pNode;
}

/*
*查找操作
*非递归实现
*内部使用函数
*/
template <typename T>
BTreeNode<T>* BinaryTree<T>::search(BTreeNode<T>* &pTree, T key)
{
	BTreeNode<T>* pTemp = pTree;
	while (pTemp != nullptr)
	{
		if (pTemp->getData() == key)
			return pTemp;
		else if (pTemp->getData() > key)
			pTemp = pTemp->getLChild();
		else
			pTemp = pTemp->getRChild();
	}
	return nullptr;
}

template<typename T>
void BinaryTree<T>::preOrder(BTreeNode<T>*&pTree)
{
	if (pTree)
	{
		cout << pTree->getData() << " ";
		preOrder(pTree->getLChild());
		preOrder(pTree->getRChild());
	}
}

template<typename T>
void BinaryTree<T>::inOrder(BTreeNode<T>*&pTree)
{
	if (pTree)
	{
		inOrder(pTree->getLChild());
		cout << pTree->getData() << " ";
		inOrder(pTree->getRChild());
	}
}

template<typename T>
void BinaryTree<T>::postOrder(BTreeNode<T>*&pTree)
{
	if (pTree)
	{
		postOrder(pTree->getLChild());
		postOrder(pTree->getRChild());
		cout << pTree->getData() << " ";
	}
}

/*
*
*查找最小的结点
*内部调用函数
*
*/
template <typename T>
BTreeNode<T>* BinaryTree<T>::minimumNode(BTreeNode<T>*&pTree)
{
	BTreeNode<T>* pTemp = pTree;
	while (pTemp->getLChild())
	{
		pTemp = pTemp->getLChild();
	}
	return pTemp;
}
/*
*
*查找最大的结点
*内部调用函数
*
*/
template <typename T>
BTreeNode<T>* BinaryTree<T>::maximumNode(BTreeNode<T>*&pTree)
{
	BTreeNode<T>* pTemp = pTree;
	while (pTemp->getRChild())
	{
		pTemp = pTemp->getRChild();
	}
	return pTemp;
}

/*
*
*删除结点
*BSTree类内部调用函数
*
*/
template <class T>
BTreeNode<T>* BinaryTree<T>::remove(BTreeNode<T>* &pTree, BTreeNode<T> *pNode)
{
	BTreeNode<T> *pX = nullptr;
	BTreeNode<T> *pY = nullptr;
	if ((pNode->getLChild() == nullptr) || (pNode->getRChild() == nullptr))
		pY = pNode;
	else
		pY = sucessor(pNode);
	if (pY->getLChild() != nullptr)
		pX = pY->getLChild();
	else
		pX = pY->getRChild();
	if (pX != nullptr)
		pX->getParent() = pY->getParent();
	if (pY->getParent() == nullptr)
		pTree = pX;
	else if (pY == pY->getParent()->getLChild())
		pY->getParent()->getLChild() = pX;
	else
		pY->getParent()->getRChild() = pX;
	if (pY != pNode)
		pNode->setData(pY->getData());
	return pY;
}

template <typename T>
BTreeNode<T>* BinaryTree<T>::predecessor(BTreeNode<T>* pNode)
{
	if(pNode->getData() == minimumNode(m_pRoot)->getData())//如果x是最小的结点，则它没有前驱
		return nullptr;
	BTreeNode <T> *pY = nullptr;
	pY = search(m_pRoot, pNode->getData());
	if (pY == nullptr) return nullptr;
	//如果y有左孩子，则x的前驱为“以x的左孩为根的子树的最大结点”
	if (pY->getLChild() != nullptr)
		return maximumNode(pY->getLChild());
	//如果y没有左孩子，则x有两种可能：
	//1.y是一个右孩子，此时x的前驱为其双亲节点
	BTreeNode<T>* pParent = pY->getParent();
	if (pParent->getRChild() == pY)
		return pParent;
	//2.y是一个左孩子，则其前驱为其双亲结点中“第一个拥有右孩子结点”的结点
	while (pParent != nullptr && pParent->getRChild() == nullptr)
	{
		pParent = pParent->getParent();
	}
	return pParent;
}

template <typename T>
BTreeNode<T>* BinaryTree<T>::sucessor(BTreeNode<T>* pNode)
{
	//如果x是键值最大的，则x没有后继结点
	if (pNode->getData() == maximumNode(m_pRoot)->getData())
		return nullptr;
	//获取x在二叉树中的结点y
	BTreeNode<T>* pY = nullptr;
	pY = search(m_pRoot, pNode->getData());
	if (pY == nullptr) return nullptr;
	//如果y有右孩子，则y的后继为其右孩子的最小结点
	if (pY->getRChild() != nullptr)
		return minimumNode(pY->getRChild());
	//如果y没有右孩子，则可分为两种情况：
	//1.y 是左孩子。此时y的后继为y的父结点
	BTreeNode<T>* pParent = pY->getParent();
	if (pY->getParent()->getLChild() == pY)
		return pParent;

	//2.y是右孩子。此时y的后继结点为“第一个拥有左孩且不是y的直接双亲”的结点
	while (pParent != nullptr)
	{
		if (pParent->getLChild() != nullptr && pParent != pY->getParent())
			return pParent;
		pParent = pParent->getParent();
	}
	return nullptr;
}

/*
*
*打印函数
*打印出平衡二叉树
*BStree内部函数
*/
template<typename T>
void BinaryTree<T>::print(BTreeNode<T>* &pTree)
{
	if (pTree) //如果tree不为空
	{
		if (pTree->getLChild()) //结点有左孩子
		{
			cout << "Node" << pTree->getData() << "L Child:" << pTree->getLChild()->getData() << endl;
		}
		else
			cout << "Node" << pTree->getData() << "do not has L Child" << endl;
		if (pTree->getRChild())
		{
			cout << "Node" << pTree->getData() << "R Child" << pTree->getRChild()->getData() << endl;
		}
		else
			cout << "Node" << pTree->getData() << "do not has R Child" << endl;
		print(pTree->getLChild());
		print(pTree->getRChild());
	}
}

/*
*
*销毁查找二叉树
*内部调用函数
*
*/
template<typename T>
void BinaryTree<T>::destory(BTreeNode<T>*& pTree)
{
	if (pTree->getLChild() != nullptr)
		destory(pTree->getLChild());
	if (pTree->getRChild() != nullptr)
		destory(pTree->getRChild());
	if (pTree->getLChild() == nullptr && pTree->getRChild() == nullptr)
	{
		delete(pTree);
		pTree = nullptr;
	}
}

template <typename T>
void BinaryTree<T>::insert(T key)
{
	BTreeNode<T> *pNode = new BTreeNode<T>(key);
	if(pNode != nullptr)
		insert(m_pRoot, pNode);
}

template <typename T>
BTreeNode<T> * BinaryTree<T>::search(T key)
{
	return search(m_pRoot, key);
}

template<typename T>
void BinaryTree<T>::preOrder()
{
	preOrder(m_pRoot);
}

template<typename T>
void BinaryTree<T>::inOrder()
{
	inOrder(m_pRoot);
}

template<typename T>
void BinaryTree<T>::postOrder()
{
	postOrder(m_pRoot);
}

template<typename T>
BTreeNode<T>* BinaryTree<T>::minimumNode()
{
	return minimumNode(m_pRoot);
}

template<typename T>
BTreeNode<T>* BinaryTree<T>::maximumNode()
{
	return maximumNode(m_pRoot);
}

template<typename T>
T BinaryTree<T>::minimumKey()
{
	BTreeNode<T> *pNode = minimumNode(m_pRoot);
	if (pNode != nullptr)
		return pNode->getData();
}

template<typename T>
T BinaryTree<T>::maximumKey()
{
	BTreeNode<T> *pNode = maximumNode(m_pRoot);
	if (pNode != nullptr)
		return pNode->getData();
}

template<typename T>
void BinaryTree<T>::print()
{
	print(m_pRoot);
}

template<typename T>
void BinaryTree<T>::remove(T key)
{
	BTreeNode<T> *pZ, *pNode;
	if ((pZ = search(m_pRoot, key)) != nullptr)
		if ((pNode = remove(m_pRoot, pZ)) != nullptr)
			delete pNode;
}


template<typename T>
void BinaryTree<T>::destory()
{
	destory(m_pRoot);
}
#endif // !_BINARYTREE_


