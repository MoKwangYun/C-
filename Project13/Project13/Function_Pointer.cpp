#include<iostream>
#include<Functional>

using namespace std;

/*
�Լ� ������: �Լ��� �޸� �ּҸ� �����ϱ� ���� ������ ������ ����

�����Լ��� ��� �Լ����� �� �Լ��� �޸� �ּ��̴� (- �迭������ �迭�� ù �ּҸ� �����ϴ� �Ͱ� ����)

�Լ������� ������: ��ȯŸ�� (* �����ͺ�����) (����Ÿ��) ; 
*/

int Sum(int a, int b) {
	return a + b;
}



void Output() {
	cout << "Output" << endl;
}

class CHanzo {
public:
	CHanzo() {//������
		m_iTest = 120;
	}

	~CHanzo() {//�Ҹ���

	}

	int m_iTest;

	void Output() { //Ŭ���� ��� �Լ�

		cout << "Hanzo" << endl;
		cout << "Test: " << this->m_iTest << endl;//this->�� ���� ���� , ȣ���� ��ü�� ���� ��� ���� �����ϵ��� ������ش�.
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
	
	int (*pFunc) (int, int) = NULL; //���� Ÿ���� int�̰� int �� ���� �ΰ��� ���� �Լ��� �ּҸ� ������ �� �ִ� �����ͺ��� ����
	//�Ȱ��� ������ �Լ���(�̸�, ����� �ٸ�����) Sum�� OutSum�� �ּ� ��� ���� ����

	pFunc = Sum;

	cout << pFunc(10, 20) << endl;

	pFunc = OutSum; //�Լ� ������ ������ ����Ű�� �Լ��� OutSum���� ����

	OutSum(10, 20);

	//pFunc = Output; pFunc�� ����Ÿ��, ���ڰ� Output�Լ��� �ٸ��� ������ ���� �Ұ���

	CHanzo hanzo1, hanzo2; //CHanzo Ŭ���� ��ü ����

	//this ����Ÿ: Ŭ���� �ȿ��� this�� ����� ��� �ش� ��ü�� �޸� �ּҰ� �ȴ�. �� �ڱ��ڽ��� �������̴�.
	//����Լ��� ȣ���� �� this�� ȣ���ڷ� �����Ѵ�.
	hanzo1.m_iTest = 100;
	hanzo2.m_iTest = 200;

	hanzo1.Output();
	hanzo2.Output();

	//��� �Լ������� ����� �����ͺ��� �̸��տ� ����Լ��� �����ִ� Ŭ������ :: �� �ٿ��ش�.
	// :: --> �������� ������

	void (CHanzo :: * pFunc2) () = &CHanzo :: Output; 

	//��� �Լ������� ���� pFunc�� CHanzo Ŭ������ ��� �Լ� Output�� �ּ� ����
	//����Լ��� ��� �Լ���  != �Լ��� �ּ� --> &�� �տ� �ٿ��ش�

	//(*pFunc2)();  - error --> ȣ���� (��ü.)�� �ʿ��ϴ�! �׷��� �ش� ��ü�� ����� �̿��Ͽ� �Լ� ���
	//hanzo1.(*pFunc2)(); - error
	(hanzo1.*pFunc2)(); //�̷��� �ϸ� ��� �Լ������� ��� ���� , but ���� --> C++11���� functional ��� �߰� <Functional>��� �߰�
	
	/*Functional ����� �Լ������͸� ����, ��� ������ �ʰ� ���� �ּҸ� �����Ͽ� ȣ������ �� �ֵ��� ������ִ� ���
	
	Functional ��ü ���� ���: function<��ȯŸ��(����Ÿ��)> ������;

	*/


	function<void()>	func; //functional ��ü�� ����� --> �����Լ�,  ����Լ� ���� ���� ��� ����!!
	function<void()>	func2;


	func = bind(Output); //bind �Լ��� ����Ͽ� functional ��ü�� �����Լ� Output �ּ� ����
	//bind �Լ� --> 1��° ���� : �Լ� �ּ�

	func2 = bind(&CHanzo::Output, &hanzo1); 
	//��� �Լ��� ��� 1��° ����: �Լ� �ּ�,  2��° ����: ȣ����(����Լ��� ����Ϸ��� ��ü)

	cout << endl <<"<Functional>" << endl << endl;
	func();
	func2();


	function<int(int, int)> func3;  //��ȯŸ�� = int , ���� = int �� �ΰ�
	function<float(float)> func4;

	//�Լ��� ���ڰ����� ��� placeholders�� �̿��ؼ� ������ ������ ������ �� �ִ�
	//OutSum(int a, int b) { a - b} ���� placeholders::_2�� b�� �ǰ� placeholders::_1�� a �� �ȴ�.
	func3 = bind(OutSum, placeholders::_2, placeholders::_1);

	//������ bind �Լ��� ���� 10�� OutSum(int a, int b) �߿� b, 20�� a�� ����
	func3(10, 20);

	func4 = bind(TestFunc, placeholders::_1);
	//TestFunc �Լ��� ���ڰ� �ϳ� �ۿ� ���� ������ placeholders::_1�� ����

	func4(3.14);


	return 0;
}