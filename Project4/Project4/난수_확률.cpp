#include<stdio.h>

#include<iostream>
#include<time.h>//�ð� ���� �Լ��� ����

using namespace std;

int main() {
	//���� �߻� 
	srand((unsigned int) time(NULL)); // �������̺� ����/ unsigned int --> ���� ��� �Ұ� / time(NULL) --> ���� �ð� �������� �ð���

	int num = rand() % 100 + 1; //1~100 ������ ���� num�� ����
	double num2 = (rand() % 10000) / 100.f; // 0~ 99.99 ���� ���� num2�� ���� (10000���� ������ ������ = 0~9999 �� 100f���� ������ 0~99.99

	printf("%d", num);
	printf("\n%f", num2);

	printf("\n\n");

	//��ȭ Ȯ�� ���ϱ�
	int up = 0;
	cout << "upgrade �⺻��ġ �Է� : "; // = printf("upgrade  �⺻��ġ �Է� : ");
	cin >> up; // = scanf("%d", &up);

	float per = rand() % 10000 / 100.f;
	
	//��ȭ Ȯ��: up �� 0~ 3= 100% ���� / 4 ~6 = 40% ���� / 7~9 = 10% ���� / 10~13 = 1% ���� / 14~15 = 0.01% ����

	cout << "Upgrade : " << up << endl;
	cout << "Percent : " << per << endl;

	if (up <= 3)
		cout << "��ȭ ����" << endl;
	else if (up >= 4 && up <= 6) {
		if(per < 40.f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}
	else if (up >= 7 && up <= 9) {
		if (per < 10.f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}
	else if (up >= 10 && up <= 13) {
		if (per < 1.f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}
	else if (up >= 14 && up <= 15) {
		if (per < 0.01f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}


	return 0;
}