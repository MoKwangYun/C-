#include<iostream>

using namespace std;

int main() {

	/*
	���۷��� : �ٸ� ����� �����ϰ� ������ִ� ���
	������ �ϰԵǸ� �� ��� �����Ͽ� ���� ������ �� �ִ�.
	��, ���۷����� ó�� ���۷��� ���� ������ �����ϴ� �����  �������־�� �Ѵ�.

	���� -  ����Ÿ�� &���۷����� = �����Һ�����;
	*/

	int iNumber = 100;
	int iNumber1 = 999;

	//iRefNum ���۷��� ������ iNumbe�� �����Ѵ� / �����Ϳ� ���� ������ �ʿ� ���� ������ �ϰ� �ִٸ� �ٷ� �����Ͽ� ���� ����
	int& iRefNum = iNumber;

	iRefNum = 1234;

	cout << iNumber << endl;

	iRefNum = iNumber1; //iNumber1�� ���� iRefNum�� �����ϴ� ����� iNumber�� ����
	//�����ϴ� ����� ������ �� ����!!

	cout << iNumber << endl; 
	return 0;
}