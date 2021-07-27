#include<iostream>

using namespace std;

/*
함수 : 사용할 기능을 만들어준다.
특정 상황에 동작하는 코드 집합을 만들어낸다

형태 
-->반환타입 함수명(인자==파라미터) { 내용 }

반환타입: 해당 함수가 기능을 수행하고 결과를 반환할 경우 반환하는 타입
함수명: 함수의 이름(가급적이면 함수가 하는 역할 정확하게 표시-가독성 위해)

인자(파라미터) : 해당 함수 사용할 때 넘겨줄 값이 있을 경우 활용(없을 수도 있음)
*/

int sum(int a, int b) {
	return a + b;
}//결과를 반환 - call by value 


//반환 타입이 없는 경우(결과로 반환 X)
void OutputText() {
	cout << "OutputText Function" << endl;
}

void ChangeNumber(int num) {
	num = 999; 
	/* 
	변수 num는 ChangeNumber 함수의 지역변수이기 때문에 999로 변경하더라도
	main 함수의 num 변수와는 다르다

	!!반환 타입은 오버로딩에 관련 X !!
	*/
}

void ChangeNum(int* num) { // Call by address, 주소를 받아와 결과를 주소에 넣어줌

	*num = 99;
}

/* 
함수 오버로딩: 같은 이름의 함수여도 인자, 기능 다른 함수

오버로딩 조건: 함수 이름이 같다. / But, 인자의 개수 or  타입 상이
*/

/*
함수의 디폴트 인자: 인자에 기본값을 대입해두면 인자를 넘겨주지 않을 경우 대입한 기본 값이 설정되고
넘겨준 경우 넘겨받은 값으로 인자 설정

!! 디폴트 인자는 가장 오른쪽부터 지정 가능
*/

void Output(int num1, int num2 = 10) {
	cout << "\nOutput 함수 결과(num2 == 디폴트 인자)" << endl;
	cout << num1 << endl;
	cout << num2 << endl;
}

//함수 오버로딩 주의!! 
//함수 이름 동일 & 두 함수 모두 인자가 하나만 있어도 되기 때문에 main 함수에서 사용시 에러

//void Output(int num1) {
//	cout << "\nOutput 함수 결과" << endl;
//	cout << num1 << endl;
//}

int main() {

	//함수 호출 --> 함수명(인자로 넘겨줄 값)

	cout << sum(10, 20) << endl << endl;

	OutputText();

	int num = 1;
	ChangeNum(&num);
	cout << num << endl;


	
	Output(100); 
	//Output 함수의 두번째 인자가 디폴트 인자이기 때문에 
	//인자를 하나만 입력하면 num1에 100이 들어가고 num2는 디폴트값 10으로 함수 실행


	return 0;
}