#pragma once

template<typename T>
class CQueueNode {
private:
	CQueueNode() {

	}
	~CQueueNode() {

	}

private:
	template<typename T>
	friend class CQueue;

private:
	T m_Data;
	CQueueNode<T>* m_pNext;
};

template<typename T>
class CQueue
{
public:
	CQueue() {

	}
	~CQueue() {

	}

private:
	typedef CQueueNode<T> NODE;
	typedef CQueueNode<T>* PNODE;

private:
	PNODE m_pBegin;
	PNODE m_pEnd;
	unsigned int m_iSize;
};

template<typename T, int SIZE = 100> //아래 클래스에서 사용할 상수 설정 --> 배열 크기를 넣기 위해!!(변수로는 배열 개수 지정 불가 but, 상수는 가능)
class CCircleQueue {
public:
	CCircleQueue() {
		m_iSize = 0;
		m_iHead = 0;
		m_iTail = 0;

	}
	~CCircleQueue() {

	}
private:
	T	m_Data[SIZE + 1];//SIZE + 1 크기 배열 생성
	int				m_iSize;
	unsigned int	m_iHead;//가장 오래 전에 추가한 원소 인덱스 표시 변수
	unsigned int	m_iTail;//가장 최근에 추가한 원소 인덱스 표시 변수

public:
	void push(const T& data) {

		if (full())
			return;

		int idx = (m_iTail + 1) % (SIZE + 1);

		m_Data[idx] = data;

		m_iTail = idx;

		++m_iSize;
	}

	T pop() {
		if (empty())
			return 0;

		int idx = (m_iHead + 1) % (SIZE + 1);

		T data = m_Data[idx];

		m_iHead = idx;
		--m_iSize;

		return data;
	}

	bool empty() {

		return m_iSize == 0;
	}
	bool full() {

		return m_iSize == SIZE;
	}

};
