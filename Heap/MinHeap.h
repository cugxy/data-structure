// Author：xiongw	
// Date：2018-03-16
// filename:MinHeap.h

#ifndef _MINHEAP_H_
#define _MINHEAP_H_

#define DEFAULTSIZE 10
#include "PQueue.h"

/**
* \brief 最小堆
* \author	xy
*/
template<class E>
class MinHeap :public PQueue<E>
{
private:
	//E	   *m_pHeap;	/**< 数组存储方式 */
	//int		m_nCount;	/**< 元素个数 */
	//int		m_nMaxSize;	/**< 最大 */

private:

	/**
	* \brief 
	* \param[in] nStart
	* \param[in] m
	* \return void
	*/
	void siftDown(int nStart, int m);

	/**
	* \brief 
	* \param[in] nStart
	* \return void
	*/
	void siftUp(int nStart);

public:

	/**
	* \brief 构造函数
	* \param[in] size 最大容量
	*/
	MinHeap(int size = DEFAULTSIZE);

	/**
	* \brief 构造函数
	* \param[in] arr 数组，用于构造最小堆
	* \param[in] size 最大容量
	*/
	MinHeap(E arr[], int size);

	/**
	* \brief 析构函数
	*/
	~MinHeap();

	/**
	* \brief 插入元素
	* \param[in] x 插入元素
	* \return bool
	*/
	bool Insert(const E& x);

	/**
	* \brief 删除最小元素
	* \param[out] x 删除的元素
	* \return bool
	*/
	bool RemoveMin(E& x);

	/**
	* \brief 是否为空
	* \return bool
	*/
	bool IsEmpty() const;

	/**
	* \brief 是否为空
	* \return bool
	*/
	bool IsFull() const;

	/**
	* \brief 置空
	* \return void
	*/
	void MakeEmpty();
};

template<class E>
void MinHeap<E>::siftDown(int nStart, int m)
{
	return;
}

template<class E>
void MinHeap<E>::siftUp(int nStart)
{
	return;
}

template<class E>
MinHeap<E>::MinHeap(int size)
	: m_pHeap(nullptr)
	, m_nCount(0)
	, m_nMaxSize(0)
{
	m_nMaxSize = (DEFAULTSIZE < size) ? size : DEFAULTSIZE;
	m_pHeap = new E[m_nMaxSize];
	if (m_pHeap == nullptr)
	{
		cerr << "faild";
		exit(1);
	}
	m_nCount = 0;
}

template<class E>
MinHeap<E>::MinHeap(E arr[], int size)
{
	m_nMaxSize = (DEFAULTSIZE < size) ? size : DEFAULTSIZE;
	m_pHeap = new E[m_nMaxSize];
	if (m_pHeap == nullptr)
	{
		cerr << "faild";
		exit(1);
	}
	for (int i = 0; i < size; ++i)
		m_pHeap[i] = arr[i];
	m_nCount = size;

	int nTmpPos = (m_nCount - 2) / 2;
	while (nTmpPos > 0)
	{
		siftDown(nTmpPos, m_nCount - 1);
		--nTmpPos;
	}
}


template<class E>
MinHeap<E>::~MinHeap()
{
	if (m_pHeap != nullptr)
	{
		delete m_pHeap;
		m_pHeap = nullptr;
	}
}


template<class E>
bool MinHeap<E>::Insert(const E& x)
{
	return false;
}

template<class E>
bool MinHeap<E>::RemoveMin(E& x)
{

	return false;
}

template<class E>
bool MinHeap<E>::IsEmpty() const
{
	return (m_nCount == 0) ? true : false;
}

template<class E>
bool MinHeap<E>::IsFull()const
{
	return (m_nCount == m_nMaxSize) ? true : false;
}

template<class E>
void MinHeap<E>::MakeEmpty()
{
	m_nCount = 0;
}


#endif // !_MINHEAP_H_

