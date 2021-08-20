#include "CQueue.h"
#include<iostream>

using namespace std;

int main() {

	CCircleQueue<int, 10> queueInt;//SIZE�� 10���� ��������, �������� ���� ��� ������� ������ 100

	for (int i = 0; i < 10; i++) {
		queueInt.push(i + 1);
	}

	cout << endl << "3�� pop " << endl << endl;
	for (int i = 0; i < 3; i++) {
		cout << queueInt.pop() << endl;

	}

	cout << endl << "4�� push " << endl << endl;
	for (int i = 0; i < 4; i++) {
		queueInt.push(i + 1);
	}

	cout << endl << "���� pop " << endl << endl;
	while (!queueInt.empty()) {
		cout << queueInt.pop() << endl;
	}
}
