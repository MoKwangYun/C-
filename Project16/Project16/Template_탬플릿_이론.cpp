#include<iostream>

using namespace std;

enum Enum {

};
/*
탬플릿 : 컴파일 단계에서 타입을 결정짓는 기능
타입이 다양하게  바뀔 수 있다.

template < typename 원하는 이름>  or template <class  원하는 이름> 형태로 사용가능

ex) template<typename T>
void Output(){
	cout<<typeid(T).name << endl;
}

위처럼 함수를 만들고 호출시
Outut<int>();
Output(float>();

이렇게 해주면 int, float로 타입이 정해진다. 넣어주는 타입으로 타입이 가변적으로 바뀐다.
가변타입은 여러개로 지정해 줄 수 있다.
-->
template<typename T, typename T1>
void Output(){
]


****!! 함수나 클래스 생성시 타입을 가변적으로 입력 받기 가능 !!****
*/

template <typename T>
void OutputType() {
	cout << " ========Output TYPE =====" << endl;
	cout << typeid(T).name() << endl;
}

template  <typename T>
void OutputData(T data) {
	cout << " ========Output Data =====" << endl;
	cout << typeid(T).name() << endl;
	cout << data << endl;
}

//클래스나 구조체, 열거체도 template으로 사용 가능
//(클래스나 구조체 = 사용자 지정 타입 --> 지정한 타입이 template의 T가 될 수 있다)
typedef struct _tagStudent {

}STUDENT, *PSTUDENT;

class CCar {
public:
	CCar() {

	}
	~CCar() {

	}
};

class CTemplate {
public:
	CTemplate() {

	}
	~CTemplate() {

	}
public:
	template<class T, class T1>
	void Output(T a, T1 b) {
		cout << endl << "=======CTemplate Output===========" << endl;
		cout << a << endl;
		cout << b << endl;
	}
};

template <typename T>
class CTemplate1 {
public:
	CTemplate1() {
		cout << "Template Class Type: " << typeid(T).name() << endl;
	}
	~CTemplate1() {

	}
private:
	//T	m_Data; //입력 받을 T 타입의 변수 m_Data 선언

public:
	void Output(T m_Data)
	{
		cout << typeid(T).name() << endl;
		cout << m_Data << endl;
	}
};


int main() {

	OutputType<int>(); //Output 함수를 사용하는데 tempalte 의 T(타입)을 지정해저 함수에 사용
	OutputType<float>();
	OutputType<STUDENT>();
	OutputType<CCar>();
	OutputType<Enum>();

	OutputData(10);
	OutputData(3.1);
	OutputData(382.383f);
	OutputData('a');
	OutputData("kkk");
	// T 는 타입을 의미, 타입을 입력하지 않더라도 받은 인자의 타입이 T 가 됨
	
	CTemplate tem;


	tem.Output(10, 3.14f);

	CTemplate1<int> tem1;//CTemplate1 클래스의 객체를 생성하는데 template을 사용했기 때문에 타입을 가변적으로 지정해줄 수 있다.
	tem1.Output(3.14f); //입력은 3.14로 받았지만 tempalte이 int로 지정되었기 때문에 m_Data는 int가 된다

	CTemplate1<CTemplate> tem2;
	

	return 0;
}