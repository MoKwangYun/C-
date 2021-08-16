#pragma once

template <typename T>
class CListNode {

	/*�����ڿ� �Ҹ��ڸ� private�ϰ� �Ǹ� �ܺο��� ��ü�� ����, ������ �� ����.
	�����ڴ� ��ü�� ������ �� �ڵ����� ȣ�� �Ǵ� �Լ��ε� private���� �Ǹ� ��ü �����ϸ鼭 ȣ��� ������ �Ұ����ϴ�.(�ܺο��� ��ü ���� �Ұ�)
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
	//friend : ģ���� ������ش�  --> friend�� �������� Ŭ�������� private�̳� protected�� ������ �����ϴ�.
	//�Ϲ� Ŭ������ friend�� ������ ������ template Ŭ������ ��� ��ó�� template���� ������ �־�� �Ѵ�.
	//CListNode ��ü�� friend�� CLinkdeList ������ ���� ����

	template<typename T>
	friend class CListIterator;



private:
	T m_Data;
	CListNode<T>* m_pNext; //TŸ���� CListNode ������ Ÿ���� m_pNext 
	CListNode<T>* m_pPrev;

	
};

//�ݺ��� Ŭ���� : ����Ʈ�� ��带 �ݺ��ؼ� ��ȸ�� �� �ִ� ����� �����ϴ� Ŭ����
template<typename T>
class CListIterator {
private:
	CListIterator() {

	}
	~CListIterator() {

	}
private:
	typedef CListNode<T> NODE; //CListNode<T>�� Node�� ���� (�̳�Ŭ����)
	typedef CListNode<T>* PNODE;


	PNODE m_pNode; //���� ������ �Ǵ� ���
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
	typedef CListNode<T> NODE; //CListNode<T>�� Node�� ���� (�̳�Ŭ����)
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
	���۷����� �����ϴ� ����� ���� ������ �� �ִ�. �׷��� const�� �ٿ��ָ� �����ϴ� ����� ���� ������ �� ����.
	���� ������ �� ������ ������ �� ���� ��ü�� �������� �ͺ��� �޸𸮰� ���� ������ ���� �ż��ϴ�.
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
	//����Լ� �ڿ� const�� �ٿ��ָ� �� �Լ� ������ ��������� ���� ������ �� ����.
	unsigned int size() const{
		return m_iSize;
	}

	bool empty() const{ //������� Ȯ��(m_iSize == 0�̸� true ����)
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

