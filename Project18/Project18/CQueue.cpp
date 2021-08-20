#include "CQueue.h"
#include<iostream>

using namespace std;

int main() {

	CCircleQueue<int, 10> queueInt;//SIZE를 10으로 지정해줌, 지정하지 않을 경우 헤더에서 선언한 100

	for (int i = 0; i < 10; i++) {
		queueInt.push(i + 1);
	}

	cout << endl << "3개 pop " << endl << endl;
	for (int i = 0; i < 3; i++) {
		cout << queueInt.pop() << endl;

	}

	cout << endl << "4개 push " << endl << endl;
	for (int i = 0; i < 4; i++) {
		queueInt.push(i + 1);
	}

	cout << endl << "전부 pop " << endl << endl;
	while (!queueInt.empty()) {
		cout << queueInt.pop() << endl;
	}
}
