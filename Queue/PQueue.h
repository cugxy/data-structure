// Author：xiongw	
// Date：2018-03-16
// filename:MinHeap.h

#ifndef _PQUEUE_H_
#define _PQUEUE_H_

#include <iostream>
#include <stdlib.h>

const int knDefaultPQSize = 50;

/**
* \brief 优先队列 小的优先
* \author	xy
*/
template<class E>
class PQueue
{
protected:
	E * m_pElemets; /**< 数组存储方式 */
	int m_nCount;	/**< 元素个数 */
	int m_nMaxSize;	/**< 最大 */

protected:
	/**
	* \brief 调整 将新加的元素调整到合适的位置，之前的所有元素已经排序好，所以最坏时间复杂度为 O(n)所有的都要向后移动一次
	* return
	*/
	void adjust()
	{
		E tmp = m_pElemets[m_nCount - 1]; // 最后一个元素
		int j = 0;
		for (j = m_nCount - 2; j >= 0; --j)
		{
			if (m_pElemets[j] < tmp) break;
			else m_pElemets[j + 1] = m_pElemets[j];
		}
		m_pElemets[j + 1] = tmp;
	}

public:
	/**
	* \brief 构造函数
	* \param[in] size 队列最大长度
	*/
	PQueue(int size = knDefaultPQSize)
		: m_pElemets(nullptr)
		, m_nCount(0)
		, m_nMaxSize(-1)
	{
		m_nMaxSize = size;
		m_pElemets = new T[m_nMaxSize];
	}

	/**
	* \brief 析构函数
	*/
	virtual ~PQueue()
	{
		if (m_pElemets != nullptr)
		{
			delete m_pElemets;
			m_pElemets = nullptr;
		}
	}

	/**
	* \brief 插入
	* \param[in] x 插入元素
	* \return bool
	*/
	bool Insert(const E& x)
	{
		if (m_nCount == m_nMaxSize) return false;
		m_pElemets[m_nCount++] = x;
		adjust();
		return true;
	}

	/**
	* \brief 移除 第一个元素
	* \param[out] x 移除元素
	* \return bool
	*/
	bool RemoveMin(E& x)
	{
		if (m_nCount == 0) return false;
		x = m_pElemets[0];
		for (int i = 1; i < m_nCount; ++i)
		{
			m_pElemets[i - 1] = m_pElemets[i];
		}
		--m_nCount;
		return true;
	}
	
	/**
	* \brief 获取第一个
	* \param[out] x 获取元素
	* \return bool
	*/
	bool GetFront(E& x)const
	{
		if (m_nCount == 0) return false;
		x = m_pElemets[0];
		return true;
	}

	/**
	* \brief 置空
	* \return 
	*/
	void MakeEmpty() { m_nCount = 0; }

	/**
	* \brief 是否为空
	* \return bool
	*/
	bool IsEmpty() const
	{
		return (0 == m_nCount) ? true : false;
	}

	/**
	* \brief 是否填满
	* \return bool
	*/
	bool IsFull() const
	{
		return (m_nCount == m_nMaxSize) ? true : false;
	}

	/**
	* \brief 获取大小
	* \return int
	*/
	int GetSize() const { return m_nCount; }
};

#endif // !_PQUEUE_H_

