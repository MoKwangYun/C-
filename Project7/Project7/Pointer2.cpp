#include<stdio.h>
#include<iostream>

using namespace std;

struct Student {
	int kor;
	int eng;
	int matth;
	int total;
	float avg;
};

//�迭�� == ������!!(�迭�� ��ü�� �ش� �迭�� ������ �ּ� �� �ǹ�)

int main() {
	const char* pText = "�ؽ�Ʈ ���ڿ�"; //pText �̸��� ��� �޸� �迭�� ������.  --> �ش� �迭�� �޸� �ּҸ� pText�� ������
	//pText[0] = '��';�� ���� ���� ���� �Ұ�  --> ���� ���� ���ڿ��� char * ���

	cout << pText << endl;

	cout << (int*)pText << endl; //pText�� �޸� �ּ�

	pText = "abcd"; //�ٸ� ���ڿ��� ����Ű������ �� �� ����
	cout << pText << endl;
	cout << (int*)pText << endl; 

	pText = "abcd"; 
	cout << pText << endl;
	cout << (int*)pText << endl; //���� ���ڿ��� ���� �޸� �ּҿ� ����ȴ�

	pText = "abcdefg";
	cout << pText << endl;
	cout << (int*)pText << endl;


	char text[8] = "abcdefg";
	cout << text << endl;
	cout << (int *)text << endl; //���� ���ڿ������� ��� �迭�� �ƴϱ� ������ �ּ� �ٸ�



	//����ü ������

	 //������ ����ϴ� ���� : �ٸ� ������ �޸� �ּҸ� ���� ���� & ����

	Student student = {};

	Student* pstudent = &student;

	(*pstudent).kor = 50; //.�� ���� �ν��ϱ� ������ *pstudent�� ��ȣ�� ������ �Ŀ� ����Ű�� ����� ����� ����
	 
	cout << "kor = " << student.kor << endl;

	pstudent->kor = 80;

	cout << "kor = " << student.kor << endl; // ->�� �̿��Ͽ� ����Ű�� ��� ����� ����


	//void ������
	//void : Ÿ���� ����. void�� ������ Ÿ��Ȱ�� ���� -->> void* ������ �����ϰ� �Ǹ� � Ÿ���� �޸� �ּҵ� ���� ����
	//��, ������ �Ұ����ϸ� �޸� �ּ� ���常 ����
	//only �޸� �ּ� ����� ���� �뵵�� ���
	int num = 100;

	void* pvoid = &num;
	cout << "num address: " << pvoid << endl;
	//*pvoid = 1000;  --> ������ �Ұ�
	//cout << "*pvoid : " << *pvoid ;  --> ������ �Ұ�
	cout << "*((int *)pvoid) == num : " << *((int*)pvoid) << endl;  //�ش� ���� ���� Ÿ�������� ����ȯ�� ���� �������� ����

	int* pnum = (int*)pvoid;
	*pnum = 1000; // int Ÿ������ ����ȯ�� �� �� int Ÿ�� ������ ������ �����ϸ� ������(����) ����

	cout << "num : " << num << endl;
	
	pvoid = &student;
	cout << "student address: " << pvoid << endl;  //int, ����ü Ÿ�� �޸� �ּ� ���� ����
	//*pvoid->kor = 1000; -->������ �Ұ�
	
	//������ �迭& ������

	int ar[][2] = { {1,2} , {3,4} };

	cout << "&ar[0][0] : " << &ar[0][0] << endl;
	cout << "ar : " << ar << endl;
	cout << "ar[0] : " << ar[0] << endl;


}