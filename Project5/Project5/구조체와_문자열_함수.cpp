#include<stdio.h>
#include<iostream>


#define NAME_SIZE 32

using namespace std;
struct student {
	int kor;
	int eng;
	int math;
	int avr;
	int total;
	int num;
	char name[NAME_SIZE];
};

int main() {

	student tstudent = {}; //tstudent(studentŸ��)�� ������� 0���� �ʱ�ȭ
	student tstudent2 = {};
	student studentarray[100] = {}; //student Ÿ���� �迭

	//����ü ����� ����
	tstudent.kor = 100;

	//���ڿ��� �迭�� �־��� ���� �ܼ� ���� �Ұ� --> strcpy_s �Լ� �̿��Ͽ� ���ڿ��� ����
	strcpy_s(tstudent.name, "Ken");
	
	//���ڿ��� ���� �׻� 0(NULL)�� ������ �Ѵ�. 
	//�׷��� �����Ⱚ�� �� �ִ� ���¿��� tstudent.name[0] = '��';�� ���� �� �迭 �ε����� ���� �־��ְ� �Ǹ�
	//�� ���� ��µǰ� ���� �־����� ���� ������ �κ��� ������ ������ ���
	//Because ���ڿ��� ���� �ν��� �� ���� �����̴�.
	tstudent2.name[0] = 'K';
	tstudent2.name[1] = 'e';
	tstudent2.name[2] = 'n';
	tstudent2.name[3] = 0;//0�� �ְ����ϴ� ���ڿ� ���� �ε����� �־��־�� [2] �ε������� ����� ���� �� �� �ִ�(0�� ������ �ν��ϱ� ����)

	printf("%s \n %s\n", tstudent.name, tstudent2.name);

	strcat_s(tstudent2.name, " Hi");
	printf("%s \n tstudent2.name length = %d", tstudent2.name, strlen(tstudent2.name));

	char name[NAME_SIZE] = {};
	printf("\n�̸� �Է�");
	cin >> name;

	if (strcmp(tstudent.name, name) == 0) {
		printf("tstudent.name�� ������ �̸�");
	}
	

	return 0;
}