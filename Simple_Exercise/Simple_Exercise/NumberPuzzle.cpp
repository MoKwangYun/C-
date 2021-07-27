#include<stdio.h>
#include<iostream>
#include<time.h>
#include<conio.h>//�ܼ�â���� ������ϴ� �Լ��� �����ϴ� ���

using namespace std;

//, wasd�� ����Ͽ� ��ǥ�� �����̴� ���� ���� ����

int main() {
	
	srand((unsigned int)time(NULL));

	int Num[25] = {};

	for (int i = 0; i < 24; i++) {
		Num[i] = i + 1;
	}

	//���� ������ ���Ҵ� �������� ����д�. , ������ �ǹ��ϴ� ������ Ư���� �� ���: INT_MAX(�̹� ���ǵǾ� �ִ°�
	Num[24] = INT_MAX; // F12�� ���� Ȯ�� ���� (INT_MAX = int�� ǥ���� �� �ִ� �ִ밪
	
	int starindex = 24;//�ʱ� *�� ��µ� ��ġ
	//������ ���� �����ϰ� 1~24������ ���ڸ� �����ش�.

	int temp, index1, index2;

	for (int i = 0; i < 100; i++) { // ���� �˰���
		index1 = rand() % 24;
		index2 = rand() % 24;

		temp = Num[index1];
		Num[index1] = Num[index2];
		Num[index2] = temp;
	}

	/*for (int i = 0; i < 25; i++) {
		printf("\n%d", Num[i]);
	}*/

	//5 x  5 �� ���
	while (true) {
		system("cls");

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {

				if (Num[i * 5 + j] == INT_MAX)
					printf("  *");

				else
					printf("%3.d ", Num[(i * 5) + j]);

			}
			printf("\n");
		}

		bool win = true;

		for (int i = 0; i < 24; i++) {
			if (Num[i] != i + 1) {
				win = false;
				break;
			}
	
		}//�� ��ġ�� ��� ���ڰ� ���� ������(= 0~24 �������) ���������� Ȯ��

		if (win == true) {
			printf(" ���ڸ� ��� ������ϴ�!!\n");
			break;
		}


		printf("\nw:�� s: �Ʒ� a: ���� d: ������ q: ����");
		char c = _getch(); //���� �Ѱ��� �Է� �޴µ� enter ������ ������ �ƴ϶� ���ڸ� ������ ���� ��  ���� ��ȯ

		if (c == 'q' || c == 'Q')
			break;

		switch (c) {

			
			case 'w': case 'W': {//���� �ִ� ��ġ �ٷ� ���� ���� ��ü
				if (starindex - 5 >= 0) {
					Num[starindex] = Num[starindex - 5];
					Num[starindex - 5] = INT_MAX;
					starindex -= 5;
				}

				else {
					Num[starindex] = Num[25 - (5-starindex)];
					Num[25-(5-starindex)] = INT_MAX;
					starindex = 25 - (5 - starindex);
				}
				break;
			}
			case 's': case 'S': {
				if (starindex + 5 <= 24) {
					Num[starindex] = Num[starindex + 5];
					Num[starindex + 5] = INT_MAX;
					starindex += 5;
				}

				else {
					Num[starindex] = Num[5-(25 - starindex)];
					Num[5 - (25 - starindex)] = INT_MAX;
					starindex = 5 - (25 - starindex);
				}
				break;
			}
			case 'a': case 'A': {
				if (starindex - 1 >= 0) {
					Num[starindex] = Num[starindex - 1];
					Num[starindex - 1] = INT_MAX;
					starindex -= 1;
				}

				else {
					Num[starindex] = Num[24];
					Num[24] = INT_MAX;
					starindex = 24;
				}
				break;
			}
			case 'd': case 'D': {
				if (starindex + 1 <= 24) {
					Num[starindex] = Num[starindex + 1];
					Num[starindex + 1] = INT_MAX;
					starindex += 1;
				}

				else {
					Num[starindex] = Num[0];
					Num[0] = INT_MAX;
					starindex = 0;
				}
				break;
			}
		}
		
	}

	return 0;
}