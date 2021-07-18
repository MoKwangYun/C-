#include<stdio.h>
#include<iostream>
#include<time.h>


int main() {
	//샘플 프로그램으로 로또 당첨 번호 뽑는 프로그램, 6개 숫자 무작위 & 중복 X
	int iL[45] = {}; //45개의 원소0으로 초기화

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 6; i++) {
		printf("%d\n", rand() % 45 + 1); //1~45, but 중복 있을 수 있음
	}

	printf("\n\n");

	//셔플 알고리즘  활용, 1~45를 배열에 저장한 뒤 난수가 아니라 원소들을 섞음으로 6개 숫자 구함.
	// 활용 = 하스스톤 등 카드 게임에 주로 사용
	for (int j = 0; j < 45; j++) {
		iL[j] = j + 1;//1~45까지 넣어준다
	}

	//Swap 알고리즘
	int inum1 = 1, inum2 = 2, inum3;
	inum3 = inum1;
	inum1 = inum2;
	inum2 = inum3; //결과적으로 inum1과 inum2를 바꾸는 swap 알고리즘

	//shuffle
	int itemp, idex1, idex2;
	//100번 정도섞어준다
	for (int i = 0; i < 100; i++) {
		idex1 = rand() % 44;
		idex2 = rand() % 44; //랜덤한 두개 인덱스 구해옴

		itemp = iL[idex1];
		iL[idex1] = iL[idex2];
		iL[idex2] = itemp;

		//랜덤한 두개 값을 인덱스로 하여 swap --> 이것을 100번 반복함으로 iL 배열을 섞어준다.
	}

	for (int i = 0; i < 6; i++) {
		printf("%d\n", iL[i]);
	}

	printf("보너스 번호: %d", iL[6]);


}