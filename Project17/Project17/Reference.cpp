#include<iostream>

using namespace std;

/*
���۷��� : �ٸ� ����� �����ϰ� ������ִ� ���
--> ������ �ϰ� �Ǹ� �� ��� �����Ͽ� ���� ������ �� �ִ�.
��, ���۷����� ó�� ���۷��� ���� ������ �����ϴ� ����� �������־�� �Ѵ�.

<����>
����Ÿ��& ���۷����� = ������ ������;

const ���۷����� ��� ������ �� ���� �Ұ�!!
*/

int main() {
	int iNumber = 100;
	int iNumber1 = 9999;

	//iRefNum ���۷��� ������ iNumber�� �����Ѵ�.
	int& iRefNum = iNumber;

	iRefNum = 1234;

	cout << iNumber << endl;
	//��� ��� --> 1234  ������ iRefNum�� �ٷ� ���� ���� iNumber �� ����!!

	iRefNum = iNumber1; 

	cout << iNumber << endl; 
	/*��� ��� : 9999  ���� �ڵ�� �����ϴ� ������ �ٲ� ���� �ƴ϶� 
	iRefNum�� �����ϴ� iNumber�� iNumber1 �� 9999�� �����ϰ� �Ǵ� ��!!
	
	*** �����ϴ� ��� ���� �Ұ�!! ****
	*/

	cout << sizeof(int&) << endl; //int�� ���۷��� --> 4byte
	cout << sizeof(iRefNum) << endl;
}
