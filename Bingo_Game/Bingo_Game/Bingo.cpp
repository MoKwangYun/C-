#include<stdio.h>
#include<iostream>
#include<time.h>

// 숫자 입력 & 별이 몇 줄인지 파악하는 코드
//bingo 5 x 5

enum AI_MODE {
	A_HARD = 1,
	A_EASY
}; // A_EASY == 2

enum LINE {//Hard 모드에서 빙고 가능성 가장 높은 줄 선택을 위한 열거체
	h1, //가로줄
	h2,
	h3,
	h4,
	h5,
	v1, //세로줄
	v2,
	v3,
	v4,
	v5,
	lt, //왼쪽 대각선
	rt  //오른쪽 대각선

};
int main() {

	srand((unsigned int)time(NULL));

	int num[25] = {};
	int ainum[25] = {}; //ai 용 배열

	for (int i = 0; i < 25; i++) {
		num[i] = i + 1;
		ainum[i] = i + 1;
	}

	//셔플

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

	int count = 0; //빙고 줄 수 체크
	int aicount = 0; // ai 빙고 줄 수 체크

	//ai 난이도 선택
	int aimode;
	while (true) {
		system("cls");

		printf("1. HARD \n");
		printf("2. EASY ");
		
		scanf_s("%d", &aimode);

		if (aimode >= A_HARD || aimode <= A_EASY) // A_HARD는 1 A_EASY는 2이기 때문에 1보다 크거나 같고 2보다 작거나 같으면 정확하게 모드 선택 완료!
			break;
	}
	//easy모드 = 현재 숫자 목록 중 *로 바뀌지 않은 숫자 목록 만들어 그 목록 중 하나 랜덤하게 선택 --> 선택 안 된 숫자 배열 만들어야 함
	int ns[25] = {}; // ns = noneselect

	//선택 안 된 숫자 개수 저장 변수 - 초기값 0, 반복할 때마다 새로 구해줌
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
			} // 5 x 5 출력

			printf("Player Bingo : %d\n", count);

			//ai 빙고 판 출력

			printf("=================AI=================\n");
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {

					if (ainum[i * 5 + j] == INT_MAX)
						printf("*\t");
						
					else
						printf("%d\t", ainum[i * 5 + j]);
				}
				printf("\n");
			} // ai 빙고판 5 x 5 출력

			printf(" AI Bingo : %d\n", aicount);



			if (count >= 5) {//5 빙고 이상일 경우 게임 종료
				printf("Player Win!!");
				break;
			}
			else if (aicount >= 5) {
				printf("AI Win!!");
				break;
			}



			printf("숫자를 입력하세요(0:종료) : ");
			int input;
			scanf_s("%d", &input);

			if (input == 0) {
				break;
			}
			else if (input < 1 || input > 25) {
				printf("\n 다시 입력하시오");
				continue;
			}

			// 정상적 입력이라면 입력 받은 숫자를 별로 바꿈

			bool ac = true;//전에 별로 바뀌었던 숫자(중복) 확인 위한 변수 - 중복일시 다시 입력 받음

			for (int i = 0; i < 25; i++) {//모든 숫자를 반복하며 입력한 숫자와 같은지 확인

				if (input == num[i]) {//같은 숫자 있을 경우(: 중복 X _ 전에 입력된 숫자들은 모두 INT_MAX로 교체됨)

					ac = false; // false = 중복 X 로 규정

					// 숫자를 *로 변경하기 위한 특수한 값 INT_MAX
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

			//ai 숫자 선택

			switch (aimode) {
				//hard모드 = ai가 빙고가능성이 가장 높은 줄을 선택(빙고를 위해 선택해야할 수의 개수가 가장 적은 줄), 그 중 줄 하나의 숫자 선택
				//*이 가장 많은 줄 탐색!(빙고 완성된 줄 제외)
				case A_HARD: {
					int line = 0;
					int starcount = 0;
					int savecount = 0;

					for (int i = 0; i < 5; i++) {//가로 라인 중가장 *많은 줄 찾아낸다
						starcount = 0;
						for (int j = 0; j < 5; j++) {
							if (ainum[i * 5 + j] == INT_MAX)
								starcount++;
						}

						if ((starcount < 5) && (savecount < starcount)) {//카운트한 줄이 *개수가 5보다 작고 이전에 저장한 savecount보다 클 겨우
							line = i ;//몇번 째 가로줄 인지 저장
							savecount = starcount;
						}// 현재 for문 종료 후에 line == 0이면 가로 줄 중에 *이 가장 많고 빙고가 아닌줄은 첫번째 가로줄!!, 가로줄 0~4로 의미부여
					}

					for (int i = 0; i < 5; i++) {//가로 라인 가장 *많은 줄 구한 상태 ==> 그 값과 세로 라인들 비교하여 가장 * 많은 줄 갱신
						starcount = 0;
						for (int j = 0; j < 5; j++) {
							if (ainum[ (j * 5) + i] == INT_MAX) {
								starcount++;
							}
						}
						if (starcount < 5 && savecount < starcount) {
							line = i + 5; //세로라인은 5~9로 의미부여
							savecount = starcount;
						}
					}

					starcount = 0;
					for (int i = 0; i < 25; i += 6) {//우하향 대각선 체크
						if (ainum[i] == INT_MAX)
							starcount++;
					}

					if (starcount < 5 && savecount < starcount) {
						line = lt;//열거체 LINE 에서 lt는 10으로 지정됨
						savecount = starcount;
					}

					starcount = 0;
					for (int i = 4; i <= 20; i += 4) {//우상향 대각선 체크
						if (ainum[i] == INT_MAX)
							starcount++;
					}

					if (starcount < 5 && savecount < starcount) {
						line = rt;//열거체 LINE 에서 lt는 11으로 지정됨
						savecount = starcount;
					}

					//모든 라인 조사 완료 =  모든 라인 중 line에 빙고 가능성 가장 높은 라인의 번호가 저자되어 있음
					//해당 줄에 있는 *이 아닌 숫자 중 하나를 선택하게 한다
					
					//가능성 높은 줄이 가로줄일 경우
					if (line <= h5) {
						for (int i = 0; i < 5; i++) {
							if (ainum[line * 5 + i] != INT_MAX) {//가로줄 중 라인 번호내 숫자들을 반복하며 *이 아닌 값을 확인
								input = ainum[line * 5 + i];
								break;

							}
						}
					}
					//세로줄 일 경우 (line 5~9)
					else if (line <= v5 && line > h5) {
						for (int i = 0; i < 5; i++) {
							if (ainum[i * 5 + (line - 5)] != INT_MAX) {
								input = ainum[i * 5 + (line - 5)];
								break;
							}
						}
					}
					//우하향 대각선일 경우
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
				case A_EASY: {//선택 안된 숫자 목록 만듬
					ns_count = 0;

					for (int i = 0; i < 25; i++) {
						ns[ns_count] = ainum[i];
						ns_count++; // *이 아닌 원소만 ns[]에 저장  --> 선택 안 된 목록 & 선택 안 된 개수가 만들어짐
					}

					input = ns[rand() % ns_count];//선택 안 된 원소 중 0~선택 안 될 개수 까지 중 하나의 랜덤 인덱스를 input에 저장
					break;
				}
			}
			//ai 숫자 선택 완료
			
			for (int i = 0; i < 25; i++) {
				if (num[i] == input) {
					num[i] = INT_MAX;
					break;
				}
			} // ai가 선택한 숫자를 player 빙고판에서 *로 교체

			for (int i = 0; i < 25; i++) {
				if (ainum[i] == input) {
					ainum[i] = INT_MAX;
					break;
				}
			}// ai가 선택한 숫자를 ai 빙고판에서 *로 교체
			

			
			//ac 가 true일 경우 중복된 숫자 입력 ==> continue하여 다시 입력
			if (ac == true) {
				printf("\n 중복된 값 입력, 다시 입력하시오");
				continue;
			}

			//반복할 때마다 빙고 수 (count) 새로 카운트 ==> 매번 count = 0초기화하고 새로 카운트
			count = 0;
			//가로, 세로 별 수 카운트
			int c1 = 0, c2 = 0;

			for (int i = 0; i < 5; i++) {
				c1 = 0, c2 = 0;
				for (int j = 0; j < 5; j++) {
					//가로 별 개수 체크
					if (num[i * 5 + j] == INT_MAX)
						c1++;

					//세로 별 개수 체크
					if (num[i + (5 * j)] == INT_MAX)
						c2++;
				}
				if (c1 == 5) {
					count++;
				}

				if (c2 == 5)
					count++;
			}

			//대각선 빙고 체크 (0,6,12,18,24) 위치 & (20, 16,12,8,4) 위치
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


			//ai 빙고 카운트
			aicount = 0;
			//가로, 세로 별 수 카운트
			int cc1 = 0, cc2 = 0;

			for (int i = 0; i < 5; i++) {
				cc1 = 0, cc2 = 0;
				for (int j = 0; j < 5; j++) {
					//가로 별 개수 체크
					if (ainum[i * 5 + j] == INT_MAX)
						cc1++;

					//세로 별 개수 체크
					if (ainum[i + (5 * j)] == INT_MAX)
						cc2++;
				}
				if (cc1 == 5) {
					aicount++;
				}

				if (cc2 == 5)
					aicount++;
			}

			//대각선 빙고 체크 (0,6,12,18,24) 위치 & (20, 16,12,8,4) 위치
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