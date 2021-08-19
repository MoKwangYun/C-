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

	template<typename T>
	friend class CListReverseIterator;



private:
	T m_Data;
	CListNode<T>* m_pNext; //T타입의 CListNode 포인터 타입의 m_pNext 
	CListNode<T>* m_pPrev;

	
};

//반복자 클래스 : 리스트의 노드를 반복해서 순회할 수 있는 기능을 제공하는 클래스
template<typename T>
class CListIterator {
public:
	CListIterator() {

	}
	~CListIterator() {

	}
private:
	typedef CListNode<T> NODE; //CListNode<T>를 Node로 정의 (이너클래스)
	typedef CListNode<T>* PNODE;


	PNODE m_pNode; //현재 기준이 되는 노드

	template<typename T>
	friend class CLinkedList;

public:
	bool operator == (const CListIterator<T>& iter) {
		
		return m_pNode == iter.m_pNode;
	}

	bool operator != (const CListIterator<T>& iter) {

		return m_pNode != iter.m_pNode;
	}

	void operator ++ () {
		m_pNode = m_pNode->m_pNext;
	}

	void operator -- () {
		m_pNode = m_pNode->m_pPrev;
	}

	T operator *() {//반환타입 = T

		return m_pNode->m_Data;
	}
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
	//이너클래스 : CLinkedList 안에 소속되어 있는 것! --> iterator 객체 생성시 
	//CLinkedList :: iterator 객체 이름;  이처럼 ::을 붙여주어 어떤 클래스에 속해있는지 알게해줌

	typedef CListReverseIterator<T> reverse_iterator;

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

	reverse_iterator rbegin() {

		reverse_iterator iter;
		iter.m_pNode = m_pEnd->m_pPrev;

		return iter;
	}
	reverse_iterator rend() {

		reverse_iterator iter;
		iter.m_pNode = m_pBegin;

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

template<typename T>
class CListReverseIterator {
public:
	CListReverseIterator() {

	}
	~CListReverseIterator() {

	}

private:
	template<typename T>
	friend class CLinkedList;

private:
	typedef CListNode<T> NODE;
	typedef CListNode<T>* PNODE;

private:
	PNODE m_pNode;

public:
	bool operator ==(const CListReverseIterator<T>& iter) {
		/*const를 사용하는 이유: 참조한 데이터를 변경하지 않으려고 
		레퍼런스 사용 이유 : 레퍼런스 변수의 메모리가 훨씬 작아 속도 빠름(레퍼런스 참조 = 4byte) 
		, 값에 의한 참조일 경우 인자로 받아오는 변수, 클래스 등의 메모리 크기만큼 스택에 지역변수로 저장해야 한다!! 

		-->포인터도 메모리 절약 O, 포인터로 인자로 받아와도 무방(참조의 경우 역참조, 주소연산자(&) 등 필요 없기 때문에 레퍼런스가 훨신 간단한 듯)
				*/
		return m_pNode == iter.m_pNode;
	}

	bool operator !=(const CListReverseIterator<T>& iter) {

		return m_pNode != iter.m_pNode;
	}

	void operator ++() { //역반복이기 때문에 이전노드로 이동하도록

		m_pNode = m_pNode->m_pPrev;
	}

	void operator --() {

		m_pNode = m_pNode->m_pNext;
	}

	T operator *() {//연산에 객체가 하나만 필요하기 때문에  인자를 비운다 , 만약 * 를 곱하기로 사용한다면 객체가 두개가 필요하다 --> *(...) 인자 필요

		return m_pNode->m_Data;
	}

};