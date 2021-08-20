#pragma once

//스택 구현 방법 : 배열 or 리스트 이용(여기서는 리스트 이용)

template<typename T>
class CStackNode {
private:
	CStackNode() :
		m_pNext(NULL)
	{
		
	}
	~CStackNode() {

	}

private:
	template<typename T>
	friend class CStack;

private:
	T m_Data;
	CStackNode<T>* m_pNext;
	
};
template<typename T>
class CStack
{

public:
	CStack() {
		m_pBegin = new NODE;
		m_pEnd = new NODE;
		m_iSize = 0;

		m_pBegin->m_pNext = m_pEnd;
	

	}
	~CStack() {
		PNODE pNode = m_pBegin;

		while (pNode) {
			PNODE NEXT = pNode->m_pNext;
			delete pNode;
			pNode = NEXT;
		}
	}

private:
	typedef CStackNode<T> NODE;
	typedef CStackNode<T>* PNODE;

private:
	PNODE m_pBegin;
	PNODE m_pEnd;
	unsigned int m_iSize;

public:
	void push(const T& data) {//push_front를 사용하는 stack 
// stack은 단방향으로만 노드 접근이 가능하기 때문에 m_pNext or m_pPrev 중 하나만 존재하는 싱글링크드리스트로도 구현가능
// push_front로 노드를 저장하고 begin의 next 노드부터 접근한다면 나중에 저장된 노드부터 나오게 되는 것!!(FILO)
		PNODE pNode = new NODE;

		pNode->m_Data = data;

		PNODE NEXT = m_pBegin->m_pNext;

		pNode->m_pNext = NEXT;
		m_pBegin->m_pNext = pNode;

		++m_iSize;
	}

	T pop() {//가장 마지막에 추가한 노드 하나를 리턴하는 함수
		if (empty())
			return 0; //추가된 노드가 없으면 0 리턴

		PNODE pNode = m_pBegin->m_pNext;//가져올 노드(데이터 추출 후 지워줌 --> begin과 pNode의 다음 노드를 연결해준다) 
		PNODE NEXT = pNode->m_pNext;//가져올 노드의 다음 노드

		T data = pNode->m_Data;

		delete pNode;

		m_pBegin->m_pNext = NEXT;

		--m_iSize;
		return data;
	}

	bool empty() {
		return m_iSize == 0;
	}

	T top() { //pop 처럼 추출후 노드를 지우는 것이 아니라 그냥 가장 마지막에 추가된 노드(top)의 데이터만 리턴
		if (empty())
			return 0;

		return m_pBegin->m_pNext->m_Data; 
	}

	int size() {

		return m_iSize;
	}
};

