#include<stdio.h>

#include<iostream>
#include<time.h>//시간 관련 함수들 존재

using namespace std;

int main() {
	//난수 발생 
	srand((unsigned int) time(NULL)); // 난수테이블 생성/ unsigned int --> 음수 사용 불가 / time(NULL) --> 현재 시간 기준으로 시간값

	int num = rand() % 100 + 1; //1~100 사이의 난수 num에 저장
	double num2 = (rand() % 10000) / 100.f; // 0~ 99.99 사이 난수 num2에 저장 (10000으로 나눌때 나머지 = 0~9999 을 100f으로 나누면 0~99.99

	printf("%d", num);
	printf("\n%f", num2);

	printf("\n\n");

	//강화 확률 구하기
	int up = 0;
	cout << "upgrade 기본수치 입력 : "; // = printf("upgrade  기본수치 입력 : ");
	cin >> up; // = scanf("%d", &up);

	float per = rand() % 10000 / 100.f;
	
	//강화 확률: up 이 0~ 3= 100% 성공 / 4 ~6 = 40% 성공 / 7~9 = 10% 성공 / 10~13 = 1% 성공 / 14~15 = 0.01% 성공

	cout << "Upgrade : " << up << endl;
	cout << "Percent : " << per << endl;

	if (up <= 3)
		cout << "강화 성공" << endl;
	else if (up >= 4 && up <= 6) {
		if(per < 40.f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}
	else if (up >= 7 && up <= 9) {
		if (per < 10.f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}
	else if (up >= 10 && up <= 13) {
		if (per < 1.f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}
	else if (up >= 14 && up <= 15) {
		if (per < 0.01f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}


	return 0;
}