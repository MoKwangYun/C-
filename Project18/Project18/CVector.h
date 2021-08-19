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
		m_iCapasity = 2;//�ʱ� �迭 ũ�⸦ 2�� ����

		m_pArray = new NODE[m_iCapasity + 2];//�����迭 �Ҵ� , + 2�� end�� begin ���
	}
	cVector(int iSize) {//�Է� ���� iSize��ŭ �迭 ���� �����ϰ� �����ϴ� ������
		m_pArray = new NODE[iSize + 2];
		m_iCapasity = iSize;
		m_iSize = 0;
	}
	~CVector() {
		delete[]  m_pArray; //�����迭 �Ҵ�  ����
	}

private:
	typedef CVectorNode<T> NODE;
	typedef CVectorNode<T>* PNODE;

private:
	PNODE m_pArray;
	unsigned int m_iSize; //��ü ��� ����
	unsigned int m_iCapasity; //��ü �迭 ����

public:
	void push_back(const T& data) {

		if (full())//��ü �迭 ����(capasity)��ŭ �̹� ��尡 �߰��� ���(size)
			resize(m_iSize * 2); //size�� �ι踸ŭ �迭 ������ �÷��ش�

		m_pArray[m_iSize + 1].m_Data = data;//0�� �ε����� begin ����̰� iSize���� begin�� end���� ���Ե��� �ʴ´�.
		m_pArray[m_iSize + 1].m_index = m_iSize;
		++m_iSize;
	}

	void resize(int iSize) {
		PNODE pArray = new NODE[iSize + 2];//+ 2 �� begin, end ��� ���� , m_iSize * 2��ŭ�� �迭�� �����Ҵ��Ѵ�.

		memcpy(pArray + 1, m_pArray + 1, sizeof(NODE) * m_iSize); //�����Ҵ��� �迭�� ���� �迭 m_pArray�� �����͸� �����Ѵ�.
		//�޸� �ּҿ� +1������ ������ 1�� �ε������� �����̱� ������ ������� ���縦 ���ֱ� ����(0���ε����� begin ���)
		/*
		memcpy �Լ�
<����> - memcpy (void* dest, const void* source, size_t num)

ù��° ���� void* dest
= ���� ���� �޸𸮸� ����Ű�� ������

�ι�° ���� const void* source
= ������ �޸𸮸� ����Ű�� �ִ� ������

����° ���� size_t num
= ������ ������(��)�� ����(����Ʈ ����)

���� ��� ������ �����ʹ� Ȯ���ϱ� ������ ��� ���� * NODE ũ��
*/
		//���� ��� ����
		delete[] m_pArray;

		m_pArray = pArray;

		m_iCapasity = iSize;//��ü ���� ��Ÿ���� ���� capasity Ȯ��
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
//�迭���� �ε����� ���� ���� ex.Array[10]���� [] ���� operator�� �̿��Ͽ� �����ǰ� ������ �������̴�!! �̰�� ���ڴ� []�ȿ� ���� �ε��� ��ȣ�̴�
		
		return m_pArray[idx + 1].m_Data; //0�ε����� begin�̱� ������ ������ �迭 ������ [1]����
	}

	void clear() {
		delete[] m_pArray;
		m_iSize = 0;
		m_iCapasity = 2;
		m_pArray = newNODE[m_iCapasity = 2];
	}

	void reserve(int iSize) {//�迭������ �Է¹��� iSize��ŭ �����δ� �Լ�

		delete[] m_pArray;
		m_pArray = new NODE{ iSize + 2 };

		m_iCapasity = iSize;
		m_iSize = 0;

		
	}
};

//iterator �����غ���!! --> 0�� �ε����� begin����, �����Ͱ� ����ִ� ������ ����� ���� ��带 end ���� �����ؾ���
