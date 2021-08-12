#include<iostream>

using namespace std;

//Ŭ������ Linked List ����

class CListNode {
public:
	CListNode() :
		m_pNext(NULL),
		m_pPrev(NULL)
	{

	}
	~CListNode() {
		
	}

	int m_iData;
	CListNode* m_pNext;
	CListNode* m_pPrev;
};

class CList {
public:
	CList(){
		m_pBegin = new CListNode;
		m_pEnd = new CListNode;

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;

		m_iSize = 0;
	}
	~CList() {
		clear(); //�����Ҵ� ����
		delete m_pBegin; 
		delete m_pEnd;
	}

private:
	CListNode* m_pBegin;
	CListNode* m_pEnd;
	int m_iSize;

public:
	void push_back(int iData) {//End��� �ٷ� �տ� ��� �߰��ϴ� �Լ�
		CListNode* pNode = new CListNode;

		pNode->m_iData = iData;

		CListNode* PREV = m_pEnd->m_pPrev;

		PREV->m_pNext = pNode;
		pNode->m_pPrev = PREV;

		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		++m_iSize;
	}

	bool empty() { //m_iSize == 0�̸� true , m_iSize != 0 �̸� false ����
		return m_iSize == 0;
	}

	void clear() {
		CListNode* pNode = m_pBegin->m_pNext;

		while (pNode != m_pEnd) {
			CListNode* NEXT = pNode->m_pNext;

			delete pNode;

			pNode = NEXT;
		}

		//Begin�� End ���� ��� ���� ���� �� Begin�� End �ۿ� �� ���ұ� ������ �� ����
		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
		m_iSize = 0;  
	}

	int pop_back() {//�Ǹ����� ���� ����� ���� ����
		CListNode* PREV = m_pEnd->m_pPrev;

		if (PREV == m_pBegin) { //End�� Begin��� ���� ��尡 ���� ���
			return INT_MAX;
		}

		int iData = PREV->m_iData;

		PREV->m_pPrev->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = PREV->m_pPrev; //PREV��� ���� ���� ��� ���ܤä�

		--m_iSize;

		delete PREV;

		return iData;
	}
};

int main() {

	CList list;

	for (int i = 0; i < 100; i++) {
		list.push_back(i);
	}

	while (!list.empty()) {//list�� ��������� true���� -> !�� ���� false �� �� --> whlie�� Ż��
		
		cout << list.pop_back() << endl;
	}

	return 0;
}