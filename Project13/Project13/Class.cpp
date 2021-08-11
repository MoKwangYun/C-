#include<iostream>

using namespace std;

/*
객체(Object) : 모든 사물을 의미

Class : 객체지향 프로그래밍을 지원하기 위해 제공되는 수단, 객체를 만들기 위한 틀  
--> Class는 구조체와 같이 변수 타입에 해당 / 클래스 자체가 객체가 되는 것은 아님
--> Class나 구조체 등을 통해 생성된 변수 : 인스턴스( = 객체)

객체지향 프로그래밍(OOP) : 객체들의 관계를 설정해주어서 부품을 조립하듯 객체들을 조립하여 완성된프로그램을 만들어나가는 방식

<클래스 선언>
- class 클래스명{}; 형태로 선언
- 코드블럭 안에 멤버 변수를 넣어줄 수 있다. 함수도 멤버로 가능(C는 구조체나 클래스 멤버로 함수 불가능 <-> C++은 멤버 함수 가능)

클래스의 4가지 속성
1. 캡슐화 : 클래스 안에 속하는 여러 변수 혹은 함수를 하나의 클래스로 묶어주는 기능을 말한다. 
2. 은닉화 : 클래스 안에 속하는 변수 혹은 함수를 내가 원하는 부분만 외부에 공개하고 외부에 공개하지 않을 수 있다.
	
	(접근지정자)
	--> public : 클래스 내부와 외부에서 모두 접근 가능한 방법(구조체의 경우 디폴트)
	--> protected : 클래스 외부에서는 접근 불가능 & 자기자신 내부 or 자식 클래스 내부에서 접근 가능
	--> private : (클래스의 경우 디폴트) : 자기자신 내부에서만 접근 가능
	- 클래스 or 구조체 내부 = 해당 멤버 함수의 내부

3. 상속성 : 클래스는 클래스와 클래스 간에 부모, 자식 관계 형성 가능
	--> 자식  클래스는 부모 클래스의 멤버 or 멤버 함수를 물려받아 자신의 멤버처럼 사용할 수 있다 (단, private 멤버는 접근 불가)

4. 다형성 : 부모 자식 관계로 상속관계가 형성되어 있는 클래스 간에 서로 형변환이 가능한 성질을 말한다. (업캐스팅, 다운캐스팅)

<생성자와 소멸자> - 클래스에서 사용하는 특수한 함수
-생성자 : 어떤 클래스를 이용해서 객체를  생성할 때 자동으로 호출되는 함수. 
	-->  객체 생성시 호출되는 함수이기 때문에 객체의 멤버변수를 초기화할 때 유용하다.
	--> 생성자를 만들어주지 않을 경우 내부적으로 기본 생성자가 제공 되어 객체 생성시 기본 생성자를 자동으로 호출해주게 된다.

	형태: 
	클래스명(){
	}

-소멸자 : 어떤 클래스를 이용해서 생성한 객체가 메모리에서 해제될 때(ex. main()종료) 자동으로 호출되는 함수
	--> 밑의 main()에서 CTracer tr1이라는 겍체를 만들었는데 해당 객체는 main() 안에서 유효한 지역변수 이므로 main()이 종료될 때 해제 --> 소멸자 호출
	--> 객체를 사용하고 난 뒤 마무리 작업으로 유용하게 사용될 수 있다.

	형태: 
	~클래스명(){
	}
*/

class CTracer {
	
	

	char m_strName[23]; //접근지정자가  없기 때문에 class의 디폴트 값인 private이 적용됨  --> main()에서 접근 불가

public : //public: 키워드아래 있는 멤버는 외부에서 접근 가능
	int m_iAttack;
	

private:
	int m_MP;
	int m_HP;

public: 
	void Output() {
		cout << "Name: " << m_strName << endl;
	}

	void Output_2() {
		cout << "Name: " << m_strName << endl;
		cout << "HP: " << m_HP << endl;
		cout << "MP: " << m_MP << endl;
	}
	CTracer() { //생성자
		cout << "Tracer 생성자" << endl;

	}

	CTracer(const char* pName) {//생성자 오버로딩
		strcpy_s(m_strName, pName); //클래스 내부이기 때문에 private 멤버인 m_strName에 접근가능
	}
	
	CTracer(const char* pName, int HP, int MP) :
		m_HP(HP),
		m_MP(MP) //객체 생성시 인자로 받은 HP, MP로 클래스 멤버인 m_HP와 m_HP 초기화
		// {}  안에서 m_HP = HP를 한것과 동일한 결과
	{
		strcpy_s(m_strName, pName);
	}

	~CTracer() { //소멸자 (소멸자는 오버로딩 불가)
		cout << "Tracer 소멸자" << endl;
	}
};

int main() {

	CTracer tr1("hanzo"); //--> 생성자 CTracer(const char* pName)을 호출함

	//public 으로 설정된 멤버에만 접근 가능

	tr1.Output();


	CTracer tr2("Mac", 200, 100);

	tr2.Output_2();

	//객체를 두개 tr1, tr2 생성하였기 때문에 소멸자 역시 두번 호출된다.

	return 0;
}