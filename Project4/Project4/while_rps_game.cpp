#include<stdio.h>
#include<iostream>
#include<time.h>


//����ü : ���ӵ� ������ �̸��� �ο��� �� �ִ� ��� = enum

enum NUM { // NUM = ����ü �̸�, ����ü�̸��� �̿��Ͽ� ����ü Ÿ�� ���� ���� ���� ==> ����ü ��ü�� ��������� ���� Ÿ���� �� �� ����
	NUM_0,
	NUM_1,
	NUM_2,//�ƹ��͵� �ο����� ���� ��� 0���� 1�� ���ʷ� ���� �ο��ȴ� ==> 0�� NUM_0���� 1�� NUM_1�� ���� +  NUM_0= 10�� ��� NUM_1�� 11, NUM_12�� 12
	NUM_3 = 20//���� ������ ����
};

#define NUM_4 30 //NUM_0 ~ NUM_4�� ���

enum RPS {
	RPS_S = 1,
	RPS_R,
	RPS_P,
	RPS_END
};

using namespace std;

int main() {

	NUM eNUM; //�տ��� ������ NUM����ü Ÿ���� ������ ����(������ 4byte) sizeof(eNUM) == 4
	cout << typeid(eNUM).name() << endl;// typeid(���� or Ÿ��) --> ��ȣ �ȿ� �ִ� Ÿ�� Ȥ�� ������ Ÿ���� ���ڿ��� ��ȯ
	
	eNUM = (NUM)10;
	cout << eNUM << endl;
	

	//while: ���ǽ���true�� ��� �ϴ��ڵ� ����, false�� ��� while���� ����������. = break�� ������ ��������
	//���������� ����(rps)

	system("cls"); // ȭ��(�ܼ�â)�� ������ �����ش�

	srand((unsigned int)time(NULL));//���� ���̺� ����

	int iplayer;
	int ia;

	while (true) {
		printf("\n\n1.����\n");
		printf("2.����\n");
		printf("3.��\n");
		printf("4.����\n");
		printf("�޴��� �����Ͽ���");
		cin >> iplayer;

		if (iplayer < RPS_S || iplayer > RPS_END)
		{
			printf("�߸��� �Է�");
			system("pause");//�Ͻ�����
			continue;//�ݺ����� ������������ �̵�
		}
		else if (iplayer == RPS_END) {
			break;
		}
		
		ia = rand() % 3 + RPS_S;

		switch (ia) {
			case RPS_S: {
				printf("ai = ����\n");
				break;
			}
			case RPS_R: {
				printf("ai = ����\n");
				break;
			}
			case RPS_P: {
				printf("ai = ��\n");
				break;
			}

		}

		int iwin = iplayer - ia;

		if (iwin == 1 || iwin == -2) { //
			printf("player win\n");
		}
		else if (iwin == 0) {
			printf("draw\n");
		}
		else {
			printf("player lose\n");
		}



	}

	return 0;

}