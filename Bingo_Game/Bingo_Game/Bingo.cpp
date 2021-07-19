#include<stdio.h>
#include<iostream>
#include<time.h>

// ���� �Է� & ���� �� ������ �ľ��ϴ� �ڵ�
//bingo 5 x 5

enum AI_MODE {
	A_HARD = 1,
	A_EASY
}; // A_EASY == 2

enum LINE {//Hard ��忡�� ���� ���ɼ� ���� ���� �� ������ ���� ����ü
	h1, //������
	h2,
	h3,
	h4,
	h5,
	v1, //������
	v2,
	v3,
	v4,
	v5,
	lt, //���� �밢��
	rt  //������ �밢��

};
int main() {

	srand((unsigned int)time(NULL));

	int num[25] = {};
	int ainum[25] = {}; //ai �� �迭

	for (int i = 0; i < 25; i++) {
		num[i] = i + 1;
		ainum[i] = i + 1;
	}

	//����

	int temp, index1, index2, aindex1, aindex2;
	for (int i = 0; i < 100; i++) {
		index1 = rand() % 25;
		index2 = rand() % 25;

		temp = num[index1];
		num[index1] = num[index2];
		num[index2] = temp;

		aindex1 = rand() % 25;
		aindex2 = rand() % 25;

		temp = ainum[aindex1];
		ainum[aindex1] = ainum[aindex2];
		ainum[aindex2] = temp;
	}

	int count = 0; //���� �� �� üũ
	int aicount = 0; // ai ���� �� �� üũ

	//ai ���̵� ����
	int aimode;
	while (true) {
		system("cls");

		printf("1. HARD \n");
		printf("2. EASY ");
		
		scanf_s("%d", &aimode);

		if (aimode >= A_HARD || aimode <= A_EASY) // A_HARD�� 1 A_EASY�� 2�̱� ������ 1���� ũ�ų� ���� 2���� �۰ų� ������ ��Ȯ�ϰ� ��� ���� �Ϸ�!
			break;
	}
	//easy��� = ���� ���� ��� �� *�� �ٲ��� ���� ���� ��� ����� �� ��� �� �ϳ� �����ϰ� ���� --> ���� �� �� ���� �迭 ������ ��
	int ns[25] = {}; // ns = noneselect

	//���� �� �� ���� ���� ���� ���� - �ʱⰪ 0, �ݺ��� ������ ���� ������
	int ns_count = 0;


	

		while (true) {
			system("cls");

			printf("=================Player=================\n");
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {

					if (num[i * 5 + j] == INT_MAX)
						printf("*\t");
					else
						printf("%d\t", num[i * 5 + j]);
				}
				printf("\n");
			} // 5 x 5 ���

			printf("Player Bingo : %d\n", count);

			//ai ���� �� ���

			printf("=================AI=================\n");
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {

					if (ainum[i * 5 + j] == INT_MAX)
						printf("*\t");
						
					else
						printf("%d\t", ainum[i * 5 + j]);
				}
				printf("\n");
			} // ai ������ 5 x 5 ���

			printf(" AI Bingo : %d\n", aicount);



			if (count >= 5) {//5 ���� �̻��� ��� ���� ����
				printf("Player Win!!");
				break;
			}
			else if (aicount >= 5) {
				printf("AI Win!!");
				break;
			}



			printf("���ڸ� �Է��ϼ���(0:����) : ");
			int input;
			scanf_s("%d", &input);

			if (input == 0) {
				break;
			}
			else if (input < 1 || input > 25) {
				printf("\n �ٽ� �Է��Ͻÿ�");
				continue;
			}

			// ������ �Է��̶�� �Է� ���� ���ڸ� ���� �ٲ�

			bool ac = true;//���� ���� �ٲ���� ����(�ߺ�) Ȯ�� ���� ���� - �ߺ��Ͻ� �ٽ� �Է� ����

			for (int i = 0; i < 25; i++) {//��� ���ڸ� �ݺ��ϸ� �Է��� ���ڿ� ������ Ȯ��

				if (input == num[i]) {//���� ���� ���� ���(: �ߺ� X _ ���� �Էµ� ���ڵ��� ��� INT_MAX�� ��ü��)

					ac = false; // false = �ߺ� X �� ����

					// ���ڸ� *�� �����ϱ� ���� Ư���� �� INT_MAX
					num[i] = INT_MAX;
					break;
				}
			}

			for (int i = 0; i < 25; i++) {
				if (input == ainum[i]) {
					ainum[i] = INT_MAX;
					break;
				}
			}

			//ai ���� ����

			switch (aimode) {
				//hard��� = ai�� �����ɼ��� ���� ���� ���� ����(���� ���� �����ؾ��� ���� ������ ���� ���� ��), �� �� �� �ϳ��� ���� ����
				//*�� ���� ���� �� Ž��!(���� �ϼ��� �� ����)
				case A_HARD: {
					int line = 0;
					int starcount = 0;
					int savecount = 0;

					for (int i = 0; i < 5; i++) {//���� ���� �߰��� *���� �� ã�Ƴ���
						starcount = 0;
						for (int j = 0; j < 5; j++) {
							if (ainum[i * 5 + j] == INT_MAX)
								starcount++;
						}

						if ((starcount < 5) && (savecount < starcount)) {//ī��Ʈ�� ���� *������ 5���� �۰� ������ ������ savecount���� Ŭ �ܿ�
							line = i ;//��� ° ������ ���� ����
							savecount = starcount;
						}// ���� for�� ���� �Ŀ� line == 0�̸� ���� �� �߿� *�� ���� ���� ���� �ƴ����� ù��° ������!!, ������ 0~4�� �ǹ̺ο�
					}

					for (int i = 0; i < 5; i++) {//���� ���� ���� *���� �� ���� ���� ==> �� ���� ���� ���ε� ���Ͽ� ���� * ���� �� ����
						starcount = 0;
						for (int j = 0; j < 5; j++) {
							if (ainum[ (j * 5) + i] == INT_MAX) {
								starcount++;
							}
						}
						if (starcount < 5 && savecount < starcount) {
							line = i + 5; //���ζ����� 5~9�� �ǹ̺ο�
							savecount = starcount;
						}
					}

					starcount = 0;
					for (int i = 0; i < 25; i += 6) {//������ �밢�� üũ
						if (ainum[i] == INT_MAX)
							starcount++;
					}

					if (starcount < 5 && savecount < starcount) {
						line = lt;//����ü LINE ���� lt�� 10���� ������
						savecount = starcount;
					}

					starcount = 0;
					for (int i = 4; i <= 20; i += 4) {//����� �밢�� üũ
						if (ainum[i] == INT_MAX)
							starcount++;
					}

					if (starcount < 5 && savecount < starcount) {
						line = rt;//����ü LINE ���� lt�� 11���� ������
						savecount = starcount;
					}

					//��� ���� ���� �Ϸ� =  ��� ���� �� line�� ���� ���ɼ� ���� ���� ������ ��ȣ�� ���ڵǾ� ����
					//�ش� �ٿ� �ִ� *�� �ƴ� ���� �� �ϳ��� �����ϰ� �Ѵ�
					
					//���ɼ� ���� ���� �������� ���
					if (line <= h5) {
						for (int i = 0; i < 5; i++) {
							if (ainum[line * 5 + i] != INT_MAX) {//������ �� ���� ��ȣ�� ���ڵ��� �ݺ��ϸ� *�� �ƴ� ���� Ȯ��
								input = ainum[line * 5 + i];
								break;

							}
						}
					}
					//������ �� ��� (line 5~9)
					else if (line <= v5 && line > h5) {
						for (int i = 0; i < 5; i++) {
							if (ainum[i * 5 + (line - 5)] != INT_MAX) {
								input = ainum[i * 5 + (line - 5)];
								break;
							}
						}
					}
					//������ �밢���� ���
					else if (line == lt) {
						for (int i = 0; i < 25; i += 6) {
							if (ainum[i] != INT_MAX) {
								input = ainum[i];
								break;
							}
						}
					}
					else if(line == rt) {
						for (int i = 4; i <= 20; i += 4) {
							if (ainum[i] != INT_MAX) {
								input = ainum[i];
								break;
							}
						}
					}


					break;
				}
				case A_EASY: {//���� �ȵ� ���� ��� ����
					ns_count = 0;

					for (int i = 0; i < 25; i++) {
						ns[ns_count] = ainum[i];
						ns_count++; // *�� �ƴ� ���Ҹ� ns[]�� ����  --> ���� �� �� ��� & ���� �� �� ������ �������
					}

					input = ns[rand() % ns_count];//���� �� �� ���� �� 0~���� �� �� ���� ���� �� �ϳ��� ���� �ε����� input�� ����
					break;
				}
			}
			//ai ���� ���� �Ϸ�
			
			for (int i = 0; i < 25; i++) {
				if (num[i] == input) {
					num[i] = INT_MAX;
					break;
				}
			} // ai�� ������ ���ڸ� player �����ǿ��� *�� ��ü

			for (int i = 0; i < 25; i++) {
				if (ainum[i] == input) {
					ainum[i] = INT_MAX;
					break;
				}
			}// ai�� ������ ���ڸ� ai �����ǿ��� *�� ��ü
			

			
			//ac �� true�� ��� �ߺ��� ���� �Է� ==> continue�Ͽ� �ٽ� �Է�
			if (ac == true) {
				printf("\n �ߺ��� �� �Է�, �ٽ� �Է��Ͻÿ�");
				continue;
			}

			//�ݺ��� ������ ���� �� (count) ���� ī��Ʈ ==> �Ź� count = 0�ʱ�ȭ�ϰ� ���� ī��Ʈ
			count = 0;
			//����, ���� �� �� ī��Ʈ
			int c1 = 0, c2 = 0;

			for (int i = 0; i < 5; i++) {
				c1 = 0, c2 = 0;
				for (int j = 0; j < 5; j++) {
					//���� �� ���� üũ
					if (num[i * 5 + j] == INT_MAX)
						c1++;

					//���� �� ���� üũ
					if (num[i + (5 * j)] == INT_MAX)
						c2++;
				}
				if (c1 == 5) {
					count++;
				}

				if (c2 == 5)
					count++;
			}

			//�밢�� ���� üũ (0,6,12,18,24) ��ġ & (20, 16,12,8,4) ��ġ
			int d1 = 0, d2 = 0;

			for (int i = 0; i < 5; i++) {

				if (num[i * 6] == INT_MAX)
					d1++;

				if (num[(i + 1) * 4] == INT_MAX)
					d2++;
			}

			if (d1 == 5)
				count++;
			if (d2 == 5)
				count++;


			//ai ���� ī��Ʈ
			aicount = 0;
			//����, ���� �� �� ī��Ʈ
			int cc1 = 0, cc2 = 0;

			for (int i = 0; i < 5; i++) {
				cc1 = 0, cc2 = 0;
				for (int j = 0; j < 5; j++) {
					//���� �� ���� üũ
					if (ainum[i * 5 + j] == INT_MAX)
						cc1++;

					//���� �� ���� üũ
					if (ainum[i + (5 * j)] == INT_MAX)
						cc2++;
				}
				if (cc1 == 5) {
					aicount++;
				}

				if (cc2 == 5)
					aicount++;
			}

			//�밢�� ���� üũ (0,6,12,18,24) ��ġ & (20, 16,12,8,4) ��ġ
			int dd1 = 0, dd2 = 0;

			for (int i = 0; i < 5; i++) {

				if (ainum[i * 6] == INT_MAX)
					dd1++;

				if (ainum[(i + 1) * 4] == INT_MAX)
					dd2++;
			}

			if (dd1 == 5)
				aicount++;
			if (dd2 == 5)
				aicount++;
		}

	return 0;
	
}