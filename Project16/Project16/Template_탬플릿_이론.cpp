#include<iostream>

using namespace std;

enum Enum {

};
/*
���ø� : ������ �ܰ迡�� Ÿ���� �������� ���
Ÿ���� �پ��ϰ�  �ٲ� �� �ִ�.

template < typename ���ϴ� �̸�>  or template <class  ���ϴ� �̸�> ���·� ��밡��

ex) template<typename T>
void Output(){
	cout<<typeid(T).name << endl;
}

��ó�� �Լ��� ����� ȣ���
Outut<int>();
Output(float>();

�̷��� ���ָ� int, float�� Ÿ���� ��������. �־��ִ� Ÿ������ Ÿ���� ���������� �ٲ��.
����Ÿ���� �������� ������ �� �� �ִ�.
-->
template<typename T, typename T1>
void Output(){
]


****!! �Լ��� Ŭ���� ������ Ÿ���� ���������� �Է� �ޱ� ���� !!****
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

//Ŭ������ ����ü, ����ü�� template���� ��� ����
//(Ŭ������ ����ü = ����� ���� Ÿ�� --> ������ Ÿ���� template�� T�� �� �� �ִ�)
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
	//T	m_Data; //�Է� ���� T Ÿ���� ���� m_Data ����

public:
	void Output(T m_Data)
	{
		cout << typeid(T).name() << endl;
		cout << m_Data << endl;
	}
};


int main() {

	OutputType<int>(); //Output �Լ��� ����ϴµ� tempalte �� T(Ÿ��)�� �������� �Լ��� ���
	OutputType<float>();
	OutputType<STUDENT>();
	OutputType<CCar>();
	OutputType<Enum>();

	OutputData(10);
	OutputData(3.1);
	OutputData(382.383f);
	OutputData('a');
	OutputData("kkk");
	// T �� Ÿ���� �ǹ�, Ÿ���� �Է����� �ʴ��� ���� ������ Ÿ���� T �� ��
	
	CTemplate tem;


	tem.Output(10, 3.14f);

	CTemplate1<int> tem1;//CTemplate1 Ŭ������ ��ü�� �����ϴµ� template�� ����߱� ������ Ÿ���� ���������� �������� �� �ִ�.
	tem1.Output(3.14f); //�Է��� 3.14�� �޾����� tempalte�� int�� �����Ǿ��� ������ m_Data�� int�� �ȴ�

	CTemplate1<CTemplate> tem2;
	

	return 0;
}