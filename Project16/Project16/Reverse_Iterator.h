#pragma once

template <typename T>
class Node {
private:
	Node():
		pNext(NULL),
		pPrev(NULL)
	{
		
	}
	~Node(){
	
	}

	template<typename T>
	friend class LinkedList;

	template<typename T>
	friend class Reverse_Iterator;//Node Ŭ������ �����ڰ� private�̱� ������ �ٸ� Ŭ�������� Node�� �����Ϸ��� friend�� �ξ����

public:
	T Data;
	Node<T>* pNext;
	Node<T>* pPrev;

};

template<typename T>
class LinkedList {

public:
	LinkedList() {
		m_pBegin = new NODE;
		m_pEnd = new NODE;
		
		m_pBegin->pNext = m_pEnd;
		m_pEnd->pPrev = m_pBegin;
		Size = 0;


	}
	~LinkedList() {

	}

public:
	typedef Node<T> NODE;
	typedef Node<T>* PNODE;
	int Size;
	PNODE m_pBegin;
	PNODE m_pEnd;

public:
	typedef Reverse_Iterator<T> iterator;

public:
	iterator _Begin() {
		iterator iter;
		iter.m_pNode = m_pBegin;

		return iter;
	}
	
	iterator _End() {
		iterator iter;
		iter.m_pNode = m_pEnd->pPrev;

		return iter;
	}
	

	
public:
	void push_front(const T& data) {
		PNODE pNode = new NODE;
		pNode->Data = data;

		PNODE FIRST = m_pBegin->pNext;

		FIRST->pPrev = pNode;
		pNode->pNext = FIRST;

		m_pBegin->pNext = pNode;
		pNode->pPrev = m_pBegin;

		++Size;
	}

};

template<typename T>
class Reverse_Iterator {
public:
	Reverse_Iterator() {
		
	}
	~Reverse_Iterator() {

	}

public:
	typedef Node<T> NODE;
	typedef Node<T>* PNODE;

	PNODE m_pNode = new NODE; //�� ��带 �湮�ϱ� ���� ���� ���

	template<typename T>
	friend class LinkedList;


public:
	bool operator !=(const Reverse_Iterator<T>& iter) {

		return m_pNode != iter.m_pNode;
	}

	void operator -- () {

		m_pNode = m_pNode->pPrev;

	}

	T operator * () {
		return m_pNode->Data;
	}
	
};

