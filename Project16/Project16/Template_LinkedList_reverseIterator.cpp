#include<iostream>
#include "Reverse_Iterator.h"


using namespace std;

int main() {

	LinkedList<int> listint;//LinkedList 클래스의 생성자가 private으로 되어있으면 main함수에서 해당 클래스 객체 생성 불가


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