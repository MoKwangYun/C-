#pragma once

template <typename T>
class CListNode {

	/*생성자와 소멸자를 private하게 되면 외부에서 객체를 생성, 해제할 수 없다.
	생성자는 객체를 생성할 때 자동으로 호출 되는 함수인데 private으로 되면 객체 생성하면서 호출시 접근이 불가능하다.(외부에서 객체 생성 불가)
	*/	
private:
	CListNode() :
		m_pNext(NULL),
		m_pPrev(NULL)
	{
	
	}
	~CListNode() {

	}

private:
	template<typename T>
	friend class CLinkedList;
	//friend : 친구로 만들어준다  --> friend로 지정해준 클래스에서 private이나 protected에 접근이 가능하다.
	//일반 클래스는 friend만 적으면 되지만 template 클래스의 경우 위처럼 template으로 지정해 주어야 한다.
	//CListNode 객체를 friend인 CLinkdeList 에서만 생성 가능

	template<typename T>
	friend class CListIterator;



private:
	T m_Data;
	CListNode<T>* m_pNext; //T타입의 CListNode 포인터 타입의 m_pNext 
	CListNode<T>* m_pPrev;

	
};

//반복자 클래스 : 리스트의 노드를 반복해서 순회할 수 있는 기능을 제공하는 클래스
template<typename T>
class CListIterator {
private:
	CListIterator() {

	}
	~CListIterator() {

	}
private:
	typedef CListNode<T> NODE; //CListNode<T>를 Node로 정의 (이너클래스)
	typedef CListNode<T>* PNODE;


	PNODE m_pNode; //현재 기준이 되는 노드
};

template <typename T>
class CLinkedList
{
public:
	CLinkedList() {
		m_pBegin = new NODE;
		m_pEnd = new NODE;

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;

		m_iSize = 0;
	}
	
	~CLinkedList() {
		clear();
		delete m_pBegin;
		delete m_pEnd;
		m_iSize = 0;
	}

private:
	typedef CListNode<T> NODE; //CListNode<T>를 Node로 정의 (이너클래스)
	typedef CListNode<T>* PNODE;

public:
	typedef CListIterator<T> iterator;

private:
	PNODE m_pBegin;
	PNODE m_pEnd;
	unsigned int m_iSize;

public:
	iterator _Begin() {
		iterator iter;
		iter.m_pNode = m_pBegin->m_pNext;

		return iter;
	}

	iterator _End() {
		iterator iter;
		iter.m_pNode = m_pEnd;

		return iter;
	}
public:
	/*
	레퍼런스는 참조하는 대상의 값을 변경할 수 있다. 그런데 const를 붙여주면 참조하는 대상의 값을 변경할 수 없다.
	값은 변경할 수 없지만 참조가 그 변수 자체를 가져오는 것보다 메모리가 적기 때문에 더욱 신속하다.
	*/
	void push_back(const T& data) {

		PNODE pNode = new NODE;

		pNode->m_Data = data;

		PNODE PREV = m_pEnd->m_pPrev;
		PREV->m_pNext = pNode;
		pNode->m_pPrev = PREV;

		m_pEnd->m_pPrev = pNode;
		pNode->m_pNext = m_pEnd;

		++m_iSize;
	}
public:
	void push_front(const T& data) {
		PNODE pNode = new NODE;

		pNode->m_Data = data;

		PNODE NEXT = m_pBegin->m_pNext;

		NEXT->m_pPrev = pNode;
		pNode->m_pNext = NEXT;

		m_pBegin->m_pNext = pNode;
		pNode->m_pPrev = m_pBegin;

		++m_iSize;
	}

public:
	//멤버함수 뒤에 const를 붙여주면 이 함수 내에서 멤버변수의 값을 변경할 수 없다.
	unsigned int size() const{
		return m_iSize;
	}

	bool empty() const{ //비었는지 확인(m_iSize == 0이면 true 리턴)
		return m_iSize == 0;
	}

	void clear() {
		PNODE pNode = m_pBegin->m_pNext;

		

		while (pNode != m_pEnd) {
			PNODE pNext = pNode->m_pNext;

			delete pNode;

			pNode = pNext;
		}

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
		m_iSize = 0;
	}

	
	
};

