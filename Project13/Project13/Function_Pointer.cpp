#include<iostream>
#include<Functional>

using namespace std;

/*
함수 포인터: 함수의 메모리 주소를 저장하기 위한 포인터 변수를 선언

전역함수의 경우 함수명이 곧 함수의 메모리 주소이다 (- 배열명으로 배열의 첫 주소를 접근하는 것과 유사)

함수포인터 선언방법: 반환타입 (* 포인터변수명) (인자타입) ; 
*/

int Sum(int a, int b) {
	return a + b;
}



void Output() {
	cout << "Output" << endl;
}

class CHanzo {
public:
	CHanzo() {//생성자
		m_iTest = 120;
	}

	~CHanzo() {//소멸자

	}

	int m_iTest;

	void Output() { //클래스 멤버 함수

		cout << "Hanzo" << endl;
		cout << "Test: " << this->m_iTest << endl;//this->는 생략 가능 , 호출한 객체에 따라 멤버 접근 가능하도록 만들어준다.
	}
	


};

int OutSum(int a, int b) {
	cout << a - b << endl;
	return a - b;
}

float TestFunc(float a) {

	cout << a << endl;
	return a;
}
int main() {
	
	int (*pFunc) (int, int) = NULL; //리턴 타입이 int이고 int 형 인자 두개를 갖는 함수의 주소를 저장할 수 있는 포인터변수 선언
	//똑같은 형태의 함수인(이름, 기능은 다르지만) Sum과 OutSum의 주소 모두 저장 가능

	pFunc = Sum;

	cout << pFunc(10, 20) << endl;

	pFunc = OutSum; //함수 포인터 변수가 가리키는 함수를 OutSum으로 변경

	OutSum(10, 20);

	//pFunc = Output; pFunc의 리턴타입, 인자가 Output함수와 다르기 때문에 저장 불가능

	CHanzo hanzo1, hanzo2; //CHanzo 클래스 객체 생성

	//this 포인타: 클래스 안에서 this를 사용할 경우 해당 객체의 메모리 주소가 된다. 즉 자기자신의 포인터이다.
	//멤버함수를 호출할 때 this를 호출자로 세팅한다.
	hanzo1.m_iTest = 100;
	hanzo2.m_iTest = 200;

	hanzo1.Output();
	hanzo2.Output();

	//멤버 함수포인터 선언시 포인터변수 이름앞에 멤버함수가 속해있는 클래스명 :: 을 붙여준다.
	// :: --> 범위지정 연산자

	void (CHanzo :: * pFunc2) () = &CHanzo :: Output; 

	//멤버 함수포인터 변수 pFunc에 CHanzo 클래스의 멤버 함수 Output의 주소 저장
	//멤버함수의 경우 함수명  != 함수의 주소 --> &를 앞에 붙여준다

	//(*pFunc2)();  - error --> 호출자 (객체.)가 필요하다! 그래야 해당 객체의 멤버를 이용하여 함수 사용
	//hanzo1.(*pFunc2)(); - error
	(hanzo1.*pFunc2)(); //이렇게 하면 멤버 함수포인터 사용 가능 , but 복잡 --> C++11부터 functional 기능 추가 <Functional>헤어 추가
	
	/*Functional 기능은 함수포인터를 전역, 멤버 가리지 않고 쉽게 주소를 저장하여 호출해줄 수 있도록 만들어주는 기능
	
	Functional 객체 선언 방법: function<반환타입(인자타입)> 변수명;

	*/


	function<void()>	func; //functional 객체를 만든다 --> 전역함수,  멤버함수 관계 없이 사용 가능!!
	function<void()>	func2;


	func = bind(Output); //bind 함수를 사용하여 functional 객체에 전역함수 Output 주소 저장
	//bind 함수 --> 1번째 인자 : 함수 주소

	func2 = bind(&CHanzo::Output, &hanzo1); 
	//멤버 함수의 경우 1번째 인자: 함수 주소,  2번째 인자: 호출자(멤버함수를 사용하려는 객체)

	cout << endl <<"<Functional>" << endl << endl;
	func();
	func2();


	function<int(int, int)> func3;  //반환타입 = int , 인자 = int 형 두개
	function<float(float)> func4;

	//함수에 인자가있을 경우 placeholders를 이용해서 인자의 순서를 정의할 수 있다
	//OutSum(int a, int b) { a - b} 에서 placeholders::_2는 b가 되고 placeholders::_1은 a 가 된다.
	func3 = bind(OutSum, placeholders::_2, placeholders::_1);

	//위에서 bind 함수를 통해 10은 OutSum(int a, int b) 중에 b, 20은 a로 들어간다
	func3(10, 20);

	func4 = bind(TestFunc, placeholders::_1);
	//TestFunc 함수는 인자가 하나 밖에 없기 때문에 placeholders::_1만 존재

	func4(3.14);


	return 0;
}