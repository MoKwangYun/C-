#include<iostream>
#include"CVector.h"

using namespace std;

int main() {

	CVector<int> vecInt;

	for (int i = 0; i < 100; i++) {
		vecInt.push_back(i + 1);
	}

	for (int i = 0; i < vecInt.size(); i++) {

		cout << vecInt[i] << endl;
	}


	cout << endl << " ========== iterator ==============" << endl << endl;
	CVector<int>::iterator iter;
	int j = 0;
	for (iter = vecInt._begin(); iter != vecInt._end(); ++iter) {
		cout << *iter << endl;
	}

	return 0;
}