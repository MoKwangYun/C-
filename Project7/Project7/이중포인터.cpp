#include<iostream>

using namespace std;

int main() {
	//����������: ������ ������ �ּҸ� ����

	int num1 = 11;

	int* pnum = &num1;

	int** ppnum = &pnum; // ������ ������ �޹��� �ּҸ� �����ϴ� ������

	*pnum = 222;

	cout << "num1 :\t" << num1 << endl;
	cout << "num1  address:\t" << &num1 << endl;
	cout << "*pnum :\t" << *pnum << endl;
	cout << "pnum value(���尪) :\t" << pnum << endl;
	cout << "pnum address :\t" << &pnum << endl << endl;

	cout << "*pnum :\t" << *ppnum << endl; // ppnum�� ����Ű�� pnum�� ���尪 == num�� �ּҰ�
	cout << "**pnum :\t" << **ppnum << endl; //ppnum�� ����Ű�� pnum�� ����Ű�� num�� ���尪
	cout << "ppnum addrress: \t" << &ppnum << endl;
	cout << " ppnum value :  " << ppnum << endl;

	int num2 = 777;

	*ppnum = &num2; // ������ ���� pnum�� ����Ű�� ������ �ٲ� �� �ִ�.

	cout << "\n\n���� �� \n*pnum : " << *pnum << endl;

}