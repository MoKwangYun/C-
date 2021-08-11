#include<iostream>

using namespace std;

int main() {

	/*
	레퍼런스 : 다른 대상을 참조하게 만들어주는 기능
	참조를 하게되면 그 대상에 접근하여 값을 변경할 수 있다.
	단, 레퍼런스는 처음 레퍼런스 변수 생성시 참조하는 대상을  지정해주어야 한다.

	형식 -  변수타입 &레퍼런스명 = 참조할변수명;
	*/

	int iNumber = 100;
	int iNumber1 = 999;

	//iRefNum 레퍼런스 변수는 iNumbe를 참조한다 / 포인터와 같이 역참조 필요 없이 참조만 하고 있다면 바로 접근하여 변경 가능
	int& iRefNum = iNumber;

	iRefNum = 1234;

	cout << iNumber << endl;

	iRefNum = iNumber1; //iNumber1의 값을 iRefNum이 참조하는 대상인 iNumber에 대입
	//참조하는 대상을 변경할 수 없다!!

	cout << iNumber << endl; 
	return 0;
}