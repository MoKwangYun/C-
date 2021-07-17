#include<stdio.h>
#include<iostream>
#include<time.h>


//열거체 : 연속된 숫자의 이름을 부여할 수 있는 기능 = enum

enum NUM { // NUM = 열거체 이름, 열거체이름을 이용하여 열거체 타입 변수 선언 가능 ==> 열거체 자체가 사용자정의 변수 타입이 될 수 있음
	NUM_0,
	NUM_1,
	NUM_2,//아무것도 부여하지 않을 경우 0부터 1씩 차례로 값이 부여된다 ==> 0을 NUM_0으로 1을 NUM_1로 지정 +  NUM_0= 10일 경우 NUM_1은 11, NUM_12는 12
	NUM_3 = 20//직접 지정도 가능
};

#define NUM_4 30 //NUM_0 ~ NUM_4는 상수

enum RPS {
	RPS_S = 1,
	RPS_R,
	RPS_P,
	RPS_END
};

using namespace std;

int main() {

	NUM eNUM; //앞에서 선언한 NUM열거체 타입의 변수를 선언(무조건 4byte) sizeof(eNUM) == 4
	cout << typeid(eNUM).name() << endl;// typeid(변수 or 타입) --> 괄호 안에 있는 타입 혹은 변수의 타입을 문자열로 반환
	
	eNUM = (NUM)10;
	cout << eNUM << endl;
	

	//while: 조건식이true일 경우 하단코드 수행, false일 경우 while문을 빠져나간다. = break를 만나면 빠져나감
	//가위바위보 게임(rps)

	system("cls"); // 화면(콘솔창)을 깨끗히 지워준다

	srand((unsigned int)time(NULL));//난수 테이블 생성

	int iplayer;
	int ia;

	while (true) {
		printf("\n\n1.가위\n");
		printf("2.바위\n");
		printf("3.보\n");
		printf("4.종료\n");
		printf("메뉴를 선택하에쇼");
		cin >> iplayer;

		if (iplayer < RPS_S || iplayer > RPS_END)
		{
			printf("잘못된 입력");
			system("pause");//일시정지
			continue;//반복문의 시작지점으로 이동
		}
		else if (iplayer == RPS_END) {
			break;
		}
		
		ia = rand() % 3 + RPS_S;

		switch (ia) {
			case RPS_S: {
				printf("ai = 가위\n");
				break;
			}
			case RPS_R: {
				printf("ai = 바위\n");
				break;
			}
			case RPS_P: {
				printf("ai = 보\n");
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