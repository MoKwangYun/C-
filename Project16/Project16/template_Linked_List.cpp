#include<iostream>
#include "CLinkedList.h"
using namespace std;



int main() {

	CLinkedList<int> listInt; //class�� T�� int�� ��


	for (int i = 0; i < 100; i++) {

		listInt.push_back(i + 1);
	}
	cout << listInt.size() << endl;

	CLinkedList<int>:: iterator iter; //CLinkedList Ŭ���� �ȿ� typedef�� iterator Ÿ������ ��ü ����

	for (iter = listInt._Begin(); iter != listInt._End(); ++iter){
		//iter�� Ÿ���� iterator ��, CListIterator<T> Ŭ���� �̱� ������ != , ++ ������ ���ؼ� != , ++ �����ڸ� operator�� ���� ����������� �Ѵ�

		cout << *iter << endl;
	}
	return 0;
}