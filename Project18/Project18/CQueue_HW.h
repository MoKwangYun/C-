#pragma once

template<typename T>
class QNode {
private:
	QNode()
		//m_pPrev(NULL)
	{

	}
	~QNode() {

	}

private:
	template<typename T>
	friend class CQueue_HW;

	QNode<T>* m_pPrev;
	QNode<T>* m_pNext;
	T m_Data;
};

template<typename T>
class CQueue_HW
{
public:
	CQueue_HW() {
		m_pBegin = new NODE;
		m_pEnd = new NODE;
		m_iSize = 0;

		m_pEnd->m_pPrev = m_pBegin;
		m_pBegin->m_pNext = m_pEnd;
	}
	~CQueue_HW() {

	}

private:
	typedef QNode<T> NODE;
	typedef QNode<T>* PNODE;

	int m_iSize;
	PNODE m_pBegin;
	PNODE m_pEnd;

public:

	void push(const T& data) {
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		PNODE PREV = m_pEnd->m_pPrev;

		m_pEnd->m_pPrev = pNode;
		pNode->m_pPrev = PREV;

		pNode->m_pNext = m_pEnd;
		PREV->m_pNext = pNode;
		++m_iSize;
	}

	T pop() {
		if (empty())
			return 0;

		PNODE pNode = m_pBegin->m_pNext;
		T data = pNode->m_Data;

		PNODE NEXT = pNode->m_pNext;

		delete pNode;

		m_pBegin->m_pNext = NEXT;

		--m_iSize;

		return data;
	}

	bool empty() {

		return m_iSize == 0;
	}

	int size() {

		return m_iSize;
	}

};

