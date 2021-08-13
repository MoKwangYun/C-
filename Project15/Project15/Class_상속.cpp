#include<iostream>

using namespace std;

/*
상속 : 클래스는 클래스 간에 부모와 자식 관계를 형성할  수 있다.

자식 클래스는 부모 클래스의 멤버들(멤버 변수, 멤버 함수)을 사용할 수 있다.

부모클래스에서 public이나 protected로 되어있는 멤버들은 자식클래스에서 사용 가능하지만,
private으로 되어있는 멤버는 자식에서도 사용 불가

+ protected : 자식클래스  only 사용 가능(외부 사용불가)

상속의 형태: public,private 상속

다형성 : 상속관계에 있는 클래스 간에 서로 형변환이 가능한 성질을 말한다

가상함수(= 함수 오버라이딩) : 함수를 재정의하는 기능이다.
--> 멤버함수 앞에 virtual 키워드를 붙이면 해당 함수는가상함수가 된다.
만약 CParnet 클래스에 virtual void Output() 함수가 있다면 자식클래스에서는 이 가상함수를 재정의할 수 있다.
-->재정의시 함수이름& 인자가 완전히 같아야 가능

가상함수를 가지고 있는클래스는 내부적으로 가상함수 테이블을 생성한다.
가상함수 테이블은 가상함수들의 메모리 주소를 저장하는 테이블이다.

만약 CParent의 Output이 가상함수이고 CChild 클래스에 Output을 재정의한다면
그 다음 CChild 객체를 생성하면 가상함수 테이블에는 CChild 클래스의 Output 주소가 올라가게된다.
or CParent 객체를 생성한다면 CParent의 Output 주소가 올라간다.

--> Output 함수, 즉 가상함수를 호출하게 되면 먼저 가상함수 테이블을 참조해서 메모리주소를 확인한다.

ex.  CChild 객체의 Output 호출시 가상함수 테이블내 해당 Child 객체에  속한 Output 함수 주소 확인
가상함수 테이블에 CChild의 Output주소가 들어가 있다면 그 주소의 함수를 호출해주는  구조이다.

*******!!소멸자도 가상함수로 만들 수 있다. 부모의 소멸자는 가상함수로 만들기!!******


순수가상함수 : 함수 뒤에 = 0 을 붙여주면 해당 가상함수는 순수가상함수가 된다.
순수가상함수는 구현 부분이 존재하지 않는다!!
-->순수가상함수를 가지고 있는 클래스 =  추상클래스
-->추상클래스는 객체(인스턴스) 생성이 불가능하다.
-->순수가상함수는 해당 클래스를 상속받는 모든 자식클래스에서 반드시 재정의해야 한다!!(자식클래스에서 재정의하여 사용할 목적으로 존재!!) 
-->자식클래스에서 어떤 함수를 재정의할지를 알려주는 인터페이스 역할!!

*/

class CParent {
public:
	CParent() {
		cout << "CParent 생성자" << endl;
	}
	virtual ~CParent() {
		cout << "CParent 소멸자" << endl;
	}

public:
	int m_iA;

	virtual void Output() {
		cout << "Parent Output Virtual Function" << endl;
	}

	virtual void OutputPure() = 0;
protected:
	int m_iB;

private:
	int m_iC;

};

class CChild : public CParent { //public으로 CChild 클래스에 상속
public: 
	CChild() {
		m_iB = 300; //m_iB가 protected 이기 때문에 main에서는 접근이 불가능하고 자식클래스에서는 접근 가능

		//m_iC = 500;  m_iC는 private 이기 때문에 자식클래스에서도 접근 불가능
		cout << "CChild 생성자" << endl;
	}
	virtual ~CChild() {
		cout << "CChild 소멸자" << endl;
	}

	

protected:
	int m_iD;

public:
	void ChildOutput() {
		
		cout << "ChildOutput Function" << endl;
	}

	virtual void Output() {

		CParent::Output(); //부모클래스의 멤버함수 호출
		cout << "Child Output Virtual Function"<<endl << endl;

	}
	
	virtual void OutputPure() {
		cout << "Child Pure Function" << endl;
	}
};

class CChild1 : private CParent { // private으로 CChild1 클래스에 상속
public:
	CChild1() {

		m_iA = 222; //private으로 상속을 받았지만 CChild1클래스 내부에서는 부모클래스 멤버 접근 가능 , but 외부에서는 접근 불가
		cout << "CChild1 생성자" << endl;
	}

	~CChild1() {
		cout << "CChild1 소멸자" << endl;
	}
	virtual void OutputPure() {
		cout << "Child1 Pure Function" << endl;
	}
private:
	int m_iD;
};

class CChildChild : public CChild { // CParent 클래스의 자식 클래스인 CChild 클래스를 public으로 상속 받는 CChildChild 클래스

public:
	CChildChild() {

		m_iD = 500;
		cout << "CChildChild 생성자" << endl;
	}
	~CChildChild() {
		cout << "CChildChild 소멸자" << endl;
	}
	
	virtual void OutputPure() {
		cout << "ChildChild Pure Function" << endl;
	}

private:
	int m_iE;

};
int main() {

	/*
	상속관계에서의 생성자 호출 순서 : 부모 -> 자식 순 호출
	상속관계에서의 소멸자 호출 순서 : 자식 -> 부모 순 호출


	*/
	// CParent parent; //CParnet() 생성자 호출  --> 순수가상함수를 갖고 있는 추상클래스이기 때문에 객체 생성 불가
	CChild child;	 // CParent() 생성자 호출 -> CChild() 생성자 호출
	CChild1 child1;	//CParent() 생성자 호출 -> CChild1() 생성자 호출 
	CChildChild childchild;	//CParent() 생성자 호출-> CChild() 생성자 호출 -> CChildChild() 생성자 호출


	child.m_iA = 200; //부모클래스의 멤버인 m_iA 접근 가능

	//child1.Output(); & child1.m_iA = 222;  --> error 
	// CChild1 클래스는 private으로 CParent 클래스를 상속받기 때문에 부모클래스 멤버 접근 불가
	// but, private으로 상속받았다 하더라도 클래스 안에서는 접근 가능




	cout << endl << endl << "====================업캐스팅, 다운캐스팅 ========================" << endl << endl;

	/*CChild 클래스는 CParent 클래스를 상속받고 있다.
	new CChild를 하게되면 CChild 객체 하나를생성해주고 그 메모리 주소를 반환한다.
	그런데 아래에서는 CParent* 타입 변수에 반환된 주소를 대입해주고 있다.
	부모포인터 타입에 CChild 객체의 메모리 주소를 넣을 수 있는 이유는 상속관계에 있기 때문이다.
	자식 메모리 주소를 부모포인터  타입으로 형변환 된 것이다. --> 업캐스팅

	자식 -> 부모 형변환 : 업캐스팅
	부모 -> 자식 형변환 :  다운캐스팅
	*/

	CParent* pParent = new CChild;

	/*아래 두 클래스는 모두 CParent 클래스를 상속받고 있다.
	그러므로 pParent를 두 타입 모두 다운캐스팅 가능하다.
	그런데 pParent는 CChild로 할당한 객체이다.
	이 객체(pParent)를 CChild1 타입으로 다운캐스팅하여 넣어주게 되면 pParent를 사용할 때 문제가 발생할 수 있다.
	왜냐하면 애초에 생성한 객체가 아닌 다른 타입으로 변환되었기 때문이다.

	==> 생성했던 타입으로만 다운캐스팅 해야 한다!!
	*/


	/* 
	pParent->ChildOutput(); 
	pParent는 CParent 포인터 타입 ==> 자식 멤버에는 접근이 불가능하기 때문에 접근하려면 형변환 필요!!
	*/
	cout << endl << "=================형변환하여 함수 호출=================" << endl;
	((CChild*)pParent)->ChildOutput();

	cout << endl << "==================Vitual 함수 호출=====================" << endl;
	pParent->Output();
	//pParent* 타입이지만 생성은 CChild 타입으로 하였기 때문에 가상함수 테이블에서 CChild의 Output 함수 주소를 호출!!
	//만약 CChild 클래스에 Output()을 재정의하지 않으면 CParent 클래스 Output 함수 주소 호출!!

	cout << endl << "==================Vitual 함수이지만 부모 함수 호출=====================" << endl;
	pParent->CParent::Output(); //CChild 클래스의 Output 함수 주소를 호출해야 하지만 CParent :: 를 추가함으로 명시적으로 CParent의 Output 함수를 지정
	
	cout << endl;


	CChild* pChild = (CChild*)pParent;
	/*CChild1* pChild1 = (CChild1*)pParent;  
	--> pParent 객체는 CChild 타입으로 생성한 메모리 공간이고 이를 CParnet* 타입으로 형변환 한것이다.(업캐스팅)
	그러므로 다운캐스팅을 할 때에도 처음 생성한 타입인 CChild 타입으로 다운캐스팅해야 한다.
	*/


	//CParnet* pParent1 = new CChild1;  --> CChild1 클래스는 private으로 부모클래스를 상속 받기 때문에 error
	 CParent* pParent2 = new CChildChild;  //--> 가능
	 pParent2->Output(); //CChildChild 클래스에서는 Output 함수를 재정의하지 않았기 때문에 CChildChild의 부모클래스 CChild 클래스의 Output주소 호출

	CParent* pParentArr[2] = {};

	pParentArr[0] = new CChild;
	pParentArr[1] = new CChildChild;
	//상속 관계에 있는 모든 클래스들을 (private 상속 제외) 부모클래스에서 관리 가능  --> 관리하기에 편하고 유용함!

	for (int i = 0; i < 2; i++) {

		delete pParentArr[i]; // pParentArr[]는 CParent* 타입이기 때문에 소멸시 CParent 소멸자만 호출된다. CChild나 CChildChild 소멸자는 호출 X
		//하지만 생성시에는 CChild, CChildChild 타입으로 먼저 생성하기 때문에 각각 클래스 생성자 호출 O
		// cf. 부모의 소멸자를 가상함수(virtual)로 만들어두면 해당 객체가 생성된 클래스의 소멸자도 호출된다!!(자식 -> 부모 순 소멸자 호출)
	
	}

	return 0;
}