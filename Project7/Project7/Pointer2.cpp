#include<stdio.h>
#include<iostream>

using namespace std;

struct Student {
	int kor;
	int eng;
	int matth;
	int total;
	float avg;
};

//배열명 == 포인터!!(배열명 자체가 해당 배열의 시작점 주소 를 의미)

int main() {
	const char* pText = "텍스트 문자열"; //pText 이름의 상수 메모리 배열이 잡힌다.  --> 해당 배열의 메모리 주소를 pText에 저장함
	//pText[0] = '테';와 같이 원소 변경 불가  --> 수정 않을 문자열만 char * 사용

	cout << pText << endl;

	cout << (int*)pText << endl; //pText의 메모리 주소

	pText = "abcd"; //다른 문자열을 가리키도록은 할 수 있음
	cout << pText << endl;
	cout << (int*)pText << endl; 

	pText = "abcd"; 
	cout << pText << endl;
	cout << (int*)pText << endl; //같은 문자열은 같은 메모리 주소에 저장된다

	pText = "abcdefg";
	cout << pText << endl;
	cout << (int*)pText << endl;


	char text[8] = "abcdefg";
	cout << text << endl;
	cout << (int *)text << endl; //같은 문자열이지만 상수 배열이 아니기 때문에 주소 다름



	//구조체 포인터

	 //포인터 사용하는 이유 : 다른 변수의 메모리 주소를 통해 접근 & 제어

	Student student = {};

	Student* pstudent = &student;

	(*pstudent).kor = 50; //.을 먼저 인식하기 때문에 *pstudent를 괄호로 감싸준 후에 가리키는 대상의 멤버에 접근
	 
	cout << "kor = " << student.kor << endl;

	pstudent->kor = 80;

	cout << "kor = " << student.kor << endl; // ->를 이용하여 가리키는 대상 멤버에 접근


	//void 포인터
	//void : 타입이 없다. void의 포인터 타입활용 가능 -->> void* 변수를 선언하게 되면 어떤 타입의 메모리 주소도 저장 가능
	//단, 역참조 불가능하며 메모리 주소 저장만 가능
	//only 메모리 주소 저장용 버퍼 용도로 사용
	int num = 100;

	void* pvoid = &num;
	cout << "num address: " << pvoid << endl;
	//*pvoid = 1000;  --> 역참조 불가
	//cout << "*pvoid : " << *pvoid ;  --> 역참조 불가
	cout << "*((int *)pvoid) == num : " << *((int*)pvoid) << endl;  //해당 변수 등의 타입으로의 형변환을 통한 역참조는 가능

	int* pnum = (int*)pvoid;
	*pnum = 1000; // int 타입으로 형변환을 한 후 int 타입 포인터 변수에 저장하면 역참조(수정) 가능

	cout << "num : " << num << endl;
	
	pvoid = &student;
	cout << "student address: " << pvoid << endl;  //int, 구조체 타입 메모리 주소 저장 가능
	//*pvoid->kor = 1000; -->역참조 불가
	
	//이차원 배열& 포인터

	int ar[][2] = { {1,2} , {3,4} };

	cout << "&ar[0][0] : " << &ar[0][0] << endl;
	cout << "ar : " << ar << endl;
	cout << "ar[0] : " << ar[0] << endl;


}