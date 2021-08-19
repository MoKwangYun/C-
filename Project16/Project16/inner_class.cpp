#include<iostream>

using namespace std;

//클래스 : 객체를 만들기 위한 틀
class A {
public:
	A() {

	}
	~A() {

	}

public:
	class B {
	public:
		B() {

		}
		~B() {
		}

	};

	typedef C c;
};

//B와 c는 inner class!!
//A 외부에 선언된 C클래스를 A 안에서 typedef 함으로 C를 이너클래스와 같이 사용할 수 있다!!

class C {
public:
	C() {

	}
	~C() {

	}

	friend class A;
};

int main() {

	A a; 

	A::B b; //A클래스 안에서 선언된 이너클래스 B의 객체를 선언할 때는 ::를 붙여주어 B가 어떤 클래스에 속해있는지 표시

	A::c cc;//A클래스 안에서 재정의된 c 클래스 객체 선언시 ::를 붙여주어 재정의된 위치 표시

	C cc1; //이너클래스(c)를 활용해 C의 객체를 만들거나 C클래스를 이용해 객체를 만들거나 동일!!

	//but, B클래스는 애초에 A 클래스 안에서 선언되었기 때문에 B b;는 불가
}