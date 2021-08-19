#pragma once

template<typename T>
class CVectorNode {
private:
	CVectorNode() {

	}
	~CVectorNode() {

	}
private:
	template<typename T>
	friend class CVector;

private:
	T m_Data;
	int m_index;


};

template<typename T>
class CVector
{
public:
	CVector() {
		m_iSize = 0;
		m_iCapasity = 2;//초기 배열 크기를 2로 지정

		m_pArray = new NODE[m_iCapasity + 2];//동적배열 할당 , + 2는 end와 begin 노드
	}
	cVector(int iSize) {//입력 받은 iSize만큼 배열 공간 생성하고 시작하는 생성자
		m_pArray = new NODE[iSize + 2];
		m_iCapasity = iSize;
		m_iSize = 0;
	}
	~CVector() {
		delete[]  m_pArray; //동적배열 할당  해제
	}

private:
	typedef CVectorNode<T> NODE;
	typedef CVectorNode<T>* PNODE;

private:
	PNODE m_pArray;
	unsigned int m_iSize; //전체 노드 개수
	unsigned int m_iCapasity; //전체 배열 개수

public:
	void push_back(const T& data) {

		if (full())//전체 배열 공간(capasity)만큼 이미 노드가 추가된 경우(size)
			resize(m_iSize * 2); //size의 두배만큼 배열 공간을 늘려준다

		m_pArray[m_iSize + 1].m_Data = data;//0번 인덱스는 begin 노드이고 iSize에는 begin과 end노드는 포함되지 않는다.
		m_pArray[m_iSize + 1].m_index = m_iSize;
		++m_iSize;
	}

	void resize(int iSize) {
		PNODE pArray = new NODE[iSize + 2];//+ 2 는 begin, end 노드 공간 , m_iSize * 2만큼의 배열을 동적할당한다.

		memcpy(pArray + 1, m_pArray + 1, sizeof(NODE) * m_iSize); //동적할당한 배열에 원래 배열 m_pArray의 데이터를 복사한다.
		//메모리 주소에 +1을해준 이유는 1번 인덱스부터 시작이기 때문에 여기부터 복사를 해주기 위함(0번인덱스는 begin 노드)
		/*
		memcpy 함수
<문법> - memcpy (void* dest, const void* source, size_t num)

첫번째 인자 void* dest
= 복사 받을 메모리를 가리키는 포인터

두번째 인자 const void* source
= 복사할 메모리를 가리키고 있는 포인터

세번째 인자 size_t num
= 복사할 데이터(값)의 길이(바이트 단위)

위의 경우 복사할 데이터는 확장하기 이전의 노드 개수 * NODE 크기
*/
		//기존 노드 삭제
		delete[] m_pArray;

		m_pArray = pArray;

		m_iCapasity = iSize;//전체 공간 나타내는 변수 capasity 확장
	}

	bool full() {
		return m_iSize == m_iCapasity;
	}

	bool empty() {
		return m_iSize == 0;
	}

	unsigned int size() const {

		return m_iSize;
	}

	unsigned int capasity() const {

		return m_iCapasity;
	}

	T operator [] (int idx) {
//배열에서 인덱스를 통한 접근 ex.Array[10]에서 [] 또한 operator를 이용하여 재정의가 가능한 연산자이다!! 이경우 인자는 []안에 들어올 인덱스 번호이다
		
		return m_pArray[idx + 1].m_Data; //0인덱스는 begin이기 때문에 실질적 배열 시작은 [1]부터
	}

	void clear() {
		delete[] m_pArray;
		m_iSize = 0;
		m_iCapasity = 2;
		m_pArray = newNODE[m_iCapasity = 2];
	}

	void reserve(int iSize) {//배열공간을 입력받은 iSize만큼 만들어두는 함수

		delete[] m_pArray;
		m_pArray = new NODE{ iSize + 2 };

		m_iCapasity = iSize;
		m_iSize = 0;

		
	}
};

//iterator 구현해보기!! --> 0번 인덱스를 begin노드로, 데이터가 들어있는 마지막 노드의 다음 노드를 end 노드로 설정해야함
