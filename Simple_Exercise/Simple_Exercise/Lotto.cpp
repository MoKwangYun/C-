#include<stdio.h>
#include<iostream>
#include<time.h>


int main() {
	//���� ���α׷����� �ζ� ��÷ ��ȣ �̴� ���α׷�, 6�� ���� ������ & �ߺ� X
	int iL[45] = {}; //45���� ����0���� �ʱ�ȭ

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 6; i++) {
		printf("%d\n", rand() % 45 + 1); //1~45, but �ߺ� ���� �� ����
	}

	printf("\n\n");

	//���� �˰���  Ȱ��, 1~45�� �迭�� ������ �� ������ �ƴ϶� ���ҵ��� �������� 6�� ���� ����.
	// Ȱ�� = �Ͻ����� �� ī�� ���ӿ� �ַ� ���
	for (int j = 0; j < 45; j++) {
		iL[j] = j + 1;//1~45���� �־��ش�
	}

	//Swap �˰���
	int inum1 = 1, inum2 = 2, inum3;
	inum3 = inum1;
	inum1 = inum2;
	inum2 = inum3; //��������� inum1�� inum2�� �ٲٴ� swap �˰���

	//shuffle
	int itemp, idex1, idex2;
	//100�� ���������ش�
	for (int i = 0; i < 100; i++) {
		idex1 = rand() % 44;
		idex2 = rand() % 44; //������ �ΰ� �ε��� ���ؿ�

		itemp = iL[idex1];
		iL[idex1] = iL[idex2];
		iL[idex2] = itemp;

		//������ �ΰ� ���� �ε����� �Ͽ� swap --> �̰��� 100�� �ݺ������� iL �迭�� �����ش�.
	}

	for (int i = 0; i < 6; i++) {
		printf("%d\n", iL[i]);
	}

	printf("���ʽ� ��ȣ: %d", iL[6]);


}