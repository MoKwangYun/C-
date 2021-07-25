#include<stdio.h>

#include<iostream>

using namespace std;

int main(void) {

	/*
	������: �޸� �ּҸ�  ��Ƴ���(�����ϴ�) �����̱� ������ x86�� ��� 4yte, x64�� ��� 8byte
	�Ϲ� ������ ���� ���� / ������ ������ �޸� �ּҸ�  ����
	��� ���� Ÿ���� ������ Ÿ���������� �� �ִ�.
	
	����� �޸� �ּҿ� �����Ͽ� ���� ������ �� �ִ�.
	*/

	int num = 100;

	//������ ���� ����
	int* p = &num; //���� num�� �޸� �ּҸ� �����ϴ� ������ ���� p

	cout << "num address : " << &num << endl;
	cout << "p : " << p << endl;

	//�������� ���� �ּҰ� ����� ������ �� ����, ���� ����
	cout << "*p == num : " <<*p << endl;

	*p = 123; //num�� 123���� ����

	cout << "*p == num : " << num<< endl;


	/*
	�����Ϳ�  �迭�� ���� = �迭���� �����ʹ�!!(�迭�� ��ü�� �ش� �迭�� ������ �ּ� �� �ǹ�)
	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
	array == &array[0]
	*/
	
	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };

	cout << " array address : " << array << endl;
	cout << " array address : " << &array[0] << endl;

	int* parray = array; //(!= &array);

	cout << " parray[2] : " << parray[2] << endl;
	cout << " array[2] : " << array[2] << endl;


	/*
	������ ����: +, - ���� Ȱ��
	int �������� ��� �޸� �ּҿ� +1 ==> 1�� �ƴ� int Ÿ�� ũ�� ��ŭ �޸� �ּ� ���� (+4) 
	*/
	

	cout << "parray :" << parray << endl;
	cout << "parray + 2:" << (parray + 2) << endl; // ���� �޷θ� �ּ� �� 8 ����

	cout << "*parray: " << *parray << endl;
	cout << "*(parray + 2) : " << *(parray + 2) << endl; //8 ������ �ּ��� ���尪 ��� == array[2] (int �迭�� ���Ҵ� �޸� ũ�� 4byte)
	cout << "*parray + 100: " << *parray + 100 << endl; //*parray�� ����ѵ� �� ������ 100�� ���Ѵ�
														 
	
	


	return 0;
}