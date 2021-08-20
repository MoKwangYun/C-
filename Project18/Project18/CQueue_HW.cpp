#include "CQueue_HW.h"
#include<iostream>
using namespace std;

int main() {

	CQueue_HW < float>  queueFloat;

	for (float i = 0.1f; i < 100; i++) {
		queueFloat.push(i + 1);
	}

	cout << "queue size = " << queueFloat.size() << endl << endl;

	while(!queueFloat.empty()) {
		cout << queueFloat.pop() << endl;
	}

	return 0;
}
