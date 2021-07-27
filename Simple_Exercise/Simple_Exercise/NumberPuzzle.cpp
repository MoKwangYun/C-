#include<stdio.h>
#include<iostream>
#include<time.h>
#include<conio.h>//콘솔창에서 입출력하는 함수들 제공하는 헤더

using namespace std;

//, wasd를 사용하여 별표를 움직이는 숫자 퍼즐 게임

int main() {
	
	srand((unsigned int)time(NULL));

	int Num[25] = {};

	for (int i = 0; i < 24; i++) {
		Num[i] = i + 1;
	}

	//가장 마지막 원소는 공백으로 비워둔다. , 공백을 의미하는 값으로 특수한 값 사용: INT_MAX(이미 정의되어 있는값
	Num[24] = INT_MAX; // F12를 통해 확인 가능 (INT_MAX = int로 표현할 수 있는 최대값
	
	int starindex = 24;//초기 *가 출력될 위치
	//마지막 공백 제외하고 1~24까지의 숫자만 섞어준다.

	int temp, index1, index2;

	for (int i = 0; i < 100; i++) { // 셔플 알고리즘
		index1 = rand() % 24;
		index2 = rand() % 24;

		temp = Num[index1];
		Num[index1] = Num[index2];
		Num[index2] = temp;
	}

	/*for (int i = 0; i < 25; i++) {
		printf("\n%d", Num[i]);
	}*/

	//5 x  5 로 출력
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
	
		}//각 위치의 모든 숫자가 셔플 이전의(= 0~24 순서대로) 맞춰졌는지 확인

		if (win == true) {
			printf(" 숫자를 모두 맞췄습니다!!\n");
			break;
		}


		printf("\nw:위 s: 아래 a: 왼쪽 d: 오른쪽 q: 종료");
		char c = _getch(); //문자 한개를 입력 받는데 enter 누르는 순간이 아니라 문자를 누르는 순간 그  문자 반환

		if (c == 'q' || c == 'Q')
			break;

		switch (c) {

			
			case 'w': case 'W': {//별이 있는 위치 바로 위의 값과 교체
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