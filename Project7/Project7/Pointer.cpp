#include<stdio.h>

#include<iostream>

using namespace std;

int main(void) {

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

	int* parray = array; //(!= &array);

	cout << " parray[2] : " << parray[2] << endl;
	cout << " array[2] : " << array[2] << endl;


	/*
	포인터 연산: +, - 연산 활용
	int 포인터의 경우 메모리 주소에 +1 ==> 1이 아닌 int 타입 크기 만큼 메모리 주소 증가 (+4) 
	*/
	

	cout << "parray :" << parray << endl;
	cout << "parray + 2:" << (parray + 2) << endl; // 저장 메로리 주소 값 8 증가

	cout << "*parray: " << *parray << endl;
	cout << "*(parray + 2) : " << *(parray + 2) << endl; //8 증가된 주소의 저장값 출력 == array[2] (int 배열은 원소당 메모리 크기 4byte)
	cout << "*parray + 100: " << *parray + 100 << endl; //*parray를 출력한뒤 그 값에서 100을 더한다
														 
	
	


	return 0;
}