#include<iostream>

using namespace std;

int main() {

	/*
	포인터: 메모리 주소를  담아놓는(저장하는) 변수이기 때문에 x86의 경우 4yte, x64의 경우 8byte
	일반 변수는 값을 저장 / 포인터 변수는 메모리 주소를  저장
	모든 변수 타입은 포인터 타입을선언할 수 있다.
	
	저장된 메모리 주소에 접근하여 값을 제어할 수 있다.
	*/

	int num = 100;

	//포인터 변수 선언
	int* p = &num; //변수 num의 메모리 주소를 저장하는 포인터 변수 p

	cout << "num address : " << &num << endl;
	cout << "p : " << p << endl;

	//역참조를 통해 주소가 저장된 변수의 값 변경, 접근 가능
	cout << "*p == num : " <<*p << endl;

	*p = 123; //num의 123으로 변경

	cout << "*p == num : " << num<< endl;


	/*
	포인터와  배열의 관계 = 배열명은 포인터다!!(배열명 자체가 해당 배열의 시작점 주소 를 의미)
	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
	array == &array[0]
	*/
	
	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };

	cout << " array address : " << array << endl;
	cout << " array address : " << &array[0] << endl;
	
	
	//char 포인터



	return 0;
}