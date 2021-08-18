#include<iostream>
#include "CLinkedList.h"
using namespace std;



int main() {

	CLinkedList<int> listInt; //class의 T가 int가 됨


	for (int i = 0; i < 100; i++) {

		listInt.push_back(i + 1);
	}
	cout << listInt.size() << endl;

	CLinkedList<int>:: iterator iter; //CLinkedList 클래스 안에 typedef된 iterator 타입으로 객체 생성

	for (iter = listInt._Begin(); iter != listInt._End(); ++iter){
		//iter의 타입은 iterator 즉, CListIterator<T> 클래스 이기 때문에 != , ++ 연산을 위해선 != , ++ 연산자를 operator를 통해 재정의해줘야 한다

		cout << *iter << endl;
	}
	return 0;
}