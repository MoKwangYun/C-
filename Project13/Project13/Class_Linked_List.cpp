#include<iostream>

using namespace std;

//클래스로 Linked List 구현

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
		clear(); //동적할당 해제
		delete m_pBegin; 
		delete m_pEnd;
	}

private:
	CListNode* m_pBegin;
	CListNode* m_pEnd;
	int m_iSize;

public:
	void push_back(int iData) {//End노드 바로 앞에 노드 추가하는 함수
		CListNode* pNode = new CListNode;

		pNode->m_iData = iData;

		CListNode* PREV = m_pEnd->m_pPrev;

		PREV->m_pNext = pNode;
		pNode->m_pPrev = PREV;

		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		++m_iSize;
	}

	bool empty() { //m_iSize == 0이면 true , m_iSize != 0 이면 false 리턴
		return m_iSize == 0;
	}

	void clear() {
		CListNode* pNode = m_pBegin->m_pNext;

		while (pNode != m_pEnd) {
			CListNode* NEXT = pNode->m_pNext;

			delete pNode;

			pNode = NEXT;
		}

		//Begin과 End 사이 노드 전부 삭제 후 Begin과 End 밖에 안 남았기 때문에 둘 연결
		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
		m_iSize = 0;  
	}

	int pop_back() {//맨마지막 같을 지우고 값을 리턴
		CListNode* PREV = m_pEnd->m_pPrev;

		if (PREV == m_pBegin) { //End와 Begin노드 사이 노드가 없을 경우
			return INT_MAX;
		}

		int iData = PREV->m_iData;

		PREV->m_pPrev->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = PREV->m_pPrev; //PREV노드 이전 다음 노드 연겨ㅓㄹ

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

	while (!list.empty()) {//list가 비어있으면 true리턴 -> !와 만나 false 가 됨 --> whlie문 탈출
		
		cout << list.pop_back() << endl;
	}

	return 0;
}