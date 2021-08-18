#include<iostream>

using namespace std;

/*
레퍼런스 : 다른 대상을 참조하게 만들어주는 기능
--> 참조를 하게 되면 그 대상에 접근하여 값을 변경할 수 있다.
단, 레퍼런스는 처음 레퍼런스 변수 생성시 참조하는 대상을 지정해주어야 한다.

<문법>
변수타입& 레퍼런스명 = 참조할 변수명;

const 레퍼런스의 경우 참조한 값 변경 불가!!
*/

int main() {
	int iNumber = 100;
	int iNumber1 = 9999;

	//iRefNum 레퍼런스 변수는 iNumber를 참조한다.
	int& iRefNum = iNumber;

	iRefNum = 1234;

	cout << iNumber << endl;
	//출력 결과 --> 1234  참조한 iRefNum에 바로 접근 통해 iNumber 값 변경!!

	iRefNum = iNumber1; 

	cout << iNumber << endl; 
	/*출력 결과 : 9999  위의 코드는 참조하는 변수를 바꾼 것이 아니라 
	iRefNum이 참조하는 iNumber에 iNumber1 값 9999를 대입하게 되는 것!!
	
	*** 참조하는 대상 변경 불가!! ****
	*/

	cout << sizeof(int&) << endl; //int형 레퍼런스 --> 4byte
	cout << sizeof(iRefNum) << endl;
}
