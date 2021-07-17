//비트논리 연산 & 시프트 연산 & iostream 출력
#include<stdio.h> // #include : 헤더파일을 여기에 포함시키는 기능

// <iostream> : 입력 &  출력 등 기본적 기능 포함
#include<iostream>

using namespace std;
int main() {

	//출력
	std::cout << "TestOutput" << endl; // = printf("TestOutput");
	//cout : 콘솔창에 출력해주는기능, 뒤에 있는 " " 안의 문자들 화면에 출력 (문자열 출력)

	//main 바깥에 using namespace std;를 사용함으로 std;; 생략가능
	cout << "test" << endl; //문자열 뒤에 <<endl 은 \n과 같은 기능




	//const : 상수 : 변하지 않는 수(값 한번 저장하면 변경 불가==> 선언과 동시에 값 지정) <-> 변수
	const int iA = 0x00000001;//16진수 1(1)
	const int iarmor = 0x00000002;//	= 10(in 2진수)
	const int ihp = 0x00000004; //		= 100
	const int imp = 0x00000008; //		= 1000
	const int icri = 0x00000010; //		= 10000

	int ibuf = iA | ihp | icri; // 1 | 100 ==> 101 , 101 | 10000 ==> 10101 : ibuf로 (각 비트에 추가할 때는 or 연산)

	//ibuf에 ihp, imp등 있는지 확인  (0이면 포함 X)
	cout << "Armor : " << (ibuf & iarmor) << endl;  //ibuf는 10101, iarmor은 00010 & 연산 ==> 00000 (포함 X)
	cout << "Hp : " << (ibuf & ihp) << endl; // 10101, ihp 00100 & 연산 ==> 00100 (!= 0 포함 O)

	//원하는 비트 제거
	ibuf ^= ihp;//(ibuf = ibuf ^ ihp) - ^ : xor  = 다르면 1, 같으면 0 / 10101 ^ 00100 = 100001 ==> ihp만 사라짐

	//다시 복구
	ibuf ^= ihp; // 10001 ^ 00100 ==> 10101 (기존 ibuf)
	// 스위치와 같이  ^를 이용하여 특정 비트 제거 , 재저장(?) 가능

	
	/*
	쉬프트 연산: <<, >> // 값 대 값을 연산하여 값으로 나옴
	ex. 20 << 2 = 10100 << 2 = 1010000 = 80 (:20 * 2^2)
	ex. 20 << 3 = 160 (:20 * 2^3)

	20 >> 2 = 10100 >> 2 = 00101 = 5 (:20 / 2^2)
	20 >> 3 = 2 (:20 / 2^3)  
	*/

	
	return 0;
}