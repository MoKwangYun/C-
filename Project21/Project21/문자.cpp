#include<iostream>
#include<stdio.h>

using namespace std;

/* 메모리 영역
1. 스택
2. 데이터
3. 힙
4. ROM(코드) - 읽기 전용(수정 불가) / 우변에 있는 문자열 등 
	ex. char s[10] = "abc"; --> "abc"는 사용자가 선언한 적이 없는 문자열이다
	이러한 데이터는 ROM 메모리에 저장된다
*/


int main() {
	
	//문자
	char  c = 65; //1byte  아스키코드 65 저장 --> 'A' 저장됨
	char cc = '65';  //문자로서의 65저장

	wchar_t c1 = 97; //2byte  아스키코드 97 저장 --> 'a' 저장됨

	cout << c << endl;
	cout << cc << endl;
	cout << c1 << endl;
	printf("%c\n", c1);


	/*문자열
		- 문자열의 경우 마지막에 '\0' 을 넣어줘야 문자열의 끝임을 인식한다

	whcar = 문자 하나를 2byte로 표현하는 자료형(1byte로 표현할 때보다 표현 범위가 넓어짐)
	--> printf의 경우 ls 형으로 입력 ex) printf("%ls", );
	
	*/

	char f = 'a';
	wchar_t ff = L'a'; //wchar 자료형 변수에 문자 저장시 앞에 L 작성

	//<문자열 선언>

	//1. 배열로 선언
	char arrChar[10] = "abcdef"; //문자열을 저장하는  배열 선언시 문자열 마지막에 '\0'이 들어갈  공간까지 선언해야함
	wchar_t arrWChar[10] = L"abcdef";//원소 하나당 공간이 2byte
	//문자열의 데이터를 배열에 저장


	//2. 포인터로 선언
	
	//char *pChar = "abcdef";  
	//우변에 위치한 문자열은 const 포인터 형식으로 문자열의 주소를 리턴하기 때문에 좌변의 변수도 const 포인터 타입이어야  한다
	char* pChar = (char*)"abcdef";//형변환을 통해 가능

	const wchar_t* pWChar = L"abcdef";
	//문자의 시작주소를 포인터 변수에 저장

	arrWChar[1] = 'z';
	//pWChar[1] = 'z';  -오류(pWChar이  const형이기 때문에 수정 불가)
	
	

	cout << arrChar[1] << endl;
	cout << pChar[1] << endl << *(pChar + 2) << endl << endl;
	//*(pChar + 1)  == pChar[1] ;

	/*  *(pChar + 1) = 'z';  -->오류
	/	pChar[2] = 'y';		--> 오류
	배열의 경우 문자열을 복사하여 새로운 메모리에 저장하는 것이지만
	강제 형변환을 통해 const가 아닌 일반 포인터 타입으로 받아오더라도 우변에 대입 목적으로 작성한 문자열("abcedf")
	자체가 애초에 메모리에 읽기만 가능한 ROM에 저장되기 때문에 수정이 불가능하다!!

	*/

	char S[10] = "ABC";
	char* SS = S;
	SS[0] = 'Z'; //이 경우에는 포인터 변수 SS가 ROM에 있는 "ABC"가 아닌 직접 선언한 배열 S[10]에 저장되어 있기 때문에 수정 가능
	cout << S << endl;

	cout << endl << arrChar << endl;
	printf("%ls\n", arrWChar);
	printf("%ls\n", pWChar);



}