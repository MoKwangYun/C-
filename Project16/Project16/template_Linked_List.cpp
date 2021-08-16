#include<iostream>
#include "CLinkedList.h"
using namespace std;



int main() {

	CLinkedList<int> listInt; //class¿« T∞° int∞° µ 
	CLinkedList<float> listFloat;


	for (int i = 0; i < 100; i++) {
		
		listInt.push_back(i + 1);
	}
	cout << listInt.size() << endl;

	CLinkedList<int>::iterator iter;
	for (iter = listInt._Begin(); iter != listInt._End(); ++iter)[

	]
	return 0;
}