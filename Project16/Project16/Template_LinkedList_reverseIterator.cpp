#include<iostream>
#include "Reverse_Iterator.h"


using namespace std;

int main() {

	LinkedList<int> listint;//LinkedList Ŭ������ �����ڰ� private���� �Ǿ������� main�Լ����� �ش� Ŭ���� ��ü ���� �Ұ�


	for (int i = 0; i < 50; i++) {
		listint.push_front(i + 1);
	}

	cout << listint.Size << endl;


	LinkedList<int>::iterator iter;

	for (iter = listint._End(); iter != listint._Begin(); --iter) {

		cout << *iter << endl;
	}

	return 0;
}