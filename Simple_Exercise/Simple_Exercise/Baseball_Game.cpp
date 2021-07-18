#include<stdio.h>
#include<iostream>
#include<time.h>

int main() {
	int ia[9] = {};
	for (int i = 0; i < 9; i++) {
		ia[i] = i + 1;
	}

	int itemp, index1, index2;
	
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 100; i++) {
		index1 = rand() % 8;
		index2 = rand() % 8;//0~8까지 인덱스 중 하나 구함

		itemp = ia[index1];
		ia[index1] = ia[index2];
		ia[index2] = itemp;

	}

	for (int i = 0; i < 3; i++) {
		int temp = ia[i];
		
		printf("\n%d\n", temp);
		while (temp != 0) {
			printf("* ");
			temp--;
		}

		
	}

	int iA[3] = {};

	int n = 1;

	do{
		printf("\n\n숫자 세개를 입력하시오: ");
		for (int i = 0; i < 3; i++) {
			scanf_s("%d", &iA[i]);
		}

		int s = 0, b = 0, out = 0;
		for (int i = 0; i < 3; i++) {
			if (ia[i] == iA[i])
				s++;
			else {
				switch (i) {
				case 0: {
					if (iA[i] == ia[i + 1])
						b++;
					else if (iA[i] == ia[i + 2])
						b++;
					else
						out++;
					break;
				}

				case 1: {
					if (iA[i] == ia[i + 1])
						b++;
					else if (iA[i] == ia[i - 1])
						b++;
					else
						out++;
					break;
				}

				case 2: {
					if (iA[i] == ia[i - 1])
						b++;
					else if (iA[i] == ia[i - 2])
						b++;
					else
						out++;
					break;
					}
				}
			}

			
		}
		if (s == 3) {
			printf("\n 3Strike");
			n = 0;
		}
		else if (out == 3) {
			printf("\n Out");
		}
		else {
			printf("\n%dStrike %dball", s, b);
		}

	} while (n != 0);
	


}