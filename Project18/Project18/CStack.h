#pragma once

//���� ���� ��� : �迭 or ����Ʈ �̿�(���⼭�� ����Ʈ �̿�)

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
	void push(const T& data) {//push_front�� ����ϴ� stack 
// stack�� �ܹ������θ� ��� ������ �����ϱ� ������ m_pNext or m_pPrev �� �ϳ��� �����ϴ� �̱۸�ũ�帮��Ʈ�ε� ��������
// push_front�� ��带 �����ϰ� begin�� next ������ �����Ѵٸ� ���߿� ����� ������ ������ �Ǵ� ��!!(FILO)
		PNODE pNode = new NODE;

		pNode->m_Data = data;

		PNODE NEXT = m_pBegin->m_pNext;

		pNode->m_pNext = NEXT;
		m_pBegin->m_pNext = pNode;

		++m_iSize;
	}

	T pop() {//���� �������� �߰��� ��� �ϳ��� �����ϴ� �Լ�
		if (empty())
			return 0; //�߰��� ��尡 ������ 0 ����

		PNODE pNode = m_pBegin->m_pNext;//������ ���(������ ���� �� ������ --> begin�� pNode�� ���� ��带 �������ش�) 
		PNODE NEXT = pNode->m_pNext;//������ ����� ���� ���

		T data = pNode->m_Data;

		delete pNode;

		m_pBegin->m_pNext = NEXT;

		--m_iSize;
		return data;
	}

	bool empty() {
		return m_iSize == 0;
	}

	T top() { //pop ó�� ������ ��带 ����� ���� �ƴ϶� �׳� ���� �������� �߰��� ���(top)�� �����͸� ����
		if (empty())
			return 0;

		return m_pBegin->m_pNext->m_Data; 
	}

	int size() {

		return m_iSize;
	}
};

