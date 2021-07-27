#include<iostream>

using namespace std;

int main() {
	//이중포인터: 포인터 변수의 주소를 저장

	int num1 = 11;

	int* pnum = &num1;

	int** ppnum = &pnum; // 포인터 변수의 메무리 주소를 저장하는 포인터

	*pnum = 222;

	cout << "num1 :\t" << num1 << endl;
	cout << "num1  address:\t" << &num1 << endl;
	cout << "*pnum :\t" << *pnum << endl;
	cout << "pnum value(저장값) :\t" << pnum << endl;
	cout << "pnum address :\t" << &pnum << endl << endl;

	cout << "*pnum :\t" << *ppnum << endl; // ppnum이 가리키는 pnum의 저장값 == num의 주소값
	cout << "**pnum :\t" << **ppnum << endl; //ppnum이 가리키는 pnum이 가리키는 num의 저장값
	cout << "ppnum addrress: \t" << &ppnum << endl;
	cout << " ppnum value :  " << ppnum << endl;

	int num2 = 777;

	*ppnum = &num2; // 포인터 변수 pnum이 가리키는 변수를 바꿀 수 있다.

	cout << "\n\n변경 후 \n*pnum : " << *pnum << endl;

}