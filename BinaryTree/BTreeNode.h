// Author：xiongy
// Date：2018/02/08
// filename:BTreeNode.h
#ifndef _BTREENODE_
#define _BTREENODE_

#include "ExportBinaryTree.h"

template<class T> class BinaryTree;

template<class T> 
class BINARYTREE_LIBRARY_EXPORT BTreeNode
{
	friend class BinaryTree<T>;
public:
	BTreeNode() : m_pParent(0), m_pLChild(0), m_pRChild(0) {}
	BTreeNode(T elem, BTreeNode<T>* parent = 0, BTreeNode* lchild = 0, BTreeNode* rchild = 0) :
		m_pParent(parent), m_pLChild(lchild), m_pRChild(rchild), m_data(elem) {}

	T getData() const; //获取节点数据;  
	BTreeNode<T>*& getParent() ;//获取节点的父节点  
	BTreeNode<T>*& getLChild() ;//获取节点的左孩子节点  
	BTreeNode<T>*& getRChild() ;//获取节点的右孩子节点  
	void setData(const T& elem);//修改节点的数据;  
private:
	BTreeNode<T>* m_pParent;
	BTreeNode<T>* m_pLChild;
	BTreeNode<T>* m_pRChild;
	T m_data;
};

template<class T>
inline T BTreeNode<T>::getData()const
{
	return m_data;
}

template<class T>
inline BTreeNode<T>*& BTreeNode<T>::getParent()
{
	return m_pParent;
}

template<class T>
inline BTreeNode<T>*& BTreeNode<T>::getLChild()
{
	return m_pLChild;
}

template<class T> 
inline BTreeNode<T>*& BTreeNode<T>::getRChild()
{
	return m_pRChild;
}

template<class T> 
inline void BTreeNode<T>::setData(const T& elem)
{
	m_data = elem;
}
#endif // !_BTREENODE_
